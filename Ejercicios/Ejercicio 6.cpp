#include <iostream>
using namespace std;
// Se ingresan tres valores numéricos enteros,
// diferentes entre sí, informar cuál es el menor,
// cuál está en el medio y cuál es el mayor.
int main()
{
   int a, b, c;
   cout << "Ingrese los numeros a, b y c: " << endl;
   cin >> a;
   cin >> b;
   cin >> c;
   if (a > b && a > c)
   {
      cout << "El numero mayor entre a, b y c es: " << a << endl;
      if (b > c)
      {
         cout << "El numero del medio entre a, b y c es: " << b << endl;
         cout << "El numero menor entre a, b y c es: " << c << endl;
      }
      else
      {
         cout << "El numero del medio entre a, b y c es: " << c << endl;
         cout << "El numero menor entre a, b y c es: " << b << endl;
      }
   }
   if (b > a && b > c)
   {
      cout << "El numero mayor entre a, b y c es: " << b << endl;
      if (a > c)
      {
         cout << "El numero del medio entre a, b y c es: " << a << endl;
         cout << "El numero menor entre a, b y c es: " << c << endl;
      }
      else
      {
         cout << "El numero del medio entre a, b y c es: " << c << endl;
         cout << "El numero menor entre a, b y c es: " << a << endl;
      }
   }
   if (c > a && c > b)
   {
      cout << "El numero mayor entre a, b y c es: " << c << endl;
      if (a > b)
      {
         cout << "El numero del medio entre a, b y c es: " << a << endl;
         cout << "El numero menor entre a, b y c es: " << b << endl;
      }
      else
      {
         cout << "El numero del medio entre a, b y c es: " << b << endl;
         cout << "El numero menor entre a, b y c es: " << a << endl;
      }
   }
   return 0;
}
