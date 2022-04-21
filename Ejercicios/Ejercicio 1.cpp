#include <iostream>
using namespace std;
// Se ingresan por teclado dos valores numéricos enteros, a y b,
// se pide calcular e in - formar por consola el resultado de las siguientes operaciones:
// 1. La suma : a + b.
// 2. La diferencia : a - b.
// 3. El producto : a *b.
// 4. El cociente : a / b, aceptando que b es distinto de 0(cero).
int main()
{
   int a, b;
   cout << "Ingrese el numero a y b: " << endl;
   cin >> a;
   cin >> b;
   int suma = a + b;
   int resta = a - b;
   int producto = a * b;
   cout << "La suma de a y b es: " << suma << endl;
   cout << "La resta de a y b es: " << resta << endl;
   cout << "El producto de a y b es: " << producto << endl;
   if (b != 0)
   {
      double cociente = a / (double)b;
      cout << "El cociente de a y b es: " << cociente << endl;
   }
   else
   {
      cout << "El número a tiene que ser distinto de cero" << endl;
   }

   return 0;
}