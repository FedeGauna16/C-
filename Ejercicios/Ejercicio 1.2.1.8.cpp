#include <iostream>
using namespace std;
// Dado un número de ocho dígitos que representa una fecha con formato aaaammdd,
// se pide mostrar por separado el día, el mes y el año de la fecha ingresada 20201230.
int main()
{
   int fecha;
   cout << "Ingrese la fecha con formato aaaammdd:" << endl;
   cin >> fecha;
   int dia = fecha % 100;
   cout << "Dia: " << dia << endl;
   int mes = (fecha % 10000) / 100;
   cout << "Mes: " << mes << endl;
   int anio = fecha / 10000;
   cout << "Anio: " << anio << endl;

   return 0;
}
