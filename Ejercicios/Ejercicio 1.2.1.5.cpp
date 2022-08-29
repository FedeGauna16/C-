#include <iostream>
using namespace std;
// Se ingresa por teclado dos valores numéricos enteros,
// informar cuál es el mayor y cuál el menor.
// Si son iguales, entonces, mostrar un mensaje con el siguiente texto :
// “Los valores ingresados son iguales”.
int main()
{
   int a, b;
   cout << "Ingrese los numeros a y b: " << endl;
   cin >> a;
   cin >> b;
   if (a > b)
   {
      cout << "El numero mayor entre a y b es: " << a << endl;
      return 0;
   }
   if (a < b)
   {
      cout << "El numero mayor entre a y b es: " << b << endl;
      return 0;
   }
   cout << "Los valores ingresados son iguales: " << a << ", " << b << endl;

   return 0;
}
