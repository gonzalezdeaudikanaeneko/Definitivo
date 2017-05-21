/*
 * AdministradorCuentas.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#include "AdministradorCuentas.h"
#include "Banco.h"
#include "Cuenta.h"
#include "Funciones.h"
#include "Trabajador.h"

#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;


AdministradorCuentas::AdministradorCuentas() {
	// TODO Auto-generated constructor stub

}

AdministradorCuentas::~AdministradorCuentas() {
	// TODO Auto-generated destructor stub
}

void AdministradorCuentas::anadirCuenta(list<Cuenta> cuentasB, float liq, int cli) {

	Cuenta c;
	c.setLiquidacion(liq);
	c.setNombre("Halo");
	cuentasB.push_back(c);
	cout << "Exito\n";
}
void AdministradorCuentas::eliminarCuenta(list<Cuenta*>* cuentasB, int cli) {
//	unsigned int i = 0, enc = 0;
//	while (enc == 0 && i < cuentasB->size()) {
//		if (get(cuentasB, i)->getNumeroId() == cli) {
//			enc = 1;
//		} else {
//			i++;
//		}
//	}
//	if (enc == 1) {
//		while (i < cuentasB->size()) {
//			remove(cuentasB[i]);
//			i++;
//		}
//		printf("eliminado\n\n");
//
//		CuentasB->numCuentas = CuentasB->numCuentas - 1;
//	} else {
//		printf("no encontrado\n\n");
//	}
}
void AdministradorCuentas::transaccion(list<Cuenta*>* CuentasB, int cliA, int cliB, int cant) {
//
//	int i = 0, j = 0;
//	int t = 0, t1 = 0;
//	while (i < CuentasB->size() && t == 0) {
//		if (get(CuentasB, i)->getNumeroId() == cliA) {
//			t = 1;
//		} else {
//			i++;
//		}
//	}
//
//	while (j < CuentasB->size() && t1 == 0) {
//		if (get(CuentasB, i)->getNumeroId() == cliB) {
//			t1 = 1;
//		} else {
//			j++;
//		}
//	}
//	if (t == 0 || t1 == 0) {
//		//printf("No se han encontrado los clientes %i o %i\n", cliA, cliB);
//		cout << "No se han encontrado los clientes %i o %i\n" << cliA << cliB;
//	} else {
////		CuentasB[j].setLiquidacion(CuentasB[j].getLiquidacion() + cant);
////		CuentasB[i].setLiquidacion(CuentasB[i].getLiquidacion() - cant);
//		get(CuentasB, j)->setLiquidacion(get(CuentasB, j)->getLiquidacion() + cant);
//		get(CuentasB, j)->setLiquidacion(get(CuentasB, j)->getLiquidacion() - cant);
//
//		cout << "Exito\n";
//	}
}
