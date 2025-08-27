# generated from rosidl_generator_py/resource/_idl.py.em
# with input from open_manipulator_msgs:msg/JointPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'position'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_JointPosition(type):
    """Metaclass of message 'JointPosition'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('open_manipulator_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'open_manipulator_msgs.msg.JointPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__joint_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__joint_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__joint_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__joint_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__joint_position

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class JointPosition(metaclass=Metaclass_JointPosition):
    """Message class 'JointPosition'."""

    __slots__ = [
        '_joint_name',
        '_position',
        '_max_accelerations_scaling_factor',
        '_max_velocity_scaling_factor',
    ]

    _fields_and_field_types = {
        'joint_name': 'sequence<string>',
        'position': 'sequence<double>',
        'max_accelerations_scaling_factor': 'double',
        'max_velocity_scaling_factor': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.joint_name = kwargs.get('joint_name', [])
        self.position = array.array('d', kwargs.get('position', []))
        self.max_accelerations_scaling_factor = kwargs.get('max_accelerations_scaling_factor', float())
        self.max_velocity_scaling_factor = kwargs.get('max_velocity_scaling_factor', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.joint_name != other.joint_name:
            return False
        if self.position != other.position:
            return False
        if self.max_accelerations_scaling_factor != other.max_accelerations_scaling_factor:
            return False
        if self.max_velocity_scaling_factor != other.max_velocity_scaling_factor:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def joint_name(self):
        """Message field 'joint_name'."""
        return self._joint_name

    @joint_name.setter
    def joint_name(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'joint_name' field must be a set or sequence and each value of type 'str'"
        self._joint_name = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'position' array.array() must have the type code of 'd'"
            self._position = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'position' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._position = array.array('d', value)

    @builtins.property
    def max_accelerations_scaling_factor(self):
        """Message field 'max_accelerations_scaling_factor'."""
        return self._max_accelerations_scaling_factor

    @max_accelerations_scaling_factor.setter
    def max_accelerations_scaling_factor(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_accelerations_scaling_factor' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_accelerations_scaling_factor' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_accelerations_scaling_factor = value

    @builtins.property
    def max_velocity_scaling_factor(self):
        """Message field 'max_velocity_scaling_factor'."""
        return self._max_velocity_scaling_factor

    @max_velocity_scaling_factor.setter
    def max_velocity_scaling_factor(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_velocity_scaling_factor' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_velocity_scaling_factor' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_velocity_scaling_factor = value
