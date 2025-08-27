// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from open_manipulator_msgs:msg/KinematicsPose.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "open_manipulator_msgs/msg/detail/kinematics_pose__struct.h"
#include "open_manipulator_msgs/msg/detail/kinematics_pose__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool open_manipulator_msgs__msg__kinematics_pose__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("open_manipulator_msgs.msg._kinematics_pose.KinematicsPose", full_classname_dest, 57) == 0);
  }
  open_manipulator_msgs__msg__KinematicsPose * ros_message = _ros_message;
  {  // pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // max_accelerations_scaling_factor
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_accelerations_scaling_factor");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_accelerations_scaling_factor = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max_velocity_scaling_factor
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_velocity_scaling_factor");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max_velocity_scaling_factor = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tolerance
    PyObject * field = PyObject_GetAttrString(_pymsg, "tolerance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tolerance = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * open_manipulator_msgs__msg__kinematics_pose__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of KinematicsPose */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("open_manipulator_msgs.msg._kinematics_pose");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "KinematicsPose");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  open_manipulator_msgs__msg__KinematicsPose * ros_message = (open_manipulator_msgs__msg__KinematicsPose *)raw_ros_message;
  {  // pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_accelerations_scaling_factor
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_accelerations_scaling_factor);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_accelerations_scaling_factor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_velocity_scaling_factor
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max_velocity_scaling_factor);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_velocity_scaling_factor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tolerance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tolerance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tolerance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
