/*
 * informes.h
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "contribuyente.h"


int SubMenuInformes(int opcion, contribuyente *aContribuyente, int lenContribuyente,
							recaudacion *aRecaudacion, int lenRecaudacion);

int maxContribuyenteRefinanciar(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente);

int contRefinanciarXContrib(recaudacion *list, int len, int idContribuyente, int *contador);

int ContRecaudacionesMasMil(recaudacion *list, int len);

int pagosFebrero(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente);

int listadoPorTipo(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente);




#endif /* INFORMES_H_ */
