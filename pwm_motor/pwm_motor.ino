#define MOTOR_X1 10 // pinos IN1 a IN4 do driver ponte H
#define MOTOR_X2 9  // 
#define MOTOR_Y1 8  // 
#define MOTOR_Y2 7  // 

#define PINO_INT0 2 // pinos onde estão ligados os 
#define PINO_INT1 3 // comparadores dos encoders

#define PWM1 11   //pino ENB do driver ponte H
#define PWM2 6    //pino ENA

void setup() {
  pinMode(MOTOR_X1, OUTPUT);
  pinMode(MOTOR_X2, OUTPUT);
  pinMode(MOTOR_Y1, OUTPUT);
  pinMode(MOTOR_Y2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

  //isso faz com que os dois motores girem para frente
  digitalWrite(MOTOR_X1, HIGH);
  digitalWrite(MOTOR_X2, LOW);
  digitalWrite(MOTOR_Y1, LOW);
  digitalWrite(MOTOR_Y2, HIGH);
  analogWrite(PWM1, 240);
  analogWrite(PWM2, 240);
}

void loop() {
}
