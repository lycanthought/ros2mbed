#ifndef _RCL_INTERFACES_PARAMETERVALUE_H_
#define _RCL_INTERFACES_PARAMETERVALUE_H_

#include "../topic.hpp"

// Manualy include list

namespace rcl_interfaces
{

class ParameterValue: public ros2::Topic<ParameterValue>
{
public:
    using SharedPtr = std::shared_ptr<ParameterValue>;

    uint8_t type;
    bool bool_value;
    int64_t integer_value;
    double double_value;
    std::string string_value;
    std::vector<uint8_t> byte_array_value;
    //std::vector<bool> bool_array_value;
    std::vector<uint8_t> bool_array_value;
    std::vector<int64_t> integer_array_value;
    std::vector<double> double_array_value;
    std::vector<std::string> string_array_value;

    ParameterValue()
        : Topic("rcl_interfaces::msg::dds_::ParameterValue_", "ParameterValue", RCL_INTERFACES_PARAMETERVALUE_ID),
        type(0),
        bool_value(false),
        integer_value(0),
        double_value(0)
    {
    }

    bool serialize(void* msg_buf, ParameterValue* topic)
    {
        ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
        (void) ucdr_serialize_uint8_t(writer, topic->type);
        (void) ucdr_serialize_bool(writer, topic->bool_value);
        (void) ucdr_serialize_int64_t(writer, topic->integer_value);
        (void) ucdr_serialize_double(writer, topic->double_value);
        (void) ucdr_serialize_string(writer, topic->string_value);
        (void) ucdr_serialize_vec_uint8_t(writer, topic->byte_array_value);
        (void) ucdr_serialize_vec_uint8_t(writer, topic->bool_array_value);
        (void) ucdr_serialize_vec_int64_t(writer, topic->integer_array_value);
        (void) ucdr_serialize_vec_double(writer, topic->double_array_value);
        
        // Todo:
        //(void) ucdr_serialize_vec_string(writer, topic->string_array_value);

        return !writer->error;
    }

    bool deserialize(void* msg_buf, ParameterValue* topic)
    {
        ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
        (void) ucdr_deserialize_uint8_t(reader, &topic->type);
        (void) ucdr_deserialize_bool(reader, &topic->bool_value);
        (void) ucdr_deserialize_int64_t(reader, &topic->integer_value);
        (void) ucdr_deserialize_double(reader, &topic->double_value);
        (void) ucdr_deserialize_string(reader, topic->string_value);
        (void) ucdr_deserialize_vec_uint8_t(reader, topic->byte_array_value);
        (void) ucdr_deserialize_vec_uint8_t(reader, topic->bool_array_value);
        (void) ucdr_deserialize_vec_int64_t(reader, topic->integer_array_value);
        (void) ucdr_deserialize_vec_double(reader, topic->double_array_value);
        (void) ucdr_deserialize_vec_string(reader, topic->string_array_value);

        return !reader->error;
    }

    uint32_t size_of_topic(const ParameterValue* topic, uint32_t size)
    {
        (void) (topic);

        uint32_t previousSize = size;
        size += ucdr_alignment(size, 1) + 1;
        size += ucdr_alignment(size, 1) + 1;
        size += ucdr_alignment(size, 8) + 8;
        size += ucdr_alignment(size, 8) + 8;
        size += ucdr_alignment(size, 4) + 4 + (uint32_t)(topic->string_value.length() + 1);
        size += ucdr_alignment(size, 4) + 4;
        size += ucdr_alignment(size, 1) + (topic->byte_array_value.size() * 1);
        size += ucdr_alignment(size, 4) + 4;
        size += ucdr_alignment(size, 1) + (topic->bool_array_value.size() * 1);
        size += ucdr_alignment(size, 4) + 4;
        size += ucdr_alignment(size, 8) + (topic->integer_array_value.size() * 8);
        size += ucdr_alignment(size, 4) + 4;
        size += ucdr_alignment(size, 8) + (topic->double_array_value.size() * 8);
        size += ucdr_alignment(size, 4) + 4;
        for(size_t i = 0; i < topic->string_array_value.size(); i++)
        {
            //size += ucdr_alignment(size, 4) + 4 + (uint32_t)(topic->string_array_value[i].length());
        }

        return size - previousSize;
    }

};

} // namespace rcl_interfaces

#endif // _RCL_INTERFACES_PARAMETERVALUE_H_