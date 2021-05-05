
void salvaTempAlerta(){
  
   lcd.setCursor (0,0); 
   lcd.print("Caliditas Salva");
   delay(475);
   
   lcd.setCursor (0,1); 
   lcd.print("Com Sucesso:");
   delay(2500);
   
   lcd.setCursor (12,1); 
   lcd.print(tempop);
   delay(300);
   
   lcd.setCursor (15,1); 
   lcd.print("C");
   delay(1000);
}
