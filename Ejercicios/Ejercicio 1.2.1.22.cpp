#include <iostream>
using namespace std;
// Dados tres valores numéricos enteros positivos: n, a y b,
// informar el n-ésimo múltiplo de a que no es múltiplo de b.
// Por ejemplo : si n = 10, a = 5, b = 3 entonces el n - ésimo múltiplo de 5 que no es múltiplo de 3 es: 70;
// y surge de la siguiente lista:
// Múltiplos de 5 = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70}

int main()
{
   int n, a, b, cont1 = 0, cont2 = 0;

   cout << "Escribir tres numeros enteros positivos:" << endl;
   cin >> n;
   cin >> a;
   cin >> b;
   cout << "Los n numeros son: " << endl;

   while (cont1 != n)
   {
      cont2++;
      if ((cont2 % a) == 0 && (cont2 % b) != 0)
      {
         cont1++;
      }
   }
   cout << cont2;

   return 0;
}
