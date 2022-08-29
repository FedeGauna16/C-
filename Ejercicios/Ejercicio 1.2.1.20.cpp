#include <iostream>
using namespace std;
// Se ingresan varios valores numéricos enteros, finalizando la carga de datos al ingresar un 0 (cero).
// Se pide informar:
// 1. Cantidad positivos.
// 2. Cantidad de negativos.
// 3. Porcentaje de pares.
// 4. Promedio de los positivos.
// 5. Porcentaje de negativos.

int main()
{
   int n, pos = 0, neg = 0, par, prom, neg2, cantN = 0, a = 0;
   cout << "Ingresar valores enteros: " << endl;

   while (n != 0)
   {
      cin >> n;
      if (n != 0)
      {
         cantN++;
      }
      if (n > 0)
      {
         pos++;
         a = a + n;
      }
      if (n < 0)
      {
         neg++;
      }
      par = (pos * 100) / cantN;
      prom = a / pos;
      neg2 = (neg * 100) / cantN;
   }
   cout << "Cantidad positivos: " << pos << endl;
   cout << "Cantidad de negativos: " << neg << endl;
   cout << "Porcentaje de pares: " << par << endl;
   cout << "Promedio de los positivos: " << prom << endl;
   cout << "Porcentaje de negativos: " << neg2 << endl;

   return 0;
}
