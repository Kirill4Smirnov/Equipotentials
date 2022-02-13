#define stepx 5
#define dirx 2
#define stepy 6
#define diry 3
#define in A0
#define flag HIGH

#define StepsPer 20 //количество шагов двигателя на шаг измерения

void steps(int num, int pin) {
  pinMode(pin, OUTPUT);
  
  for (int i = 0; i < num; i++) {
    digitalWrite(pin, HIGH);
    delay(10); //задержка между шагами - чем меньше, тем быстрее работает мотор
    digitalWrite(pin, LOW);
    delay(10);
  }
}

void setup() {
  pinMode(stepx, OUTPUT);
  pinMode(dirx, OUTPUT);
  pinMode(stepy, OUTPUT);
  pinMode(diry, OUTPUT);
  pinMode(in, INPUT);
  
  float val;
  Serial.begin(9600);

  for (int x = 0; x <= 70; x+=1) {
    digitalWrite(dirx, flag);
    
    if (x % 2 == 0) {
      digitalWrite(diry, flag);
      for (int y = 50; y >= 0; y--) {
        steps(StepsPer, stepy);

        //delay(200);
        
        val = analogRead(in) / 1024.0 * 5.0;
        Serial.print("{");
        Serial.print(x);
        Serial.print(", ");
        Serial.print(y);
        Serial.print(", ");
        Serial.print(val);
        Serial.print("}, ");
      }
    } else {
      digitalWrite(diry, !flag);
      for (int y = 0; y <= 50; y++) {
        steps(StepsPer, stepy);

       // delay(200);
        
        val = analogRead(in) / 1024.0 * 5.0;
        Serial.print("{");
        Serial.print(x);
        Serial.print(", ");
        Serial.print(y);
        Serial.print(", ");
        Serial.print(val);
        Serial.print("}, ");
      }
    }

    /*if (x == 25) {
      delay(10000);
    } */
    
    steps(StepsPer, stepx);
  }
}

void loop() {
  
}
