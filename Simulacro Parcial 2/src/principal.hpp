#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Categoria
{
	char idCat[3];
	char descrip[50];
	int m3Desde;
	int m3Hasta;
};

struct RCategoria
{
	Categoria c;
	List<int> lst;
};

struct Cliente
{
	int idCli;
	char nombre[100];
	char direccion[200];
	char idCatAnt[3];
	int lecturaAnterior;
	unsigned char consumos[36];
};

struct Medicion
{
	int idCli;
	int lecturaMed;
	Fecha fecha;
};

struct Consumo
{
	int mmaaaa;
	int m3Consumidos;
};

string categoriaToDebug(Categoria x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCat;
	sout << ",";
	sout << x.descrip;
	sout << ",";
	sout << x.m3Desde;
	sout << ",";
	sout << x.m3Hasta;
	sout<< "]";
	return sout.str();
}

string categoriaToDebug(string mssg,Categoria x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCat;
	sout << ",";
	sout << x.descrip;
	sout << ",";
	sout << x.m3Desde;
	sout << ",";
	sout << x.m3Hasta;
	sout<< "]";
	return sout.str();
}

Categoria categoria(string idCat,string descrip,int m3Desde,int m3Hasta)
{
	Categoria a;
	strcpy(a.idCat,idCat.c_str());
	strcpy(a.descrip,descrip.c_str());
	a.m3Desde = m3Desde;
	a.m3Hasta = m3Hasta;
	return a;
}

bool categoriaEquals(Categoria a,Categoria b)
{
	if(a.m3Desde!=b.m3Desde) return false;
	if(a.m3Hasta!=b.m3Hasta) return false;
	return true;
}

string rCategoriaToDebug(RCategoria x)
{
	stringstream sout;
	sout<< "[";
	sout << categoriaToDebug(x.c);
	sout << ",";
	sout << list<int>ToDebug(x.lst);
	sout<< "]";
	return sout.str();
}

string rCategoriaToDebug(string mssg,RCategoria x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << categoriaToDebug(x.c);
	sout << ",";
	sout << list<int>ToDebug(x.lst);
	sout<< "]";
	return sout.str();
}

RCategoria rCategoria(Categoria c,List<int> lst)
{
	RCategoria a;
	a.c = c;
	a.lst = lst;
	return a;
}

bool rCategoriaEquals(RCategoria a,RCategoria b)
{
	if(!categoriaEquals(a.c,b.c)) return false;
	if(!list<int>Equals(a.lst,b.lst)) return false;
	return true;
}

string clienteToDebug(Cliente x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCli;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.idCatAnt;
	sout << ",";
	sout << x.lecturaAnterior;
	sout << ",";
	sout << x.consumos;
	sout<< "]";
	return sout.str();
}

string clienteToDebug(string mssg,Cliente x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCli;
	sout << ",";
	sout << x.nombre;
	sout << ",";
	sout << x.direccion;
	sout << ",";
	sout << x.idCatAnt;
	sout << ",";
	sout << x.lecturaAnterior;
	sout << ",";
	sout << x.consumos;
	sout<< "]";
	return sout.str();
}

Cliente cliente(int idCli,string nombre,string direccion,string idCatAnt,int lecturaAnterior,string consumos)
{
	Cliente a;
	a.idCli = idCli;
	strcpy(a.nombre,nombre.c_str());
	strcpy(a.direccion,direccion.c_str());
	strcpy(a.idCatAnt,idCatAnt.c_str());
	a.lecturaAnterior = lecturaAnterior;
	strcpy(a.consumos,consumos.c_str());
	return a;
}

bool clienteEquals(Cliente a,Cliente b)
{
	if(a.idCli!=b.idCli) return false;
	if(a.lecturaAnterior!=b.lecturaAnterior) return false;
	return true;
}

string medicionToDebug(Medicion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCli;
	sout << ",";
	sout << x.lecturaMed;
	sout << ",";
	sout << fechaToDebug(x.fecha);
	sout<< "]";
	return sout.str();
}

string medicionToDebug(string mssg,Medicion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCli;
	sout << ",";
	sout << x.lecturaMed;
	sout << ",";
	sout << fechaToDebug(x.fecha);
	sout<< "]";
	return sout.str();
}

Medicion medicion(int idCli,int lecturaMed,Fecha fecha)
{
	Medicion a;
	a.idCli = idCli;
	a.lecturaMed = lecturaMed;
	a.fecha = fecha;
	return a;
}

bool medicionEquals(Medicion a,Medicion b)
{
	if(a.idCli!=b.idCli) return false;
	if(a.lecturaMed!=b.lecturaMed) return false;
	if(!fechaEquals(a.fecha,b.fecha)) return false;
	return true;
}

string consumoToDebug(Consumo x)
{
	stringstream sout;
	sout<< "[";
	sout << x.mmaaaa;
	sout << ",";
	sout << x.m3Consumidos;
	sout<< "]";
	return sout.str();
}

string consumoToDebug(string mssg,Consumo x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.mmaaaa;
	sout << ",";
	sout << x.m3Consumidos;
	sout<< "]";
	return sout.str();
}

Consumo consumo(int mmaaaa,int m3Consumidos)
{
	Consumo a;
	a.mmaaaa = mmaaaa;
	a.m3Consumidos = m3Consumidos;
	return a;
}

bool consumoEquals(Consumo a,Consumo b)
{
	if(a.mmaaaa!=b.mmaaaa) return false;
	if(a.m3Consumidos!=b.m3Consumidos) return false;
	return true;
}

#endif
