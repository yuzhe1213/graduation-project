#----------------------------------------------------------------
# Generated CMake target import file for configuration "None".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ompl::ompl" for configuration "None"
set_property(TARGET ompl::ompl APPEND PROPERTY IMPORTED_CONFIGURATIONS NONE)
set_target_properties(ompl::ompl PROPERTIES
  IMPORTED_LOCATION_NONE "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libompl.so.1.7.0"
  IMPORTED_SONAME_NONE "libompl.so.18"
  )

list(APPEND _IMPORT_CHECK_TARGETS ompl::ompl )
list(APPEND _IMPORT_CHECK_FILES_FOR_ompl::ompl "${_IMPORT_PREFIX}/lib/x86_64-linux-gnu/libompl.so.1.7.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
