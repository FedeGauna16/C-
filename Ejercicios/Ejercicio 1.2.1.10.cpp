#include <iostream>
using namespace std;
// Entre dos fechas indicadas por el usuario, informar cuál es la más cercana a la actual.

int main()
{
   int fecha1, fecha2, fecha_actual;

   cout << "Escribir dos fechas en formato aaaammdd:" << endl;
   cin >> fecha1;
   cin >> fecha2;
   cout << "Escribir la fecha actual en formato aaaammdd: " << endl;
   cin >> fecha_actual;

   int diferencia1 = abs(fecha1 - fecha_actual);
   int diferencia2 = abs(fecha2 - fecha_actual);

   if (diferencia1 == diferencia2)
   {
      cout << "Ambas fechas estan igual de cerca a la fecha actual" << endl;
      return 0;
   }

   if (diferencia1 > diferencia2)
   {
      cout << "La segunda fecha esta mas cerca a la fecha actual" << endl;
   }
   else
   {
      cout << "La primera fecha esta mas cerca a la fecha actual" << endl;
   }

   return 0;
}
