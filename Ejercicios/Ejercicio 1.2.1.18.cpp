#include <iostream>
using namespace std;
// Dado un valor numérico entero positivo n, se pide mostrar el factorial de los primeros n números naturales.
// Por ejemplo : si n = 7, entonces la salida debe ser : 1, 2, 6, 24, 120, 720, 5040.

int main()
{
   int n, suma, cont = 0;

   cout << "Ingresar un numero entero positivo:" << endl;
   cin >> n;

   while (n != cont)
   {
      cont++;
      suma = 1;
      for (int i = cont; i > 0; i--)
      {
         suma = suma * i;
      }
      cout << suma << ", " << endl;
   }

   return 0;
}
