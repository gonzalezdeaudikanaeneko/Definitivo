/*
 * Cuenta.cpp
 *
 *  Created on: 15 de may. de 2017
 *      Author: Unai Jauregibeitia
 */

#include "Cuenta.h"
#include <iostream>
#include "string.h"
using namespace std;

Cuenta::Cuenta(const int nIdent, const char *nombre,
		int ID_Cuenta, char* cont) {
	// TODO Auto-generated constructor stub
	this->nIdent = nIdent;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
	this->ID_Cuenta = ID_Cuenta;
	this->liq = 0;
	this->contrasena = cont;
	this->deuda = 0;
}
Cuenta::Cuenta(const int nIdent, const char *nombre,
		int ID_Cuenta, char* cont,int deu) {
	// TODO Auto-generated constructor stub
	this->nIdent = nIdent;
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
	this->ID_Cuenta = ID_Cuenta;
	this->liq = 0;
	this->contrasena = cont;
	this->deuda=deu;
}

Cuenta::Cuenta(const Cuenta &c) {
	// TODO Auto-generated constructor stub
	this->nIdent = c.nIdent;
	this->nombre = new char[strlen(c.nombre) + 1];
	strcpy(this->nombre, c.nombre);
	this->ID_Cuenta = c.ID_Cuenta;
	this->liq = c.liq;
	this->contrasena = new char[strlen(c.contrasena) + 1];
	strcpy(this->contrasena, c.contrasena);
}
Cuenta::Cuenta() {
	// TODO Auto-generated constructor stub
}
Cuenta::~Cuenta() {
	// TODO Auto-generated destructor stub
	//delete[]this->ID_Cuenta;
}
int Cuenta::getNumeroId(){
	return nIdent;
}
int Cuenta::getLiquidacion(){
	return liq;
}
char* Cuenta::getNombre(){
	return nombre;
}
char* Cuenta::getContrasena(){
	return contrasena;
}
int Cuenta::getID(){
	return ID_Cuenta;
}
int Cuenta::getDe(){
	return deuda;
}

void Cuenta::setNumeroId(int a){
	this->nIdent=a;
}
void Cuenta::setLiquidacion(int a){
	this->liq = a;
}
void Cuenta::setNombre(char* a){
	this->nombre = a;
}
void Cuenta::setContrasena(char* a){
	this->contrasena = a;
}
void Cuenta::setID(int a){
	this->ID_Cuenta = a;
}
void Cuenta::setDe(int a){
	this->deuda = a;
}
