#include <iostream>
using namespace std;
// Dados 100 valores enteros, todos mayores que -10, informar cuál es el mayor.

int main()
{
   int n, a = -99999, cantN = 0;
   cout << "Ingresar 100 valores enteros" << endl;
   while (cantN != 5)
   {
      cin >> n;
      cantN++;
      if (n > -10)
      {
         if (n > a)
         {
            a = n;
         }
      }
   }
   cout << " El mayor es: " << a << endl;
   return 0;
}
