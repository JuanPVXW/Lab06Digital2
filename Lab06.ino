const int boton1 = PUSH1;  //PUSH1
const int boton2 = PF_0;  //PUSH2
int estado_boton1 = 0;
int estado_boton2 = 0;
int contador = 0;
int contador1 = 0;
int bandera = 0;
int bandera0 = 0;
int bandera1 = 0;
int bandera2 = 0;
#define LED_ROJO PF_1
#define LED_AZUL PF_2
#define LED_VERDE PF_3
#define LED_GANADOR PB_2
/****Contador1**************/
#define RA0 PE_3 
#define RA1 PE_2
#define RA2 PE_1
#define RA3 PD_3
#define RA4 PD_2
#define RA5 PD_1
#define RA6 PD_0
#define RA7 PA_7    //OTRO LADO
/******Contador2*******/
#define RB0 PA_6 
#define RB1 PA_5
#define RB2 PB_4
#define RB3 PE_5
#define RB4 PE_4
#define RB5 PB_1
#define RB6 PB_0
#define RB7 PB_5
/*******Prototipos de funciones*******/
void semaforo(void);
void jugador1(void);
void jugador2(void);
void setup() {
  // put your setup code here, to run once:
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_GANADOR, OUTPUT);
  pinMode(RA0, OUTPUT);
  pinMode(RA1, OUTPUT);
  pinMode(RA2, OUTPUT);
  pinMode(RA3, OUTPUT);
  pinMode(RA4, OUTPUT);
  pinMode(RA5, OUTPUT);
  pinMode(RA6, OUTPUT);
  pinMode(RA7, OUTPUT);
  pinMode(RB0, OUTPUT);
  pinMode(RB1, OUTPUT);
  pinMode(RB2, OUTPUT);
  pinMode(RB3, OUTPUT);
  pinMode(RB4, OUTPUT);
  pinMode(RB5, OUTPUT);
  pinMode(RB6, OUTPUT);
  pinMode(RB7, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  estado_boton1 = digitalRead(boton1);
  estado_boton2 = digitalRead(boton2);
  if(bandera == 0)
  {
    semaforo();      
  }
  if(bandera == 1)
  {
    jugador1();
    jugador2();
  }
  if(contador == 16 | contador1 == 16)
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_GANADOR, HIGH);
    delay(3500);
    bandera = 2;
    if(contador == 16 & bandera == 2)
    {
      delay(1000);
      digitalWrite(RA0, HIGH);
      digitalWrite(RA1, HIGH);
      digitalWrite(RA2, HIGH);
      digitalWrite(RA3, HIGH);
      digitalWrite(RA4, HIGH);
      digitalWrite(RA5, HIGH);
      digitalWrite(RA6, HIGH);
      digitalWrite(RA7, HIGH);
      delay(2500);
    }
    if(contador1 == 16 & bandera == 2)
    {
      delay(1000);
      digitalWrite(RB0, HIGH);
      digitalWrite(RB1, HIGH);
      digitalWrite(RB2, HIGH);
      digitalWrite(RB3, HIGH);
      digitalWrite(RB4, HIGH);
      digitalWrite(RB5, HIGH);
      digitalWrite(RB6, HIGH);
      digitalWrite(RB7, HIGH);
      delay(2500);
    }
    contador = 0;
    contador1 = 0;
    jugador1();
    jugador2();
    bandera = 0;
    digitalWrite(LED_GANADOR, LOW);
  }
}


/***************Funciones************************/
void semaforo(void)
{
  if(estado_boton1 == HIGH & estado_boton2 == HIGH)
      {
        bandera0 = 1;
      }
      else
      {
        if(bandera0 == 1)
        {
          digitalWrite(LED_ROJO, HIGH);
          delay(1500);
          digitalWrite(LED_ROJO, LOW);
          digitalWrite(LED_AZUL, HIGH);
          delay(1500);
          digitalWrite(LED_AZUL, LOW);
          digitalWrite(LED_VERDE, HIGH);
          delay(1500);
          //digitalWrite(LED_VERDE, LOW);
          bandera0 = 0;
          bandera = 1;
        }
      }
}
void jugador2(void)
{
  if(estado_boton2 == HIGH)
  {
    bandera2 = 1;    
  }
  else
  {
    if(bandera2 == 1)
    {
           contador1++;
           bandera2 = 0;
    }
  }
  delay(200);
  switch (contador1){
    case 0:
      digitalWrite(RB0, LOW);
      digitalWrite(RB1, LOW);
      digitalWrite(RB2, LOW);
      digitalWrite(RB3, LOW);
      digitalWrite(RB4, LOW);
      digitalWrite(RB5, LOW);
      digitalWrite(RB6, LOW);
      digitalWrite(RB7, LOW);
    break;
    case 2:
      digitalWrite(RB0, HIGH);
    break;
    case 4:
      digitalWrite(RB0, LOW);
      digitalWrite(RB1, HIGH);
    break;
    case 6:
      digitalWrite(RB1, LOW);
      digitalWrite(RB2, HIGH);
    break;
    case 8:
      digitalWrite(RB2, LOW);
      digitalWrite(RB3, HIGH);
    break;
    case 10:
      digitalWrite(RB3, LOW);
      digitalWrite(RB4, HIGH);
    break;
    case 12:
      digitalWrite(RB4, LOW);
      digitalWrite(RB5, HIGH);
    break;
    case 14:
      digitalWrite(RB5, LOW);
      digitalWrite(RB6, HIGH);
    break;
    case 16:
      digitalWrite(RB6, LOW);
      digitalWrite(RB7, HIGH);
    break;
  }
  
}
void jugador1(void)
{
  if(estado_boton1 == HIGH)
  {
    bandera1 = 1;    
  }
  else
  {
    if(bandera1 == 1)
    {
           contador++;
           bandera1 = 0;
    }
  }
  delay(200);
  switch (contador){
    case 0:
      digitalWrite(RA0, LOW);
      digitalWrite(RA1, LOW);
      digitalWrite(RA2, LOW);
      digitalWrite(RA3, LOW);
      digitalWrite(RA4, LOW);
      digitalWrite(RA5, LOW);
      digitalWrite(RA6, LOW);
      digitalWrite(RA7, LOW);
    break;
    case 2:
      digitalWrite(RA0, HIGH);
    break;
    case 4:
      digitalWrite(RA0, LOW);
      digitalWrite(RA1, HIGH);
    break;
    case 6:
      digitalWrite(RA1, LOW);
      digitalWrite(RA2, HIGH);
    break;
    case 8:
      digitalWrite(RA2, LOW);
      digitalWrite(RA3, HIGH);
    break;
    case 10:
      digitalWrite(RA3, LOW);
      digitalWrite(RA4, HIGH);
    break;
    case 12:
      digitalWrite(RA4, LOW);
      digitalWrite(RA5, HIGH);
    break;
    case 14:
      digitalWrite(RA5, LOW);
      digitalWrite(RA6, HIGH);
    break;
    case 16:
      digitalWrite(RA6, LOW);
      digitalWrite(RA7, HIGH);
    break;
  }
}
