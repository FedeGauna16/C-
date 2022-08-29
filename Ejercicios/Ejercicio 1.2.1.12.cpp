#include <iostream>
using namespace std;
// Dados dos valores numéricos enteros, informar su producto calculándolo mediante sumas sucesivas.

int main()
{
   int num1, num2, suma = 0;

   cout << "Ingresar dos numeros enteros:" << endl;
   cin >> num1;
   cin >> num2;

   for (int i = 0; i < abs(num2); i++)
   {
      if (num2 < 0)
      {
         suma = suma - num1;
      }
      else
      {
         suma = suma + num1;
      }
   }

   cout << "La suma sucesiva de " << num1 << " y " << num2 << " es de " << suma << endl;

   return 0;
}
