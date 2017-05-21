/*
 * Funciones.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */

#include "Funciones.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Cuenta.h"
#include <list>
#include "sqlite3.h"
#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;
FILE *doc;

char mostrarMenu() {
	printf("MENU PRINCIPAL\n"
			"1.\tTRABAJADOR\n"
			"2.\tCLIENTE\n"
			"3.\tSALIR\n"
			"Introduzca numero de la funcion deseada:\n");
	fflush(stdout);
	char resultado;
	resultado = getchar();
	fflush(stdin);
	return resultado;
}
char mostrarMenuTrabajador(){
	printf("Trabajador>\n"
			"MENU PRINCIPAL\n"
				"1.\tDirector\n"
				"2.\tAdministrador de cuentas\n"
				"3.\tSalir\n\n"
				"Introduzca numero de la funcion deseada:\n");
		fflush(stdout);
		char resultado;
		resultado = getchar();
		fflush(stdin);
		return resultado;
}

char mostrarMenuCliente() {
	printf("Cliente>\n"
			"MENU PRINCIPAL\n"
			"1.\tIngresar Dinero\n"
			"2.\tRetirar dinero\n"
			"3.\tSalir\n\n"
			"Introduzca numero de la funcion deseada:\n");
	fflush(stdout);
	char resultado;
	resultado = getchar();
	fflush(stdin);
	return resultado;
}
char mostrarMenuAdmin() {
	printf("Trabajador>Administrador de cuentas>\n"
			"MENU PRINCIPAL\n"
			"1.\tAñadir Cuenta\n"
			"2.\tEliminar Cuenta\n"
			"3.\tMovimiento de saldo\n"
			"4.\tMostrar datos de un cuenta\n"
			"5.\tMostrar todas las cuentas\n\n"
			"6.\tSalir\n\n"
			"Introduzca numero de la funcion deseada:\n");
	fflush(stdout);
	char resultado;
	resultado = getchar();
	fflush(stdin);
	if(resultado==1 || resultado)
	return resultado;
}
char mostrarMenuDirector() {
	printf("Trabajador>Director>\n"
			"MENU PRINCIPAL\n"
			"1.\tConceder Prestamo\n"
			"2.\tSalir\n\n"
			"Introduzca numero de la funcion deseada:\n");
	fflush(stdout);
	char resultado;
	resultado = getchar();
	fflush(stdin);
	return resultado;
}

void mostrarCuenta(Cuenta* n) {
	printf("DNI del titular de la Cuenta: %s\n", n->getNumeroId());
	fflush(stdout);
	printf("Nombre del titular de la Cuenta: %s\n", n->getNombre());
	fflush(stdout);
	printf("Numero de la cuenta: %i\n", n->getID());
	fflush(stdout);
	printf("Cantidad de saldo: %i\n", n->getLiquidacion());
	fflush(stdout);
}

int ejecutarComandoBD(char * statement) {
	int devolver;
	int rc;

	sqlite3* db;
	rc = sqlite3_open("Cuentas.s3db", &db);

	if (rc) {
		//cambiar stderr por stdout para mostrar por consola
		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
		exit(0);
	} else {
		fprintf(stdout, "Base de datos abierta exitosamente\n");
	}

	char *zErrMsg = 0;
	const char* data = "Callback function called";
	rc = sqlite3_exec(db, statement, callback, (void*) data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		fflush(stdout);
		sqlite3_free(zErrMsg);
		devolver = 1;
	} else {
		fprintf(stdout, "Operacion correcta\n");
		devolver = 0;

	}
	cerrarBD(db);
	return devolver;

}

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
void crearCuenta(int cuenta, list<Cuenta*>* cu) {

		cu->push_back(nuevaCuenta());
		almacenarEnBD(cu);
}
Cuenta* nuevaCuenta() {

	Cuenta* n = new Cuenta();
	printf("Introduce el nombre titular de la cuenta: \n");
	fflush(stdout);
	char* titulo;
	cin >> titulo;
	cout << endl;
	n->setNombre(titulo);
	//////nombre//////
	printf("Introduce DNI titular de la cuenta: \n");
	fflush(stdout);
	int dni;
	cin >> dni;
	cout << endl;
	n->setID(dni);
	//////dni///////
	printf("Introduce Numero identificativo de la cuenta: \n");
	fflush(stdout);
	int autor;
	cin >> autor;
	cout << endl;
	n->setNumeroId(autor);
	//////ID//////
	printf("Introduce la contraseña de la cuenta: \n");
	fflush(stdout);
	char* desc;
	cin >> desc;
	cout << endl;
	n->setContrasena(desc);
	//////contraseña///////
	printf("Introduce la liquidez de la cuenta: \n");
	fflush(stdout);
	int l;
	cin >> l;
	cout << endl;
	n->setLiquidacion(l);
	///////liquidez////////
	printf("Introduce la deuda de la cuenta: \n");
	fflush(stdout);
	int de;
	cin >> de;
	cout << endl;
	n->setDe(de);
	///////deudas////////
	return n;
}

void cerrarBD(sqlite3* db) {
	sqlite3_close(db);
}

void ejecutarComando(char * statement) {
	int rc;

	sqlite3* db;
	//rc = sqlite3_open("xmlbd.s3db", &db);
	rc = sqlite3_open("Cuentas.db", &db);

	if (rc) {
		//cambiar stderr por stdout para mostrar por consola
		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
		exit(0);
	} else {
		fprintf(stdout, "Base de datos abierta exitosamente\n");
	}

	char *zErrMsg = 0;
	const char* data = "Callback function called";
	rc = sqlite3_exec(db, statement, callback, (void*) data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		fflush(stdout);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Operacion correcta\n");

	}
	sqlite3_close(db);
}

Cuenta* get(list<Cuenta*>* _list, int _i) {
	list<Cuenta*>::iterator it = _list->begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}
void almacenarCuentaBD(Cuenta* c) {
	sqlite3* db;
	int rc;
	char *zErrMsg = 0;
	//conectarBD();

	rc = sqlite3_open("Cuentas.s3db", &db);

	if (rc) {
		//cambiar stderr por stdout para mostrar por consola
		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
		exit(0);
	} else {
		fprintf(stdout, "Base de datos abierta exitosamente\n");
	}

	int Number = c->getLiquidacion();//number to convert int a string
	string Result;//string which will contain the result

	stringstream convert; // stringstream used for the conversion

	convert << Number;//add the value of Number to the characters in the stream

	Result = convert.str();//set Result to the content of the stream

	int Number1 = c->getNumeroId();//number to convert int a string
	string Result1;//string which will contain the result

	stringstream convert1; // stringstream used for the conversion

	convert1 << Number1;//add the value of Number to the characters in the stream

	Result1 = convert1.str();//set Result to the content of the stream

	int Number2 = c->getID();//number to convert int a string
	string Result2;//string which will contain the result

	stringstream convert2; // stringstream used for the conversion

	convert2 << Number2;//add the value of Number to the characters in the stream

	Result2 = convert2.str();//set Result to the content of the stream

	string sql = "";
//	string sql2 = "INSERT INTO CUENTAS (N_IDENT,NOMBRE,CONTRA,ID_CUENTA_SUELDO)VALUES ('" + c.getNumeroId()
//			+ "', 'Lector Rss C++/src/" + nombreRSS + ".xml');";
	string sql2 = "INSERT INTO CUENTAS (N_IDENT,NOMBRE,CONTRA,ID_CUENTA,SUELDO)VALUES ('" + Result1 +
			"','" + c->getNombre() + "','" + c->getContrasena()+ "','" + Result2  + "','" +Result+"');";

	const char *csql2 = sql2.c_str();
	rc = sqlite3_exec(db, csql2, callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stdout, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "XML creado\n");
	}

	cerrarBD(db);
}
void almacenarEnBD(list<Cuenta*>* noticias) {
	sqlite3* db;
	int rc;
	char *zErrMsg = 0;
	//conectarBD();
	rc = sqlite3_open("xmlbd.s3db", &db);
	if (rc) {
		//cambiar stderr por stdout para mostrar por consola
		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
		exit(0);
	} else {
		fprintf(stdout, "Base de datos abierta exitosamente\n");
	}
	string sql = "";
	unsigned int i;

	for (i = 0; i < noticias->size(); i++) {

		Cuenta* c1 = get(noticias, i);
		char* nombre = c1->getNombre();
		char* nIdent = (char*) c1->getNumeroId();

		sql.append("INSERT INTO CUENTAS (N_IDENT,NOMBRE,CONTRASEÑA,SUELDO,DEUDA) VALUES ( ");
		sql.append(nIdent);
		sql.append(", '");
		sql.append(nombre);
		sql.append("', '");
		sql.append(c1->getContrasena());
		sql.append("', ");
		sql.append((char*) c1->getLiquidacion());
		sql.append(", '");
		sql.append((char*)c1->getDe());
		sql.append(");");

	}
	const char *csql = sql.c_str();
	rc = sqlite3_exec(db, csql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Noticias insertadas\n");
	}
	cerrarBD(db);
}

void createTable(){
	sqlite3 *db;
		char *zErrMsg = 0;
		int  rc;
		char *sql;

		const char* data = "Callback function called";


		/* Open database */
		rc = sqlite3_open("Cuentas.s3db", &db);
		if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		}else{
		fprintf(stdout, "Opened database successfully\n");
		}
		/* Create SQL statement */
		sql = "CREATE TABLE CUENTA("  \
		"ID_CUENTA   INT PRIMARY KEY     NOT NULL," \
		"NOMBRE           VARCHAR(20)    NOT NULL," \
		"CONTRASENA       VARCHAR(20)   NOT NULL," \
		"DNI            INT     NOT NULL," \
		"SUELDO        INT," \
		"DEUDAS         INT );";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		}else{
		fprintf(stdout, "Table created successfully\n");
		}
		sqlite3_close(db);

		/* Open database */
		rc = sqlite3_open("Cuentas.s3db", &db);
		if( rc ){
		  fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		}else{
		  fprintf(stderr, "Opened database successfully\n");
		}

		/* Create SQL statement */
		sql = "INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS) "  \
			 "VALUES (1, ' ', '32', 111, 20000, 0); " \
			 "INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS)" \
			 "VALUES (4, 'Mark', '25', 444, 65000, 1000);";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if( rc != SQLITE_OK ){
		  fprintf(stderr, "SQL error: %s\n", zErrMsg);
		  sqlite3_free(zErrMsg);
		}else{
		  fprintf(stdout, "Records created successfully\n");
		}
		sqlite3_close(db);
}
