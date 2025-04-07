int CK1 = 4; // SHCP
int LP1 = 3; // STCP
int DP1 = 2; // DS

int CK2 = 7; // SHCP
int LP2 = 6; // STCP
int DP2 = 5; // DS

// Pines para los botones
const int buttonPins[] = {8, 9, 10, 11}; // Pines de los 4 botones
const int numButtons = 4; 

byte happyface[8] = {
    B00111100, B01000010, B10100101, B10000001, B10100101, B10011001, B01000010, B00111100
};
byte sadface[8] = {
    B00111100, B01000010, B10100101, B10000001, B10011001, B10100101, B01000010, B00111100
};
byte angryface[8] = {
    B11100111, B00000000, B11100111, B00100100, B00000000, B00111100, B01000010, B10000001
};
byte surprisedface[8] = {
    B00111100, B01000010, B10100101, B10000001, B10011001, B10100101, B01011010, B00100100
};

byte* faces[] = {happyface, sadface, angryface, surprisedface};//Hago una lista de las caras para cada botón

void setup() {
  // Configuración de pines para 74HC595
  pinMode(CK1, OUTPUT);
  pinMode(LP1, OUTPUT);
  pinMode(DP1, OUTPUT);
  pinMode(CK2, OUTPUT);
  pinMode(LP2, OUTPUT);
  pinMode(DP2, OUTPUT);

  // Configuración de pines para botones
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Usar resistencias pull-up internas
  }
}

void display(byte data[]) {
  for (int j = 0; j < 8; j++) {
    digitalWrite(LP2, LOW);
    digitalWrite(LP1, LOW);

    shiftOut(DP2, CK2, MSBFIRST, ~0x80 >> j);
    shiftOut(DP1, CK1, MSBFIRST, data[j]);
    delay(1);

    digitalWrite(LP2, HIGH);
    digitalWrite(LP1, HIGH);
  }
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // Detecta si el botón está presionado
      display(faces[i]); // Muestra la cara correspondiente al botón presionado
      delay(500); // Previene rebotes
    }
  }
}