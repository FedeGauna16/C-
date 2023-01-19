#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
	T info;
	Node<T>* sig;
	int cant = 0;
};

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = e;
	nuevo->sig = NULL;

	if(p != NULL)
	{
		Node<T>* aux = p;
		while(aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = nuevo;
		p->cant++;
	}
	else
	{
		p = nuevo;
		p->cant++;
	}

   return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = e;

	if(p != NULL)
	{
		nuevo->sig = p;
		p = nuevo;
		p->cant++;
	}
	else
	{
		nuevo->sig = NULL;
		p = nuevo;
		p->cant++;
	}

   return nuevo;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{
   T t;
   Node<T>* aux = p;
   while(aux->sig != NULL)
   {
	   aux = aux->sig;
	   if(cmpTK(aux->info, k) == 0)
	   {
		   t = aux->info;
		   delete(aux);
	   }
   }
   return t;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t;
   Node<T>* aux = p->sig;
   //aux->cant = p->cant;
   t = aux->info;
   delete(p);
   p = aux;

   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
	Node<T>* aux = p;
	while(aux->sig != NULL)
	{
		aux = aux->sig;
		if(cmpTK(aux->info, k) == 0)
	    {
		   return aux;
	    }
	}

   return NULL;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
	Node<T>* aux = p;
	Node<T>* ins;
	bool ordenado = false;
	while(aux->sig != NULL && !ordenado)
	{
		aux = aux->sig;
		ordenado = true;
		if(cmpTT(aux->info, aux->sig->info) > 0)
		{
			T auxi = aux->info;
			aux->info = aux->sig->info;
			aux->sig->info = auxi;
		}
		if(cmpTT(aux->info, e) > 0)
		{
			 ins = add<T>(p, e);
		}
		else
		{
			ordenado = false;
		}
	}

   return ins;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
	Node<T>* aux = p;

	if(find(aux, e, cmpTT) != NULL)
	{
		enc = true;
		return aux;
	}
	else
	{
		while(aux->sig != NULL)
		{
			if(cmpTT(aux->info, e) > 0)
			{
				enc = false;
				add<T>(aux, e);
				return aux;
			}
			aux = aux->sig;
		}
	}

   return NULL;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
	Node<T>* aux = p;
	bool ordenado = false;

	while(aux->sig != NULL && !ordenado)
	{
		ordenado = true;
		if(cmpTT(aux->info, aux->sig->info) > 0)
		{
			T auxi = aux->info;
			aux->info = aux->sig->info;
			aux->sig->info = auxi;
		}
		else
		{
			aux = aux->sig;
			ordenado = false;
		}
	}
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return (p == NULL)?true:false;
}

template <typename T>
void free(Node<T>*& p)
{
	while(p != NULL)
	{
		Node<T>* aux = p->sig;
		delete(p);
		p = aux;
	}
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
	Node<T>* aux = addFirst<T>(p, e);
   return aux;
}

template <typename T>
T pop(Node<T>*& p)
{
   T t = removeFirst<T>(p);

   return t;
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
	/*Node<T>* nuevo = new Node<T>();
	nuevo->info = e;
	nuevo->sig = NULL;

	if(p != NULL)
	{
		q->sig = nuevo;
		q = nuevo;
	}
	else
	{
		p = nuevo;
		q = nuevo;
	}*/
	q = add<T>(p, e);

   return q;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
	Node<T>* nuevo = new Node<T>();
	nuevo->info = e;
	nuevo->sig = NULL;

	if(q != NULL)
	{
		q->sig = nuevo;
		q = nuevo;
	}
	else
	{
		q = nuevo;
	}

   return nuevo;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t = removeFirst<T>(p);

   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
   T t;

   return t;
}

#endif
