
/*FUNÇÃO MENU  p/ Orientação
   Quatro Opções:
 *'A' Menu
 *'B' mostrar temperatura 
 *'C' programar temperatura de alerta
 *'D' logo
 */
void menu(){

   lcd.clear ();
   lcd.setCursor (0,0);
   lcd.print ("MENU.");
   lcd.setCursor (0,1); 
   lcd.print ("Aguarde...");
   delay(3000); 
   
   lcd.clear (); 
   lcd.setCursor (0,0); 
   lcd.print ("A-Menu");
   lcd.setCursor (8,1); 
   lcd.print ("D-logo");
   lcd.setCursor (0,1); 
   lcd.print ("B-Temp.");
   lcd.setCursor (8,0); 
   lcd.print ("C-prog.");
   delay(1000);
}
