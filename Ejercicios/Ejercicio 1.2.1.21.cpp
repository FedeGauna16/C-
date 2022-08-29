#include <iostream>
using namespace std;
// Dados 50 valores numéricos enteros, que se ingresan de a uno por vez,
// se pide informar el promedio de los mayores que 100, y la suma de los menores que -10.

int main()
{
   int n, may = 0, cantN = 0, a = 0, b = 0, prom;
   cout << "Ingresar valores enteros: " << endl;

   while (cantN != 50)
   {
      cin >> n;
      cantN++;
      if (n > 100)
      {
         may++;
         a = a + n;
      }
      if (n < -10)
      {
         b = b + n;
      }

      prom = a / may;
   }
   cout << "promedio de los mayores que 100: " << prom << endl;
   cout << "suma de los menores que -10: " << b << endl;
   return 0;
}
