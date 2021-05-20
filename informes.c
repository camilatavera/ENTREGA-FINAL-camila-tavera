/*
 * informes.c
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */


#include "informes.h"


int SubMenuInformes(int opcion, contribuyente *aContribuyente, int lenContribuyente,
							recaudacion *aRecaudacion, int lenRecaudacion){

	int ret=-1;
	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){
		ret=0;


		switch(opcion){
		case 1:
			maxContribuyenteRefinanciar(aRecaudacion, lenContribuyente, aContribuyente, lenContribuyente);
			break;
		case 2:
			ContRecaudacionesMasMil(aRecaudacion, lenContribuyente);
			break;
		case 3:
			listadoPorTipo(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente);
		case 4:
			pagosFebrero(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente);
		}
	}
	return ret;
}


int maxContribuyenteRefinanciar(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;
	int i;
	int cont;
	int mayor=0;
	int flag=1;
	int posMayor;


	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){
		ret=0;

		for(i=0; i<lenContribuyente; i++){
					contRefinanciarXContrib(aRecaudacion, lenRecaudacion, aContribuyente[i].id, &cont);

					if(flag || cont>mayor){
						mayor=cont;;
						posMayor=i;
						flag=0;
					}
				}

				printContribuyente(aContribuyente, lenContribuyente, aContribuyente[posMayor].id);
			}
			return ret;
}


//contador de recaudaciones en estado refinanciar por contribuyente
int contRefinanciarXContrib(recaudacion *list, int len, int idContribuyente, int *contador){

	int ret=-1;
	int i;

	if(list!=NULL && len>0 && contador!=NULL){
		ret=0;
		*contador=0;

		for(i=0; i<len; i++){
			if(list[i].idContribuyente==idContribuyente && list[i].isEmpty==0 &&
					list[i].estado==REFINANCIAR){
					(*contador)++;
			}
		}
	}
	return ret;
}


int ContRecaudacionesMasMil(recaudacion *list, int len){

	int ret=-1;
	int i;
	int cont=0;

	if(list!=NULL && len>0){
		ret=0;

		for(i=0; i<len; i++){
			if(list[i].isEmpty==0 && list[i].estado==SALDADA && list[i].importe>=1000){
				cont++;
			}
		}
		printf("La Cantidad de recaudaciones en estado saldado es %d \n", cont);
	}
		return ret;
}

int listadoPorTipo(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;
	int opcionIngresada;
	int i;

	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){
		ret=0;

		listadoTiposRecaudaciones();
		getNumero(&opcionIngresada, "Ingrese la opcion\n", "Error", 1, 3, 20);

		switch(opcionIngresada){
		case 1:
			for(i=0; i<lenRecaudacion; i++){
				if(aRecaudacion[i].isEmpty==0 && aRecaudacion[i].tipo==1){
					printContribuyente(aContribuyente, lenRecaudacion, aRecaudacion[i].idContribuyente);
				}
			}
			break;

		case 2:
		for(i=0; i<lenRecaudacion; i++){
						if(aRecaudacion[i].isEmpty==0 && aRecaudacion[i].tipo==2){
							printContribuyente(aContribuyente, lenRecaudacion, aRecaudacion[i].idContribuyente);
						}
					}
					break;

		case 3:
			for(i=0; i<lenRecaudacion; i++){
				if(aRecaudacion[i].isEmpty==0 && aRecaudacion[i].tipo==3){
						printContribuyente(aContribuyente, lenRecaudacion, aRecaudacion[i].idContribuyente);
					}
				}
						break;

		}

	}
	return ret;
}

int pagosFebrero(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;

	int i;

	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){
		ret=0;

		for(i=0; i<lenRecaudacion; i++){
			if(aRecaudacion[i].isEmpty==0 && aRecaudacion[i].mes==2){
				printContribuyente(aContribuyente, lenContribuyente, aRecaudacion[i].idContribuyente);
			}
		}
	}
		return ret;
}



