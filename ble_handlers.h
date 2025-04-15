#ifndef BLE_HANDLERS_H   /* Include guard */
#define BLE_HANDLERS_H


#define  ACCEL_SERVICE "03f1781d-5c9c-43c3-9186-087b7cf4a7dc"
#define ACCEL_CHARACTERISTIC_X "75235997-bb4c-4057-8aa2-34358d658ee6"
#define ACCEL_CHARACTERISTIC_Y "7962f1c5-b206-4af0-a56c-f4bd9363c01e"
#define ACCEL_CHARACTERISTIC_Z "3060e742-ed88-434e-bfcb-0f11ca7b8293"

#include <bluefruit.h>
#include "Wire.h"
void ble_configure();
void ble_setup_char(BLECharacteristic &myChar);
void ble_start_adv(BLEService &myService);

void ble_send_data(BLECharacteristic &myChar);
void connect_callback(uint16_t conn_handle);
void disconnect_callback(uint16_t conn_handle, uint8_t reason);

  /* An example function declaration */

#endif // FOO_H_
