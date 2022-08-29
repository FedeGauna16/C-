#include <iostream>
using namespace std;
// Dado un valor numérico entero positivo n, informar los primeros n números primos.
// Por ejemplo: si n==6 entonces la salida debe ser: 1, 2, 3, 5, 7, 11.

int main()
{
   int num, cont1 = 0, cont2 = 0;

   cout << "Escribir un numero entero positivo:" << endl;
   cin >> num;
   cout << "Los primeros n numeros primos son:" << endl;

   while (cont1 != num)
   {
      int divisores = 0;
      cont2++;
      for (int i = 1; i <= cont2; i++)
      {
         if ((cont2 % i) == 0)
         {
            divisores++;
         }
      }
      if (divisores <= 2)
      {
         cont1++;
         cout << cont2 << ", ";
      }
   }

   return 0;
}
