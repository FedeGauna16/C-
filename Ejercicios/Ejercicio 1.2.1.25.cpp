#include <iostream>
using namespace std;
// Dado un conjunto de valores numéricos que finaliza con el ingreso de un 0 (cero),
// informar cuál es el mayor de los negativos, y cuál el menor de los positivos.

int main()
{
   int n, a = 0, b = 0;
   cout << "Ingresar 100 valores enteros" << endl;
   while (n != 0)
   {
      cin >> n;

      if (n < a && n != 0)
      {
         a = n;
      }
      if (n > b && n != 0)
      {
         b = n;
      }
   }

   cout << " El menor es: " << a << endl;
   cout << " El mayor es: " << b << endl;

   return 0;
}
