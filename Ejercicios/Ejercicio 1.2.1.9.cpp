#include <iostream>
using namespace std;
// Dada una terna de números naturales que representan el día, mes y año de una fecha,
// se pide unificarlos en un único valor numérico entero de ocho dígitos (aaaammdd),
// tal que los primeros cuatro dígitos representen el año, los dos siguientes el mes,
// y los dos últimos el día.
int main()
{
   int dia, mes, anio, fecha;
   cout << "Escribir dia, mes y anio:" << endl;
   cin >> dia;
   cin >> mes;
   cin >> anio;
   cout << "La fecha en formato aaaammdd es: " << anio * 10000 + mes * 100 + dia << endl;

   return 0;
}
