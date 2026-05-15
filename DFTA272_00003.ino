// =========================================
// Curve Tracer V2
// XIAO SAMD21
// Rampe DAC VCE
// 6 niveaux IB via MOSFET canal N
// =========================================

const int DAC_PIN = A0;

// 6 résistances de sélection IB
const int IB_PINS[6] = {1, 2, 3, 4, 5, 6};

// ---------------- PARAMETRES ----------------

const int dacPoints = 1023;

//const float rampFrequency = 300.0;
const float rampFrequency = 600.0;
// -------------------------------------------

void setup() {

  analogWriteResolution(10);

  // toutes les sorties à LOW au démarrage
  for (int i = 0; i < 6; i++) {
    pinMode(IB_PINS[i], OUTPUT);
    digitalWrite(IB_PINS[i], LOW);
  }

  analogWrite(DAC_PIN, 0);
}

void loop() {

  float rampPeriod_us = 1000000.0 / rampFrequency;
  float pointDelay = rampPeriod_us / dacPoints;

  for (int step = 0; step < 6; step++) {

    setIB(step);         
    sweepVCE(pointDelay);
    resetIB();           

  }
}

//--------------------------------------------

void sweepVCE(float pointDelay) {

  for (int i = 0; i < dacPoints; i++) {

    int dacValue = (1023 * i) / (dacPoints - 1);

    // si tu veux tester VCE fixe :
    // int dacValue = 300;

    analogWrite(DAC_PIN, dacValue);

    delayMicroseconds(pointDelay);
  }

  analogWrite(DAC_PIN, 0);
}

//--------------------------------------------

void holdVCE() {

  int dacFixedValue = 500;

  analogWrite(DAC_PIN, dacFixedValue);

  delay(300);
}

//--------------------------------------------

void setIB(int index) {

  // toutes OFF
  for (int i = 0; i < 6; i++) {
    digitalWrite(IB_PINS[i], LOW);
  }

  delayMicroseconds(200);

  // active uniquement la voie choisie
  digitalWrite(IB_PINS[index], HIGH);
}

//--------------------------------------------

void resetIB() {

  // toutes OFF
  for (int i = 0; i < 6; i++) {
    digitalWrite(IB_PINS[i], LOW);
  }

  //delayMicroseconds(200);
}