#include <iostream>
using namespace std;
// Dado un valor numérico entero positivo, informar su factorial.

int main()
{
   int num, suma = 1;

   cout << "Ingresar un numero entero positivo:" << endl;
   cin >> num;

   for (int i = num; i > 0; i--)
   {
      suma = suma * i;
   }

   cout << "El factorial de " << num << " es de " << suma << endl;

   return 0;
}
