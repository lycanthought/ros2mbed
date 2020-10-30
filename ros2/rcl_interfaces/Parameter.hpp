#ifndef _RCL_INTERFACES_PARAMETER_H_
#define _RCL_INTERFACES_PARAMETER_H_

#include "../topic.hpp"

// Manualy include list
// rcl_interfaces::ParameterValue
// suggest
#include "rcl_interfaces/ParameterValue.hpp"

namespace rcl_interfaces
{

class Parameter: public ros2::Topic<Parameter>
{
public:
    std::string name;
    rcl_interfaces::ParameterValue value;

    Parameter()
        : Topic("rcl_interfaces::msg::dds_::Parameter_", "Parameter", RCL_INTERFACES_PARAMETER_ID)
    {
    }

    bool serialize(void* msg_buf, const Parameter* topic)
    {
        ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
        (void) ucdr_serialize_string(writer, topic->name.data());
        (void) value.serialize(writer, &topic->value);

        return !writer->error;
    }

    bool deserialize(void* msg_buf, Parameter* topic)
    {
        ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
        (void) ucdr_deserialize_string(reader, topic->name.data(), topic->name.capacity());
        (void) value.deserialize(reader, &topic->value);

        return !reader->error;
    }

    uint32_t size_of_topic(const Parameter* topic, uint32_t size)
    {
        (void) (topic);

        uint32_t previousSize = size;
        size += ucdr_alignment(size, 4) + 4 + (uint32_t)(topic->name.length() + 1);
        size += value.size_of_topic(&topic->value, size);

        return size - previousSize;
    }

};

} // namespace rcl_interfaces

#endif // _RCL_INTERFACES_PARAMETER_H_