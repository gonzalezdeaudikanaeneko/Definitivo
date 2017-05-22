/*
 * Banco.cpp
 *
 *  Created on: 15 de may. de 2017
 *      Author: Eneko
 */
#include <cstring>
#include "Banco.h"
#include "Cuenta.h"
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <string>
#include <cstring>
Banco::Banco(char* nom, char* dir) {
	// TODO Auto-generated constructor stub
	this->nombre = nom;
	this->direccion = dir;
}

Banco::Banco() {
	// TODO Auto-generated destructor stub
}

Banco::~Banco() {
	// TODO Auto-generated destructor stub
}

//void Banco::anadirCuenta(list<Cuenta*>* CuentasB, float liq, int cli) {
//
//	Cuenta c; //(555, "Pedro Aguado", (c.numCuentas+1), cli);
//	c.setLiquidacion(liq);
//	c.setNombre("Halo");
//	CuentasB->push_back(c);
//	cout << "Exito\n";
//}

//void Banco::buscarCuenta(list<Cuenta*>* CuentasB, int cli) {
//
//	int i = 0, enc = 0;
//	while (enc == 0 && i < CuentasB->size()) {
//		if (CuentasB->size() == cli) {
//			enc = 1; // en C no existen boolean, por lo tanto cuando queramos usar lo que en java correspondería a un boolean usaremos un int, la similitud sería 1 = true y 0 = false.
//		} else {
//			i++;
//		}
//	}
//	if (enc == 1) {
//		//printf("El cliente %i tiene un total de %i€ en su cuenta\n\n",
//		//		CuentasB[i].nombre, CuentasB[i].liq);
//		cout << "El cliente %i tiene un total de %i€ en su cuenta\n\n"
//				<< CuentasB[i].getNombre() << CuentasB[i].getLiquidacion();
//
//	} else {
//		//printf("El cliente %i no existe\n\n", cli);
//		cout << "El cliente %i no existe\n\n" << cli;
//	}
//}

//Cuenta Banco::buscarCuenta1(list<Cuenta*>* CuentasB, int cli) {
//
//	int i = 0, enc = 0;
//	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
//		if (CuentasB[i].getNumeroId() == cli) {
//			enc = 1;
//		} else {
//			i++;
//		}
//	}
//	return CuentasB[i];
//}
//
//void Banco::actualizarCuenta(list<Cuenta*>* CuentasB, int cli, Cuenta c) {
//
//	int i = 0, enc = 0;
//	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
//		if (CuentasB[i].getNumeroId() == cli) {
//			enc = 1;
//			CuentasB[i] = c;
//		}
//	}
//}

//int Banco::existeCuenta(list<Cuenta*>* CuentasB, int cli) {
//
//	int i = 0, enc = 0;
//	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
//		if (CuentasB[i].getNumeroId() == cli) {
//			enc = 1;
//		} else {
//			i++;
//		}
//	}
//	return enc;
//}

//void Banco::eliminarCuenta1(list<Cuenta*>* CuentasB, int cli) { //funciona
//	int i = 0, enc = 0;
//	while (enc == 0 && i < CuentasB->getNumeroCuentas()) {
//		if (CuentasB[i].getNumeroId() == cli) {
//			enc = 1; // en C no existen boolean, por lo tanto cuando queramos usar lo que en java correspondería a un boolean usaremos un int, la similitud sería 1 = true y 0 = false.
//		} else {
//			i++;
//		}
//	}
//	if (enc == 1) {
//		while (i < CuentasB->getNumeroCuentas()) {
//			CuentasB[i] = CuentasB[i + 1];
//			i++;
//		}
//		//printf("eliminado\n\n");
//		cout << "Eliminado\n";
//		CuentasB->setNumeroCuentas(CuentasB->getNumeroCuentas() - 1);
//	} else {
//		//printf("no encontrado\n\n");
//		cout << "No encontrado\n";
//
//	}

//}
//void Banco::transaccion(list<Cuenta*>* CuentasB, int cliA, int cliB, int cant) {
//
//	int i = 0, j = 0;
//	int t = 0, t1 = 0;
//	while (i < CuentasB->getNumeroCuentas() && t == 0) {
//		if (CuentasB[i].getNumeroId() == cliA) {
//			t = 1;
//		} else {
//			i++;
//		}
//	}
//
//	while (j < CuentasB->getNumeroCuentas() && t1 == 0) {
//		if (CuentasB[i].getNumeroId() == cliB) {
//			t1 = 1;
//		} else {
//			j++;
//		}
//	}
//	if (t == 0 || t1 == 0) {
//		//printf("No se han encontrado los clientes %i o %i\n", cliA, cliB);
//		cout << "No se han encontrado los clientes %i o %i\n" << cliA << cliB;
//	} else {
//		CuentasB[j].setLiquidacion(CuentasB[j].getLiquidacion() + cant);
//		CuentasB[i].setLiquidacion(CuentasB[i].getLiquidacion() - cant);
//		//printf("Exito\n\n");
//		cout << "Exito\n";
//	}
//}

list<Cuenta*>* Banco::LeerFichero() {
	char *str;
	char* aa;
	const char* aaa;
	int i = 0, a = 0;
	cout << "Escriba el nombre del archivo a leer: " << endl;
	string filename;
	cin >> filename;
	ifstream file(filename.c_str());
	if (!file) {
		cout << "Error no se puede abrir el archivo: " << filename << endl;
	}
	string linea, archivo;
	string arch;

//    for(i=0; str[i]!=' ' && str[i] == '_';i++){
//		archivo += linea + "\n";
//    }
	Cuenta *c;
	list<Cuenta*>* users;
	Cuenta cuentastxt[100];
	while (getline(file, linea)) {
		a=0;
		aaa = linea.c_str(); //de string a const char*
		aa = const_cast<char *>(aaa);//Castea de const char* a char*
		for (i = 0; a!=5; i++) {

			do{
				do {
					arch[i] = aa[i];
					i++;
				} while (aa[i] != ' ');

				if (a == 0) {	//DNI
					const char * a = arch.c_str();
					int l = atoi(a);
					c->setNumeroId(l);
				}
				if(a == 1) {	//Nombre
					char *a = strdup(arch.c_str());//convierte de string a char*
					c->setNombre(a);
				}
				if(a == 2){		//Contrasenya
					char *a = strdup(arch.c_str());
					c->setContrasena(a);
				}
				if(a == 3)		//Numero de cuenta
				{
					const char * a = arch.c_str();
					int l = atoi(a);
					c->setID(l);
				}
				if(a == 4){		//Liquidez
					const char * a = arch.c_str();
					int l = atoi(a);
					c->setLiquidacion(l);
				}
				a++;
				if(a == 5){
					c->setDe(0);
				}
			}while(a<5);
		}
		users->push_front(c);
	}
	return users;
}
