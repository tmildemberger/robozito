#define MOTOR_X2 13 // 
#define MOTOR_X1 12 // 
#define MOTOR_Y1 11 // 
#define MOTOR_Y2 4 // 

#define PINO_INT0 2
#define PINO_INT1 3

#define OC1A 9
#define OC1B 10

volatile int risquinhos0 = 0;

volatile int risquinhos1 = 0;

void encoder_int0(){
  risquinhos0++;
}

void encoder_int1(){
  risquinhos1++;
}

void setup() {
  // usa as interrupção externa INT0 e 1 (encoders)
  // para incrementar as variaveis risquinhos 
  
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
  pinMode(PINO_INT0, INPUT);

  // pino digital 3 / INT1 => ENTRADA
  pinMode(PINO_INT1, INPUT);
  
  // configura interrupção INT0
  attachInterrupt(digitalPinToInterrupt(PINO_INT0), encoder_int0, RISING);
  attachInterrupt(digitalPinToInterrupt(PINO_INT1), encoder_int1, RISING);

  Serial.begin(115200);
}

void loop() {
  // a cada três segundos passa 1/20 minutos
  // são 20 risquinhos no encoder
  if(millis()%3000){
    Serial.print("motor0:");
    Serial.println(risquinhos0);
    Serial.print("motor1:");
    Serial.println(risquinhos1);
    risquinhos0 = 0;
    risquinhos1 = 0;
  }
}
