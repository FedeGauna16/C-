#include <iostream>
using namespace std;
// Se ingresa por teclado un valor numérico entero, informar :
// 1. La quinta parte de dicho valor.
// 2.El resto que surge al dividir el valor ingresado en cinco partes iguales.
// 3. La séptima parte de la quinta parte del valor ingresado.
int main()
{
   int a;
   cout << "Ingrese el numero a: " << endl;
   cin >> a;
   double x = (double)a / 5;
   cout << "La quinta parte de a es: " << x << endl;
   int resto = a - ((a / 5) * 5);
   cout << "El resto de dividir el valor ingresado en 5 es: " << resto << endl;
   double y = x / 7;
   cout << "La septima parte de la quinta parte de a es: " << y << endl;

   return 0;
}