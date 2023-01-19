#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
	Node<T>* p;
	int cont;
};

template<typename T>
List<T> list()
{
   List<T> lst;
   lst.p = new Node<T>();
   lst.cont = 0;

   return lst;
}

template<typename T>
T* listAdd(List<T>& lst,T e)
{
	T* nuevo = add(lst.p, e);

   return nuevo;
}

template<typename T>
T* listAddFirst(List<T>& lst,T e)
{
	T* nuevo = addFirst(lst.p, e);

   return nuevo;
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   T t = remove(lst.p, k, cmpTK);

   return t;
}

template<typename T>
T listRemoveFirst(List<T>& lst)
{
   T t = removeFirst(lst.p);

   return t;
}

template<typename T,typename K>
T* listFind(List<T> lst,K k,int cmpTK(T,K))
{
	Node<T>* aux = find(lst.p, k, cmpTK);

   return &aux->info;
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
	bool empty = isEmpty(lst.p);

   return empty;
}

template<typename T>
int listSize(List<T> lst)
{
	int size = lst.p->cant;

   return size;
}

template<typename T>
void listFree(List<T>& lst)
{
	free(lst.p);
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
	Node<T>* ins = orderedInsert<T>(lst.p, t, cmpTT);

   return &ins->info;
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
	sort(lst.p, cmpTT);
}

template<typename T>
void listReset(List<T>& lst)
{
	lst.cont = 0;
}

template<typename T>
bool listHasNext(List<T> lst)
{
   return (lst.cont<listSize(lst))?true:false;
}

template<typename T>
T* listNext(List<T>& lst)
{
	// Node<T>* next = find<T>(lst.p, lst.cont);
	  lst.cont++;

   return NULL;
}

template<typename T>
T* listNext(List<T>& lst,bool& endOfList)
{
   T* t;
   return t;
}

#endif
