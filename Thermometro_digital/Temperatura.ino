#include <Thermistor.h> 

/*Função exibe a temperaatura medida em graus celsius 
e temperatura programada para alerta; caso (temperatura<=prog) 
se (temperatura>prog)imprime texto de alerta e coloca o pino 7 em nivel baixo LOW.*/


 
void temperaturam(){

/*Converte o valor de tensão em temperatura utlizando parametros da biblioteca*/
int temperatura = temp.getTemp(); 

if(&temperatura>&tempop){
  digitalWrite(11, LOW);  
  delay(500);   
           
  lcd.clear ();
  lcd.setCursor(2,0);
  lcd.print ("ALERTA TEMP.:");
  lcd.setCursor (0,1); 
  delay(400);
  
  lcd.print ("LIMITE EXCEDIDO:");
  delay(1000);
  lcd.clear (); 
  lcd.setCursor (0,1); 
  lcd.print ("EM:");
  lcd.setCursor (3,1);
  delay (1000); 
  
  lcd.print (&temperatura-&tempop);
  lcd.setCursor (5,1); 
  lcd.print ("C");
  delay (1500); 
}
else{
 digitalWrite(11, HIGH); 
  lcd.clear (); 
  lcd.setCursor (0,0); 
  lcd.print ("Temperatura:"); 
  lcd.setCursor (0,1); 
  lcd.print ("Alerta:"); 
  lcd.setCursor (12,1); 
  lcd.print (tempop); 
  lcd.setCursor (15,1); 
  lcd.print ("C");
  lcd.setCursor (12,0); 
  lcd.print (temperatura);
  lcd.setCursor (15,0); 
  lcd.print ("C");
  delay (500); 
  }  
}
