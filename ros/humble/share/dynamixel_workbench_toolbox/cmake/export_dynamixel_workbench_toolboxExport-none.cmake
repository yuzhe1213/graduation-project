#----------------------------------------------------------------
# Generated CMake target import file for configuration "None".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "dynamixel_workbench_toolbox::dynamixel_workbench_toolbox" for configuration "None"
set_property(TARGET dynamixel_workbench_toolbox::dynamixel_workbench_toolbox APPEND PROPERTY IMPORTED_CONFIGURATIONS NONE)
set_target_properties(dynamixel_workbench_toolbox::dynamixel_workbench_toolbox PROPERTIES
  IMPORTED_LOCATION_NONE "${_IMPORT_PREFIX}/lib/libdynamixel_workbench_toolbox.so"
  IMPORTED_SONAME_NONE "libdynamixel_workbench_toolbox.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS dynamixel_workbench_toolbox::dynamixel_workbench_toolbox )
list(APPEND _IMPORT_CHECK_FILES_FOR_dynamixel_workbench_toolbox::dynamixel_workbench_toolbox "${_IMPORT_PREFIX}/lib/libdynamixel_workbench_toolbox.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
