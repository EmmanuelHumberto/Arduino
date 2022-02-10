void enter()
{
   lcd.clear();
   if ( prog == progtemp ) salvaTempAlerta () ;
   else lcd.print ( "Disgrama" ) ;
   delay ( 100 );
   lcd.clear();
   mostrarTeperatura();
}
