#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
	Node<T>* p;
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.p = new Node<T>();

   return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
	Node<T>* x = enqueue(q.p, e);
	T el = x->info;

   return &el;
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   T t;
   return t;
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
	bool empty = isEmpty(q.p);

   return true;
}

template<typename T>
int queueSize(Queue<T> q)
{
	int size = q.p->cant;

   return size;
}

#endif
