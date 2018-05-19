#define MOTOR_X2 13 // 
#define MOTOR_X1 12 // 
#define MOTOR_Y1 11 // 
#define MOTOR_Y2 4 // 

#define PINO_INT0 2
#define PINO_INT1 3

#define OC1A 9
#define OC1B 10

volatile long tempo0 = 0;

volatile long tempo1 = 0;

void encoder_int0(){
  micros() - 0;

  tempo0 = micros();
}

void encoder_int1(){
  micros();

  tempo1 = micros();
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

  // timer 2 para gerar interrupções em intervalos\
  // regulares de tempo (8ms creio eu)
  // contagem até 124 ( 0 -> 124 )
  // frequência -> 16M / 1024 = 15625 / 125 = 125Hz
  // escrever algo aqui

  // mudança de planos
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  velocidade_desejada = 70; //70%
  
}
