#include <iostream>
using namespace std;
// Dados 100 valores enteros menores que 10, informar cuál es el menor.

int main()
{
   int n, a = 0, cantN = 0;
   cout << "Ingresar 100 valores enteros menores que 10" << endl;
   while (cantN != 5)
   {
      cin >> n;
      cantN++;
      if (n < a)
      {
         a = n;
      }
   }
   cout << " El menor es: " << a << endl;
   return 0;
}
