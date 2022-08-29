#include <iostream>
using namespace std;
// Se ingresan tres valores que representan las longitudes de los lados de un triángulo,
// informar cuál es el tipo del triángulo ingresado(isósceles, equilátero o escaleno).
int main()
{
   int lado1, lado2, lado3;
   cout << "Ingrese las longitudes:" << endl;
   cout << "Lado 1:" << endl;
   cin >> lado1;
   cout << "Lado 2:" << endl;
   cin >> lado2;
   cout << "Lado 3:" << endl;
   cin >> lado3;
   cout << "Lados: " << lado1 << ", " << lado2 << ", " << lado3 << endl;

   if (lado1 == lado2 == lado3)
   {
      cout << "El triangulo es equilatero" << endl;
      return 0;
   }
   if (lado1 != lado2 && (lado1 == lado3 || lado2 == lado3) || lado1 != lado3 && (lado1 == lado2 || lado3 == lado2) || lado2 != lado3 && (lado2 == lado1 || lado3 == lado1))
   {
      cout << "El triangulo es isosceles" << endl;
      return 0;
   }
   if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3)
   {
      cout << "El triangulo es escaleno" << endl;
      return 0;
   }

   return 0;
}
