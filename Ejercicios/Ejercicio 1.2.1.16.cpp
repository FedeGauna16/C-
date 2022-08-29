#include <iostream>
using namespace std;
// Dado un valor numérico entero positivo n, informar el n-ésimo término de la sucesión de Fibonacci.
// Por ejemplo: si n es 6, la salida del programa debe ser 8.
// Fn = Fn 1 + Fn 2 con n > 2 F1 = 1 y F2 = 1

int main()
{
   int n, n1 = 1, n2 = 1, n3, cont1 = 0, cont2 = 2;
   cout << "Escribir un entero positivo: " << endl;
   cin >> n;
   cout << "El valor n-esimo es:" << endl;

   while (cont1 != n)
   {
      n3 = n1 + n2;
      cont1++;
   }

   return 0;
}
