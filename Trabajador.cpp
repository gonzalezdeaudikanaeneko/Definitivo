/*
 * Trabajador.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#include "Trabajador.h"
#include <iostream>
#include "string.h"
using namespace std;

Trabajador::Trabajador() {
	// TODO Auto-generated constructor stub

}

Trabajador::~Trabajador() {
	// TODO Auto-generated destructor stub
}

char *nombre;
int edad;
int Id_Trabajador;
char* direccion;

void Trabajador::setNombre(char* a){
	this->nombre=a;
}
void Trabajador::setEdad(int a){
	this->edad=a;
}
void Trabajador::setId(int a){
	this->Id_Trabajador=a;
}
void Trabajador::setdireccion(char* a){
	this->direccion=a;
}
char* Trabajador::getNombre(){
	return nombre;
}
char* Trabajador::getDireccion(){
	return direccion;
}
int Trabajador::getId(){
	return Id_Trabajador;
}
int Trabajador::getEdad(){
	return edad;
}
