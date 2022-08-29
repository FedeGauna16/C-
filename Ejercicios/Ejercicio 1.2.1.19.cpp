#include <iostream>
using namespace std;
// Se ingresan por teclado varios valores enteros positivos, de a uno por vez. Se solicita informar :
// 1. Cuántos valores v fueron ingresados, tal que v <= 12.
// 2. Cuántos valores v fueron ingresados, tal que12 < v <= 24.
// 3. Cuántos valores v fueron ingresados, tal que 24 < v <= 36.
// 4. Cuántos valores v fueron ingresados, tal que v == 0(cero).
// La carga de datos finaliza cuando se ingresa un valor negativo.

int main()
{
   int n, a = 0, b = 0, c = 0, d = 0;
   cout << "Ingresar valores enteros positivos: " << endl;

   while (n >= 0)
   {
      cin >> n;
      if (n <= 12)
      {
         a++;
      }
      if (12 < n && n <= 24)
      {
         b++;
      }
      if (24 < n && n <= 36)
      {
         c++;
      }
      if (n == 0)
      {
         d++;
      }
   }
   cout << " Valores menores o igual a 12: " << a << endl;
   cout << " Valores mayores a 12 y menores o igual a 24: " << b << endl;
   cout << " Valores mayores a 24 y menores o igual a 36: " << c << endl;
   cout << " Valores igual a 0: " << d << endl;

   return 0;
}
