// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from map_msgs:srv/GetPointMapROI.idl
// generated code does not contain a copyright notice

#ifndef MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__FUNCTIONS_H_
#define MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "map_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "map_msgs/srv/detail/get_point_map_roi__struct.h"

/// Initialize srv/GetPointMapROI message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * map_msgs__srv__GetPointMapROI_Request
 * )) before or use
 * map_msgs__srv__GetPointMapROI_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Request__init(map_msgs__srv__GetPointMapROI_Request * msg);

/// Finalize srv/GetPointMapROI message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__srv__GetPointMapROI_Request__fini(map_msgs__srv__GetPointMapROI_Request * msg);

/// Create srv/GetPointMapROI message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * map_msgs__srv__GetPointMapROI_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
map_msgs__srv__GetPointMapROI_Request *
map_msgs__srv__GetPointMapROI_Request__create();

/// Destroy srv/GetPointMapROI message.
/**
 * It calls
 * map_msgs__srv__GetPointMapROI_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__srv__GetPointMapROI_Request__destroy(map_msgs__srv__GetPointMapROI_Request * msg);

/// Check for srv/GetPointMapROI message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Request__are_equal(const map_msgs__srv__GetPointMapROI_Request * lhs, const map_msgs__srv__GetPointMapROI_Request * rhs);

/// Copy a srv/GetPointMapROI message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Request__copy(
  const map_msgs__srv__GetPointMapROI_Request * input,
  map_msgs__srv__GetPointMapROI_Request * output);

/// Initialize array of srv/GetPointMapROI messages.
/**
 * It allocates the memory for the number of elements and calls
 * map_msgs__srv__GetPointMapROI_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Request__Sequence__init(map_msgs__srv__GetPointMapROI_Request__Sequence * array, size_t size);

/// Finalize array of srv/GetPointMapROI messages.
/**
 * It calls
 * map_msgs__srv__GetPointMapROI_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__srv__GetPointMapROI_Request__Sequence__fini(map_msgs__srv__GetPointMapROI_Request__Sequence * array);

/// Create array of srv/GetPointMapROI messages.
/**
 * It allocates the memory for the array and calls
 * map_msgs__srv__GetPointMapROI_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
map_msgs__srv__GetPointMapROI_Request__Sequence *
map_msgs__srv__GetPointMapROI_Request__Sequence__create(size_t size);

/// Destroy array of srv/GetPointMapROI messages.
/**
 * It calls
 * map_msgs__srv__GetPointMapROI_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__srv__GetPointMapROI_Request__Sequence__destroy(map_msgs__srv__GetPointMapROI_Request__Sequence * array);

/// Check for srv/GetPointMapROI message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Request__Sequence__are_equal(const map_msgs__srv__GetPointMapROI_Request__Sequence * lhs, const map_msgs__srv__GetPointMapROI_Request__Sequence * rhs);

/// Copy an array of srv/GetPointMapROI messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Request__Sequence__copy(
  const map_msgs__srv__GetPointMapROI_Request__Sequence * input,
  map_msgs__srv__GetPointMapROI_Request__Sequence * output);

/// Initialize srv/GetPointMapROI message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * map_msgs__srv__GetPointMapROI_Response
 * )) before or use
 * map_msgs__srv__GetPointMapROI_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Response__init(map_msgs__srv__GetPointMapROI_Response * msg);

/// Finalize srv/GetPointMapROI message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__srv__GetPointMapROI_Response__fini(map_msgs__srv__GetPointMapROI_Response * msg);

/// Create srv/GetPointMapROI message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * map_msgs__srv__GetPointMapROI_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
map_msgs__srv__GetPointMapROI_Response *
map_msgs__srv__GetPointMapROI_Response__create();

/// Destroy srv/GetPointMapROI message.
/**
 * It calls
 * map_msgs__srv__GetPointMapROI_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__srv__GetPointMapROI_Response__destroy(map_msgs__srv__GetPointMapROI_Response * msg);

/// Check for srv/GetPointMapROI message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Response__are_equal(const map_msgs__srv__GetPointMapROI_Response * lhs, const map_msgs__srv__GetPointMapROI_Response * rhs);

/// Copy a srv/GetPointMapROI message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Response__copy(
  const map_msgs__srv__GetPointMapROI_Response * input,
  map_msgs__srv__GetPointMapROI_Response * output);

/// Initialize array of srv/GetPointMapROI messages.
/**
 * It allocates the memory for the number of elements and calls
 * map_msgs__srv__GetPointMapROI_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Response__Sequence__init(map_msgs__srv__GetPointMapROI_Response__Sequence * array, size_t size);

/// Finalize array of srv/GetPointMapROI messages.
/**
 * It calls
 * map_msgs__srv__GetPointMapROI_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__srv__GetPointMapROI_Response__Sequence__fini(map_msgs__srv__GetPointMapROI_Response__Sequence * array);

/// Create array of srv/GetPointMapROI messages.
/**
 * It allocates the memory for the array and calls
 * map_msgs__srv__GetPointMapROI_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
map_msgs__srv__GetPointMapROI_Response__Sequence *
map_msgs__srv__GetPointMapROI_Response__Sequence__create(size_t size);

/// Destroy array of srv/GetPointMapROI messages.
/**
 * It calls
 * map_msgs__srv__GetPointMapROI_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
void
map_msgs__srv__GetPointMapROI_Response__Sequence__destroy(map_msgs__srv__GetPointMapROI_Response__Sequence * array);

/// Check for srv/GetPointMapROI message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Response__Sequence__are_equal(const map_msgs__srv__GetPointMapROI_Response__Sequence * lhs, const map_msgs__srv__GetPointMapROI_Response__Sequence * rhs);

/// Copy an array of srv/GetPointMapROI messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_map_msgs
bool
map_msgs__srv__GetPointMapROI_Response__Sequence__copy(
  const map_msgs__srv__GetPointMapROI_Response__Sequence * input,
  map_msgs__srv__GetPointMapROI_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MAP_MSGS__SRV__DETAIL__GET_POINT_MAP_ROI__FUNCTIONS_H_
