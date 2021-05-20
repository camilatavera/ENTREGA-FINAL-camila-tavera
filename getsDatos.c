/*
 * getsDatos.c
 *
 *  Created on: Apr 28, 2021
 *      Author: caami
 */
#include "getsDatos.h"




/*
 * copia la cadena
 * return 0 si sale bien
 */


static int myGets(char cadena[], int leng){
	int ret=-1;
	char bufferString[4096]; //le pongo de mas por las dudas.


	if(cadena!=NULL && leng>0){

		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin)!=NULL){

			//si alguien apreto enter le pongo el \0
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1]=='\n'){
				bufferString[strnlen(bufferString, sizeof(bufferString))-1]='\0';
			}

			//copio la cadena aux en mi array
			if(strlen(bufferString)<=leng){
				strncpy(cadena, bufferString, leng);
				ret=0;
			}
		}
	}
			return ret;
}


static int esUnaPalabra(char string[], int leng){
	int ret=-1;
	int i;
	if(string!=NULL && leng>0){
		ret=1; //verdadero, es una palabra

		for(i=0; i<leng && string[i]!='\0'; i++){

			if(string[i]>'z' || string[i]<'a' ){ //si esta fuera de rango,devuelvo 0
				ret=0;
				break;
			}
	}//cierro for
	}
	return ret;
}


/*
static int sonPalabras(char string[], int leng){
	int ret=-1;
	int i;
	if(string!=NULL && leng>0){
		ret=1; //verdadero, son palabras.


		for(i=0; i<leng && string[i]!='\0'; i++){

			if(string[i]==' '){
				continue;
			}

			if(string[i]>'z' || string[i]<'a' ){ //si esta fuera de rango,devuelvo 0
				ret=0;
				break;
			}
	}//cierro for
	}
	return ret;
}
*/



static int esNumerica(char string[], int leng){
	int ret=-1;
	int i;
	if(string!=NULL && leng>0){
		ret=1; //verdadero, es numerico

		for(i=0; i<leng && string[i]!='\0'; i++){

			if(i==0 && (string[i]=='+' || string[i]=='-')){
				continue;
			}

			if(string[i]>'9' || string[i]<'0' ){ //si esta fuera de rango,devuelvo 0
				ret=0;
				break;
			}
	}//cierro for
	}
	return ret;
}

/*
 * verifica si la cadena es flotante
 * return 1: V, la cadena es flotante
 * return 0: F, no es flotante
 * return -1: ERROR.
 */

static int esFlotante(char string[], int leng){
	int ret=-1;
	int i;
	int flagPunto=1;

	if(string!=NULL && leng>0){
		ret=1; //verdadero, es flotante

		for(i=0; i<leng && string[i]!='\0'; i++){


			if(i==0 && (string[i]=='+' || string[i]=='-')){
				continue;
			}

			if(string[i]=='.' && flagPunto){
				flagPunto=0;
				continue;
			}
			/*
			 * else if(string[i]=='.' && !flagPunto){
				ret=0;
				break;
			}
			 */

			if(string[i]>'9' || string[i]<'0' || (string[i]=='.' && !flagPunto)){ //si esta fuera de rango,devuelvo 0
				ret=0;
				break;
			}



	}//cierro for
	}
	return ret;
}


/*
 pasa la cadena de caracteres a entero
 return 0 si se logro
 */
int getInt(int *pResultado){
	int ret=-1;
	char bufferString[50];
	if(pResultado!=NULL && //puntero no es nulo
		myGets(bufferString, sizeof(bufferString))==0 && //se copio la cadena
		esNumerica(bufferString, sizeof(bufferString))) //es numerica
	{
		ret=0;
		*pResultado=atoi(bufferString);

	}
	return ret;
}

static int getFloat(float *pResultado){
	int ret=-1;
	char bufferString[50];
	if(pResultado!=NULL && //puntero no es nulo
		myGets(bufferString, sizeof(bufferString))==0 && //se copio la cadena
		esFlotante(bufferString, sizeof(bufferString))) //es numerica
	{
		ret=0;
		*pResultado=atof(bufferString);

	}
	return ret;
}



int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

	 int ret=-1;
	 int bufferInt;

	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
	 while(reintentos>=0){
		 reintentos--;
		 printf("%s", mensaje);
		 if(getInt(&bufferInt)==0 &&
				 bufferInt>=minimo &&
				 bufferInt<=maximo)
		 {
		 	 *pResultado = bufferInt;
		 	 ret=0;
			 break;
		 }
		 else{
			 fflush(stdin);
			 printf("%s", mensajeError);
		 }
	 }//cierro while
	 };//cierro la validacion de los punteros.
	 return ret;
}

int getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	//
	 int ret=-1;
	 float bufferFloat;

	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
		 while(reintentos>=0){
			 reintentos--;
			 printf("%s", mensaje);
			 if(getFloat(&bufferFloat)==0 &&
					 bufferFloat>=minimo &&
					 bufferFloat<=maximo)
			 {
				 *pResultado = bufferFloat;
				 ret=0;
				 break;
			 }
			 else
			 {
				 fflush(stdin);
				 printf("%s", mensajeError);
			 }
		 }//cierro while
	 	 };//cierro la validacion de los punteros.
	 	 return ret;
}

int getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	//
	 int ret=-1;
	 char bufferChar;

	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
		 while(reintentos>=0){
			 reintentos--;
			 printf("%s", mensaje);
			 if(//getFloat(&bufferFloat)==0 &&
					 scanf("%c",&bufferChar)==1 &&
					 bufferChar>=minimo &&
					 bufferChar<=maximo)
			 {
				 *pResultado = bufferChar;
				 ret=0;
				 break;
			 }
			 else
			 {
				 fflush(stdin);
				 printf("%s", mensajeError);
			 }
		 }//cierro while
	 	 };//cierro la validacion de los punteros.
	 	 return ret;
}

int validarChar(char* pResultado, char* mensaje, char* mensajeError, char opcion1, char opcion2, int reintentos){
	//
	 int ret=-1;
	 char bufferChar;

	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL){
		 while(reintentos>=0){
			 reintentos--;
			 printf("%s", mensaje);
			 if(//getFloat(&bufferFloat)==0 &&
					 scanf("%c",&bufferChar)==1 &&
					 (bufferChar==opcion1 ||
					 bufferChar==opcion2) )
			 {
				 *pResultado = bufferChar;
				 ret=0;
				 break;
			 }
			 else
			 {
				 fflush(stdin);
				 printf("%s", mensajeError);
			 }
		 }//cierro while
	 	 };//cierro la validacion de los punteros.
	 	 return ret;
}

int utn_getString(char *pResultado, int len, char* mensaje, char* mensajeError, int reintentos){

	 int ret=-1;
	 char bufferString[4000];


	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && len>0){
	 while(reintentos>=0){
		 reintentos--;
		 printf("%s", mensaje);

		 if(myGets(bufferString, sizeof(bufferString))==0 &&
				 esUnaPalabra(bufferString, sizeof(bufferString))){

			 strncpy(pResultado, bufferString, len);
			 ret=0;
			 break;
		 }

		 else{
			 fflush(stdin);
			 printf("%s", mensajeError);
		 }
	 }//cierro while
	 };//cierro la validacion de los punteros.
	 return ret;
}



int getTexto(char *pResultado, int len, char* mensaje, char* mensajeError, int reintentos){

	 int ret=-1;
	 char bufferString[4000];


	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && len>0){
	 while(reintentos>=0){
		 reintentos--;
		 printf("%s", mensaje);

		 if(myGets(bufferString, sizeof(bufferString))==0){

			 strncpy(pResultado, bufferString, len);
			 ret=0;
			 break;
		 }

		 else{
			 fflush(stdin);
			 printf("%s", mensajeError);
		 }
	 }//cierro while
	 };//cierro la validacion de los punteros.
	 return ret;
}



int getCuil(char *pResultado, int len, char* mensaje, char* mensajeError, int reintentos){

	 int ret=-1;
	 char bufferString[20];


	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && len>0){
	 while(reintentos>=0){
		 reintentos--;
		 printf("%s", mensaje);

		 if(myGets(bufferString, sizeof(bufferString))==0 &&
				 esCuil(bufferString, sizeof(bufferString))){

			 strncpy(pResultado, bufferString, len);
			 ret=0;
			 break;
		 }

		 else{
			 fflush(stdin);
			 printf("%s", mensajeError);
		 }
	 }//cierro while
	 };//cierro la validacion de los punteros.
	 return ret;
}

int esCuil(char string[], int leng){
	int ret=-1;
	int i;
	int contDigito=0;
	int contGuion=0;

	if(string!=NULL && leng>0){
		ret=1; //verdadero, es cuit.

		for(i=0; i<leng && string[i]!='\0'; i++){

			if( (i==0 && string[i]=='2') ||
				 (i==1 && (string[i]=='0' || string[i]=='3' || string[i]=='4' || string[i]=='7'))){
				contDigito++;
				continue;
			}
			else if(i==0 || i==1){
				ret=0;
				break;
			}

			if(i==2){
				if(string[i]=='-'){
				contGuion++;
				continue;
				}

				else{
					ret=0;
					break;
				}
			}


			if(i>2 && i<=12){
				if(isdigit(string[i])!=0){
					contDigito++;
					continue;
				}
				else if(string[i]=='-'){
					contGuion++;
					continue;
				}
				else{
					ret=0;
					break;
			}

			if(contGuion==2){
				if( (contDigito==10 && string[10]=='-' && (string[11]>0 || string[11]<=9)) ||

					(contDigito==11 && string[11]=='-' && (string[12]>0 || string[12]<=9)) ){

						break;
				}
				else{
					ret=0;
					break;
				}
			}

			}
	}//cierro for
	}
	return ret;
}

/*
static int esCuit(char string[], int leng){
	int ret=-1;
	int i;
	int lenStr;
	int contDigito=0;          27-42567370-5
								27-8526852-9
	int contGuion=0;

	if(string!=NULL && leng>0){
		ret=1; //verdadero, es cuit.

		lenStr=strlen(string);

		for(i=0; i<leng && string[i]!='\0'; i++){

			if(lenStr==13){

				if( (i==0 && string[i]=='2') ||
					(i==1 && (string[i]=='0' || string[i]=='3' || string[i]=='4' || string[i]=='7'))){
					continue;
					}
				else{
					ret=0;
					break;
				}

				if( (i==2 || i==11) && string[i]=='-'){
					continue;
				}
				else{
					ret=0;
					break;
				}
			}

			if( (i==0 && string[i]=='2') ||
				 (i==1 && (string[i]=='0' || string[i]=='3' || string[i]=='4' || string[i]=='7'))){
				contDigito++;
				continue;
			}
			else if(i==0 || i==1){
				ret=0;
				break;
			}

			if(i==2){
				if(string[i]=='-'){
				contGuion++;
				continue;
				}

				else{
					ret=0;
					break;
				}
			}


			if(i>2 && i<=12){
				if(isdigit(string[i])!=0){
					contDigito++;
					continue;
				}
				else if(string[i]=='-'){
					contGuion++;
					continue;
				}
				else{
					ret=0;
					break;
			}

			if(contGuion==2){
				if( (contDigito==10 && string[10]=='-' && (string[11]>0 || string[11]<=9)) ||

					(contDigito==11 && string[11]=='-' && (string[12]>0 || string[12]<=9)) ){

						break;
				}
				else{
					ret=0;
					break;
				}
			}

			}
	}//cierro for
	}
	return ret;
}
*/
