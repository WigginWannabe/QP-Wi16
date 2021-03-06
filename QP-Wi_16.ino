const int latchPinT = 22;
const int clockPinT = 23;
const int dataPinT = 24;

const int latchPinB = 26;
const int clockPinB = 27;
const int dataPinB = 28;

int count = 10;

unsigned short colDataTop[10] = { 0x80, 0x80, 0x80, 0x80, 0x80,
                    0x80, 0x80, 0x80, 0x80, 0x80 };

// only LS nibble matters for bottom (at the moment)
unsigned short colDataBottom[10] = { 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00 };
unsigned short colDataShock[10] = { 0x8000, 0x8000, 0x8000, 0x8000, 0x8000,
                         0x8000, 0x8000, 0x8000, 0x8000, 0x8000 };
byte cols[10] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
byte joystickX = 26;
byte joystickY = 27;
byte joystickZ = 28;
byte vibration = 29;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);

  for( int i = 0; i < 10; i++) {
    pinMode(cols[i], OUTPUT);
    digitalWrite(cols[i], LOW);
  }

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 10; j++) {
      digitalWrite(cols[j], HIGH);

      digitalWrite(latchPinB, LOW);
      digitalWrite(latchPinT, LOW);
      shiftOut(dataPinB,clockPinB,LSBFIRST,colDataBottom[j]);
      shiftOut(dataPinT,clockPinT,LSBFIRST,colDataTop[j]);
      digitalWrite(latchPinB, HIGH);
      digitalWrite(latchPinT, HIGH);
      
      delay(75);
      digitalWrite(cols[j], LOW);
      
      if (i < 9) {
    	colDataTop[j] = colDataTop[j] >> 1;
      } else if (i = 9) {
      	colDataBottom[j] = 0x80;
      } else {
      	colDataBottom[j] = colDataBottom[j] >> 1;
      }
    }
  }


}

void loop() {
    for (int j = 0; j < 10; j++) {
      digitalWrite(cols[j], HIGH);

      digitalWrite(latchPinB, LOW);
      digitalWrite(latchPinT, LOW);
      shiftOut(dataPinB,clockPinB,LSBFIRST,colDataBottom[j]);
      shiftOut(dataPinT,clockPinT,LSBFIRST,colDataTop[j]);
      digitalWrite(latchPinB, HIGH);
      digitalWrite(latchPinT, HIGH);
      
      delay(3);
      digitalWrite(cols[j], LOW);
    }
  
//  if ( analogRead(joystickX) > 800) {
//    short temp = colData[9];
//    for (int k = 9; k > 0; k--) {
//      colData[k] = colData[k-1];
//    }
//    colData[0] = temp;
//  } else if ( analogRead(joystickX) < 300) {
//    short temp = colData[0];
//    for (int k = 0; k < 9; k++) {
//      colData[k] = colData[k+1];
//    }
//    colData[9] = temp;
//  }
//  if ( analogRead(joystickY) > 800) {
//    for (int k = 0; k < 9; k++) {
//      colData[k] = (colData[k] << 1) | ((colData[k]&0x8000) >> 15);
//    }
//  } else if ( analogRead(joystickY) < 300) {
//    for (int k = 0; k < 9; k++) {
//      colData[k] = (colData[k] >> 1) | ((colData[k]&0x8000) << 15);
//    }
//  }
//  if ( digitalRead(vibration) == HIGH) {
//    for (int l = 0; l < 15; l++) {
//      for (int j = 0; j < 10; j++) {
//        digitalWrite(cols[j], HIGH);
//    
//        digitalWrite(latchPin, LOW);
//        shiftOut(dataPin,clockPin,LSBFIRST,colData[j] | colDataShock[j]);
//        digitalWrite(latchPin, HIGH);
//    
//        delay(10);
//        digitalWrite(cols[j], LOW);
//      }
//    }
//  }
//  
//  for (int j = 0; j < 10; j++) {
//    digitalWrite(cols[j], HIGH);
//
//    digitalWrite(latchPin, LOW);
//    shiftOut(dataPin,clockPin,LSBFIRST,colData[j]);
//    digitalWrite(latchPin, HIGH);
//
//    delay(3);
//    digitalWrite(cols[j], LOW);
//  }
}
