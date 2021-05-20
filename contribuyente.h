/*
 * contribuyente.h
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

#define LEN_STR 15

typedef struct{
	char nombre[LEN_STR];
	char apellido[LEN_STR];
	char cuil[LEN_STR];
	int id;
	int isEmpty;

}contribuyente;

#include "getsDatos.h"
#include "recaudaciones.h"

/** \brief Indica que todas las posiciones del array estan vacias
 * Pone todas las banderas (isEmpty) en TRUE en todas las posiciones del array
 * \param  contribuyente* list
 * \param int len
 * \return int Retorna (-1) si ERROR [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initContribuyente(contribuyente* list, int len);



/*
 * \brief Itera por el array de tipo contribuyente hasta que encuentra la primera posicion libre
 * \param contribuyente* array
 * \param int leng
 * \param posicionLibre: Puntero al espacio de memoria donde se dejara la primera posicion libre
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int buscarLibreContribuyente(contribuyente *array, int leng, int *posicionLibre);


/*
 * \brief Permite al usuario ingresar datos
 * \param contribuyente *bufferContribuyente
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int ingresarValoresContribuyente(contribuyente *bufferContribuyente);


/*
 * \brief Agrega los valores ingresados y auto-generados en la primera posicion
 * que encuentra libre en el array
 * \param *contribuyente list
 * \param int len
 * \param int id: el valor del id autoincremental
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int addContribuyente(contribuyente* list, int len, int id);


/*
 * \brief Imprime el valor del id pasado por parametro
 * \param int id
 * \return Retorna 0
 */
int printIdContribuyente(int id);

/*
 * \brief Imprime el contenido del array si isEmpty esta en TRUE
 * \param contribuyente *list
 * \param int len
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int listarContribuyentes(contribuyente *list, int len);


/*
 * \brief Imprime los datos del id pasado por parametro
 * \param contribuyente *list
 * \param int len
 * \param int id del contribuyente
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */

int printContribuyente(contribuyente *list, int len, int idContribuyente);


/*
 * \brief permite al usuario ingresar un numero de id y si esta de alta (isEmpty==0) en el array de
 * tipo contribuyente, guarda el id en la direccion apunta por pResultado
 * \param contribuyente *list
 * \param int len
 * \param int *pResultado
 * \param char *mensaje
 * \param char* mensajeError
 * \param int reintentos
 * return Retorna -1 si ERROR o 0 si EXITO
 */
int getIdContribuyenteValido(contribuyente *list, int len, int* pResultado, char* mensaje, char* mensajeError,
							int reintentos);


/** \brief Busca la posicion del array donde se encuentra el id pasado por paramtro
 * y guarda la posicion en el puntero
 *
 * \param contribuyente *list
 * \param int len
 * \param int id del contribuyente
 * \int *posicion
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int FindConstribuyenteById(contribuyente *list, int len, int id, int *posicion);


/** \brief Permite al usuario modificar los valores del array
 * \param contribuyente *list
 * \param int len
 *  \return Retorna -1 si ERROR (No se encontro el contribuyente, len invalido o puntero nulo) o 0 si EXITO
 */
int modificarContribuyente(contribuyente *list, int len);


/* \brief Itera por el array hasta encontrar un contribuyente de alta (isEmpty==0)
 * \param contribuyente *list
 * \param int len
 * \return Retorna -1 si ERROR, 0 si encuentra al menos una vez isEmpty en 0,
 * 1 si todos los isEmpty estan en TRUE
 */
int contribuyenteIsEmpty(contribuyente *list, int len);


/** \brief Elimina a un contribuyente ingresado por id y a todas las recaudaciones que le pertenecen
 * (pone isEmpty en 1)
 *
 * \param contribuyente* array
 * \param recaudacion* array
 * \param int largo del array de tipo contribuyente
 * \param int largo del array de tipo recaudacion
 * \return Retorna -1 si ERROR o 0 si EXITO
 *
 */
int bajaContribuyente(contribuyente *aContribuyente, int lenContribuyente,
						recaudacion *aRecaudacion, int lenRecaudacion);


/** \brief imprime un listado de contribuyentes junto con sus recaudaciones
 * \param contribuyente* array
 * \param recaudacion* array
 * \param int largo del array de tipo contribuyente
 * \param int largo del array de tipo recaudacion
 * \return Retorna -1 si ERROR o 0 si EXITO
 *
 */
int listarContrib_Recaud(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente);

#endif /* CONTRIBUYENTE_H_ */
