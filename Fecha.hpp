//============================================================================
// Name        : Demo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
using namespace std;

struct Fecha
{
   int dia;
   int mes;
   int anio;
};

void _getDate(int& dia, int& mes, int& anio)
{
// fecha actual expresada en segundos
   time_t timestamp;
   time(&timestamp);
// separo la fecha actual en atributos
   struct tm* fechaActual = localtime(&timestamp);
   dia = fechaActual->tm_mday;
   mes = fechaActual->tm_mon+1;
   anio = fechaActual->tm_year+1900;
}


Fecha fecha(int d, int m, int a)
{
   return {d,m,a};
}

Fecha fechaHoy()
{
   int d,m,a;
   _getDate(d,m,a);

   return fecha(d,m,a);
}

void fechaHoy(Fecha& f)
{
   f = fechaHoy();
}

string fechaToString(Fecha f)
{
   return to_string(f.dia)+"/"+to_string(f.mes)+"/"+to_string(f.anio);
}

bool fechaEsAnioBisiesto(Fecha f)
{
   bool esBisiesto = false;

   // es divisible por 4?
   if( f.anio%4==0 )
   {
      esBisiesto = true;
   }
   else
   {
      if( f.anio%400==0&&f.anio%100!=0 )
      {
         esBisiesto = true;
      }
   }

   return esBisiesto;
}

void fechaEsAnioBisiesto(Fecha f,bool& b)
{
   b = fechaEsAnioBisiesto(f);
}









int fechaDiasDelMes(Fecha f)
{
   // en principio son 31 dias
   int dias = 31;

   // si es uno de los meses de 30 dias
   if( f.mes==4||f.mes==6||f.mes==9||f.mes==11 )
   {
      dias = 30;
   }
   else
   {
      if( f.mes==2 ) // es febrero???
      {
         // si el anio es bisiesto entonces son 29 dias
         if( fechaEsAnioBisiesto(f) )
         {
            dias = 29;
         }
         else
         {
            dias = 28;
         }
      }
   }
   return dias;
}

bool fechaValidar(Fecha f)
{
   // cuantos dias tiene el mes
   int maxDias = fechaDiasDelMes(f);

   // si se cumplen las condiciones, la fecha es correcta
   bool ret;
   if( (f.dia>0&&f.dia<=maxDias)&&(f.mes>0&&f.mes<=12)&&(f.anio>=0) )
   {
      ret = true;
   }
   else
   {
      ret = false;
   }
   return ret;
}
