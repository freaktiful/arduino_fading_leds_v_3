
int boton = 3;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

long tiempo_anterior;
long diferencia;

bool flagLuces = false;



void setup() {
  Serial.begin(9600);
  pinMode(boton, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(boton), botonLuces, FALLING);
}

void loop() {
  if(flagLuces){
    cambiaEstadoLED();
  }
}

void botonLuces(){
  diferencia = millis() - tiempo_anterior;
  tiempo_anterior = millis();
  //Serial.println(diferencia);

  if(diferencia > 500){
    flagLuces = true;
  }
}

void cambiaEstadoLED(){
  if(digitalRead(greenPin) == false){
    encender();
    Serial.println("encendido");
  }
  else{
    apagar();
    Serial.println("apagado");
  }
  flagLuces = false;
}

void encender(){
  for (int brillo = 0; brillo <= 122; brillo++) {
    setColor(0, brillo, brillo); // es esta combinación porque queremos el color aqua
    delay(30);
  }
  for(int brillo = 123; brillo <= 255; brillo++) {
    setColor(0, brillo, brillo);
    delay(5);
  }
}

void apagar(){
  for (int brillo = 255; brillo >= 0; brillo--) {
    setColor(0, brillo, brillo); // es esta combinación porque queremos el color aqua
    delay(10);
  }
}

void setColor(int red, int green,int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
