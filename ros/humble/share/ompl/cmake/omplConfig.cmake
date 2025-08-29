
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was omplConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

####################################################################################

# These must be set BEFORE any call to find_package because PACKAGE_PREFIX_DIR gets overwritten by Eigen3.
# See https://cmake.org/cmake/help/latest/module/CMakePackageConfigHelpers.html#command:configure_package_config_file.
## Deprecated Variables ##
set(OMPL_FOUND ${ompl_FOUND})
set(OMPL_VERSION 1.7.0)
set(OMPL_MAJOR_VERSION 1)
set(OMPL_MINOR_VERSION 7)
set(OMPL_PATCH_VERSION 0)
set_and_check(OMPL_INCLUDE_DIRS ${PACKAGE_PREFIX_DIR}/include/ompl-1.7)

include ("${CMAKE_CURRENT_LIST_DIR}/omplExport.cmake" )
include(CMakeFindDependencyMacro)
set(_ompl_boost_components serialization filesystem system)
find_dependency(Boost REQUIRED COMPONENTS ${_ompl_boost_components})
if(Boost_FOUND)
    foreach(_comp ${_ompl_boost_components})
        get_target_property(_includes Boost::${_comp} INTERFACE_INCLUDE_DIRECTORIES)
        list(APPEND OMPL_INCLUDE_DIRS ${_includes})
    endforeach()
endif()
find_dependency(Eigen3 REQUIRED)
list(APPEND OMPL_INCLUDE_DIRS /usr/include/eigen3)

# Add OMPL's find modules to the search path so consumers can also find them.
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

if(0) # if(OMPL_HAVE_FLANN)
    find_dependency(flann REQUIRED)
endif()
# If flann is required at version 1.9.2 minimum, then the below logic is unneeded.
#if(flann_FOUND)
#    if(NOT TARGET flann::flann and TARGET flann)
#        add_library(flann::flann ALIAS flan)
#    endif()
#endif()

if(FALSE) # if(OMPL_EXTENSION_TRIANGLE)
    # If OMPL was build with TRIANGLE support,
    # then it's required to have TRIANGLE to consume OMPL.
    find_dependency(Triangle REQUIRED)
endif()

if(TRUE) # if(Threads_FOUND)
    find_dependency(Threads QUIET)
endif()

if() # if(OMPL_HAVE_SPOT)
    find_dependency(spot MODULE QUIET)
endif()

# Add optional dependent library includes based on their non-portable variable directories (best effort).
foreach(_dir ;;;;;;)
    if(_dir)
        list(APPEND OMPL_INCLUDE_DIRS "${_dir}")
    endif()
endforeach()
list(REMOVE_DUPLICATES OMPL_INCLUDE_DIRS)
set(OMPL_INCLUDE_DIRS "${OMPL_INCLUDE_DIRS}" CACHE STRING "Include path for OMPL and its dependencies - DEPRECATED")

# FIX: Set OMPL_LIBRARIES based on target and allow standard library search paths
# First, try to use the target approach which is most robust
if(TARGET ompl::ompl)
    # Extract information from the target
    set(OMPL_LIBRARIES ompl::ompl)
else()
    # Try to find the library directly
    find_library(OMPL_LIBRARY_PATH NAMES ompl
        PATHS "${PACKAGE_PREFIX_DIR}/lib")
    
    # If found, set OMPL_LIBRARIES
    if(OMPL_LIBRARY_PATH)
        set(OMPL_LIBRARIES "${OMPL_LIBRARY_PATH}")
    else()
        # Last resort: try system paths
        find_library(OMPL_LIBRARY_PATH NAMES ompl)
        if(OMPL_LIBRARY_PATH)
            set(OMPL_LIBRARIES "${OMPL_LIBRARY_PATH}")
        else()
            message(FATAL_ERROR "Could not find OMPL library. Please check your installation.")
        endif()
    endif()
    
    # Add dependent libraries
    foreach(_lib Boost::serialization;Boost::filesystem;Boost::system;)
        if(_lib)
            list(APPEND OMPL_LIBRARIES "${_lib}")
        endif()
    endforeach()
endif()

# Set OMPL_LIBRARY_DIRS for backward compatibility
set_and_check(OMPL_LIBRARY_DIRS "${PACKAGE_PREFIX_DIR}/lib/x86_64-linux-gnu")
foreach(_dir ;;;)
    if(_dir)
        list(APPEND OMPL_LIBRARY_DIRS "${_dir}")
    endif()
endforeach()
list(REMOVE_DUPLICATES OMPL_LIBRARY_DIRS)
set(OMPL_LIBRARY_DIRS "${OMPL_LIBRARY_DIRS}" CACHE STRING "Library path for OMPL and its dependencies - DEPRECATED")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ompl DEFAULT_MSG OMPL_INCLUDE_DIRS OMPL_LIBRARIES)
