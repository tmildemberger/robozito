//
//#define MOTOR_X2 13 // 
//#define MOTOR_X1 12 // 
//#define MOTOR_Y1 11 // 
//#define MOTOR_Y2 4 // 
//
//#define PINO_INT0 2
//#define PINO_INT1 3
//
//#define PWM1 9
//#define PWM2 10
//
//#define MEDIDO_240 18000
//
///*
//velocidade => volta inteira = 20*interrupts
//
//tempo entre interrupts = 1/20*tempo para volta completa
//
//velocidade angular = 2pi*1/tempo para volta completa
//
//velocidade momentânea = velocidade angular * raio da roda
//
//tempo para volta completa = 20*tempo entre interrupts
//
//velocidade momentânea = 2*pi*raio da roda/(20*tempo entre interrupts)
//*/
//
//const float RAIO_DA_RODA = 32; //milímetros
//
//long calc_tempo_esperado(double velocidade){
//  return ((TWO_PI*RAIO_DA_RODA*1000000)/(20*velocidade));
//}
//
//volatile byte pwm_v0 = 240;
//volatile byte pwm_v1 = 240;
//
//volatile long tempo0 = 0;
//volatile long diff0 = 0;
//volatile long tempo1 = 0;
//volatile long diff1 = 0;
//
//long tempo_esperado0 = 0;
//long tempo_esperado1 = 0;
//
//void encoder_int0(){
//  diff0 = micros() - tempo0;
//  pwm_v0 = MEDIDO_240 * 240 / 
//  tempo0 = micros();
//}
//
//void encoder_int1(){
//  diff1 = micros() - tempo1;
//
//  tempo1 = micros();
//}
//
//void setup() {
//  pinMode(MOTOR_X1, OUTPUT);
//  pinMode(MOTOR_X2, OUTPUT);
//  pinMode(MOTOR_Y1, OUTPUT);
//  pinMode(MOTOR_Y2, OUTPUT);
//
//  pinMode(PWM1, OUTPUT);
//  pinMode(PWM2, OUTPUT);
//
//  // isso faz com que ele ande para frente/trás
//  digitalWrite(MOTOR_X1, HIGH);
//  digitalWrite(MOTOR_X2, LOW);
//  digitalWrite(MOTOR_Y1, LOW);
//  digitalWrite(MOTOR_Y2, HIGH);
//
//  // pino digital 2 / INT0 => ENTRADA
//  pinMode(PINO_INT0, INPUT);
//
//  // pino digital 3 / INT1 => ENTRADA
//  pinMode(PINO_INT1, INPUT);
//  
//  // configura interrupção INT0
//  attachInterrupt(digitalPinToInterrupt(PINO_INT0), encoder_int0, RISING);
//  attachInterrupt(digitalPinToInterrupt(PINO_INT1), encoder_int1, RISING);
//
//  analogWrite(PWM1, pwm_v0);
//  analogWrite(PWM2, pwm_v1);
//
//  Serial.begin(115200);
//}
//
//void loop() {
//  if(millis()%2000 == 0){
//    detachInterrupt(digitalPinToInterrupt(PINO_INT0));
//    detachInterrupt(digitalPinToInterrupt(PINO_INT1));
//    Serial.print("motor0:");
//    Serial.println(risquinhos0);
//    Serial.print("motor1:");
//    Serial.println(risquinhos1);
//    risquinhos0 = 0;
//    risquinhos1 = 0;
//    attachInterrupt(digitalPinToInterrupt(PINO_INT0), encoder_int0, RISING);
//    attachInterrupt(digitalPinToInterrupt(PINO_INT1), encoder_int1, RISING);
//  }
//}
