#define MOTOR_X1 10 // pinos IN1 a IN4 do driver ponte H
#define MOTOR_X2 9  // 
#define MOTOR_Y1 8  // 
#define MOTOR_Y2 7  // 

#define PINO_INT0 2 // pinos onde estão ligados os 
#define PINO_INT1 3 // comparadores dos encoders

#define PWM1 11   //pino ENB do driver ponte H
#define PWM2 6    //pino ENA

/*
 * são 20 risquinhos:
volta inteira = 20*interrupts

tempo entre interrupts = 1/20*tempo para volta completa

tempo para volta completa = 20*tempo entre interrupts

velocidade angular = 2pi*1/tempo para volta completa

velocidade momentânea = velocidade angular * raio da roda

velocidade momentânea = 2*pi*raio da roda/(20*tempo entre interrupts)
*/
const double RAIO_DA_RODA = 32; //milímetros

double calc_velocidade(long tempo_entre_interrupts){
  // usa a fórmula acima, mas leva em conta o fato de que o tempo é
  // medido em microssegundos
  return ((TWO_PI*RAIO_DA_RODA*1000000)/(20.*tempo_entre_interrupts));
}

volatile long tempo0 = 0;
volatile long diff0 = 0;
volatile long tempo1 = 0;
volatile long diff1 = 0;

void encoder_int0(){
  diff0 = micros() - tempo0;

  tempo0 = micros();
}

void encoder_int1(){
  diff1 = micros() - tempo1;

  tempo1 = micros();
}

void setup() {
  pinMode(MOTOR_X1, OUTPUT);
  pinMode(MOTOR_X2, OUTPUT);
  pinMode(MOTOR_Y1, OUTPUT);
  pinMode(MOTOR_Y2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

  // pino digital 2 / INT0 => ENTRADA
  pinMode(PINO_INT0, INPUT);

  // pino digital 3 / INT1 => ENTRADA
  pinMode(PINO_INT1, INPUT);
  
  // configura interrupção INT0 e INT1
  attachInterrupt(digitalPinToInterrupt(PINO_INT0), encoder_int0, RISING);
  attachInterrupt(digitalPinToInterrupt(PINO_INT1), encoder_int1, RISING);

  // isso faz com que ele ande para frente
  digitalWrite(MOTOR_X1, HIGH);
  digitalWrite(MOTOR_X2, LOW);
  digitalWrite(MOTOR_Y1, LOW);
  digitalWrite(MOTOR_Y2, HIGH);
  analogWrite(PWM1, 240);
  analogWrite(PWM2, 240);

  Serial.begin(115200);
}

void loop() {
  if(millis()%2000 == 0){
    detachInterrupt(digitalPinToInterrupt(PINO_INT0));
    detachInterrupt(digitalPinToInterrupt(PINO_INT1));
    Serial.print("motor0 (mm/s) ->"); //velocidade em milímetros por segundo
    Serial.println(diff0);//calc_velocidade(diff0));
    Serial.print("motor1 (mm/s) ->");
    Serial.println(diff1);//calc_velocidade(diff1));
    attachInterrupt(digitalPinToInterrupt(PINO_INT0), encoder_int0, RISING);
    attachInterrupt(digitalPinToInterrupt(PINO_INT1), encoder_int1, RISING);
  }
}
