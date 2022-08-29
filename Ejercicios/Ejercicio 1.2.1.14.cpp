#include <iostream>
using namespace std;
// Dado un valor entero positivo, informar si es un número primo.

int main()
{
   int num, cont = 0;

   cout << "Escribir un numero entero positivo:" << endl;
   cin >> num;

   for (int i = 1; i <= num; i++)
   {
      if ((num % i) == 0)
      {
         cont++;
      }
   }

   if (cont > 2)
   {
      cout << "El numero " << num << " no es primo." << endl;
   }
   else
   {
      cout << "El numero " << num << " es primo." << endl;
   }

   return 0;
}
