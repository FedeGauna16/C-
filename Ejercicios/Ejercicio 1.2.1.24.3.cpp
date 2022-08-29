#include <iostream>
using namespace std;
// Dados 100 valores enteros, informar cuál es el menor.

int main()
{
   int n, a = 0, cantN = 0;
   cout << "Ingresar 100 valores enteros" << endl;
   while (cantN != 5)
   {
      cin >> n;
      cantN++;
      if (cantN == 1)
      {
         a = n;
      }
      else
      {
         if (n < a)
         {
            a = n;
         }
      }
   }
   cout << " El menor es: " << a << endl;
   return 0;
}
