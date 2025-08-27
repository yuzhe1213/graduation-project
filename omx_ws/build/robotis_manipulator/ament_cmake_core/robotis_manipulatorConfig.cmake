# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_robotis_manipulator_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED robotis_manipulator_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(robotis_manipulator_FOUND FALSE)
  elseif(NOT robotis_manipulator_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(robotis_manipulator_FOUND FALSE)
  endif()
  return()
endif()
set(_robotis_manipulator_CONFIG_INCLUDED TRUE)

# output package information
if(NOT robotis_manipulator_FIND_QUIETLY)
  message(STATUS "Found robotis_manipulator: 1.0.0 (${robotis_manipulator_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'robotis_manipulator' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${robotis_manipulator_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(robotis_manipulator_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${robotis_manipulator_DIR}/${_extra}")
endforeach()
