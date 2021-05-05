#include<Stream.h>
#include <Thermistor.h> 
//Define os pinos A5 e A4 como as portas SDA e SCL para a comunicação I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
/*------------------------------------------------------------------------------*/

/*Inicializa o display no endereco 0x27*/
LiquidCrystal_I2C lcd(0x27,16,2);
/*------------------------------------------------------------------------------*/

/*Keypad 4 linhas*/
const byte ROWS = 4; 
/*Keypad 4 colunas*/
const byte COLS = 4; // Keypad 4 colunas

/*definição dos caracteres do Keypad*/
char hexaKeys[ROWS][COLS] = 
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'} // alterações *=F e #=E
};

/*portas D3 a D6 => linhas do Keypad*/
byte rowPins[ROWS] = {3,4,5,6}; 
/*portas D7 a D10 => colunas do Keypad*/
byte colPins[COLS] = {7,8,9,10}; 

/*inicializa o Keypad*/
Keypad teclado = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
/*------------------------------------------------------------------------------*/

/*Variaveis Temperatura*/
Thermistor temp(0);
/*Variavel recebe valor de temperatura*/
int pin2;
/*Variavel recebe programação para alerta de temperatura*/
String prog;
int tempop = String(prog).toInt();
/*------------------------------------------------------------------------------*/

/*Variavel para acionamento do rele*/
int comando = 7;
/*------------------------------------------------------------------------------*/

/*Variavel recebe valor do teclado*/
String progtemp;
/*------------------------------------------------------------------------------*/

/*Variaveis para acionamento de botaão externo*/
bool running = false;
int  LEDpin = 2;  
/* botão conectado ao pino 13 e o outro terminal ao ground*/
int  switchPin = 13 ;   
/*------------------------------------------------------------------------------*/


void setup(){

  pinMode(11,OUTPUT);
  //Ativa o pino digital 11 em nivel alto 5V  
  digitalWrite(11,HIGH);  
  pinMode(LEDpin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);    
  lcd.init(); 
  lcd.setBacklight(HIGH);
  logo();
  delay(1000);
  menu();
}
/*------------------------------------------------------------------------------*/

void loop(){
  
 char tecla = teclado.getKey(); 

  
 switch(tecla){
  
    //caso alguma das teclas imprimíveis foi pressionada
    if(tecla){
      
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '*':
      
        //concatena o novo símbolo a variável 
        progtemp.concat(tecla);
        //variavel prog recebe os dados da variavel progtemp
        prog=progtemp;
        //Faz a conversão de instring para int
        tempop = String(prog).toInt();
        lcd.print(tecla);
        break;
 /*-------------------------------------------------------------------------------------*/
 
      case 'A':
        lcd.clear();
        menu();
        break;
/*-------------------------------------------------------------------------------------*/
      case'B':
      
        for(int i = 0;tecla == '*';i++){
             
        /*Intenromper o ciclo de petição For(x)  
          SE o valor dentro switchPin estiver em nivel baixo = 0V
          o pull-up mantém o pino em HIGH internamente
         */
           if (digitalRead(switchPin) == LOW){
                delay(100);                             
                running = !running;          
                digitalWrite(LEDpin, running);  
                sair();
                lcd.clear();
                menu();
               return 0;
            }
            else{          
               temperaturam();
           } 
        }
        break;  
/*-------------------------------------------------------------------------------------*/

      //caso a tecla 'C' tenha sido pressionada
      case 'C':
 
        //limpa a variavel prog; 
        progtemp="";
        lcd.clear();
        inicio();
        break;//Fim case 'C'
/*-------------------------------------------------------------------------------------*/

      case 'D':
        logo();
        break;
/*-------------------------------------------------------------------------------------*/
      case '#':
      
        lcd.clear();
        if(prog==progtemp){ 
          salvaTempAlerta();
          delay(1500);
        }
        else{
          lcd.print("Disgrama");
         }
       delay(100);
       lcd.clear();
       break;
/*-------------------------------------------------------------------------------------*/
  }
 }
}
