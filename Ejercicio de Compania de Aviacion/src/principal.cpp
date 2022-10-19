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

Map<int,RCiudad> subirCiudades()
{
   FILE* f = fopen("CIUDADES.dat","r+b");
   Map<int,RCiudad> ret = map<int,RCiudad>();

   Ciudad c = read<Ciudad>(f);
   while( ! feof(f) )
   {
      RCiudad x = rCiudad(c,0);
      mapPut<int,RCiudad>(ret,c.idCiu,x);
      c = read<Ciudad>(f);
   }

   fclose(f);
   return ret;
}

Map<int,RVuelo> subirVuelos()
{
   return {};
}

void procesar(Reserva r,Map<int,RCiudad>& mCiu,Map<int,RVuelo>& mVue,Map<int,int>& mCli)
{
   RVuelo* rVue = mapGet<int,RVuelo>(mVue,r.idVue);

   int idOri = rVue->vue.idOri;
   RCiudad* rOri = mapGet<int,RCiudad>(mCiu,idOri);

   int idDes = rVue->vue.idDes;
   RCiudad* rDes = mapGet<int,RCiudad>(mCiu,idDes);

   // descubro cliente
   int* contMillas = mapGet<int,int>(mCli,r.idCli);
   if( contMillas==NULL )
   {
      contMillas = mapPut<int,int>(mCli,r.idCli,0);
   }

   // punto 1
   rDes->cont++;

   bool aceptoReserva = (rVue->vue.cap-rVue->contPA)>=r.cant;
   if( aceptoReserva )
   {
      // punto 2
      rVue->contPA+=r.cant;

      // punto 3
      int millas = abs(rOri->ciu.millas-rDes->ciu.millas);
      *contMillas+=millas;
   }
   else
   {
      // punto 2
      rVue->contPR+=r.cant;
   }
}

void punto1(Map<int,RCiudad> mCiu)
{
}

void punto2(Map<int,RVuelo> mVue)
{
   mapReset<int,RVuelo>(mVue);
   while( mapHasNext<int,RVuelo>(mVue) )
   {
      RVuelo* x = mapNextValue<int,RVuelo>(mVue);
      int idVue = x->vue.idVue;
      int cpr = x->contPR;
      bool completo = x->contPA==x->vue.cap;
      cout << idVue <<": " << cpr << " ("<< completo <<")" <<endl;
   }
}

void punto3(Map<int,int> mCli)
{
}

int main()
{
   Map<int,RCiudad> mCiu = subirCiudades();
   Map<int,RVuelo> mVue = subirVuelos();
   Map<int,int> mCli = map<int,int>();

   // barro las novedades
   FILE* f = fopen("RESERVAS.dat","r+b");

   Reserva r = read<Reserva>(f);
   while( !feof(f) )
   {
      // proceso
      procesar(r,mCiu,mVue,mCli);
      r = read<Reserva>(f);
   }

   // resultados
   punto1(mCiu);
   punto2(mVue);
   punto3(mCli);

   fclose(f);
   return 0;
}
