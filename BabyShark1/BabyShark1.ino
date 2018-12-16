#define toneC    1911
#define toneC1    1804
#define toneD    1703
#define toneEb    1607
#define toneE    1517
#define toneF    1432
#define toneF1    1352
#define toneG    1276
#define toneAb    1204
#define toneA    1136
#define toneBb    1073
#define toneB    1012
#define tonec       955
#define tonec1      902
#define toned       851
#define toneeb      803
#define tonee       758
#define tonef       716
#define tonef1      676
#define toneg       638
#define toneab      602
#define tonea       568
#define tonebb      536
#define toneb       506

#define tonep       0 

int speaker = 10; 
long vel = 20000;
boolean hasplayed = false;
int loops = 0;
const int LED_PIN = 6;
const int LED_PIN2 = 12;
const int SERIAL_BAUD = 9600;
 
void setup() {
  pinMode(speaker, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  Serial.begin(SERIAL_BAUD);
  delay(2000);
  
}

int melod[] = {toneD, toneE, toneG, toneG, toneG, toneG, toneG, toneG,toneG, toneD, toneE, toneG, toneG, toneG, toneG, toneG, toneG,toneG,toneD, toneE, toneG, toneG, toneG, toneG, toneG, toneG, toneG, toneG, toneG, toneF1};
int ritmo[] = {18,     18,    12,     12,    12,    8,    12,     8,    12,   12,     12,    12,    12,   12,      8,     12,    8,   12,    12,    12,    12,   12,     12,   8,     12,    8,     12,       12,   12,     36};
 
void loop() {
  
  if (hasplayed == true){ return;}
  for (int i=0; i<30; i++) {
    int tom = melod[i];
    int tempo = ritmo[i];
 
    long tvalue = tempo * vel;

    tocar(tom, tvalue);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(LED_PIN2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(LED_PIN2, LOW);
    digitalWrite(LED_PIN, LOW);
  }      delay(1000);

  loops = loops + 1;
  if(loops>3){
      hasplayed = true;
  }

}
 
void tocar(int tom, long tempo_value) {
  long tempo_gasto = 0;
  while (tempo_gasto < tempo_value) {
    digitalWrite(speaker, HIGH);
    delayMicroseconds(tom / 2);
 
    digitalWrite(speaker, LOW);
    delayMicroseconds(tom/2);  
    tempo_gasto += tom;
  }
}
