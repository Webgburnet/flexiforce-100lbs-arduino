#define FSR_PIN A0

const float VCC = 5040; // tension alim arduino en mV
const float R_DIV = 96400.0; // Resisantce 100k
const float g = 9.81 ;
const float coef = 0.1;

void setup() 
{
  Serial.begin(9600);
  pinMode(FSR_PIN, INPUT);
}

void loop() 
{
  int fsrADC = analogRead(FSR_PIN);
  float fsr_vout = map(fsrADC, 0,1023,0, VCC);
  float fsr_R = R_DIV * VCC/fsr_vout;
  float kg = fsrADC*coef;
  float force = g*kg;
  Serial.print(" Sortie Analogique : ");
  Serial.print(fsrADC);
  Serial.print(" \t Tension sortie : ");
  Serial.print(fsr_vout);
  Serial.print(" mV \t R : ");
  Serial.print(fsr_R);
  Serial.print(" Ohm \t Masse : ");
  Serial.print(kg);
  Serial.print(" kg \t Force : ");
  Serial.print(force);
  Serial.println(" N");
  
  
  
}
