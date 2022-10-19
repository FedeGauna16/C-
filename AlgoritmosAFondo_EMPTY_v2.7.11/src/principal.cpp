
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

struct Persona
{
	int dni;
	string nom;
};
Persona persona(int dni, string nom)
	{
		return {dni, nom};
	}
int cmpPersonaDNI(Persona p,int d)
{
	return p.dni-d;
}
int cmpInt(int a,int b){return a-b;}
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
	/*string s = "John|Paul|George|Ringo";
	char sep = '|';
	int pos = 1;
	string t = getTokenAt(s,sep,pos);
	cout << t << endl;*/
	/*string a[10]; int len = 0;
	add<string>(a,len,"John");
	add<string>(a,len,"Paul");
	add<string>(a,len,"George");
	add<string>(a,len,"Ringo");
	for(int i=0; i<len; i++)
	{
		cout << a[i] << endl;
	}*/
	/*string a[10];
	int len = 0;
	insert<string>(a,len,"John",0);
	insert<string>(a,len,"Paul",0);
	insert<string>(a,len,"George",0);
	insert<string>(a,len,"Ringo",0);
	for(int i=0; i<len; i++)
	{
		cout << a[i] << endl;
	}*/
	/*string a[10];
	int len = 0;
	add<string>(a,len,"John");
	add<string>(a,len,"Paul");
	add<string>(a,len,"George");
	add<string>(a,len,"Ringo");

	while( len>0 )
	{
		cout << remove<string>(a,len,0) << endl;
	}*/
	/*int len=3;
	Persona arr[] = {persona(10,"Pablo")
					,persona(20,"Pedro")
					,persona(30,"Juan")};
	int pos = find<Persona,int>(arr,len,20,cmpPersonaDNI);
	cout << pos << endl;
    pos = find<Persona,int>(arr,len,40,cmpPersonaDNI);
	cout << pos << endl;*/
	/*int arr[10];
	int len = 0;
	int pos = orderedInsert<int>(arr,len,2,cmpInt);
	  orderedInsert<int>(arr,len,2,cmpInt);
	orderedInsert<int>(arr,len,1,cmpInt);
	 orderedInsert<int>(arr,len,3,cmpInt);
	 orderedInsert<int>(arr,len,0,cmpInt);

	cout << pos << endl;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;*/
	/*
	int arr[] = {1,3,2,5,4};
	int len = 5;
	for(int i=0; i<len; i++)
		{
			cout << arr[i] << endl;
		}
	cout << "   " << endl;
	sort<int>(arr,len,cmpInt);
	for(int i=0; i<len; i++)
	{
		cout << arr[i] << endl;
	}*/
	/*Array<int> a = array<int>();
	int pos = arrayAdd<int>(a,10);
	arrayAdd<int>(a,20);
	arrayAdd<int>(a,30);
	cout << pos << endl;
	for(int i=0; i<arraySize<int>(a); i++)
	{
		int* e = arrayGet(a, i);
		cout << *e << endl;
	}
	cout << arraySize<int>(a) << endl;
	cout << a.cantEl << endl;
	int* p = arrayGet<int>(a,1);
	cout << p << endl;
	*p = 22;
	cout << *p << endl;*/
	/*Array<int> a = array<int>();
	arrayInsert<int>(a,10,0);
	arrayInsert<int>(a,20,0);
	arrayInsert<int>(a,30,0);
	for(int i=0; i<arraySize<int>(a); i++)
	{
		int* e = arrayGet(a, i);
		cout << *e << endl;
	}
	cout << arraySize<int>(a) << endl;
	cout << a.maxLen << endl;
	int* p = arrayGet<int>(a,0);
	cout << p << endl;
	cout << *p << endl;
	arraySet<int>(a,1,99);
	cout << *arrayGet(a, 1) << endl;
	int e = arrayRemove<int>(a,0);
	cout << e << endl;
	for(int i=0; i<arraySize<int>(a); i++)
	{
		int* e = arrayGet(a, i);
		cout << *e << endl;
	}
	arrayRemoveAll<int>(a);
	cout << arraySize<int>(a) << endl;
	int pos = arrayFind<int,int>(a,10,cmpInt);
	cout << pos << endl;
	pos = arrayFind<int,int>(a,40,cmpInt);
	cout << pos << endl;*/
	/*Array<int> a = array<int>();
	arrayOrderedInsert<int>(a,2,cmpInt);
	arrayOrderedInsert<int>(a,1,cmpInt);
	arrayOrderedInsert<int>(a,3,cmpInt);
	arrayOrderedInsert<int>(a,0,cmpInt);
	cout << *arrayGet<int>(a,0) << endl;
	cout << *arrayGet<int>(a,1) << endl;
	cout << *arrayGet<int>(a,2) << endl;
	cout << *arrayGet<int>(a,3) << endl;*/

	/*for(int i=0;i<arraySize<int>(a);i++)
	{
		int* p = arrayGet<int>(a,i);
		cout << *p << endl;
	}
	cout << arraySize<int>(a) << endl;
		cout << a.maxLen << endl;*/
	/*Array<int> a = array<int>();
	arrayAdd<int>(a,2);
	arrayAdd<int>(a,1);
	arrayAdd<int>(a,3);
	arraySort<int>(a,cmpInt);
	for(int i=0;i<arraySize<int>(a);i++)
	{
		int* p = arrayGet<int>(a,i);
		cout << *p << endl;
	}*/

	/*Map<string,int> m = map<string,int>();
	mapPut<string,int>(m,"uno",1);
	mapPut<string,int>(m,"dos",2);
	mapPut<string,int>(m,"tres",3);
	cout << mapGet<string,int>(m, 0) << endl;*/

	/*for(int i = 0; i<m.keys.len; i++)
	{
		cout << m.keys[i] << endl;
		cout << m.values[i] << endl;
	}*/






   return 0;
}

#endif
