#ifndef TELEMETRY_CORE_H_
#define TELEMETRY_CORE_H_

#include "stddef.h"
#include "stdint.h"
#include "telemetry_utils.h"

#define INCOMING_BUFFER_SIZE 128
#define OUTGOING_BUFFER_SIZE 128
#define TOPIC_BUFFER_SIZE 64

void init_telemetry(TM_transport * t);

void publish(const char * topic, const char * msg);
void publish_u8(const char * topic, uint8_t msg);
void publish_u16(const char * topic, uint16_t msg);
void publish_u32(const char * topic, uint32_t msg);
void publish_i8(const char * topic, int8_t msg);
void publish_i16(const char * topic, int16_t msg);
void publish_i32(const char * topic, int32_t msg);
void publish_f32(const char * topic, float msg);

// subscribe a function to be called everytime a frame is received
// second argument is a data structure that you can implement to access your program data inside the function
void subscribe(void (*callback)(TM_state * s, TM_msg * m), TM_state * s);

void update_telemetry(float elapsedTime);

#endif
