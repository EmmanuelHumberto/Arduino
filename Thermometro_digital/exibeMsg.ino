
float msgAlerta(float temperatura, float temperaturaProgramada) {
    digitalWrite(comando, HIGH); 
    digitalWrite ( rele, LOW );  
    delay(1500);   
    lcd.clear ();
    lcd.setCursor(2,0);
    lcd.print ("ALERTA TEMP.:");
    lcd.setCursor (0,1); 
    delay(500);
    lcd.print ("LIMITE EXCEDIDO:");
    delay(2500);
    lcd.clear (); 
    lcd.setCursor (0,1); 
    lcd.print ("EM.:");
    lcd.setCursor (5,1);
    delay (500); 
    lcd.print(temperatura- temperaturaProgramada);
    lcd.setCursor (11,1);
    lcd.print ("C");
    delay (100);
    return temperatura;
}
/*====================================================*/
float msgTemperatura (float temperatura, float temperaturaProgamada){ 
    digitalWrite(comando, LOW); 
    digitalWrite ( rele, HIGH);  
    lcd.clear (); 
    lcd.setCursor (0,0); 
    lcd.print ("Temp.: "); 
    lcd.setCursor (0,1); 
    lcd.print ("Alerta: "); 
    lcd.setCursor (8,1); 
    lcd.print (temperaturaProgamada); 
    lcd.setCursor (15,1); 
    lcd.print ("C");
    lcd.setCursor (8,0); 
    lcd.print (temperatura);
    lcd.setCursor (15,0); 
    lcd.print ("C");
    delay (500); 
    return temperatura;
}
/*====================================================*/
void menu(){
   programatemperatura();
}
/*====================================================*/
void logo(){
  lcd.clear(); 
  lcd.setCursor(5,0);
  lcd.print("LIGADO IOT");
  lcd.scrollDisplayRight();
  delay(1000);
}
    /*====================================================*/
  void inicio(){
   lcd.setCursor (0,0); 
   lcd.print ("Tecle '#' para"); 
   lcd.setCursor (0,1); 
   lcd.print ("Salvar a temp."); 
   delay (3500); 
   lcd.clear();
   lcd.setCursor (0,0); 
   lcd.print("Digite a");
   lcd.setCursor (0,1); 
   lcd.print("Temperatura.:");
   delay(1500);
}
/*====================================================*/
void sair(){
    lcd.clear();
    lcd.setCursor (0,0); 
    lcd.print("SAINDO. ");
    lcd.setCursor (0,1); 
    lcd.print("Aguarde... ");
    delay(4000);
}
/*====================================================*/
void salvaTempAlerta(){
   lcd.setCursor (0,0); 
   lcd.print("A temperatura");
   delay(1200);
   lcd.setCursor (0,1); 
   lcd.print("foi salva");
   delay(3500);
}
/*====================================================*/
void finalizaPrograma(){
  lcd.clear ();
  lcd.setCursor(0,0);
  lcd.print ("Programa fim");
  lcd.setCursor (0,1); 
  delay(500);
}
