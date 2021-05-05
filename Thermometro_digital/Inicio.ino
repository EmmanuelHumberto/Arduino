
void inicio(){

   lcd.setCursor (0,0); 
   lcd.print ("Configuracao"); 
   delay(500);
   lcd.setCursor (0,1); 
   lcd.print("Temp. Alerta");
   delay(2500);
   lcd.clear();
   lcd.setCursor (0,0); 
   lcd.print ("Tecle '#' Salvar"); 
   delay (2500); 
   lcd.clear();
   lcd.setCursor (0,0); 
   lcd.print("Digite T.:");

}
