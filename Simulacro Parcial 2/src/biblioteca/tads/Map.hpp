
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int cont;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.keys = array<K>();
   m.values = array<V>();
   m.cont = 0;

   return m;
}

template<typename K>
int cmpKK(K a,K b)
{
    return a-b;
}

template<typename V>
int cmpVV(V a,V b)
{
	return a-b;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
	int pos = arrayFind<K, K>(m.keys, k, cmpKK);
	V* p = arrayGet<V>(m.values, pos);

   return p;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
	int posK = arrayFind<K, K>(m.keys, k, cmpKK);
	if(posK >=0)
	{
		arraySet<V>(m.values, posK, v);
	}
	else
	{
		arrayAdd<K>(m.keys, k);
		arrayAdd<V>(m.values, v);
	}
	int posV = arrayFind<V, V>(m.values, v, cmpVV);

   return arrayGet<V>(m.values, posV);
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   int pos = arrayFind<K, K>(m.keys, k, cmpKK);
   return (pos>=0)?true:false;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   V v;
   int pos = arrayFind<K, K>(m.keys, k, cmpKK);
   v = *arrayGet<V>(m.values, pos);
   arrayRemove<V>(m.values, pos);
   arrayRemove<K>(m.keys, pos);

   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
	arrayRemoveAll(m.keys);
	arrayRemoveAll(m.values);
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return arraySize<K>(m.keys);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{

   return true;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   K k;
   return k;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   return NULL;
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
}

template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
	arraySort<K>(m.keys, cmpKK(K,K));
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
}

#endif
