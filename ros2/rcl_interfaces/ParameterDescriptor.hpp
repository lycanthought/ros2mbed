#ifndef _RCL_INTERFACES_PARAMETERDESCRIPTOR_H_
#define _RCL_INTERFACES_PARAMETERDESCRIPTOR_H_

#include "../topic.hpp"

// Manualy include list
// rcl_interfaces::FloatingPointRange
// suggest
#include "rcl_interfaces/FloatingPointRange.hpp"
// rcl_interfaces::IntegerRange
// suggest
#include "rcl_interfaces/IntegerRange.hpp"

namespace rcl_interfaces
{

class ParameterDescriptor: public ros2::Topic<ParameterDescriptor>
{
public:
    using SharedPtr = std::shared_ptr<ParameterDescriptor>;

    std::string name;
    uint8_t type;
    std::string description;
    std::string additional_constraints;
    bool read_only;
    std::vector<rcl_interfaces::FloatingPointRange> floating_point_range;
    std::vector<rcl_interfaces::IntegerRange> integer_range;

    ParameterDescriptor()
        : Topic("rcl_interfaces::msg::dds_::ParameterDescriptor_", "ParameterDescriptor", RCL_INTERFACES_PARAMETERDESCRIPTOR_ID),
        type(0),
        read_only(false)
    {
    }

    bool serialize(void* msg_buf, ParameterDescriptor* topic)
    {
        ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
        (void) ucdr_serialize_string(writer, topic->name.data());
        (void) ucdr_serialize_uint8_t(writer, topic->type);
        (void) ucdr_serialize_string(writer, topic->description.data());
        (void) ucdr_serialize_string(writer, topic->additional_constraints.data());
        (void) ucdr_serialize_bool(writer, topic->read_only);
        for(size_t i = 0; i < topic->floating_point_range.size(); i++)
        {
            (void) floating_point_range[i].serialize(writer, &topic->floating_point_range[i]);
        }
        for(size_t i = 0; i < topic->integer_range.size(); i++)
        {
            (void) integer_range[i].serialize(writer, &topic->integer_range[i]);
        }

        return !writer->error;
    }

    bool deserialize(void* msg_buf, ParameterDescriptor* topic)
    {
        ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
        (void) ucdr_deserialize_string(reader, topic->name.data(), topic->name.capacity());
        (void) ucdr_deserialize_uint8_t(reader, &topic->type);
        (void) ucdr_deserialize_string(reader, topic->description.data(), topic->description.capacity());
        (void) ucdr_deserialize_string(reader, topic->additional_constraints.data(), topic->additional_constraints.capacity());
        (void) ucdr_deserialize_bool(reader, &topic->read_only);
        for(size_t i = 0; i < topic->floating_point_range.size(); i++)
        {
            (void) floating_point_range[i].deserialize(reader, &topic->floating_point_range[i]);
        }
        for(size_t i = 0; i < topic->integer_range.size(); i++)
        {
            (void) integer_range[i].deserialize(reader, &topic->integer_range[i]);
        }

        return !reader->error;
    }

    uint32_t size_of_topic(const ParameterDescriptor* topic, uint32_t size)
    {
        (void) (topic);

        uint32_t previousSize = size;
        size += ucdr_alignment(size, 4) + 4 + (uint32_t)(topic->name.length() + 1);
        size += ucdr_alignment(size, 1) + 1;
        size += ucdr_alignment(size, 4) + 4 + (uint32_t)(topic->description.length() + 1);
        size += ucdr_alignment(size, 4) + 4 + (uint32_t)(topic->additional_constraints.length() + 1);
        size += ucdr_alignment(size, 1) + 1;
        for(size_t i = 0; i < topic->floating_point_range.size(); i++)
        {
            size += floating_point_range[i].size_of_topic(&topic->floating_point_range[i], size);
        }
        for(size_t i = 0; i < topic->integer_range.size(); i++)
        {
            size += integer_range[i].size_of_topic(&topic->integer_range[i], size);
        }

        return size - previousSize;
    }

};

} // namespace rcl_interfaces

#endif // _RCL_INTERFACES_PARAMETERDESCRIPTOR_H_
