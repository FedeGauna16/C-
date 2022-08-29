
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include <iosfwd>
using namespace std;

int main()
{
	//string s = "Esto es una prueba";
	//cout << length(" ") << endl;
	//cout << charCount("Hola", 'a') << endl;
	//cout << charCount(s,'e') << endl;
	//cout << charCount(s,' ') << endl;
	//cout << substring(s, 2, 10) << endl;
	//cout << substring(s,2,length(s)) << endl;
	//cout << substring(s,2) << endl;
	//cout << indexOf(s,'e') << endl;
	//cout << indexOf(s,'X')  << endl;
	//cout << indexOf(s,'e',0)  << endl;
	//cout << indexOf(s,'e',12)  << endl;
	//cout << indexOf(s,'o',0)  << endl;
	//cout << indexOf(s,'o',4)  << endl;
	//cout << indexOf(s,"una") << endl;
	//cout << indexOf(s,"jamon") << endl;
	//string x = "Esta funcion es la funcion mas dificil";
	//cout << indexOf(x,"funcion",0) << endl;
	//cout << indexOf(x,"funcion",13) << endl;
	//cout << indexOf(x,"jamon",0) << endl;
	//cout << lastIndexOf(s,'e') << endl;
	//cout << lastIndexOf(s,'X')  << endl;
	//string r = "John|Paul|George|Ringo";
	//cout << indexOfN(r,'|',1) << endl;
	//cout << indexOfN(r,'|',2) << endl;
	//cout << indexOfN(r,'|',3) << endl;
	//cout << indexOfN(r,'|',0) << endl;
	//cout << indexOfN(r,'|',4) << endl;
	//cout << charToInt('0') << endl;
	//cout << charToInt('2') << endl;
	//cout << charToInt('9') << endl;
	//cout << charToInt('A') << endl;
	//cout << charToInt('D') << endl;
	//cout << charToInt('Z') << endl;
	//cout << charToInt('a') << endl;
	//cout << charToInt('d') << endl;
	//cout << charToInt('z') << endl;
	//cout << intToChar(0) << endl;
	//cout << intToChar(2) << endl;
	//cout << intToChar(9) << endl;
	//cout << intToChar(10) << endl;
	//cout << intToChar(13) << endl;
	//cout << intToChar(35) << endl;
	//cout << getDigit(12345, 0) << endl;
	/*string s = "John|Paul|George|Ringo";
	char sep = '|';
	int n = tokenCount(s,sep);
	cout << n << endl;

	s = "John";
	sep = '|';
	n = tokenCount(s,sep);
	cout << n << endl;

	s = "";
	sep = '|';
	n = tokenCount(s,sep);
	cout << n << endl;*/
	//string s = "";
	//char sep = '|';
	//addToken(s,sep,"John");
	//cout << s << endl;
	//addToken(s,sep,"Paul"); cout << s << endl;
	//addToken(s,sep,"George"); cout << s << endl;
	//addToken(s,sep,"Ringo"); cout << s << endl;
	string s = "John|Paul|George|Ringo";
	char sep = '|';
	int pos = 1;
	string t = getTokenAt(s,sep,pos);
	cout << t << endl;


   return 0;
}

#endif
