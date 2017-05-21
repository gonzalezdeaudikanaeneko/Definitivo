/*
 * Director.h
 *
 *  Created on: 18 de may. de 2017
 *      Author: Txus
 */

#ifndef DIRECTOR_H_
#define DIRECTOR_H_
#include "Trabajador.h"

class Director : public Trabajador
{
public:

	Director();
	virtual ~Director();
	void concederPrestamo();
};

#endif /* DIRECTOR_H_ */
