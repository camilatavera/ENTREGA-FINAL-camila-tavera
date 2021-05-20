/*
 * contribuyente.c
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */


#include "contribuyente.h"
int initContribuyente(contribuyente* list, int len){
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




int buscarLibreContribuyente(contribuyente *array, int leng, int *posicionLibre){
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

int ingresarValoresContribuyente(contribuyente *bufferContribuyente){

	int ret=-1;
	char auxStr[LEN_STR];
	contribuyente aux;

	if(bufferContribuyente!=NULL){


		if(utn_getString(auxStr, LEN_STR, "Ingrese el nombre\n", "Error. ", 20)==0){
			auxStr[0]=toupper(auxStr[0]);
			strncpy(aux.nombre, auxStr, LEN_STR);
		}

		if(utn_getString(auxStr, LEN_STR, "Ingrese el apellido\n", "Error. ", 20)==0){
			auxStr[0]=toupper(auxStr[0]);
			strncpy(aux.apellido, auxStr, LEN_STR);
		}

		if(getCuil(aux.cuil, LEN_STR, "Ingrese el cuil XX-XXXXXXXX-X\n", "Error. ", 20)==0){
			*bufferContribuyente=aux;
			ret=0;
		}

		}

	return ret;
}




int addContribuyente(contribuyente* list, int len, int id){

	int ret=-1;
	int posicion;
	contribuyente bufferContribuyente;

	if(list!=NULL && len>0){

		if(buscarLibreContribuyente(list, len, &posicion)==0 &&
				ingresarValoresContribuyente(&bufferContribuyente)==0){

			list[posicion]=bufferContribuyente;

			list[posicion].id=id;

			list[posicion].isEmpty=0;

			ret=0;
		}
	}
	return ret;
}

int printIdContribuyente(int id){
	int ret=-1;
	printf("El id del contribuyente es %d\n", id);
	ret=0;
	return ret;
}

int listarContribuyentes(contribuyente *list, int len){

	int ret=-1;
	int i;
	if(list!=NULL && len>0){
		printf("Nombre         Apellido       Cuil            Id\n");
		ret=0;

		for(i=0; i<len; i++){
			if(list[i].isEmpty==0){
				printf("%-10s    %-10s    %-10s     %d\n",  list[i].nombre,
															list[i].apellido,
															list[i].cuil,
															list[i].id);

			}
		}
	}
	return ret;
}

int printContribuyente(contribuyente *list, int len, int idContribuyente){

	int ret=-1;
	int pos;
	if(list!=NULL && len>0){
		if(FindConstribuyenteById(list, len, idContribuyente, &pos)==0){
		printf("Nombre         Apellido       Cuil            Id\n");

				printf("%-10s    %-10s    %-10s     %d\n",  list[pos].nombre,
															list[pos].apellido,
															list[pos].cuil,
															list[pos].id);

			}
	}
	return ret;
}

int getIdContribuyenteValido(contribuyente *list, int len, int* pResultado, char* mensaje,
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
					 if(list[i].id==bufferInt && list[i].isEmpty==0){

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




int FindConstribuyenteById(contribuyente *list, int len, int id, int *posicion){

	int ret=-1;
	int i;
	if(list!=NULL && len>0 && posicion!=NULL){
		ret=1;
		for(i=0; i<len; i++){

			if(list[i].isEmpty==1){
				continue;
			}
			if(list[i].id==id){
				*posicion=i;
				ret=0;
				break;
			}
		}
	}
	return ret;
}


int modificarContribuyente(contribuyente *list, int len){
	int ret=-1;
	int id;
	int opcion;
	int pos;
	char auxStr[LEN_STR];

	if(list!=NULL && len>0){

		ret=0;
		listarContribuyentes(list, len);

		if(getIdContribuyenteValido(list, len, &id, "Ingrese el id del contribuyente\n",
				"Error. ", 25)==0 &&
				FindConstribuyenteById(list, len, id, &pos)==0){

			getNumero(&opcion, "Ingrese el numero de lo que quiera modificar\n1. Nombre\n"
					"2. Apellido\n3. Cuil\n", "Error. ", 1, 3, 20);


			switch(opcion){
			case 1:
				if(utn_getString(auxStr, LEN_STR, "Ingrese el nuevo nombre\n",
						"Error. ", 20)==0){
					auxStr[0]=toupper(auxStr[0]);
					strncpy(list[pos].nombre, auxStr, sizeof(list[pos].nombre));
				}
				break;

			case 2:
				if(utn_getString(auxStr, LEN_STR, "Ingrese el nuevo apellido\n",
						"Error. ", 20)==0){
					auxStr[0]=toupper(auxStr[0]);
					strncpy(list[pos].apellido, auxStr, sizeof(list[pos].apellido));
				}
				break;

			case 3:
				if(getCuil(auxStr, LEN_STR, "Ingrese el nuevo cuil XX-XXXXXXXX-X\n", "Error. ", 15)==0){

					strncpy(list[pos].cuil, auxStr, sizeof(list[pos].cuil));
				}
				}
			}
	}
	return ret;
}


int contribuyenteIsEmpty(contribuyente *list, int len){

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



int bajaContribuyente(contribuyente *aContribuyente, int lenContribuyente,
						recaudacion *aRecaudacion, int lenRecaudacion){

	int ret=-1;
	int idContribuyente;
	int posContribuyente;
	char seguir;

	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){

		if(getIdContribuyenteValido(aContribuyente, lenContribuyente, &idContribuyente,
					"Ingrese el id del contribuyente\n", "Error. ", 25)==0){

			FindConstribuyenteById(aContribuyente, lenContribuyente, idContribuyente, &posContribuyente);

			listarRecaudacionesDeUnContribuyente(aRecaudacion, lenRecaudacion, idContribuyente);

			validarChar(&seguir, "Quiere eliminar? Ingrese 's':si o 'n':no\n", "Error",
								's', 'n', 20);

				if(seguir=='s'){
					aContribuyente[posContribuyente].isEmpty=1;
					if(bajaRecaudacionByIdContribuyente(aRecaudacion, lenRecaudacion,
							idContribuyente)==0){
					ret=0;
					}
				}
				else{
					ret=1;
				}

	}
	}
	return ret;
}


//lista de contribuyente con sus recaudaciones
int listarContrib_Recaud(recaudacion *aRecaudacion, int lenRecaudacion,
						contribuyente *aContribuyente, int lenContribuyente){

	char descMes[LEN_STR];
	char descTipo[LEN_STR];
	char descEstado[LEN_STR];
	int ret=-1;
	int i;
	int j;
	int cont;


	if(aContribuyente!=NULL && lenContribuyente>0 && aRecaudacion!=NULL && lenRecaudacion>0){

		ret=0;
		printf("Id    Nombre     Apellido      Cuil           Id Recaud  Mes        Tipo      Estado");

		for(i=0; i<lenContribuyente && aContribuyente[i].isEmpty==0; i++){

			//if(aContribuyente[i].isEmpty==0){

				cont=0;
				printf("\n%-5d %-10s %-10s %-18s",  aContribuyente[i].id, aContribuyente[i].nombre,
												  aContribuyente[i].apellido, aContribuyente[i].cuil);


				for(j=0; j<lenRecaudacion; j++){
					if(aRecaudacion[j].isEmpty==0 && aRecaudacion[j].idContribuyente==aContribuyente[i].id){

						getDescEstadoRec(aRecaudacion[j].estado, descEstado, LEN_STR);
						getMes(aRecaudacion[j].mes, descMes, LEN_STR);
						getDescripcionTipo(aRecaudacion[j].tipo, descTipo, LEN_STR);

							if(cont==0){
								printf("%-10d %-10s %-9s %-9s\n", aRecaudacion[j].idRecaudacion,
																	descMes, descTipo, descEstado);
								cont++;
							}
							else if(cont>0){
								printf("%49d        %-10s %-10s %-9s\n", aRecaudacion[j].idRecaudacion,
																	     descMes, descTipo, descEstado);
							}
					}
				}

				continue;//cierro for j
		}//cierro for i
	}
	return ret;
}
