//COMMAND FOR MY OWN CREATE & EDIT IS ===>>> 1ST STEP EDIT_1-NK
// This example code is in the Public Domain (or CC0 licensed, at your option.)
// By Evandro Copercini - 2018
//
// This example creates a bridge between Serial and Classical Bluetooth (SPP)
// and also demonstrate that SerialBT have the same functionalities of a normal Serial
// Note: Pairing is authenticated automatically by this device

#include "BluetoothSerial.h"

String device_name = "ESP32-BT-Slave";

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif7a

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
char Nandhu; //EDIT-Create-4-NK
void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);//EDIT-2-NK
  SerialBT.begin("Nandhu");//Bluetooth device name //1ST STEP EDIT_1-NK
  //SerialBT.deleteAllBondedDevices(); // Uncomment this to delete paired devices; Must be called after begin
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
}

void loop() {
 Nandhu = (char)/*EDIT-Create-5-NK */SerialBT.read(); //EDIT-Create-3-NK
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) { //EDIT-Create-6-NK(Up to 10 Lines)
    if(Nandhu=='1'){
     digitalWrite(2,HIGH);
     Serial.println("FAN ON");
     SerialBT.println("FAN ON");
    }
    if(Nandhu=='0'){
     digitalWrite(2,LOW);
     Serial.println("FAN OFF");
     SerialBT.println("FAN OFF");
    }
  }
  delay(20);
}
