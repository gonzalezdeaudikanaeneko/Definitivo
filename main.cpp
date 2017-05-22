/*
 * main.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

#include "Cuenta.h"
#include "Usuario.h"
#include "Trabajador.h"
#include "Director.h"
#include "Funciones.h"
#include "sqlite3.h"
#include "AdministradorCuentas.h"

#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <list>
#include <sstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <list>
#include <typeinfo>

using namespace std;

int main(void) {

	Cuenta ct[20];
	createTable();
	char funcMenu, menuT, menuA, menuD, menuC;
	bool repetir;
	char nombre[20], nombre1[20], nombre2[20];
	string statement, statement2;
	string result;
	char *csql3, *csql33;
	const char *csql2, *csql22;
	char nom[20];
	char nom1[30];
	char nom2[20];
	char nom3[30];
	fflush(stdin);

	LeerFichero();

	do { //
		fflush(stdin);
		repetir = true;
		funcMenu = mostrarMenu();
		switch (funcMenu) {
		case '1':
			menuT = mostrarMenuTrabajador();
			switch (menuT) {
			case '1': {
				menuD = mostrarMenuDirector();
				if (menuD == '1') {

					printf("Introduce el ID de la Cuenta: \n");
					fflush(stdout);
					scanf("%s", nom);
					printf("Introduce el importe del prestamo: \n");
					fflush(stdout);
					scanf("%s", nom1);

					statement =
							"UPDATE CUENTA SET SUELDO = (SELECT SUELDO FROM CUENTA WHERE ID_CUENTA = ";
					statement.append(nom);
					statement.append(")+");
					statement.append(nom1);
					statement.append(" WHERE ID_CUENTA = ");
					statement.append(nom);
					statement.append(";");

					csql2 = statement.c_str();
					csql3 = (char*) csql2;

					statement2 =
							"UPDATE CUENTA SET DEUDAS = (SELECT DEUDAS FROM CUENTA WHERE ID_CUENTA = ";
					statement2.append(nom);
					statement2.append(") + ");
					statement2.append(nom1);
					statement2.append("+");
					statement2.append(nom1);
					statement2.append("/10 WHERE ID_CUENTA = ");
					statement2.append(nom);
					statement2.append(";");

					csql22 = statement2.c_str();
					csql33 = (char*) csql22;

					ejecutarComandoBD(csql3);
					ejecutarComandoBD(csql33);

				}
			}
				break;
			case '2':
				menuA = mostrarMenuAdmin();
				switch (menuA) {
				case '1': { //Añadir cuenta

					printf("Introduce Nombre de la Cuenta: \n");
					fflush(stdout);
					scanf("%s", nom);
					printf("Introduce Contraseña de la Cuenta: \n");
					fflush(stdout);
					scanf("%s", nom1);
					printf("Introduce ID cuenta de la Cuenta: \n");
					fflush(stdout);
					scanf("%s", nom2);
					printf("Introduce DNI de la Cuenta: \n");
					fflush(stdout);
					scanf("%s", nom3);

					string asd;
					asd =
							"INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS) ";
					asd.append("VALUES (");
					asd.append(nom2);
					asd.append(", '");
					asd.append(nom);
					asd.append("', '");
					asd.append(nom1);
					asd.append("', ");
					asd.append(nom3);
					asd.append(", 0, 0);");

					const char *csql2 = asd.c_str();
					char *csql3 = (char*) csql2;

					ejecutarComandoBD(csql3);

				}
					break;
				case '2': { //Eliminar cuenta
					printf("Introduce ID de la Cuenta: \n");
					fflush(stdout);
					scanf("%s", nombre);
					statement = "DELETE FROM CUENTA WHERE ID_CUENTA =";
					statement.append(nombre);
					statement.append(";");
					csql2 = statement.c_str();
					csql3 = (char*) csql2;
					ejecutarComandoBD(csql3);
					printf("\n");
				}
					break;
				case '3': //mover saldo
					//b.transaccion(CB, 123, 123, 350);
					printf("Introduce ID de la Cuenta 1: \n");
					fflush(stdout);
					scanf("%s", nombre);
					printf("Introduce ID de la Cuenta 2: \n");
					fflush(stdout);
					scanf("%s", nombre1);
					printf("Introduce el total: \n");
					fflush(stdout);
					scanf("%s", nombre2);

					statement =	"UPDATE CUENTA SET SUELDO = (SELECT SUELDO FROM CUENTA WHERE ID_CUENTA = ";
					statement.append(nombre);
					statement.append(")-");
					statement.append(nombre2);
					statement.append(" WHERE ID_CUENTA = ");
					statement.append(nombre);
					statement.append(";");

					csql2 = statement.c_str();
					csql3 = (char*) csql2;

					ejecutarComandoBD(csql3);


					statement2 =	"UPDATE CUENTA SET SUELDO = (SELECT SUELDO FROM CUENTA WHERE ID_CUENTA = ";
					statement2.append(nombre1);
					statement2.append(")+");
					statement2.append(nombre2);
					statement2.append(" WHERE ID_CUENTA = ");
					statement2.append(nombre1);
					statement2.append(";");

					csql22 = statement2.c_str();
					csql33 = (char*) csql22;


					ejecutarComandoBD(csql33);

					break;
//				case '4'://MOstra 1
//					printf("Introduce N_IDENT de la Cuenta: \n");
//					fflush(stdout);
//					scanf("%s", nombre);
//					statement = "SELECT * from CUENTAS where N_IDENT=";
//					statement.append(nombre);
//					statement.append(";");
//					csql2 = statement.c_str();
//					csql3 = (char*) csql2;
//					getTableDataNoticia(csql3);
//					printf("\n");
//					break;
				default:
					break;
				}

				break;
			case '3': {
				printf("Saliendo ...");
			}
				break;
			default:
				printf("Opcion incorrecta!\n\n");
				break;
			}

			break;
		case '2': {
			menuC = mostrarMenuCliente();
			switch (menuC) {
			case '1':

				printf("Introduce el ID de la Cuenta: \n");
				fflush(stdout);
				scanf("%s", nom);
				printf("Introduce el importe a introducir: \n");
				fflush(stdout);
				scanf("%s", nom1);
				statement =
						"UPDATE CUENTA SET SUELDO = (SELECT SUELDO FROM CUENTA WHERE ID_CUENTA = ";
				statement.append(nom);
				statement.append(")+");
				statement.append(nom1);
				statement.append(" WHERE ID_CUENTA = ");
				statement.append(nom);
				statement.append(";");

				csql2 = statement.c_str();
				csql3 = (char*) csql2;

				ejecutarComandoBD(csql3);
				break;
			case '2':
				//sacar dinero;

				printf("Introduce el ID de la Cuenta: \n");
				fflush(stdout);
				scanf("%s", nom);
				printf("Introduce el importe a sacar: \n");
				fflush(stdout);
				scanf("%s", nom1);
				statement =
						"UPDATE CUENTA SET SUELDO = (SELECT SUELDO FROM CUENTA WHERE ID_CUENTA = ";
				statement.append(nom);
				statement.append(")-");
				statement.append(nom1);
				statement.append(" WHERE ID_CUENTA = ");
				statement.append(nom);
				statement.append(";");

				csql2 = statement.c_str();
				csql3 = (char*) csql2;

				ejecutarComandoBD(csql3);
				break;
			default:
				break;
			}
		}
			break;
		case '3': {
			printf("Saliendo del programa...\n\n");
			repetir = false;
		}
			break;
		default:
			printf("Opcion incorrecta!\n\n");
			break;
		}
	} while (repetir);

	return 0;
}

