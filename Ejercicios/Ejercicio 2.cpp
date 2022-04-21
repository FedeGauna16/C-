#include <iostream>
using namespace std;
// Se ingresan por teclado dos valores numéricos enteros: a y b,
//  se pide calcular e informar el cociente a/b, validando que b sea distinto de cero.
//  En tal caso, mostrar un mensaje de error en la consola.
int main()
{
   int a, b;
   cout << "Ingrese el numero a y b: " << endl;
   cin >> a;
   cin >> b;
   if (b != 0)
   {
      double cociente = a / (double)b;
      cout << "El cocienteeeee de a y b es: " << cociente << endl;
   }
   else
   {
      cout << "Error: El número b tiene que ser distinto de cero" << endl;
   }

   return 0;
}