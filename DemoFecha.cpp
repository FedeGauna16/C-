//============================================================================
// Name        : Demo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Fecha.hpp"
using namespace std;

struct Direccion
{
   string calle;
   int nro;
};

string direccionToString(Direccion d)
{
   return d.calle+" "+to_string(d.nro);
}

Direccion direccion(string c,int n)
{
   Direccion x;
   x.calle = c;
   x.nro = n;
   return x;
}

struct Persona
{
   int dni;
   string nombre;
   Fecha fechaNacimiento;
   Direccion dir;
};

string personaToString(Persona p)
{
   string x = "";
   x = x+p.nombre+", ";
   x = x+to_string(p.dni)+", ";
   x = x+direccionToString(p.dir)+", ";
   x = x+fechaToString(p.fechaNacimiento);
   return x;
}

Persona persona(int dni,string n,Fecha f,Direccion d)
{
   return {dni,n,f,d};
}


int main()
{
   Persona p = persona(23232,"Pablo",fecha(2,10,1938),direccion("San Martin",233));
   cout << personaToString(p) << endl;

   Fecha f1 = fecha(29,2,2021);
   cout << fechaToString(f1) << endl;

   if( fechaValidar(f1) )
   {
      cout << "La fecha es correcta" << endl;
   }
   else
   {
      cout << "La fecha NO es correcta" << endl;
   }

   Fecha fh1 = fechaHoy();
   cout << "Hoy es: " << fechaToString(fh1) << endl;

   Fecha fh2;
   fechaHoy(fh2);
   cout << "Hoy es: " << fechaToString(fh2) << endl;

   return 0;
}














