#include <iostream>
using namespace std;
// Dados 100 valores enteros positivos, informar cuál es el mayor.

int main()
{
   int n, a = 0, cantN = 0;
   cout << "Ingresar 100 valores enteros positivos" << endl;
   while (cantN != 5)
   {
      cin >> n;
      cantN++;
      if (n > a)
      {
         a = n;
      }
   }
   cout << " El mayor es: " << a << endl;

   return 0;
}
