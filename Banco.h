/*
 * Banco.h
 *
 *  Created on: 15 de may. de 2017
 *      Author: Eneko
 */
#include "Cuenta.h"
#include <list>

#ifndef BANCO_H_
#define BANCO_H_

using namespace std;

class Banco {

private:

	char *nombre;
	char* direccion;

public:

	Banco(char* nom, char* dir);
	Banco();
	virtual ~Banco();
	void anadirCuenta(list<Cuenta*>* CuentasB, float liq, int cli);
	void transaccion(list<Cuenta*>* CuentasB, int cliA, int cliB, int cant);
	void eliminarCuenta1(list<Cuenta*>* CuentasB, int cli);
	void buscarCuenta(list<Cuenta*>* CuentasB, int cli);
	int existeCuenta(list<Cuenta*>* CuentasB, int cli);
	Cuenta buscarCuenta1(list<Cuenta*>* CuentasB, int cli);
	void actualizarCuenta(list<Cuenta*>* CuentasB, int cli, Cuenta c);
	list<Cuenta*>* LeerFichero();
};

#endif /* BANCO_H_ */
