#include <iostream>
using namespace std;
// Se ingresa por teclado dos valores numéricos enteros diferentes entre sí,
// informar cuál es el mayor.
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
   cout << "Los numeros son iguales: " << a << ", " << b << endl;

   return 0;
}