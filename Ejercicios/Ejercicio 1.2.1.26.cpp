#include <iostream>
using namespace std;
// Sea un conjunto de valores numéricos que finaliza al ingresar un 0 (cero),
// informar cuál es el mínimo valor considerando sólo aquellos que pertenecen al intervalo [-16, 27].

int main()
{
   int n, a = 0;
   cout << "Ingresar 100 valores enteros" << endl;
   while (n != 0)
   {
      cin >> n;
      if (a == 0)
         a = n;
      if (n >= -16 && n <= 27)
      {
         if (n < a && n != 0)
         {
            a = n;
         }
      }
   }

   cout << " El menor es: " << a << endl;
   return 0;
}
