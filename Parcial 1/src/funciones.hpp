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

struct Clientes
{
	int idCli;
	int millasAcum;
};

struct Ciudad
{
	int idCiu;
	char descr[20];
	int millas;
};

struct Vuelo
{
	int idVue;
	int cap;
	int idOri;
	int idDes;
};

struct Reserva
{
	int idCli;
	int idVue;
	int cant;
};

struct CiudadAcum
{
	Ciudad c;
	int acum;
};

CiudadAcum ciudadAcum(Ciudad c,int acum);
CiudadAcum ciudadAcumToString(CiudadAcum x);

Coll<CiudadAcum> guardarCiudades()
{
	FILE* f = fopen("CIUDADES.dat", "r+b");
	Coll<CiudadAcum> coll = coll<CiudadAcum>();
	Ciudad c = read<Ciudad>(f);
	while(!feof(f))
	{
		CiudadAcum ca = ciudadAcum(c, 0);
		collAdd<CiudadAcum>(coll, ca, ciudadAcumToString);
		c = read<Ciudad>(f);
	}
	fclose(f);
	return coll;
}

void procesarReservas(Reserva r, Coll<CiudadAcum>& c){
	int plazasR = 0;
	FILE* f = fopen("VUELOS.dat","r+b");
	Vuelo v = read<Vuelo>(f);
	while(!feof(f))
	{
		if(r.cant>v.cap){plazasR++;};
		for(int i = 0; i<collSize<CiudadAcum>(c); i++)
		{
			if(c[i].c.idCiu == v.idOri){c[i].acum++;};
		}
		cout >>"Plazas rechazadas: " >> plazasR;
		plazasR = 0;
		v = read<Vuelo>(f);
	}
	fclose(f);
}



string clientesToString(Clientes x)
{
	char sep = 1;
	string sIdCli=to_string(x.idCli);
	string sMillasAcum=to_string(x.millasAcum);
	return sIdCli+sep+sMillasAcum;
}

Clientes clientesFromString(string s)
{
	char sep = 1;
	Clientes x;
	string t0 = getTokenAt(s,sep,0);
	x.idCli=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.millasAcum=stoi(t1);
	return x;
}

string clientesToDebug(Clientes x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCli;
	sout << ",";
	sout << x.millasAcum;
	sout<< "]";
	return sout.str();
}

string clientesToDebug(string mssg,Clientes x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCli;
	sout << ",";
	sout << x.millasAcum;
	sout<< "]";
	return sout.str();
}

Clientes clientes(int idCli,int millasAcum)
{
	Clientes a;
	a.idCli = idCli;
	a.millasAcum = millasAcum;
	return a;
}

bool clientesEquals(Clientes a,Clientes b)
{
	if(a.idCli!=b.idCli) return false;
	if(a.millasAcum!=b.millasAcum) return false;
	return true;
}

string ciudadToString(Ciudad x)
{
	char sep = 2;
	string sIdCiu=to_string(x.idCiu);
	string sDesc=x.descr;
	string sMillas=to_string(x.millas);
	return sIdCiu+sep+sDesc+sep+sMillas;
}

Ciudad ciudadFromString(string s)
{
	char sep = 2;
	Ciudad x;
	string t0 = getTokenAt(s,sep,0);
	x.idCiu=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.millas=stoi(t2);
	return x;
}

string ciudadToDebug(Ciudad x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCiu;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.millas;
	sout<< "]";
	return sout.str();
}

string ciudadToDebug(string mssg,Ciudad x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCiu;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.millas;
	sout<< "]";
	return sout.str();
}

Ciudad ciudad(int idCiu,string desc,int millas)
{
	Ciudad a;
	a.idCiu = idCiu;
	strcpy(a.descr,desc.c_str());
	a.millas = millas;
	return a;
}

bool ciudadEquals(Ciudad a,Ciudad b)
{
	if(a.idCiu!=b.idCiu) return false;
	if(a.millas!=b.millas) return false;
	return true;
}

string vueloToString(Vuelo x)
{
	char sep = 3;
	string sIdVue=to_string(x.idVue);
	string sCap=to_string(x.cap);
	string sIdOri=to_string(x.idOri);
	string sIdDes=to_string(x.idDes);
	return sIdVue+sep+sCap+sep+sIdOri+sep+sIdDes;
}

Vuelo vueloFromString(string s)
{
	char sep = 3;
	Vuelo x;
	string t0 = getTokenAt(s,sep,0);
	x.idVue=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cap=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.idOri=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.idDes=stoi(t3);
	return x;
}

string vueloToDebug(Vuelo x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idVue;
	sout << ",";
	sout << x.cap;
	sout << ",";
	sout << x.idOri;
	sout << ",";
	sout << x.idDes;
	sout<< "]";
	return sout.str();
}

string vueloToDebug(string mssg,Vuelo x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idVue;
	sout << ",";
	sout << x.cap;
	sout << ",";
	sout << x.idOri;
	sout << ",";
	sout << x.idDes;
	sout<< "]";
	return sout.str();
}

Vuelo vuelo(int idVue,int cap,int idOri,int idDes)
{
	Vuelo a;
	a.idVue = idVue;
	a.cap = cap;
	a.idOri = idOri;
	a.idDes = idDes;
	return a;
}

bool vueloEquals(Vuelo a,Vuelo b)
{
	if(a.idVue!=b.idVue) return false;
	if(a.cap!=b.cap) return false;
	if(a.idOri!=b.idOri) return false;
	if(a.idDes!=b.idDes) return false;
	return true;
}

string reservaToString(Reserva x)
{
	char sep = 4;
	string sIdCli=to_string(x.idCli);
	string sIdVue=to_string(x.idVue);
	string sCant=to_string(x.cant);
	return sIdCli+sep+sIdVue+sep+sCant;
}

Reserva reservaFromString(string s)
{
	char sep = 4;
	Reserva x;
	string t0 = getTokenAt(s,sep,0);
	x.idCli=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idVue=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.cant=stoi(t2);
	return x;
}

string reservaToDebug(Reserva x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCli;
	sout << ",";
	sout << x.idVue;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

string reservaToDebug(string mssg,Reserva x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCli;
	sout << ",";
	sout << x.idVue;
	sout << ",";
	sout << x.cant;
	sout<< "]";
	return sout.str();
}

Reserva reserva(int idCli,int idVue,int cant)
{
	Reserva a;
	a.idCli = idCli;
	a.idVue = idVue;
	a.cant = cant;
	return a;
}

bool reservaEquals(Reserva a,Reserva b)
{
	if(a.idCli!=b.idCli) return false;
	if(a.idVue!=b.idVue) return false;
	if(a.cant!=b.cant) return false;
	return true;
}

string ciudadAcumToString(CiudadAcum x)
{
	char sep = 5;
	string sC=ciudadToString(x.c);
	string sAcum=to_string(x.acum);
	return sC+sep+sAcum;
}

CiudadAcum ciudadAcumFromString(string s)
{
	char sep = 5;
	CiudadAcum x;
	string t0 = getTokenAt(s,sep,0);
	x.c=ciudadFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.acum=stoi(t1);
	return x;
}

string ciudadAcumToDebug(CiudadAcum x)
{
	stringstream sout;
	sout<< "[";
	sout << ciudadToDebug(x.c);
	sout << ",";
	sout << x.acum;
	sout<< "]";
	return sout.str();
}

string ciudadAcumToDebug(string mssg,CiudadAcum x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << ciudadToDebug(x.c);
	sout << ",";
	sout << x.acum;
	sout<< "]";
	return sout.str();
}

CiudadAcum ciudadAcum(Ciudad c,int acum)
{
	CiudadAcum b;
	b.c = c;
	b.acum = acum;
	return b;
}

bool ciudadAcumEquals(CiudadAcum a,CiudadAcum b)
{
	if(!ciudadEquals(a.c,b.c)) return false;
	if(a.acum!=b.acum) return false;
	return true;
}

#endif
