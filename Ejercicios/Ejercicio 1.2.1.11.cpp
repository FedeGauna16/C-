#include <iostream>
using namespace std;
// Se ingresan dos valores numéricos enteros que corresponden a un mes y un año
// (1 para enero, 2 para febrero, etcétera), se pide informar cuántos días tiene el mes;
// teniendo en cuenta que el año podría ser bisiesto.

int main()
{
   int mes, anio;

   cout << "Escribir mes (en numero) y anio:" << endl;
   cin >> mes;
   cin >> anio;

   if (mes == 2)
   {
      if ((anio % 4) == 0)
      {
         cout << "El mes tiene 29 dias." << endl;
         return 0;
      }
      else
      {
         cout << "El mes tiene 28 dias." << endl;
         return 0;
      }
   }
   if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
   {
      cout << "El mes tiene 30 dias." << endl;
   }
   else
   {
      cout << "El mes tiene 31 dias." << endl;
   }

   return 0;
}
