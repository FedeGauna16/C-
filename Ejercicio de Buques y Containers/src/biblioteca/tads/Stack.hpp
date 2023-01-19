#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
	Node<T>* p;
};

template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.p = new Node<T>();

   return st;
}

template<typename T>
T* stackPush(Stack<T>& st,T e)
{
	Node<T>* x = push(st.p, e);
	T el = x->info;

   return &el;
}

template<typename T>
T stackPop(Stack<T>& st)
{
   T t = pop(st.p);

   return t;
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
	bool empty = isEmpty(st.p);

   return empty;
}

template<typename T>
int stackSize(Stack<T> st)
{
	int size = st.p->cant;

   return size;
}

#endif
