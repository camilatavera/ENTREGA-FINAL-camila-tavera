/*
 * menu.c
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */


#include "menu.h"




int listadoMenu(void){
	printf("Menu:\n1. ALTA CONTRIBUYENTE \n2. MODIFICAR DATOS DE CONTRIBUYENTE \n3. BAJA DE CONTRIBUYENTE"
			"\n4. NUEVA RECAUDACION \n5. REFINANCIAR RECAUDACION"
			"\n6. SALDAR RECAUDACION \n7. IMPRIMIR CONTRIBUYENTE \n8. IMPRIMIR RECAUDACIONES SALDADAS"
			"\n9. INFORMES \n10. SALIR"
			);
	return 0;
}

int listadoInformes(void){
	printf("Infomes:\n1. Contribuyentes con más recaudaciones en estado “refinanciar” "
			"\n2. Cantidad de recaudaciones saldadas de importe mayor a 1000:"
			"\n3. Datos de los contribuyente de un tipo de Recaudacion"
			);
	return 0;
}



int menu(int opcionIngresada, contribuyente *aContribuyente, int lenContribuyente,
		int *idIncrementalCont, recaudacion *aRecaudacion, int lenRecaudacion,
		int *idIncrementalRecau){


	int ret=-1;
	int idContribuyente=*idIncrementalCont;
	int idRecaudacion=*idIncrementalRecau;
	int opcionInformes;


	if(aContribuyente!=NULL && lenContribuyente>0 && idIncrementalCont!=NULL &&
		aRecaudacion!=NULL && lenRecaudacion>0 && idIncrementalRecau!=NULL){


		switch(opcionIngresada){
			case 1:
				if(addContribuyente(aContribuyente, lenContribuyente, idContribuyente)==0){
					printIdContribuyente(idContribuyente);
					(*idIncrementalCont)++;
				}
				break;

			case 2:
				if(contribuyenteIsEmpty(aContribuyente, lenContribuyente)==0){
					modificarContribuyente(aContribuyente, lenContribuyente);
				}
				else{
					printf("No hay contribuyentes de alta para modificar\n");
				}
				break;

			case 3:
				if(contribuyenteIsEmpty(aContribuyente, lenContribuyente)==0){
					bajaContribuyente(aContribuyente, lenContribuyente, aRecaudacion, lenRecaudacion);
				}
				else{
					printf("No hay contribuyentes para dar de baja\n");
					}
				break;

			case 4:
				if(contribuyenteIsEmpty(aContribuyente, lenContribuyente)==0 &&
						addRecaudacion(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente,
										idRecaudacion)==0){

						printIdRecaudaciones(idRecaudacion);
						(*idIncrementalRecau)++;
				}
				else{
					printf("Primero debes cargar un contribuyente \n");
				}
				break;
			case 5:
				if(hayRecaudacionActiva(aRecaudacion, lenRecaudacion)){
					refinanciarRecaudacion(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente);
				}
				else{
					printf("No hay recaudaciones activas \n");
				}
				break;

			case 6:
				if(hayRecaudacionesNoSaldadas(aRecaudacion, lenRecaudacion)){
					saldarRecaudacion(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente);
				}
				else{
					printf("No hay recaudaciones para saldar \n");
				}
				break;

			case 7:
				if(contribuyenteIsEmpty(aContribuyente, lenContribuyente)==0){
					listarContrib_Recaud(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente);
				}
				else{
					printf("Primero debes cargar un contribuyente \n");
				}
				break;
			case 8:
				//recaudaciones
				if(hayRecaudacionesSaldadas(aRecaudacion, lenRecaudacion)){
					listarRecaudacionesSaldadas(aRecaudacion, lenRecaudacion, aContribuyente, lenContribuyente);
				}
				else{
					printf("No hay recaudaciones saldadas\n");
				}
				break;

			case 9:
				listadoInformes();
				if(getNumero(&opcionInformes, "Ingrese la opcion de informe\n", "Error", 1, 4, 20)==0){
						SubMenuInformes(opcionInformes, aContribuyente, lenContribuyente, aRecaudacion, lenRecaudacion);
				}

			}//cierro switch
		ret=0;
	}
	return ret;
}
