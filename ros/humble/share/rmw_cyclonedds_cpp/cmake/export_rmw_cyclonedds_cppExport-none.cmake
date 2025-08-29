#----------------------------------------------------------------
# Generated CMake target import file for configuration "None".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw_cyclonedds_cpp::rmw_cyclonedds_cpp" for configuration "None"
set_property(TARGET rmw_cyclonedds_cpp::rmw_cyclonedds_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NONE)
set_target_properties(rmw_cyclonedds_cpp::rmw_cyclonedds_cpp PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NONE "CycloneDDS::ddsc;iceoryx_binding_c::iceoryx_binding_c;rcutils::rcutils;rcpputils::rcpputils;rosidl_typesupport_introspection_c::rosidl_typesupport_introspection_c;rosidl_typesupport_introspection_cpp::rosidl_typesupport_introspection_cpp;rmw_dds_common::rmw_dds_common_library;rosidl_runtime_c::rosidl_runtime_c;tracetools::tracetools"
  IMPORTED_LOCATION_NONE "${_IMPORT_PREFIX}/lib/librmw_cyclonedds_cpp.so"
  IMPORTED_SONAME_NONE "librmw_cyclonedds_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS rmw_cyclonedds_cpp::rmw_cyclonedds_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_rmw_cyclonedds_cpp::rmw_cyclonedds_cpp "${_IMPORT_PREFIX}/lib/librmw_cyclonedds_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
