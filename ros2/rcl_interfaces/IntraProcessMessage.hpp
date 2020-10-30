#ifndef _RCL_INTERFACES_INTRAPROCESSMESSAGE_H_
#define _RCL_INTERFACES_INTRAPROCESSMESSAGE_H_

#include "../topic.hpp"

// Manualy include list

namespace rcl_interfaces
{

class IntraProcessMessage: public ros2::Topic<IntraProcessMessage>
{
public:
    uint64_t publisher_id;
    uint64_t message_sequence;

    IntraProcessMessage()
        : Topic("rcl_interfaces::msg::dds_::IntraProcessMessage_", "IntraProcessMessage", RCL_INTERFACES_INTRAPROCESSMESSAGE_ID),
        publisher_id(0),
        message_sequence(0)
    {
    }

    bool serialize(void* msg_buf, const IntraProcessMessage* topic)
    {
        ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
        (void) ucdr_serialize_uint64_t(writer, topic->publisher_id);
        (void) ucdr_serialize_uint64_t(writer, topic->message_sequence);

        return !writer->error;
    }

    bool deserialize(void* msg_buf, IntraProcessMessage* topic)
    {
        ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
        (void) ucdr_deserialize_uint64_t(reader, &topic->publisher_id);
        (void) ucdr_deserialize_uint64_t(reader, &topic->message_sequence);

        return !reader->error;
    }

    uint32_t size_of_topic(const IntraProcessMessage* topic, uint32_t size)
    {
        (void) (topic);

        uint32_t previousSize = size;
        size += ucdr_alignment(size, 8) + 8;
        size += ucdr_alignment(size, 8) + 8;

        return size - previousSize;
    }

};

} // namespace rcl_interfaces

#endif // _RCL_INTERFACES_INTRAPROCESSMESSAGE_H_