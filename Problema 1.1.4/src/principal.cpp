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
#include "principal.hpp"

#include <iosfwd>
using namespace std;

int main() {
	Coll<RProducto> p = guardarProductos();
	Coll<Rubro> r = guardarRubros();

	int nrTk, idCli;
	cout << "Ingrese numero de ticket inicial: " << endl;
	cin >> nrTk;
	cout << "Ingrese cliente: " << endl;
	cin >> idCli;

	while(idCli != 0)
	{
		Coll<Item> ticket = coll<Item>();
		Coll<Ahorro> ahorro = coll<Ahorro>();

		int idProd, cant;
		cout << "Ingrese el producto y la cantidad: " << endl;
		cin >> idProd >> cant;

		while(idProd != 0)
		{
			Producto producto = buscarProducto(idProd, p);
			Rubro rubro = buscarRubro(producto.idRub, r);

			procesarDatos(cant, producto, rubro, ticket, ahorro);

			cout << "Ingrese el producto y la cantidad: " << endl;
			cin >> idProd >> cant;
		}
		imprimirTicket(nrTk, ticket, ahorro);

		procesarDemandaPro(ticket, p);
		cout << "Ingrese cliente: " << endl;
		cin >> idCli;
	}

	mostrarDemandaProd(p);


	return 0;
}

#endif
