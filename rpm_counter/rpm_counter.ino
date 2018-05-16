#define MOTOR_X2 13 // 
#define MOTOR_X1 12 // 
#define MOTOR_Y1 11 // 
#define MOTOR_Y2 4 // 

volatile int risquinhos = 0;

void encoder_int(){
  risquinhos++;
}

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

  // isso faz com que ele ande para frente/trás
  digitalWrite(MOTOR_X1, HIGH);
  digitalWrite(MOTOR_X2, LOW);
  digitalWrite(MOTOR_Y1, LOW);
  digitalWrite(MOTOR_Y2, HIGH);

  // pino digital 2 / INT0 => ENTRADA
  pinMode(2, INPUT);

  // configura interrupção INT0
  attachInterrupt(digitalPinToInterrupt(2), encoder_int, RISING);

  Serial.begin(115200);
}

void loop() {
  // a cada três segundos passa 1/20 minutos
  // são 20 risquinhos no encoder
  if(millis()%3000){
    Serial.println(risquinhos);
    risquinhos = 0;
  }
}
