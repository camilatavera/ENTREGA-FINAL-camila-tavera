/*
 * menu.h
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#ifndef MENU_H_
#define MENU_H_

#include "contribuyente.h"
#include "informes.h"


int menu(int opcionIngresada, contribuyente *aContribuyente, int lenContribuyente,
		int *idIncrementalCont, recaudacion *aRecaudacion, int lenRecaudacion,
		int *idIncrementalRecau);

int listadoMenu(void);


#endif /* MENU_H_ */
