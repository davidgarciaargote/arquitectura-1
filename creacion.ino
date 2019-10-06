#define ZUMBADOR PC4
#define ECHO PC5
#define TRIGGER PC6
float sinVal;
int toneVal;
void setup() {
   Serial.begin(9600);
   pinMode(TRIGGER, OUTPUT);
   pinMode(ECHO, INPUT);
   pinMode(ZUMBADOR,OUTPUT);
}
 
void loop() {
   ping(TRIGGER, ECHO);
   
   delay(100);
   
   ping(TRIGGER,ECHO);
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);          //La función de este programa es evitar que cualquier persona deje la puerta abierta de cualquier 
   delayMicroseconds(1);                   //parte, con esto se pueden evitar robos o cuando un niño le habrá a un desconocido la persona a 
   digitalWrite(TriggerPin, HIGH);         //cargo escuche el Buzzer, POR EJEMPLO en la universidad Cundinamarca instalaron un mecanismo 
   delayMicroseconds(1);                   //para que la puerta abriera por medio de tarjeta, pero cuando estuve ahí me di cuenta que una 
   digitalWrite(TriggerPin, LOW);          //persona ingreso a la sala y dejo la puerta pensando que se cerraría sola pero no fue así, 
                                           //¿de qué sirve tener un mecanismo de tanta seguridad para para restringir el ingreso? si la persona puede 
   duration = pulseIn(EchoPin, HIGH);      //dejar la puerta abierta sin darse cuenta, pues con este programa podrán solucionar el problema si se pone 
                                            //a un costado el sensor cuando la persona habrá la puerta, el sensor al sentir la puerta ha 10 cm 
   distanceCm = duration * 10 / 290/ 2;     //comenzara a sonar con pausas el Buzzer, alertando ha la persona de que a dejado la puerta abierta 
   if(distanceCm<10){                       //Y de esta manera evitar un robo o darle una gran utilidad de manera efectiva al mecanismo de las puertas 
    tone(ZUMBADOR,3800);                    //ya sea con tarjeta imanes huellas ect…
    delay (700);
    noTone(ZUMBADOR);
    noTone(ZUMBADOR);
    tone (ZUMBADOR,3800);
    tone(ZUMBADOR,8000);  
    
    
   }else
   noTone(ZUMBADOR);
}
