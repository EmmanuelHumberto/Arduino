#include <max6675.h>
/*====================================================*/

int thermoDO = 10;
int thermoCS = 12;
int thermoCLK = 13;
int i = 0;
/*====================================================*/

//### MedirTemperatura ###
float medirTemperatura  ( float temperatura ) 
{
  MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
  temperatura = thermocouple.readCelsius();
  verificaLeituraSenssor ( temperatura );
  processaTemperatura ( temperatura, temperaturaProgramada );
  return temperatura;
  }
/*====================================================*/
  
// ### verificaLeituraSenssor ###
void verificaLeituraSenssor(float temperatura ) 
{
  if ( isnan ( temperatura ) ) {
    lcd.clear();
    lcd.setCursor ( 0, 0 );
    lcd.print( "Falha sensor DHT!" );
    delay ( 1000 );
  }
}
/*====================================================*/

// ### mostrar temperatura ###
void mostrarTeperatura() 
{
  for ( ; ; ) 
  {
   if ( digitalRead ( switchPin ) == LOW )
   {
    botaoSair();
    break;
   }
   else medirTemperatura ( temperatura );
  }
  menu();
}
/*====================================================*/

// ### processa a temperatura ###
float processaTemperatura ( float temperatura, float temperaturaProgramada ) 
{
  if ( temperatura < temperaturaProgramada ) msgTemperatura ( temperatura, temperaturaProgramada );
  else msgAlerta ( temperatura, temperaturaProgramada );
}
/*====================================================*/
