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

struct Ciudad
{
   int idCiu;
   char descr[20];
   int millas;
};

struct RCiudad
{
   Ciudad ciu;
   int cont;
};

struct Vuelo
{
   int idVue;
   int cap;
   int idOri;
   int idDes;
};

struct RVuelo
{
   Vuelo vue;
   int contPA;
   int contPR;
};

struct Reserva
{
   int idCli;
   int idVue;
   int cant;
};

string ciudadToString(Ciudad x)
{
   char sep = 1;
   string sIdCiu=to_string(x.idCiu);
   string sDescr=x.descr;
   string sMillas=to_string(x.millas);
   return sIdCiu+sep+sDescr+sep+sMillas;
}

Ciudad ciudadFromString(string s)
{
   char sep = 1;
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

Ciudad ciudad(int idCiu,string descr,int millas)
{
   Ciudad a;
   a.idCiu = idCiu;
   strcpy(a.descr,descr.c_str());
   a.millas = millas;
   return a;
}

bool ciudadEquals(Ciudad a,Ciudad b)
{
   if(a.idCiu!=b.idCiu) return false;
   if(a.millas!=b.millas) return false;
   return true;
}

string rCiudadToString(RCiudad x)
{
   char sep = 2;
   string sCiu=ciudadToString(x.ciu);
   string sCont=to_string(x.cont);
   return sCiu+sep+sCont;
}

RCiudad rCiudadFromString(string s)
{
   char sep = 2;
   RCiudad x;
   string t0 = getTokenAt(s,sep,0);
   x.ciu=ciudadFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.cont=stoi(t1);
   return x;
}

string rCiudadToDebug(RCiudad x)
{
   stringstream sout;
   sout<< "[";
   sout << ciudadToDebug(x.ciu);
   sout << ",";
   sout << x.cont;
   sout<< "]";
   return sout.str();
}

string rCiudadToDebug(string mssg,RCiudad x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << ciudadToDebug(x.ciu);
   sout << ",";
   sout << x.cont;
   sout<< "]";
   return sout.str();
}

RCiudad rCiudad(Ciudad ciu,int cont)
{
   RCiudad a;
   a.ciu = ciu;
   a.cont = cont;
   return a;
}

bool rCiudadEquals(RCiudad a,RCiudad b)
{
   if(!ciudadEquals(a.ciu,b.ciu)) return false;
   if(a.cont!=b.cont) return false;
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

string rVueloToString(RVuelo x)
{
   char sep = 4;
   string sVue=vueloToString(x.vue);
   string sContPA=to_string(x.contPA);
   string sContPR=to_string(x.contPR);
   return sVue+sep+sContPA+sep+sContPR;
}

RVuelo rVueloFromString(string s)
{
   char sep = 4;
   RVuelo x;
   string t0 = getTokenAt(s,sep,0);
   x.vue=vueloFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.contPA=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.contPR=stoi(t2);
   return x;
}

string rVueloToDebug(RVuelo x)
{
   stringstream sout;
   sout<< "[";
   sout << vueloToDebug(x.vue);
   sout << ",";
   sout << x.contPA;
   sout << ",";
   sout << x.contPR;
   sout<< "]";
   return sout.str();
}

string rVueloToDebug(string mssg,RVuelo x)
{
   stringstream sout;
   sout<< mssg<<":[";
   sout << vueloToDebug(x.vue);
   sout << ",";
   sout << x.contPA;
   sout << ",";
   sout << x.contPR;
   sout<< "]";
   return sout.str();
}

RVuelo rVuelo(Vuelo vue,int contPA,int contPR)
{
   RVuelo a;
   a.vue = vue;
   a.contPA = contPA;
   a.contPR = contPR;
   return a;
}

bool rVueloEquals(RVuelo a,RVuelo b)
{
   if(!vueloEquals(a.vue,b.vue)) return false;
   if(a.contPA!=b.contPA) return false;
   if(a.contPR!=b.contPR) return false;
   return true;
}

string reservaToString(Reserva x)
{
   char sep = 5;
   string sIdCli=to_string(x.idCli);
   string sIdVue=to_string(x.idVue);
   string sCant=to_string(x.cant);
   return sIdCli+sep+sIdVue+sep+sCant;
}

Reserva reservaFromString(string s)
{
   char sep = 5;
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

#endif
