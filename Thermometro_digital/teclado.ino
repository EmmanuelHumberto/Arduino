char tecla = teclado.getKey() ; 

void tecladotemp ( char tecla ) 
{
  //concatena o novo símbolo a variável 
  progtemp . concat ( tecla );
  
  //variavel prog recebe os dados da variavel progtemp
  prog = progtemp;
  
  //Faz a conversão de instring para int
  temperaturaProgramada = String ( prog ) . toInt();
  lcd.print ( tecla );
}
