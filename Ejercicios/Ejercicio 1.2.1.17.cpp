#include <iostream>
using namespace std;
// Dado un valor numérico entero positivo n, informar los primeros n múltiplos de 5
// que no sean múltiplos de 3. Por ejemplo: si n fuera 6, la salida deberá ser: 5, 10, 20, 25, 35, 40.

int main()
{
   int n, cont1 = 0, cont2 = 0;

   cout << "Escribir un numero entero positivo:" << endl;
   cin >> n;
   cout << "Los n numeros son: " << endl;

   while (cont1 != n)
   {
      cont2++;
      if ((cont2 % 5) == 0 && (cont2 % 3) != 0)
      {
         cout << cont2 << ", ";
         cont1++;
      }
   }
   return 0;
}
