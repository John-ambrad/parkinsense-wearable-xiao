#ifndef ACCEL_HANDLERS_H   /* Include guard */
#define ACCEL_HANDLERS_H

#include "LSM6DS3.h"
#include "Wire.h"
#define I2C_ADDR 0x6A

float accel_X_float();
float accel_Y_float();
float accel_Z_float();

float gyro_X_float();
float gyro_Y_float();
float gyro_Z_float();

#endif