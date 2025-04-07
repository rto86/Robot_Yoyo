#include <LedControl.h>

// Inicializamos el objeto LedControl con los pines: DIN = 12, CLK = 10, CS = 11
LedControl lc = LedControl(12, 10, 11, 1);

// Definición de las caras y figuras
byte happyface[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100
};

byte sadface[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100
};

byte angryface[8] = {
    B11100111,
    B00000000,
    B11100111,
    B00100100,
    B00000000,
    B00111100,
    B01000010,
    B10000001
};

byte surprisedface[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01011010,
    B00100100
};

byte neutralface[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10000001,
    B10111101,
    B01000010,
    B00111100
};

byte heart[8] = {
    B01100110,
    B11111111,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000,
    B00000000
};

byte sadheart[8] = {
    B01100110,
    B11101111,
    B11110111,
    B11101111,
    B01011110,
    B00101100,
    B00010000,
    B00000000
};

byte Iloveyou[8] = {
    B11100000,
    B01011011,
    B01011111,
    B11101110,
    B00000100,
    B10100000,
    B01000101,
    B01010111
};

// Pines de los botones
const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

// Asociamos cada botón a una cara
byte *faces[8] = {happyface, sadface, angryface, surprisedface, neutralface, heart, sadheart, Iloveyou};

void setup() {
    // Configurar pines de los botones como entrada
    for (int i = 0; i < 8; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }

    lc.shutdown(0, false);       // Desactiva el modo de apagado del display
    lc.setIntensity(0, 8);       // Ajusta el brillo a nivel 8 (0 mínimo, 15 máximo)
    lc.clearDisplay(0);          // Limpia el display
}

void displayFace(byte face[8]) {
    for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, face[i]); // Configura cada fila con el patrón correspondiente
    }
}

void loop() {
    for (int i = 0; i < 8; i++) {
        // Verificar si se ha presionado un botón (LOW = presionado)
        if (digitalRead(buttonPins[i]) == LOW) {
            displayFace(faces[i]); // Mostrar la cara correspondiente
            delay(100);           // Pequeña pausa para evitar rebotes
        }
    }
}
