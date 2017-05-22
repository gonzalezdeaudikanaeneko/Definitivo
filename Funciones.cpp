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
#include <iostream>
#include <string>
#include <fstream>
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
char mostrarMenuTrabajador() {
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
			//"4.\tMostrar datos de un cuenta\n"
			"4.\tSalir\n\n"
			"Introduzca numero de la funcion deseada:\n");
	fflush(stdout);
	char resultado;
	resultado = getchar();
	fflush(stdin);
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
	printf("ID de la Cuenta: %i\n", n->getID());
	fflush(stdout);
	printf("DNI del titular de la Cuenta: %i\n", n->getNumeroId());
	fflush(stdout);
	printf("Nombre del titular de la Cuenta: %s\n", n->getNombre());
	fflush(stdout);
	printf("Contraseña de la cuenta: %s\n", n->getContrasena());
	fflush(stdout);
	printf("Cantidad de saldo: %i\n", n->getLiquidacion());
	fflush(stdout);
	printf("Deudas de la Cuenta: %i\n", n->getDe());
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
void almacenarEnBD(list<Cuenta*>* cu) {
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
	string sql = "";
	unsigned int i;

	for (i = 0; i < cu->size(); i++) {

		Cuenta* c1 = get(cu, i);
		char* nombre = c1->getNombre();
		char* nIdent = (char*) c1->getNumeroId();

		sql.append(
				"INSERT INTO CUENTAS (N_IDENT,NOMBRE,CONTRASEÑA,SUELDO,DEUDA) VALUES ( ");
		sql.append(nIdent);
		sql.append(", '");
		sql.append(nombre);
		sql.append("', '");
		sql.append(c1->getContrasena());
		sql.append("', ");
		sql.append((char*) c1->getLiquidacion());
		sql.append(", '");
		sql.append((char*) c1->getDe());
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

void createTable() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;

	const char* data = "Callback function called";

	/* Open database */
	rc = sqlite3_open("Cuentas.s3db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	} else {
		fprintf(stdout, "Opened database successfully\n");
	}
	/* Create SQL statement */
	sql = "CREATE TABLE CUENTA("
			"ID_CUENTA   INT PRIMARY KEY     NOT NULL,"
			"NOMBRE           VARCHAR(20)    NOT NULL,"
			"CONTRASENA       VARCHAR(20)   NOT NULL,"
			"DNI            INT     NOT NULL,"
			"SUELDO        INT,"
			"DEUDAS         INT );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);

	/* Open database */
	rc = sqlite3_open("Cuentas.s3db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	} else {
		fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS) "
			"VALUES (1, 'Peter ', '32', 111, 20000, 0); "
			"INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS)"
			"VALUES (4, 'Mark', '25', 444, 65000, 1000);";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
}
Cuenta* getTableDataNoticia(char* query) {
	sqlite3_stmt *statement;
	sqlite3* db;
	int rc;
	Cuenta* n = new Cuenta();
	const char* csql22;
	char* csql33;
	rc = sqlite3_open("Cuentas.s3db", &db);

	if (rc) {
		//cambiar stderr por stdout para mostrar por consola
		fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
		exit(0);
	} else {
		fprintf(stdout, "Base de datos abierta exitosamente\n");
	}

	if (sqlite3_prepare(db, query, -1, &statement, 0) == SQLITE_OK) {
		int ctotal = sqlite3_column_count(statement);
		int res = 0;

		while (1) {
			res = sqlite3_step(statement);

			if (res == SQLITE_ROW) {

				for (int i = 0; i < ctotal; i++) {

					string s = (char*) sqlite3_column_text(statement, i);
					// print or format the output as you want

					switch (i) {
					case 0:
						n->setID(atoi(s.c_str()));
						break;
					case 1:
						csql22 = s.c_str();
						csql33 = (char*) csql22;
						n->setNombre(csql33);
						break;
					case 2:
						csql22 = s.c_str();
						csql33 = (char*) csql22;
						n->setContrasena(csql33);
						break;
					case 3:
						n->setNumeroId(atoi(s.c_str()));
						break;
					case 4:
						n->setLiquidacion(atoi(s.c_str()));
						break;
					case 5:
						n->setDe(atoi(s.c_str()));
						break;
					default:
						break;
					}
				}
			}

			if (res == SQLITE_DONE || res == SQLITE_ERROR) {
				cout << "done " << endl;
				break;
			}
		}

	}
	mostrarCuenta(n);
	return n;
}

//void LeerFichero(list<Cuenta*>* cu) {
//	char* aa;
//	const char* aaa;
//	int i, a;
//	cout << "Escriba el nombre del archivo a leer: " << endl;
//	string filename;
//	cin >> filename;
//	ifstream file(filename.c_str());
//	if (!file) {
//		cout << "Error no se puede abrir el archivo: " << filename << endl;
//	}
//	string linea, archivo;
//	string arch;
//
//	Cuenta c;
//	while (getline(file, linea)) {
//
//		i = 0;
//		a = 0;
//		aaa = linea.c_str(); //de string a const char*
//		aa = const_cast<char *>(aaa); //Castea de const char* a char*
//
//		for (i = 0; a != 6; i++) {
//
//			do {
//				do {
//					arch[i] = aa[i];
//					i++;
//				} while (aa[i] != ' ');
//
//				if (a == 0) {	//DNI
//					const char * a = arch.c_str();
//					int l = atoi(a);
//					c.setNumeroId(l);
//					arch = "";
//				}
//				if (a == 1) {	//Nombre
//					char *a = strdup(arch.c_str());	//convierte de string a char*
//					c.setNombre(a);
//					arch = "";
//				}
//				if (a == 2) {		//Contrasenya
//					char *a = strdup(arch.c_str());
//					//char* a = (char*)arch;
//					c.setContrasena(a);
//				}
//				if (a == 3)		//Numero de cuenta
//						{
//					const char * a = arch.c_str();
//					int l = atoi(a);
//					c.setID(l);
//					arch = "";
//				}
//				if (a == 4) {		//Liquidez
//					const char * a = arch.c_str();
//					int l = atoi(a);
//					c.setLiquidacion(l);
//					arch = "";
//				}
//				if (a == 5) {
//					c.setDe(0);
//					arch = "";
//				}
//				a++;
//			} while (a != 6);
//
//			string asd;
//			asd =
//					"INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS) ";
//			asd.append("VALUES (");
//			asd.append((char*) c.getNumeroId());
//			asd.append(", '");
//			asd.append(c.getNombre());
//			asd.append("', '");
//			asd.append(c.getContrasena());
//			asd.append("', ");
//			asd.append((char*) c.getID());
//			asd.append(", ");
//			asd.append((char*) c.getLiquidacion());
//			asd.append(", ");
//			asd.append((char*) c.getDe());
//			asd.append(");");
//
//			const char *csql2 = asd.c_str();
//			char *csql3 = (char*) csql2;
//
//			ejecutarComandoBD(csql3);
//
//		}
//	}
//}
void LeerFichero() {
	char *str;
	string ar, ar1, ar2, ar3, ar4, ar5;
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

	Cuenta *c;
	while (getline(file, linea)) {
		a = 0;
		aaa = linea.c_str(); //de string a const char*
		aa = const_cast<char *>(aaa); //Castea de const char* a char*
		for (i = 0; a != 6; i++) {
			//free(c);
			//Cuenta *c;
			//si no deja pasar a char* la linea
			do {
				do {
					arch[i] = aa[i];
					i++;
				} while (aa[i] != ' ');

				if (a == 0) {	//DNI
					const char * a = arch.c_str();
					int l = atoi(a);
					c->setNumeroId(l);
					ar = arch;
				}
				if (a == 1) {	//Nombre
					char *a = strdup(arch.c_str());	//convierte de string a char*
					c->setNombre(a);
					ar1 = arch;
				}
				if (a == 2) {		//Contrasenya
					char *a = strdup(arch.c_str());
					c->setContrasena(a);
					ar2 = arch;
				}
				if (a == 3)		//Numero de cuenta
						{
					const char * a = arch.c_str();
					int l = atoi(a);
					c->setID(l);
					ar3 = arch;
				}
				if (a == 4) {		//Liquidez
					const char * a = arch.c_str();
					int l = atoi(a);
					c->setLiquidacion(l);
					ar4 = arch;
				}
				if (a == 5) {
					const char * a = arch.c_str();
					int l = atoi(a);
					c->setDe(l);
					ar5 = arch;

					char *a00 = strdup(ar.c_str());
					char *a03 = strdup(ar3.c_str());
					char *a04 = strdup(ar4.c_str());
					char *a05 = strdup(ar5.c_str());

					string asd;
					asd =
							"INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS) ";
					asd.append("VALUES (");
					asd.append(a00);
					asd.append(", '");
					asd.append(ar1);
					asd.append("', '");
					asd.append(ar2);
					asd.append("', ");
					asd.append(a03);
					asd.append(", ");
					asd.append(a04);
					asd.append(", ");
					asd.append(a05);
					asd.append(");");

					const char *csql2 = asd.c_str();
					char *csql3 = (char*) csql2;

					ejecutarComandoBD(csql3);
				}
				a++;
			} while (a <= 5);
		}

	}
}
//void almacenarBD(Cuenta ct[]){
//
//	sqlite3* db;
//		int rc;
//		char *zErrMsg = 0;
//		//conectarBD();
//
//		rc = sqlite3_open("Cuentas.s3db", &db);
//
//		if (rc) {
//			//cambiar stderr por stdout para mostrar por consola
//			fprintf(stdout, "Error al abrir BD: %s\n", sqlite3_errmsg(db));
//			exit(0);
//		} else {
//			fprintf(stdout, "Base de datos abierta exitosamente\n");
//		}
//
//
//		string sql = "";
//		string sql2 = "INSERT INTO XML (NOM_XML, RUTA)VALUES ('" + nombreRSS
//				+ "', 'Lector Rss C++/src/" + nombreRSS + ".xml');";
//
////		const char *csql2 = sql2.c_str();
////		rc = sqlite3_exec(db, csql2, callback, 0, &zErrMsg);
////
////		if (rc != SQLITE_OK) {
////			fprintf(stdout, "SQL error: %s\n", zErrMsg);
////			sqlite3_free(zErrMsg);
////		} else {
////			fprintf(stdout, "XML creado\n");
////		}
////		int a;
////		a = getTableDataID(
////				(char*) ("SELECT COD_XML FROM XML WHERE NOM_XML LIKE '" + nombreRSS
////						+ "';").c_str());
////
////		unsigned int i;
////
////		string result;
////
////		ostringstream convert;
////
////		convert << a;
////
////		result = convert.str();
//
//		for (i = 0; i < 50; i++) {
//
//			sql += "INSERT INTO NOTICIA (TITULO,AUTOR,DESC, COD_XML)VALUES ( '"
//					+ get(noticias, i)->getTitulo() + "', '"
//					+ get(noticias, i)->getAutor() + "', '"
//					+ get(noticias, i)->getDescripcion() + "'," + result + ");";
//		}
//		const char *csql = sql.c_str();
//		rc = sqlite3_exec(db, csql, callback, 0, &zErrMsg);
//		if (rc != SQLITE_OK) {
//			fprintf(stderr, "SQL error: %s\n", zErrMsg);
//			sqlite3_free(zErrMsg);
//		} else {
//			fprintf(stdout, "Noticias insertadas\n");
//		}
//		cerrarBD(db);
//
//}
