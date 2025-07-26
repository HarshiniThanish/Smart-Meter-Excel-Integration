#include <PZEM004Tv30.h>

// Initialize the PZEM-004T sensor on digital pins D5 (RX) and D6 (TX) of NodeMCU
PZEM004Tv30 pzem1(14, 12); // NodeMCU D5 -> GPIO14 (RX of PZEM), D6 -> GPIO12 (TX of PZEM)

void setup() {
  Serial.begin(9600);
  Serial.println("PZEM-004T Reader");
}

void loop() {
  float voltage = pzem1.voltage();
  float current = pzem1.current();
  float power   = pzem1.power();
  float energy  = pzem1.energy();
  float pf      = pzem1.pf();  // Power Factor

  // Print column headers only once
  static bool headersPrinted = false;
  if (!headersPrinted) {
    Serial.println("LABEL,Voltage (V),Current (A),Power (W),Energy (Wh),Power Factor");
    headersPrinted = true;
  }

  // Print data in PLX-DAQ format
  Serial.print("DATA,");
  Serial.print(voltage); Serial.print(",");
  Serial.print(current); Serial.print(",");
  Serial.print(power); Serial.print(",");
  Serial.print(energy); Serial.print(",");
  Serial.println(pf); // Append power factor

  delay(2000); // Delay for 2 seconds before next reading
}
