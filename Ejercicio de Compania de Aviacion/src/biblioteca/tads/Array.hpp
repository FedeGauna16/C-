#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
	T* arr;
	int len;
	int maxLen;
};

template<typename T>
Array<T> array()
{
   Array<T> ret;
   ret.len = 0;
   ret.maxLen = 0;
   ret.arr = new T[ret.maxLen];
   return ret;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{
	a.maxLen++;
   return add<T>(a.arr, a.len, t);
}


template<typename T>
T* arrayGet(Array<T> a,int p)
{
	T* dir = &a.arr[p];
	return dir;
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
	T* dir = &a.arr[p];
	*dir = t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
	a.maxLen++;
	insert<T>(a.arr, a.len, t, p);
}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   T t = a.arr[p];
   remove(a.arr, a.len, p);
   return t;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
	while(a.len != 0)
	{
	   remove(a.arr, a.len, 0);
	}
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find(a.arr, a.len, k, cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
	a.maxLen++;
   return orderedInsert(a.arr, a.len, t, cmpTT);
}

template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
	sort(a.arr, a.len, cmpTT);
}

#endif
