#define MOTOR_X1 10 // pinos IN1 a IN4 do driver ponte H
#define MOTOR_X2 9  // 
#define MOTOR_Y1 8  // 
#define MOTOR_Y2 7  // 

#define PINO_INT0 2 // pinos onde estão ligados os 
#define PINO_INT1 3 // comparadores dos encoders

#define PWM1 11   //pino ENB do driver ponte H
#define PWM2 6    //pino ENA

volatile int risquinhos0 = 0;
volatile int risquinhos1 = 0;

// cada vez que passa um risquinho pelo encoder N
// a variável risquinhosN é incrementada

void encoder_int0(){
  risquinhos0++;
}

void encoder_int1(){
  risquinhos1++;
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
  // a cada três segundos passa 1/20 minutos
  // são 20 risquinhos no encoder
  // por isso, o que temos na variável risquinhos
  // é na verdade a velocidade do motor em RPM
  if(millis()%3000 == 0){
    detachInterrupt(digitalPinToInterrupt(PINO_INT0));
    detachInterrupt(digitalPinToInterrupt(PINO_INT1));
    Serial.print("motor1:");
    Serial.println(risquinhos0);
    Serial.print("motor2:");
    Serial.println(risquinhos1);
    Serial.print("\n"); //para separar melhor as medições
    
    delay(1); // para garantir que os valores sejam mostrados somente
              // uma vez a cada 3ms

    // a contagem recomeça
    risquinhos0 = 0;
    risquinhos1 = 0;
    attachInterrupt(digitalPinToInterrupt(PINO_INT0), encoder_int0, RISING);
    attachInterrupt(digitalPinToInterrupt(PINO_INT1), encoder_int1, RISING);
  }
}
