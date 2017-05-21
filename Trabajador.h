/*
 * Trabajador.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_
#include "Cuenta.h"
#include <list>

using namespace std;

class Trabajador {
private:
	char *nombre;
	int edad;
	int Id_Trabajador;
	char* direccion;
public:
	Trabajador();
	virtual ~Trabajador();
	void anadirCuenta(Cuenta * CuentasB, float liq, int cli);
	void eliminarCuenta(list<Cuenta*>* cuentasB, int cli);
	void transaccion(list<Cuenta*>* CuentasB, int cliA, int cliB, int cant);
	void concederPrestamo(list<Cuenta*>* cuentasB, int cli);
	void cambioDeMoneda(list<Cuenta*>* cuentasB, int cli);
	void setNombre(char* a);
	void setEdad(int a);
	void setId(int a);
	void setdireccion(char* a);
	char* getNombre();
	char* getDireccion();
	int getId();
	int getEdad();
};



#endif /* TRABAJADOR_H_ */
