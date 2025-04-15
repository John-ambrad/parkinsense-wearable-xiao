#include "ble_handlers.h"
#include "accel_handlers.h"

LSM6DS3 devIMU(I2C_MODE, I2C_ADDR);

BLEService accel_service(ACCEL_SERVICE);
BLECharacteristic accel_char_x(ACCEL_CHARACTERISTIC_X);
BLECharacteristic accel_char_y(ACCEL_CHARACTERISTIC_Y);
BLECharacteristic accel_char_z(ACCEL_CHARACTERISTIC_Z);

void send_accel_data(LSM6DS3 &devIMU);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  ble_configure();
  accel_service.begin();

  ble_setup_char(accel_char_x);
  ble_setup_char(accel_char_y);
  ble_setup_char(accel_char_z);

  ble_start_adv(accel_service);

  if (devIMU.begin() != 0) {
      Serial.println("Device error");
  } else {
      Serial.println("Device OK!");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  // ble_send_data(accel_char_x);
  send_accel_data(devIMU,accel_char_x,accel_char_y,accel_char_z);

}


void send_accel_data(LSM6DS3 &devIMU, BLECharacteristic &accel_X_char,BLECharacteristic &accel_Y_char,BLECharacteristic &accel_Z_char){
  float accel_x;
  float accel_y;
  float accel_z;
  accel_x = devIMU.readFloatAccelX();
  accel_y = devIMU.readFloatAccelY();
  accel_z = devIMU.readFloatAccelZ();

  uint8_t buffer_x[sizeof(float)];
  uint8_t buffer_y[sizeof(float)];
  uint8_t buffer_z[sizeof(float)];

  memcpy(buffer_x, &accel_x,sizeof(float));
  memcpy(buffer_y, &accel_x,sizeof(float));
  memcpy(buffer_z, &accel_x,sizeof(float));


  accel_X_char.notify(buffer_x,sizeof(float));
  accel_Y_char.notify(buffer_y,sizeof(float));
  accel_Z_char.notify(buffer_z,sizeof(float));

  //Serial.println(accel_x);
  //Serial.println(accel_y);





}