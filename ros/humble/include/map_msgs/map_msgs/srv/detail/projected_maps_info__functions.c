// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_msgs:srv/ProjectedMapsInfo.idl
// generated code does not contain a copyright notice
#include "map_msgs/srv/detail/projected_maps_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `projected_maps_info`
#include "map_msgs/msg/detail/projected_map_info__functions.h"

bool
map_msgs__srv__ProjectedMapsInfo_Request__init(map_msgs__srv__ProjectedMapsInfo_Request * msg)
{
  if (!msg) {
    return false;
  }
  // projected_maps_info
  if (!map_msgs__msg__ProjectedMapInfo__Sequence__init(&msg->projected_maps_info, 0)) {
    map_msgs__srv__ProjectedMapsInfo_Request__fini(msg);
    return false;
  }
  return true;
}

void
map_msgs__srv__ProjectedMapsInfo_Request__fini(map_msgs__srv__ProjectedMapsInfo_Request * msg)
{
  if (!msg) {
    return;
  }
  // projected_maps_info
  map_msgs__msg__ProjectedMapInfo__Sequence__fini(&msg->projected_maps_info);
}

bool
map_msgs__srv__ProjectedMapsInfo_Request__are_equal(const map_msgs__srv__ProjectedMapsInfo_Request * lhs, const map_msgs__srv__ProjectedMapsInfo_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // projected_maps_info
  if (!map_msgs__msg__ProjectedMapInfo__Sequence__are_equal(
      &(lhs->projected_maps_info), &(rhs->projected_maps_info)))
  {
    return false;
  }
  return true;
}

bool
map_msgs__srv__ProjectedMapsInfo_Request__copy(
  const map_msgs__srv__ProjectedMapsInfo_Request * input,
  map_msgs__srv__ProjectedMapsInfo_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // projected_maps_info
  if (!map_msgs__msg__ProjectedMapInfo__Sequence__copy(
      &(input->projected_maps_info), &(output->projected_maps_info)))
  {
    return false;
  }
  return true;
}

map_msgs__srv__ProjectedMapsInfo_Request *
map_msgs__srv__ProjectedMapsInfo_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__ProjectedMapsInfo_Request * msg = (map_msgs__srv__ProjectedMapsInfo_Request *)allocator.allocate(sizeof(map_msgs__srv__ProjectedMapsInfo_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__srv__ProjectedMapsInfo_Request));
  bool success = map_msgs__srv__ProjectedMapsInfo_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__srv__ProjectedMapsInfo_Request__destroy(map_msgs__srv__ProjectedMapsInfo_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__srv__ProjectedMapsInfo_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__srv__ProjectedMapsInfo_Request__Sequence__init(map_msgs__srv__ProjectedMapsInfo_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__ProjectedMapsInfo_Request * data = NULL;

  if (size) {
    data = (map_msgs__srv__ProjectedMapsInfo_Request *)allocator.zero_allocate(size, sizeof(map_msgs__srv__ProjectedMapsInfo_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__srv__ProjectedMapsInfo_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__srv__ProjectedMapsInfo_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
map_msgs__srv__ProjectedMapsInfo_Request__Sequence__fini(map_msgs__srv__ProjectedMapsInfo_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      map_msgs__srv__ProjectedMapsInfo_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

map_msgs__srv__ProjectedMapsInfo_Request__Sequence *
map_msgs__srv__ProjectedMapsInfo_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__ProjectedMapsInfo_Request__Sequence * array = (map_msgs__srv__ProjectedMapsInfo_Request__Sequence *)allocator.allocate(sizeof(map_msgs__srv__ProjectedMapsInfo_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__srv__ProjectedMapsInfo_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__srv__ProjectedMapsInfo_Request__Sequence__destroy(map_msgs__srv__ProjectedMapsInfo_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__srv__ProjectedMapsInfo_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__srv__ProjectedMapsInfo_Request__Sequence__are_equal(const map_msgs__srv__ProjectedMapsInfo_Request__Sequence * lhs, const map_msgs__srv__ProjectedMapsInfo_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__srv__ProjectedMapsInfo_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__srv__ProjectedMapsInfo_Request__Sequence__copy(
  const map_msgs__srv__ProjectedMapsInfo_Request__Sequence * input,
  map_msgs__srv__ProjectedMapsInfo_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(map_msgs__srv__ProjectedMapsInfo_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__srv__ProjectedMapsInfo_Request * data =
      (map_msgs__srv__ProjectedMapsInfo_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__srv__ProjectedMapsInfo_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__srv__ProjectedMapsInfo_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__srv__ProjectedMapsInfo_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
map_msgs__srv__ProjectedMapsInfo_Response__init(map_msgs__srv__ProjectedMapsInfo_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
map_msgs__srv__ProjectedMapsInfo_Response__fini(map_msgs__srv__ProjectedMapsInfo_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
map_msgs__srv__ProjectedMapsInfo_Response__are_equal(const map_msgs__srv__ProjectedMapsInfo_Response * lhs, const map_msgs__srv__ProjectedMapsInfo_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
map_msgs__srv__ProjectedMapsInfo_Response__copy(
  const map_msgs__srv__ProjectedMapsInfo_Response * input,
  map_msgs__srv__ProjectedMapsInfo_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

map_msgs__srv__ProjectedMapsInfo_Response *
map_msgs__srv__ProjectedMapsInfo_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__ProjectedMapsInfo_Response * msg = (map_msgs__srv__ProjectedMapsInfo_Response *)allocator.allocate(sizeof(map_msgs__srv__ProjectedMapsInfo_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_msgs__srv__ProjectedMapsInfo_Response));
  bool success = map_msgs__srv__ProjectedMapsInfo_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_msgs__srv__ProjectedMapsInfo_Response__destroy(map_msgs__srv__ProjectedMapsInfo_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_msgs__srv__ProjectedMapsInfo_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_msgs__srv__ProjectedMapsInfo_Response__Sequence__init(map_msgs__srv__ProjectedMapsInfo_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__ProjectedMapsInfo_Response * data = NULL;

  if (size) {
    data = (map_msgs__srv__ProjectedMapsInfo_Response *)allocator.zero_allocate(size, sizeof(map_msgs__srv__ProjectedMapsInfo_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_msgs__srv__ProjectedMapsInfo_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_msgs__srv__ProjectedMapsInfo_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
map_msgs__srv__ProjectedMapsInfo_Response__Sequence__fini(map_msgs__srv__ProjectedMapsInfo_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      map_msgs__srv__ProjectedMapsInfo_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

map_msgs__srv__ProjectedMapsInfo_Response__Sequence *
map_msgs__srv__ProjectedMapsInfo_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_msgs__srv__ProjectedMapsInfo_Response__Sequence * array = (map_msgs__srv__ProjectedMapsInfo_Response__Sequence *)allocator.allocate(sizeof(map_msgs__srv__ProjectedMapsInfo_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_msgs__srv__ProjectedMapsInfo_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_msgs__srv__ProjectedMapsInfo_Response__Sequence__destroy(map_msgs__srv__ProjectedMapsInfo_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_msgs__srv__ProjectedMapsInfo_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_msgs__srv__ProjectedMapsInfo_Response__Sequence__are_equal(const map_msgs__srv__ProjectedMapsInfo_Response__Sequence * lhs, const map_msgs__srv__ProjectedMapsInfo_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_msgs__srv__ProjectedMapsInfo_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_msgs__srv__ProjectedMapsInfo_Response__Sequence__copy(
  const map_msgs__srv__ProjectedMapsInfo_Response__Sequence * input,
  map_msgs__srv__ProjectedMapsInfo_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(map_msgs__srv__ProjectedMapsInfo_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_msgs__srv__ProjectedMapsInfo_Response * data =
      (map_msgs__srv__ProjectedMapsInfo_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_msgs__srv__ProjectedMapsInfo_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_msgs__srv__ProjectedMapsInfo_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_msgs__srv__ProjectedMapsInfo_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
