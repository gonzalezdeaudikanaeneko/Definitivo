/*
 * Usuario.cpp
 *
 *  Created on: 17 de may. de 2017
 *      Author: Eneko
 */

#include "Usuario.h"
#include <iostream>
#include "string.h"
using namespace std;

Usuario::Usuario() {
	// TODO Auto-generated constructor stub

}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

void ingresarDinero(int dinero, Cuenta *c)
{
	c->setLiquidacion(c->getLiquidacion()+dinero);
}

void sacarDinero(int dinero, Cuenta *c)
{
	if(c->getLiquidacion() - dinero < 0){
		cout << "No tienes suficiente dinero en la cuenta :-(\n";
		//printf("No tienes suficiente dinero en la cuenta :-(\n");
	}else{
		c->setLiquidacion(c->getLiquidacion() - dinero);
	}
}

char* Usuario::getNombre(){
	return nombre;
}
char* Usuario::getContrasena(){
	return direccion;
}
void Usuario::setDNI(char* a){
	this->DNI = a;
}
void Usuario::setNombre(char* a){
	this->nombre=a;
}
void Usuario::setContrasena(char* a){
	this->direccion=a;
}
