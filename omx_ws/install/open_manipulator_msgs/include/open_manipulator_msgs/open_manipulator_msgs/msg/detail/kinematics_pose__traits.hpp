// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from open_manipulator_msgs:msg/KinematicsPose.idl
// generated code does not contain a copyright notice

#ifndef OPEN_MANIPULATOR_MSGS__MSG__DETAIL__KINEMATICS_POSE__TRAITS_HPP_
#define OPEN_MANIPULATOR_MSGS__MSG__DETAIL__KINEMATICS_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "open_manipulator_msgs/msg/detail/kinematics_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace open_manipulator_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const KinematicsPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: max_accelerations_scaling_factor
  {
    out << "max_accelerations_scaling_factor: ";
    rosidl_generator_traits::value_to_yaml(msg.max_accelerations_scaling_factor, out);
    out << ", ";
  }

  // member: max_velocity_scaling_factor
  {
    out << "max_velocity_scaling_factor: ";
    rosidl_generator_traits::value_to_yaml(msg.max_velocity_scaling_factor, out);
    out << ", ";
  }

  // member: tolerance
  {
    out << "tolerance: ";
    rosidl_generator_traits::value_to_yaml(msg.tolerance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const KinematicsPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: max_accelerations_scaling_factor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_accelerations_scaling_factor: ";
    rosidl_generator_traits::value_to_yaml(msg.max_accelerations_scaling_factor, out);
    out << "\n";
  }

  // member: max_velocity_scaling_factor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_velocity_scaling_factor: ";
    rosidl_generator_traits::value_to_yaml(msg.max_velocity_scaling_factor, out);
    out << "\n";
  }

  // member: tolerance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tolerance: ";
    rosidl_generator_traits::value_to_yaml(msg.tolerance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const KinematicsPose & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace open_manipulator_msgs

namespace rosidl_generator_traits
{

[[deprecated("use open_manipulator_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const open_manipulator_msgs::msg::KinematicsPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  open_manipulator_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use open_manipulator_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const open_manipulator_msgs::msg::KinematicsPose & msg)
{
  return open_manipulator_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<open_manipulator_msgs::msg::KinematicsPose>()
{
  return "open_manipulator_msgs::msg::KinematicsPose";
}

template<>
inline const char * name<open_manipulator_msgs::msg::KinematicsPose>()
{
  return "open_manipulator_msgs/msg/KinematicsPose";
}

template<>
struct has_fixed_size<open_manipulator_msgs::msg::KinematicsPose>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<open_manipulator_msgs::msg::KinematicsPose>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<open_manipulator_msgs::msg::KinematicsPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OPEN_MANIPULATOR_MSGS__MSG__DETAIL__KINEMATICS_POSE__TRAITS_HPP_
