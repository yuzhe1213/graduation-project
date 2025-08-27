// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from open_manipulator_msgs:srv/SetKinematicsPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "open_manipulator_msgs/srv/detail/set_kinematics_pose__rosidl_typesupport_introspection_c.h"
#include "open_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "open_manipulator_msgs/srv/detail/set_kinematics_pose__functions.h"
#include "open_manipulator_msgs/srv/detail/set_kinematics_pose__struct.h"


// Include directives for member types
// Member `planning_group`
// Member `end_effector_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `kinematics_pose`
#include "open_manipulator_msgs/msg/kinematics_pose.h"
// Member `kinematics_pose`
#include "open_manipulator_msgs/msg/detail/kinematics_pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  open_manipulator_msgs__srv__SetKinematicsPose_Request__init(message_memory);
}

void open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_fini_function(void * message_memory)
{
  open_manipulator_msgs__srv__SetKinematicsPose_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_member_array[4] = {
  {
    "planning_group",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetKinematicsPose_Request, planning_group),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "end_effector_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetKinematicsPose_Request, end_effector_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kinematics_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetKinematicsPose_Request, kinematics_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetKinematicsPose_Request, path_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_members = {
  "open_manipulator_msgs__srv",  // message namespace
  "SetKinematicsPose_Request",  // message name
  4,  // number of fields
  sizeof(open_manipulator_msgs__srv__SetKinematicsPose_Request),
  open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_member_array,  // message members
  open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_type_support_handle = {
  0,
  &open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_open_manipulator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetKinematicsPose_Request)() {
  open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, msg, KinematicsPose)();
  if (!open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_type_support_handle.typesupport_identifier) {
    open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &open_manipulator_msgs__srv__SetKinematicsPose_Request__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "open_manipulator_msgs/srv/detail/set_kinematics_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "open_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "open_manipulator_msgs/srv/detail/set_kinematics_pose__functions.h"
// already included above
// #include "open_manipulator_msgs/srv/detail/set_kinematics_pose__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  open_manipulator_msgs__srv__SetKinematicsPose_Response__init(message_memory);
}

void open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_fini_function(void * message_memory)
{
  open_manipulator_msgs__srv__SetKinematicsPose_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_member_array[1] = {
  {
    "is_planned",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(open_manipulator_msgs__srv__SetKinematicsPose_Response, is_planned),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_members = {
  "open_manipulator_msgs__srv",  // message namespace
  "SetKinematicsPose_Response",  // message name
  1,  // number of fields
  sizeof(open_manipulator_msgs__srv__SetKinematicsPose_Response),
  open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_member_array,  // message members
  open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_type_support_handle = {
  0,
  &open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_open_manipulator_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetKinematicsPose_Response)() {
  if (!open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_type_support_handle.typesupport_identifier) {
    open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &open_manipulator_msgs__srv__SetKinematicsPose_Response__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "open_manipulator_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "open_manipulator_msgs/srv/detail/set_kinematics_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_service_members = {
  "open_manipulator_msgs__srv",  // service namespace
  "SetKinematicsPose",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_Request_message_type_support_handle,
  NULL  // response message
  // open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_Response_message_type_support_handle
};

static rosidl_service_type_support_t open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_service_type_support_handle = {
  0,
  &open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetKinematicsPose_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetKinematicsPose_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_open_manipulator_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetKinematicsPose)() {
  if (!open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_service_type_support_handle.typesupport_identifier) {
    open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetKinematicsPose_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, open_manipulator_msgs, srv, SetKinematicsPose_Response)()->data;
  }

  return &open_manipulator_msgs__srv__detail__set_kinematics_pose__rosidl_typesupport_introspection_c__SetKinematicsPose_service_type_support_handle;
}
