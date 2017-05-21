/*
 * AdministradorCuentas.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#ifndef ADMINISTRADORCUENTAS_H_
#define ADMINISTRADORCUENTAS_H_
#include "Trabajador.h"
#include "Cuenta.h"
#include <list>
using namespace std;


class AdministradorCuentas : public Trabajador
{
private:

public:
	AdministradorCuentas();
	virtual ~AdministradorCuentas();
	void anadirCuenta(list<Cuenta> CuentasB, float liq, int cli);
	void eliminarCuenta(list<Cuenta*>* cuentasB, int cli);
	void transaccion(list<Cuenta*>* CuentasB, int cliA, int cliB, int cant);
};

#endif /* ADMINISTRADORCUENTAS_H_ */
