#include <BleGamepad.h>

BleGamepad bleGamepad("ESP Gamepad", "Design By HamzaYslmn", 100);

// TRIGGER BUTTONS
#define LT 2
#define RT 23

// LEFT-JOYSTICK
#define LH 34
#define LV 35
#define LS 15

// RIGHT-JOYSTICK
#define RH 39
#define RV 36
#define RS 19

// D-PAD
#define L1 32
#define L2 33
#define L3 27
#define L4 14

#define R1 18
#define R2 5
#define R3 17
#define R4 16

int buttons[12] = {32, 33, 27, 14, 18, 5, 17, 16, 15, 23, 2, 19};

int period = 10000;
unsigned long time_now = 0;

const int numberOfPotSamples = 5;     
const int delayBetweenSamples = 2;    
const int delayBetweenHIDReports = 5; 
const int debounceDelay = 10;        

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 12; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  bleGamepad.begin();
  Serial.println("Starting BLE work!");

}

void loop() {
  if (bleGamepad.isConnected()) {

    //digitalWrite(led, HIGH);
    
    if (digitalRead(LT) == LOW) {
      Serial.println(F("Left Trigger"));
      bleGamepad.press(BUTTON_7);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.release(BUTTON_7);
      bleGamepad.sendReport();
    }
    if (digitalRead(RT) == LOW) {
      Serial.println(F("Right Trigger"));
      bleGamepad.press(BUTTON_8);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.release(BUTTON_8);
      bleGamepad.sendReport();
    }
    if (digitalRead(LS) == LOW) {
      Serial.println(F("Left Joystick"));
      bleGamepad.press(BUTTON_14);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.release(BUTTON_14);
      bleGamepad.sendReport();
    }
    if (digitalRead(RS) == LOW) {
      Serial.println(F("Right Joystick"));
      Serial.println("Right Joystick");
      bleGamepad.press(BUTTON_15);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.release(BUTTON_15);
      bleGamepad.sendReport();
    }

    if (digitalRead(R1) == LOW) {
      Serial.println(F("Right Button 1"));
      bleGamepad.press(BUTTON_5);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.release(BUTTON_5);
      bleGamepad.sendReport();
    }
    if (digitalRead(R2) == LOW) {
      Serial.println(F("Right Button 2"));
      bleGamepad.press(BUTTON_2);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.release(BUTTON_2);
      bleGamepad.sendReport();
    }
    if (digitalRead(R3) == LOW) {
      Serial.println(F("Right Button 3"));
      bleGamepad.press(BUTTON_1);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.release(BUTTON_1);
      bleGamepad.sendReport();
    }
    if (digitalRead(R4) == LOW) {
      Serial.println(F("Right Button 4"));
      bleGamepad.press(BUTTON_4);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.release(BUTTON_4);
      bleGamepad.sendReport();
    }

    if (digitalRead(L1) == LOW) {
      Serial.println(F("Left Button 1"));
      bleGamepad.setHat1(DPAD_UP);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.setHat1();
      bleGamepad.sendReport();
    }
    if (digitalRead(L2) == LOW) {
      Serial.println(F("Left Button 2"));
      bleGamepad.setHat1(DPAD_LEFT);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.setHat1();
      bleGamepad.sendReport();
    }
    if (digitalRead(L3) == LOW) {
      Serial.println(F("Left Button 3"));
      bleGamepad.setHat1(DPAD_DOWN);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.setHat1();
      bleGamepad.sendReport();
    }
    if (digitalRead(L4) == LOW) {
      Serial.println(F("Left Button 4"));
      bleGamepad.setHat1(DPAD_RIGHT);
      bleGamepad.sendReport();
      delay(debounceDelay);
      bleGamepad.setHat1();
      bleGamepad.sendReport();
    }
    
    int value1 = map(analogRead(LH), 0, 4095, 32737, -32737);
    int value2 = map(analogRead(LV), 0, 4095, 32737, -32737);
    bleGamepad.setLeftThumb(value1, value2);

    
    int value3 = map(analogRead(RH), 0, 4095, 0, 65475);
    int value4 = map(analogRead(RV), 0, 4095, 0, 65475);
    bleGamepad.setRightThumb(value3, value4);
    
    //Send the gamepad report
    bleGamepad.sendReport();
    delay(1);
  }
}