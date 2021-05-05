/*Constantes*/

const int segundo = 1000;
const int mile_segundo = 500;
const int led_verde = 3;
const int led_amarelo = 4;
const int led_vermelho = 5;
const int led_azul = 6;

/*varaiveis globais */

int sequencia_luzes[]
{ led_verde, led_amarelo, led_vermelho, led_azul};

/*setup*/

void setup(){
    Serial.begin(9600);
    iniciaPortas();
    iniciaJogo();
}

/*INICIA JOGO*/
void iniciaJogo(){

     sizeof(sequencia_luzes) -1;
     
     /*sequencia_luzes[0];
     sequencia_luzes[1];
     sequencia_luzes[2];
     sequencia_luzes[3];*/
          
}

/*INICIA PORTAS*/
void iniciaPortas(){
     pinMode(led_verde, OUTPUT);
     pinMode(led_amarelo, OUTPUT);
     pinMode(led_vermelho, OUTPUT);
     pinMode(led_azul, OUTPUT);
    
}
   

/*LOOP*/
void loop(){
    for(int i = 0; i < sizeof(sequencia_luzes) -1; i++){
        piscaLed(sequencia_luzes[i]);
    }
}
/**/
void piscaLed(int portaLed){
    digitalWrite(portaLed, HIGH);
    delay(segundo);
    digitalWrite(portaLed, LOW);
    delay(mile_segundo);    
}
