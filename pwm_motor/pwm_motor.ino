#define MOTOR_X2 13 // 
#define MOTOR_X1 12 // 
#define MOTOR_Y1 11 // 
#define MOTOR_Y2 4 //  

void setup() {
  // timer 1 para o motor E e D
  // contagem até 625 ( 0 -> 625 -> 0 )
  // frequência -> 16M / 625*2 = 12.8kHz
  // resolução -> 5 / 625 = 8mV

  // valor maximo de contagem
  TCCR1A = 0;
  TCCR1B = 0;
  ICR1 = 625;

  // OC1A e OC1B saídas PWM
  TCCR1A |= (1 << COM1B1);
  TCCR1A |= (1 << COM1A1);

  // phase and frequency correct
  // contando até ICR1 = 625
  TCCR1B |= (1 << WGM13);

  // prescaler 1
  TCCR1B |= (1 << CS10);

  // duty cycle = 80%
  OCR1A = 500;
  OCR1B = 500;

  pinMode(MOTOR_X1, OUTPUT);
  pinMode(MOTOR_X2, OUTPUT);
  pinMode(MOTOR_Y1, OUTPUT);
  pinMode(MOTOR_Y2, OUTPUT);
  pinMode(OC1A, OUTPUT);
  pinMode(OC1B, OUTPUT);
  digitalWrite(MOTOR_X1, HIGH);
  digitalWrite(MOTOR_X2, LOW);
  digitalWrite(MOTOR_Y1, LOW);
  digitalWrite(MOTOR_Y2, HIGH);
}

void loop() {
  // isso só serve para teste
  if(millis()%7000){
    OCR1A = ((OCR1A + 125) % 625);
    OCR1B = ((OCR1B + 125) % 625);
  }
}
