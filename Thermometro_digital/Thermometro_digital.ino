#include<Stream.h>
//Define os pinos A5 e A4 como as portas SDA e SCL para a comunicação I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
/*====================================================*/

/*Inicializa o display no endereco 0x27*/
LiquidCrystal_I2C lcd ( 0x27, 16, 2 );
/*-------------------------------------------------------------------------------------*/
/*Keypad 4 linhas*/
const byte ROWS = 4; 
/*Keypad 4 colunas*/
const byte COLS = 4; // Keypad 4 colunas

/*definição dos caracteres do Keypad*/
char hexaKeys [ ROWS ][ COLS ] = 
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'} 
};

/*portas D3 a D6 => linhas do Keypad*/
byte rowPins [ ROWS ] = { 2, 3, 4, 5 }; 
/*portas D7 a D10 => colunas do Keypad*/
byte colPins [ COLS ] = { 6,7,8,9 }; 

/*-------------------------------------------------------------------------------------*/

/*inicializa o Keypad*/
Keypad teclado = Keypad( makeKeymap( hexaKeys ), rowPins, colPins, ROWS, COLS ); 
/*------------------------------------------------------------------------------*/
float temperatura;
/*-------------------------------------------------------------------------------------*/
/*Variavel recebe programação para alerta de temperatura*/
String prog;
/*-------------------------------------------------------------------------------------*/
float temperaturaProgramada= String ( prog ) . toInt();
/*------------------------------------------------------------------------------*/
/*Variavel para acionamento do rele*/
int comando= A1;
/*------------------------------------------------------------------------------*/
/*Variavel recebe valor do teclado*/
String progtemp;
/*------------------------------------------------------------------------------*/
/*Variaveis para acionamento de botaão externo*/
bool running = false;
/*-------------------------------------------------------------------------------------*/
int  LEDpin = 2;  
/*-------------------------------------------------------------------------------------*/
/* botão conectado ao pino 13 e o outro terminal ao ground*/
int  switchPin = 11;   
/*====================================================*/

void setup()
{
  pinMode( LEDpin, OUTPUT );
  pinMode( switchPin, INPUT_PULLUP );
  digitalWrite ( switchPin, HIGH );    
  lcd.init(); 
  lcd.setBacklight ( HIGH );
  logo();
  delay(1000);
  
  if (isnan(temperatura)) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Falha sensor DHT!");
    return;
  }
  programatemperatura();
}
/*====================================================*/

void loop(){

char tecla = teclado.getKey(); 
  
 switch(tecla)
 {
    //caso alguma das teclas imprimíveis foi pressionada
    if(tecla)
    {
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
      
      tecladotemp(tecla);
      break;
 /*-------------------------------------------------------------------------------------*/
      case 'A':
        lcd.clear();
        menu();

      case '#':
        enter();
        break;
        
/*-------------------------------------------------------------------------------------*/
  }
 }
}
 
