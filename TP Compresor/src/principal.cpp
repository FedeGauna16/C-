
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
#include "biblioteca/tads/huffman/HuffmanSetup.hpp"
#include "biblioteca/tads/BitWriter.hpp"
#include "biblioteca/tads/BitReader.hpp"
#include "principal.hpp"


#include <iosfwd>
using namespace std;

void vaciarTabla(HuffmaneTable tabla[])
{
	int i = 0;
	while(i<256)
	{
		tabla[i].n=0;
		i++;
	}
}

void contarOcurrencias(string fName, HuffmaneTable tabla[])
{
	FILE* f = fopen("hola.txt","r+b");
	int pos;
	char c = read<char>(f);
	while(!feof(f))
	{
		pos = int(c);
		tabla[pos].n++;
		c=read<char>(f);
	}
	fclose(f);
}

int cmpHuff(HuffmanTreeInfo a, HuffmanTreeInfo b)
{
	return b.n - a.n;
}

void crearLista(List<HuffmanTreeInfo>& lista, HuffmaneTable tabla[])
{
	int indice = 0;
	int contador;
	HuffmanTreeInfo nodo;
	while(indice<=255)
	{
		contador = tabla[indice].n;
		if(contador>0)
		{
			nodo.c = indice;
			nodo.n = contador;
			HuffmanTreeInfo* a = listOrderedInsert<HuffmanTreeInfo>(lista,nodo,cmpHuff);
			//cout << "//" << endl << a->c << a->n << endl;
		}
		indice++;
	}

}

void mostrarLista(List<HuffmanTreeInfo> lista)
{
	//cout << listSize(lista) << endl;
	while(listHasNext(lista))
	{
		HuffmanTreeInfo* p = listNext<HuffmanTreeInfo>(lista);
		cout<<"["<<char(p->c)<<"],{"<<p->n<<"}"<<endl;
	}
	//cout << "sali de aca" << endl;
}

bool tieneHijos(HuffmanTreeInfo nodo)
{
	if(nodo.left == NULL && nodo.right == NULL)
		return false;
	else
		return true;
}

HuffmanTreeInfo* crearNodo(HuffmanTreeInfo* nododer, HuffmanTreeInfo* nodoizq, int i)
{
 	//Creo un nuevo nodo.
	HuffmanTreeInfo* newnodo = new HuffmanTreeInfo();
	newnodo->c = 255+i;
	newnodo->n = nodoizq->n + nododer->n;
	newnodo->right = nododer;
	newnodo->left = nodoizq;

	return newnodo;
}

HuffmanTreeInfo* crearArbol(List<HuffmanTreeInfo>& lista)
{
	//cout << "AAAAAAAA" << endl;
	int i = 1;
	while(listSize(lista)>1) //mientras que la lista tenga mas de un elemento
	{
		HuffmanTreeInfo* nododer = new HuffmanTreeInfo();
		HuffmanTreeInfo* nodoizq = new HuffmanTreeInfo();

		//elimino los dos primeros nodos de la lista
		*nododer = listRemoveFirst(lista);
		*nodoizq = listRemoveFirst(lista);

		//creo un nuevo nodo = newnodo
		HuffmanTreeInfo* newnodo = new HuffmanTreeInfo();
		newnodo = crearNodo(nododer,nodoizq, i);
		listOrderedInsert<HuffmanTreeInfo>(lista,*newnodo,cmpHuff);

		i++;
	}
	HuffmanTreeInfo* root = listNext(lista);

	//cout << root->c << "//" << root->n << endl;

	return root;
}

void cargarCodigosEnTabla(HuffmanTreeInfo* raiz, HuffmaneTable tabla[])
{
    HuffmanTree ht = huffmanTree(raiz);
    string code;

    while(!huffmanTreeHasNext(ht))
    {
        HuffmanTreeInfo* x = huffmanTreeNext(ht, code);
        tabla[x->c].code = code;
    }
}

char contarHojas(HuffmaneTable tabla[])
{
	int i = 0;
	int cont = 0;
	while(i<=255)
	{
		if(tabla[i].n != 0)
		{
			cont++;
		}
		i++;
	}
	char charCont = intToChar(cont);
	return charCont;
}

Registro crearRegistro(char c, string code)
{
	Registro r;
	r.c = c;
	r.h = char(length(code));
	int i = 0;
	i = length(code);

	while((length(code) % 8) != 0)
	{
		code = rpad(code,i++,'0'); //funcion de string
	}
	r.codeFlushed = stringToInt(code);

	return r;
}

void grabarCodes(FILE* fc, string code, BitWriter bw)
{
	int n = 0;
	while(code[n] != '/0')
	{
		char b = code[n];
		int bit = charToInt(b);

		bitWriterWrite(bw, bit);
	}
}

void grabarArchivoComprimido(string fName,HuffmaneTable tabla[])
{
	FILE* f = fopen("hola.txt","r+b");
	FILE* fc = fopen("hola.txt.huf", "w+b");

	write<char>(fc, contarHojas(tabla));
	write<int>(fc, fileSize<char>(f));

	char c = read<char>(f);
	while(!feof(f))
	{
		BitWriter bw = bitWriter(fc);
		string code = tabla[charToInt(c)].code;
		cout << "a" << endl;
		Registro r = crearRegistro(c, code);
		write<Registro>(fc, r);
		grabarCodes(fc, code, bw);

		c=read<char>(f);
	}
}


void comprimir (string fName)
{
	//paso 1
	HuffmaneTable tabla[256];
	vaciarTabla(tabla);
	contarOcurrencias (fName,tabla);

	//paso 2
	List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
	crearLista(lista,tabla);
	mostrarLista(lista);

	//paso 3
	//cout << "AAA" << endl;
	HuffmanTreeInfo* raiz = crearArbol (lista);

	// Recorro el arbol para obtener los codigos y los cargo en el array de contadores, en el campo code
	cargarCodigosEnTabla(raiz,tabla);

	//Grabo el archivo comprimido
	grabarArchivoComprimido (fName,tabla);
}

void descomprimir(string fName)
{

}

int main()
{
	 //recibo el nombre del archivo
	 string fName = "prueba.txt";

	 // si no termina con ".huf" comprimo

	 FILE* f = fopen("hola.txt","w+b");
	 write<char>(f,'h');
	 write<char>(f,'o');
	 write<char>(f,'l');
	 write<char>(f,'a');
	 write<char>(f,'a');
	 write<char>(f,'a');

	 fclose(f);

	 comprimir(fName);


	 if(!endsWith(fName,".huf"))
	 {
		 comprimir(fName);
		 cout << "maricon" << endl;
	 }
	 else
	 {
		 descomprimir(fName);
	 }

   return 0;
}

#endif
