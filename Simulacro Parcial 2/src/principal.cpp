//============================================================================
// Name        : cpp.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
#include "principal.hpp"
using namespace std;

Array<Consumo> decodeConsumo(unsigned char acumulado[])
{
	return {};
}
unsigned char* encodeConsumo(Array<Consumo> arr)
{
	return NULL;
}
int calculoConsumoAnual(Array<Consumo> arr,int actual)
{
	return 0;
}

Map<string,RCategoria> subirCategorias()
{
	FILE* f = fopen("CATEGORIAS.dat","r+b");
	Map<string,RCategoria> mCat = map<string,RCategoria>();
	Categoria c = read<Categoria>(f);
	while(!feof(f))
	{
		RCategoria rc = rCategoria(c,list<int>());
		mapPut<string,RCategoria>(mCat,c.idCat,rc);
		c = read<Categoria>(f);
	}
	fclose(f);

	return mCat;
}

int buscarCliente(FILE* fCli, int idCli)
{
	int ret;
	Cliente c;
	int i = 0;
	int j = fileSize<Cliente>(fCli)-1;
	bool enc = false;
	while( i<=j && !enc)
	{
		int k = (i+j)/2;
		seek<Cliente>(fCli,k);
		ret = k;
		c = read<Cliente>(fCli);
		if( c.idCli<idCli )
		{
			i = k+1;
		}
		else
		{
			if( c.idCli>idCli )
			{
				j = k-1;
			}
			else
			{
				enc = true;
			}
		}
	}
	return ret;
}

string buscarCategoria(int consAnual, Map<string,RCategoria> mCat)
{
	mapReset<string,RCategoria>(mCat);
	string cat;
	while(mapHasNext<string,RCategoria>(mCat))
	{
		RCategoria* rc = mapNextValue<string,RCategoria>(mCat);
		if(rc->c.m3Desde <= consAnual <= rc->c.m3Hasta)
		{
			cat = rc->c.descrip;
		}
	}

	return cat;
}

int fechaGet()
{
	return 0;
}

void procesarMediciones(Medicion m, FILE* fCli, Map<string,RCategoria>& mCat)
{
	int pos = buscarCliente(fCli,m.idCli);
	seek<Cliente>(fCli,pos);
	Cliente cli = read<Cliente>(fCli);

	Array<Consumo> cons = decodeConsumo(cli.consumos);
	int consActual = m.lecturaMed - cli.lecturaAnterior;
	int consAnual = calculoConsumoAnual(cons,consActual);

	string cat = buscarCategoria(consAnual,mCat);

	string idCatAnt = cli.idCatAnt;
	if(cat!=idCatAnt)
	{
		RCategoria* rc = mapGet<string,RCategoria>(mCat,cat);
		List<int> lstCli = rc->lst;
		listAdd<int>(lstCli,pos);
	}
	seek<Cliente>(fCli,pos);
	cli.idCatAnt = cat;
	cli.lecturaAnterior = m.lecturaMed;
	strcpy(cli.idCatAnt,cat.c_str());

	arrayRemove<Consumo>(cons,0);
	arrayAdd<Consumo>(cons,consumo(fechaGet(),consActual));
	strcpy(cli.consumos,encodeConsumo(cons));

	seek<Cliente>(fCli,pos);
	write<Cliente>(fCli,cli);
}

void mostrarPunto1(Map<string,RCategoria>mCat, FILE* fCli)
{
	mapReset<string,RCategoria>(mCat);
	while(mapHasNext<string,RCategoria>(mCat))
	{
		RCategoria* rc = mapNextValue<string,RCategoria>(mCat);
		cout << "Categoria: " << rc->c.descrip << endl;
		listReset<int>(rc->lst);
		while(listHasNext<int>(rc->lst))
		{
			int* pos = listNext<int>(rc->lst);
			seek<Cliente>(fCli,*pos);
			Cliente cli = read<Cliente>(fCli);
			cout << "Cliente : " << cli.idCli << endl;
		}
	}
}

int main()
{
   Map<string,RCategoria> mCat = subirCategorias();
   Map<string,List<int>> mLisCat = map<string,List<int>>();

   FILE* fMed = fopen("MEDICIONES.dat","r+b");
   FILE* fCli = fopen("CLIENTES.dat","r+b");

   Medicion m = read<Medicion>(fMed);
   while(!feof(fMed))
   {
	   procesarMediciones(m,fCli,mCat);

	   m = read<Medicion>(fMed);
   }
   mostrarPunto1(mCat,fCli);

   fclose(fMed);
   fclose(fCli);
   return 0;
}
