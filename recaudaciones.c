/*
 * recaudaciones.c
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#include "recaudaciones.h"


int listadoTiposRecaudaciones(void){
	int ret=-1;
	printf("1. ARBA   2.IIBB  3.GANANCIAS\n");
	ret=0;
	return ret;
}



int recaudacionIsEmpty(recaudacion *list, int len){

	int ret=-1;
	if(list!=NULL && len>0){
		ret=1;

		for(int i=0; i<len; i++){
			if(list[i].isEmpty==0){
				ret=0;
				break;
			}
		}
	}
	return ret;
}

int hayRecaudacionActiva(recaudacion *list, int len){

	int ret=-1;
	if(list!=NULL && len>0){
		ret=0;

		for(int i=0; i<len; i++){
			if(list[i].isEmpty==0 && list[i].estado==ACTIVA){
				ret=1;
				break;
			}
		}
	}
	return ret;
}


int hayRecaudacionesNoSaldadas(recaudacion *list, int len){

	int ret=-1;
	if(list!=NULL && len>0){
		ret=0;

		for(int i=0; i<len; i++){
			if(list[i].isEmpty==0 && (list[i].estado==ACTIVA || list[i].estado==REFINANCIAR)){
				ret=1;
				break;
			}
		}
	}
	return ret;
}



int initRecaudaciones(recaudacion* list, int len){
	int ret=-1;
	int i;

	if(list!=NULL && len>0){
		for(i=0; i<len; i++){
			list[i].isEmpty=1;
		}
		ret=0;
	}
	return ret;
}



int buscarLibreRecaudacion(recaudacion *array, int leng, int *posicionLibre){
	int i;
	int ret=-1;

	if(array!=NULL && leng>0){
		for(i=0; i<leng; i++){
				if(array[i].isEmpty==1){
					*posicionLibre=i;
					ret=0;
					break;
				}
		}
	}
	return ret;
}


int ingresarValoresRecaudacion(recaudacion *bufferAviso, contribuyente *list, int len){

	int ret=-1;
	recaudacion auxAviso;


	if(bufferAviso!=NULL && list!=NULL && len>0){

		if(getIdContribuyenteValido(list, len, &auxAviso.idContribuyente, "Ingrese el id del contribuyente\n",
				"Error. ", 15)==0 &&

			getNumero(&auxAviso.mes, "Ingrese el numero del mes, de 1 a 12: \n",
					"Error. ", 1, 12, 20)==0 &&

			getNumero(&auxAviso.importe, "Ingrese el importe\n", "Error", 0, 1000000,25)==0 &&

			listadoTiposRecaudaciones()==0 &&
			getNumero(&auxAviso.tipo, "Ingrese el tipo de recaudacion\n", "Error. ",
					1, 3, 20)==0 ){

					*bufferAviso=auxAviso;
					ret=0;
			}
	}
	return ret;
}




int addRecaudacion(recaudacion* aRecaudacion, int lenRecaudacion, contribuyente* aContribuyente,
		int lenContribuyente, int idRecaudacion){

	int ret=-1;
	int posicion;

	recaudacion bufferRec;


	if(aRecaudacion!=NULL && lenRecaudacion>0 && aContribuyente!=NULL && lenContribuyente>0){

		if(buscarLibreRecaudacion(aRecaudacion, lenRecaudacion, &posicion)==0 &&
			ingresarValoresRecaudacion(&bufferRec, aContribuyente, lenContribuyente)==0){

			aRecaudacion[posicion]=bufferRec;
			aRecaudacion[posicion].idRecaudacion=idRecaudacion;
			aRecaudacion[posicion].estado=ACTIVA;
			aRecaudacion[posicion].isEmpty=0;
			ret=0;
		}
	}
	return ret;
}


int printIdRecaudaciones(int id){
	int ret=-1;
	printf("El id de la recaudacion es %d \n", id);
	ret=0;
	return ret;
}


int bajaRecaudacionByIdContribuyente(recaudacion *list, int len, int idContribuyente){

	int ret=-1;

	if(list!=NULL && len>0){

		for(int i=0; i<len; i++){

			if(list[i].isEmpty==0 && list[i].idContribuyente==idContribuyente){
				list[i].isEmpty=1;
				ret=0;
			}
		}
	}
	return ret;
}

int listarRecaudacionesDeUnContribuyente(recaudacion *list, int len, int idContribuyente){

	int ret=-1;
	int i;
	char descTipo[LEN_STR];
	char descMes[LEN_STR];
	char descEstado[LEN_STR];

	if(list!=NULL && len>0){
		ret=0;
		printf("Id Recaudacion       Mes        Tipo         Estado       \n");

		for(i=0; i<len; i++){
			if(list[i].isEmpty==0 && list[i].idContribuyente==idContribuyente){

				if(getDescripcionTipo(list[i].tipo, descTipo, LEN_STR)==0 &&
				getMes(list[i].mes, descMes, LEN_STR)==0 &&
				getDescEstadoRec(list[i].estado, descEstado, LEN_STR)==0){

					printf("%-18d %-10s %-12s %s\n", list[i].idRecaudacion, descMes, descTipo, descEstado);
				}
			}
		}
	}
	return ret;
}


int getDescripcionTipo(int nTipo, char *desc, int len){


	int ret=-1;
	if(desc!=NULL && len>0 && nTipo>=1 && nTipo<=12){
		ret=0;

		switch(nTipo){
		case 1:
			strncpy(desc, "ARBA", len);
			break;
		case 2:
			strncpy(desc, "IIBB", len);
			break;
		case 3:
			strncpy(desc, "GANANCIAS", len);
			break;
		}
	}
	return ret;
}






int getMes(int nMes, char *desc, int len){

	int ret=-1;
	if(desc!=NULL && len>0 && nMes>=1 && nMes<=12){
		ret=0;

		switch(nMes){
		case 1:
			strncpy(desc, "Enero", len);
			break;
		case 2:
			strncpy(desc, "Febrero", len);
			break;
		case 3:
			strncpy(desc, "Marzo", len);
			break;
		case 4:
			strncpy(desc, "Abril", len);
			break;
		case 5:
			strncpy(desc, "Mayo", len);
			break;
		case 6:
			strncpy(desc, "Junio", len);
			break;
		case 7:
			strncpy(desc, "Julio", len);
			break;
		case 8:
			strncpy(desc, "Agosto", len);
			break;
		case 9:
			strncpy(desc, "Septiembre", len);
			break;
		case 10:
			strncpy(desc, "Octubre", len);
			break;
		case 11:
			strncpy(desc, "Noviembre", len);
			break;
		case 12:
			strncpy(desc, "Diciembre", len);
			break;
		}
	}
	return ret;
}



int getDescEstadoRec(int estado, char *desc, int len){

	int ret=-1;
	if(estado>=-1 && estado<=1 && desc!=NULL && len>0){


		ret=0;
		switch(estado){
		case SALDADA:
			strncpy(desc, "SALDADA", len);
			break;
		case ACTIVA:
			strncpy(desc, "ACTIVA", len);
			break;
		case REFINANCIAR:
			strncpy(desc, "REFINANCIAR", len);
			break;
		}
	}
	return ret;
}

int getIdRecaudacionActiva(recaudacion *list, int len, int* pResultado, char* mensaje,
		char* mensajeError,	int reintentos){

	 int ret=-1;
	 int bufferInt;
	 int i;
	 int flag=1;

	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
		 while(reintentos>=0 && flag){
			 reintentos--;
			 printf("%s", mensaje);

			 if(getInt(&bufferInt)==0){

				 for(i=0; i<len; i++){
					 if(list[i].idRecaudacion==bufferInt && list[i].isEmpty==0 &&
						list[i].estado==ACTIVA){

						 *pResultado = bufferInt;
						  ret=0;
						  flag=0;
						  break;
					 }
				 }
					if(flag){
						 fflush(stdin);
						 printf("%s", mensajeError);
					 }
				 }
			 }
		 }

	 return ret;
}


int getIdRecaudacion_noSaldada(recaudacion *list, int len, int* pResultado, char* mensaje,
		char* mensajeError,	int reintentos){

	 int ret=-1;
	 int bufferInt;
	 int i;
	 int flag=1;

	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
		 while(reintentos>=0 && flag){
			 reintentos--;
			 printf("%s", mensaje);

			 if(getInt(&bufferInt)==0){

				 for(i=0; i<len; i++){
					 if(list[i].idRecaudacion==bufferInt && list[i].isEmpty==0 &&
						(list[i].estado==ACTIVA || list[i].estado==REFINANCIAR)){

						 *pResultado = bufferInt;
						  ret=0;
						  flag=0;
						  break;
					 }
				 }
					if(flag){
						 fflush(stdin);
						 printf("%s", mensajeError);
					 }
				 }
			 }
		 }

	 return ret;
}



int findRecaudacionById(recaudacion *list, int len, int id, int *posicion){

	int ret=-1;
	int i;
	if(list!=NULL && len>0 && posicion!=NULL){

		for(i=0; i<len; i++){


			if(list[i].isEmpty==0 && list[i].idRecaudacion==id){
				*posicion=i;
				ret=0;
				break;
			}
		}
	}
	return ret;
}





int refinanciarRecaudacion(recaudacion *aRecaudacion, int lenRecaudacion,
							contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;
	int idRecaudacion;
	//int idContribuyente;
	int posRec;
	char seguir;

	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){

			if(getIdRecaudacionActiva(aRecaudacion, lenRecaudacion, &idRecaudacion,
					"Ingrese el id de la recaudacion\n", "Error. ", 15)==0 &&
				findRecaudacionById(aRecaudacion, lenRecaudacion, idRecaudacion, &posRec)==0){

					//idContribuyente=aRecaudacion[posRec].idContribuyente;
					printContribuyente(aContribuyente, lenContribuyente, aRecaudacion[posRec].idContribuyente);

					validarChar(&seguir, "Quiere cambiar el estado a REFINANCIAR? Ingrese 's':si o 'n':no\n", "Error",
													's', 'n', 20);

					if(seguir=='s'){
						aRecaudacion[posRec].estado=REFINANCIAR;
						ret=0;
					}
					else{
						ret=1;
					}
			}
		}
		return ret;
}



int saldarRecaudacion(recaudacion *aRecaudacion, int lenRecaudacion,
					contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;
	int idRecaudacion;
	//int idContribuyente;
	int posRec;
	char seguir;

	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){


			if(getIdRecaudacion_noSaldada(aRecaudacion, lenRecaudacion, &idRecaudacion,
					"Ingrese el id de la recaudacion\n", "Error. ", 15)==0 &&
				findRecaudacionById(aRecaudacion, lenRecaudacion, idRecaudacion, &posRec)==0){

					//idContribuyente=aRecaudacion[posRec].idContribuyente;

					printContribuyente(aContribuyente, lenContribuyente, aRecaudacion[posRec].idContribuyente);

					validarChar(&seguir, "Quiere cambiar el estado a SALDADO? Ingrese 's':si o 'n':no\n", "Error",
													's', 'n', 20);

					if(seguir=='s'){
						aRecaudacion[posRec].estado=SALDADA;
						ret=0;
					}
					else{
						ret=1;
					}
			}
		}
		return ret;
}


//Recaudacion saldadas con sus datos junto + c.u.i.l. y nombre del contribuyente correspondiente.

int listarRecaudacionesSaldadas(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente){

	int ret=-1;
	int i;
	int posContribuyente;
	char descMes[LEN_STR];
	char descTipo[LEN_STR];
	char descEstado[LEN_STR];


	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){


		printf("RECAUDACIONES SALDADAS\n");
		printf("id      Mes       Estado    Tipo      Id Contribuyente  Nombre      Cuil\n");
		ret=0;

		for(i=0; i<lenRecaudacion; i++){
			if(aRecaudacion[i].estado==SALDADA){
				FindConstribuyenteById(aContribuyente, lenContribuyente, aRecaudacion[i].idContribuyente,
						&posContribuyente);

				getMes(aRecaudacion[i].mes, descMes, LEN_STR);
				getDescripcionTipo(aRecaudacion[i].tipo, descTipo, LEN_STR);
				getDescEstadoRec(aRecaudacion[i].estado, descEstado, LEN_STR);



				printf("%-7d %-9s %-9s %-9s %-17d %-11s %-11s\n ", aRecaudacion[i].idRecaudacion,
																descMes, descEstado, descTipo,
																aRecaudacion[i].idContribuyente,
																aContribuyente[posContribuyente].nombre,
																aContribuyente[posContribuyente].cuil);


			}
		}
	}
	return ret;
}




int hayRecaudacionesSaldadas(recaudacion *list, int len){

	int ret=-1;
	if(list!=NULL && len>0){
		ret=0;

		for(int i=0; i<len; i++){
			if(list[i].isEmpty==0 && list[i].estado==SALDADA){
				ret=1;
				break;
			}
		}
	}
	return ret;
}


