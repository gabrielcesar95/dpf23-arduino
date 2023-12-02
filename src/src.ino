unsigned int distance;
const int LED_GREEN = 2;
const int LED_YELLOW = 3;
const int LED_RED = 4;

const int TRIG = 6;
const int ECHO = 5;

void setup() {
  Serial.begin(9600);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void loop() {
  distance = getDistance(TRIG,ECHO); // Chamada da função de leitura.
  Serial.println(distance);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);

  // Objeto muito próximo
  if (distance < 5) {
    digitalWrite(LED_RED, HIGH);
    // Distância média
  } else if (distance < 13) {
    digitalWrite(LED_YELLOW, HIGH);
  } else {
    // Objeto longe
    digitalWrite(LED_GREEN, HIGH);
  }
}

int getDistance(int pinotrig,int pinoecho){ // Função para leitura do sensor
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}