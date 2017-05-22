/*
 * Funciones.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */
#include "sqlite3.h"
#include <list>
#include <string.h>
#include <string>
#include "Cuenta.h"
#include <stdlib.h>
#include "Banco.h"
#include <iostream>
#include <string>
#include <fstream>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
using namespace std;

	int callback(void *NotUsed, int argc, char **argv, char **azColName);
	int ejecutarComandoBD(char * statement);
	void ejecutarComando(char * statement);
	void cerrarBD(sqlite3* db);
	char mostrarMenu() ;
	void abrirBD();
	char mostrarMenuTrabajador();
	char mostrarMenuCliente();
	void almacenarEnBD(list<Cuenta*>* noticias);
	char mostrarMenuDirector();
	char mostrarMenuAdmin();
	Cuenta* nuevaCuenta();
	void crearCuenta(int cuenta, list<Cuenta*>* cu);
	void almacenarCuentaBD(Cuenta* c);
	void createTable();
	Cuenta* getTableDataNoticia(char* query);
	void LeerFichero();
	void almacenarBD(Cuenta ct[]);
	void mostrarCuenta(Cuenta* n) ;

#endif /* FUNCIONES_H_ */
