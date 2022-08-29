#include <iostream>
using namespace std;
// Dados 100 valores enteros, informar cuál es el mayor.

int main()
{
   int n, a = -99999, cantN = 0;
   cout << "Ingresar 100 valores enteros" << endl;
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
