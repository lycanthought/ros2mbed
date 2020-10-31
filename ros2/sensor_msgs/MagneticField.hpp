// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


/*! 
 * @file MagneticField.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */
#ifndef _SENSOR_MSGS_MAGNETIC_FIELD_HPP_
#define _SENSOR_MSGS_MAGNETIC_FIELD_HPP_


#include "../topic.hpp"

#include "../std_msgs/Header.hpp"
#include "../geometry_msgs/Vector3.hpp"

namespace sensor_msgs {


class MagneticField : public ros2::Topic<MagneticField>
{
public: 
    using SharedPtr = std::shared_ptr<MagneticField>;
    
    std_msgs::Header header;
    geometry_msgs::Vector3 magnetic_field;
    double magnetic_field_covariance[9];

  MagneticField():
    Topic("sensor_msgs::msg::dds_::MagneticField_", "MagneticField", SENSOR_MSGS_MAGNETIC_FIELD_ID),
    header(), magnetic_field()
  { 
    memset(magnetic_field_covariance, 0, sizeof(magnetic_field_covariance));
  }

  bool serialize(void* msg_buf, MagneticField* topic)
  {
    ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
    (void) header.serialize(writer, &topic->header);
    (void) magnetic_field.serialize(writer, &topic->magnetic_field);
    (void) ucdr_serialize_array_double(writer, topic->magnetic_field_covariance, 9);

    return !writer->error;
  }

  bool deserialize(void* msg_buf, MagneticField* topic)
  {
    ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
    (void) header.deserialize(reader, &topic->header);
    (void) magnetic_field.deserialize(reader, &topic->magnetic_field);
    (void) ucdr_deserialize_array_double(reader, topic->magnetic_field_covariance, 9);

    return !reader->error;
  }

  virtual uint32_t size_of_topic(const MagneticField* topic, uint32_t size)
  {
    uint32_t previousSize = size;
    size += header.size_of_topic(&topic->header, size);
    size += magnetic_field.size_of_topic(&topic->magnetic_field, size);
    size += ucdr_alignment(size, 8) + ((9) * 8);

    return size - previousSize;
  }

};

} // namespace sensor_msgs


#endif // _SENSOR_MSGS_MAGNETIC_FIELD_HPP_
