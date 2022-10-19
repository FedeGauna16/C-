#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
	arr[len] = e;
	len++;
   return len-1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
	for(int i = len; i>p; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[p] = e;
	len++;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret = arr[p];
   for(int i = p+1; i<len; i++)
   {
	   arr[i-1] = arr[i];
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
	int i = 0;
	while(i<len && cmpTK(arr[i], k))
	{
		i++;
	}

   return i!=len?i:-1;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
	int i = 0;
	bool ordenado = false;

	while(i<len && !ordenado)
	{
		ordenado = true;
		if(cmpTT(arr[i], arr[i+1]) > 0)
		{
			T aux = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = aux;
		}
		if(cmpTT(arr[i], e) > 0)
		{
			insert(arr, len, e, i);
		}
		else
		{
			i++;
			ordenado = false;
		}
	}
	if(len == 0)
	{
		insert(arr, len, e, i);
	}
   return i;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
	bool ordenado = false;
	int k = 1;
	while(!ordenado)
	{
		for(int i = 0; i<len-k; i++)
		{
			ordenado = true;
			if(cmpTT(arr[i], arr[i+1]) > 0)
			{
				T aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
				ordenado = false;
			}
		}
		k++;
		if(k == len)
		{
			ordenado = true;
		}
	}
   return;
}



#endif
