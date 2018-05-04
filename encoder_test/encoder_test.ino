// programa ainda não finalizado
volatile int risquinhos = 0;

void encoder_int(){
  risquinhos++;
}

void setup() {
  // usa a interrupção externa INT0 (encoder)
  // para incrementar a variavel risquinhos 

  
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
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
