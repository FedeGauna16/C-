#include <iostream>
using namespace std;
// Se ingresan tres valores que representan las longitudes de los lados de un triángulo,
// informar cuál es el tipo del triángulo ingresado(isósceles, equilátero o escaleno).
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
