#include <iostream>
using namespace std;
// Se ingresa un conjunto de pares (n, f), donde n es el nombre de una persona y f su fecha de nacimiento,
// informar el nombre de la persona más joven y el de la más vieja.

int main()
{
   int f, fmayor, fmenor, cant = 0, factual, a;
   string n, nmayor, nmenor, nactual;

   while (a != 0)
   {
      cout << "Ingresar un nombre" << endl;
      cin >> n;
      cout << "Ingresar una fecha de nacimiento (aaaammdd)" << endl;
      cin >> f;
      cant++;
      if (cant == 1)
      {
         nactual = n;
         factual = f;
      }

      if (f < factual)
      {
         fmenor = f;
         nmenor = n;
         factual = f;
         nactual = n;
      }
      if (f > factual)
      {
         fmayor = f;
         nmayor = n;
         factual = f;
         nactual = n;
      }
      cout << "¿Desea continuar? 0 para no." << endl;
      cin >> a;
   }

   cout << " El nombre de la persona mas vieja es: " << nmayor << ", " << fmayor << endl;
   cout << " El nombre de la persona mas joven es: " << nmenor << ", " << fmenor << endl;
   return 0;
}
