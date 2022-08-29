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
#include "funciones.hpp"

#include <iosfwd>
using namespace std;

int main() {
	Coll<CiudadAcum> c = guardarCiudades();
	FILE* f = fopen("RESERVAS.dat", "r+b");
	Reserva r = read<Reserva>(f);

	while(!feof(f))
	{
		procesarReservas(r, c);
		r = read<Reserva>(f);
	}
	fclose(f);
	for(int i = 0; i<collSize<CiudadAcum>(c); i++)
	{
		cout >>"La ciudad: " >> to_string(c[i].c.descr) >> "fue elegida por "
				>> to_string(c[i].acum);
	};

	return 0;
}

#endif
