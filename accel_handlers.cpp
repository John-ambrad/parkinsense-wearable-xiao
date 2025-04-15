#include "accel_handlers.h"

LSM6DS3 myIMU(I2C_MODE, I2C_ADDR);

float accel_X_float(){
  return myIMU.readFloatAccelX();

}

float accel_Y_float(){
  return myIMU.readFloatAccelY();


}

float accel_Z_float(){
  return myIMU.readFloatAccelZ();



}

float gyro_X_float(){
  return myIMU.readFloatGyroX();

}
float gyro_Y_float(){
  return myIMU.readFloatGyroY();


}
float gyro_Z_float(){
  return myIMU.readFloatGyroZ();


}