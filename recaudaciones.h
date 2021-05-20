/*
 * recaudaciones.h
 *
 *  Created on: May 13, 2021
 *      Author: caami
 */

#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

typedef struct{
	int idContribuyente;
	int mes;
	int tipo; //1)ARBA 2)IIBB 3)GANANCIAS
	int idRecaudacion;
	int estado;
	long int importe;
	int isEmpty;
}recaudacion;

//ESTADOS
#define REFINANCIAR 1
#define SALDADA -1
#define ACTIVA 0

#include "contribuyente.h"


/*
 * Imprime el tipo de recaudaciones existentes
 */
int listadoTiposRecaudaciones(void);

/* \brief Itera por el array hasta encontrar una recaudacion de alta (isEmpty==0)
 * \param recaudacion *list
 * \param int len
 * \return Retorna -1 si ERROR, 0 si encuentra al menos una vez isEmpty en 0,
 * 1 si todos los isEmpty estan en TRUE
 */
int recaudacionIsEmpty(recaudacion *list, int len);



/* \brief Itera por el array hasta encontrar una recaudacion activa (campo estado igual a ACTIVa)
 * \param recaudacion* array
 * \param int largo DEL ARRAY
 * \return Retorna -1 si ERROR, 0 si no hay recaudaciones activas, 1 si encuentra
 */
int hayRecaudacionActiva(recaudacion *list, int len);


/* \brief Itera por el array hasta encontrar una recaudacion activa (campo estado igual a ACTIVa)
 * \param recaudacion* array
 * \param int largo DEL ARRAY
 * \return Retorna -1 si ERROR, 0 si no hay recaudaciones activas, 1 si encuentra
 */
int hayRecaudacionesNoSaldadas(recaudacion *list, int len);


/** \brief Indica que todas las posiciones del array estan vacias
 * Pone todas las banderas (isEmpty) en TRUE en todas las posiciones del array
 * \param  recaudacion* list
 * \param int len
 * \return int Retorna (-1) si ERROR [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initRecaudaciones(recaudacion* list, int len);


/*
 * \brief Itera por el array de tipo recaudacion hasta que encuentra la primera posicion libre
 * \param recaudacion* array
 * \param int leng
 * \param posicionLibre: Puntero al espacio de memoria donde se dejara la primera posicion libre
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int buscarLibreRecaudacion(recaudacion *array, int leng, int *posicionLibre);


/*
 * \brief Permite al usuario ingresar datos
 * \param recaudacion *bufferRecaudacion
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int ingresarValoresRecaudacion(recaudacion *bufferAviso, contribuyente *list, int len);


/*
 * \brief Agrega los valores ingresados y auto-generados en la primera posicion
 * que encuentra libre en el array
 * \param *recaudacion list
 * \param int len
 * \param int id: el valor del id autoincremental
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int addRecaudacion(recaudacion* aRecaudacion, int lenRecaudacion, contribuyente* aContribuyente,
					int lenContribuyente, int idRecaudacion);


/*
 * \brief Imprime el valor del id pasado por parametro
 * \param int id
 * \return Retorna 0
 */
int printIdRecaudaciones(int id);



/** \brief Da de baja la recaudacion (poniendo el campo isEmpty en 1) pertenecientes
 * al id del contribuyente pasado por parametro
 * \param recaudacion* array
 * \param int largo del array
 * \param int id contribuyente
 * \return Retorna -1 si ERROR o 0 si EXITO
 */
int bajaRecaudacionByIdContribuyente(recaudacion *list, int len, int idContribuyente);

/** \brief Listado de recaudaciones perteneciente al id de un contribuyente
 * pasado por parametro
 * \param recaudacion* array
 * \param int largo del array de tipo recaudacion
 * \return Retorna -1 si ERROR o 0 si EXITO
 */
int listarRecaudacionesDeUnContribuyente(recaudacion *list, int len, int idContribuyente);


/* \brief Copia en la direccion del puntero la descripcion correspondiente al numero que le
 * paso por parametro
 * \param int nTipo
 * \param char *desc
 * \param int len
 * \return Retorna -1 si ERROR o 0 si EXITO
 */
int getDescripcionTipo(int nTipo, char *desc, int len);


/* \brief Copia en la direccion del puntero la descripcion correspondiente al numero que le
 * paso por parametro
 * \param int nTipo
 * \param char *desc
 * \param int len
 * \return Retorna -1 si ERROR o 0 si EXITO
 */
int getMes(int nMes, char *desc, int len);


/*
 * \brief Permite al usuario ingresar un numero de id y si esta de alta (isEmpty==0) y activa
 * (estado==ACTIVA) en el array de
 * tipo recaudacion, guarda el id en la direccion apunta por pResultado
 * \param recaudacion *list
 * \param int len
 * \param int *pResultado
 * \param char *mensaje
 * \param char* mensajeError
 * \param int reintentos
 * return Retorna -1 si ERROR o 0 si EXITO
 */
int getIdRecaudacionActiva(recaudacion *list, int len, int* pResultado, char* mensaje,
		char* mensajeError,	int reintentos);



/*
 * \brief Permite al usuario ingresar un numero de id y si esta de alta (isEmpty==0) y no saldada
 * (estado != SALDADA) en el array de
 * tipo recaudacion, guarda el id en la direccion apunta por pResultado
 * \param recaudacion *list
 * \param int len
 * \param int *pResultado
 * \param char *mensaje
 * \param char* mensajeError
 * \param int reintentos
 * return Retorna -1 si ERROR o 0 si EXITO
 */
int getIdRecaudacion_noSaldada(recaudacion *list, int len, int* pResultado, char* mensaje,
		char* mensajeError,	int reintentos);


/** \brief Busca la posicion del array donde se encuentra el id pasado por paramtro
 * y guarda la posicion en la direccion de memoria del puntero
 *
 * \param contribuyente *list
 * \param int len
 * \param int id de la recaudacion
 * \int *posicion
 * \return Retorna -1 si ERROR o retorna 0 si EXITO
 */
int findRecaudacionById(recaudacion *list, int len, int id, int *posicion);


/** \brief Permite ingresar el id de la recaudacion y la pone en estado REFINANCIAR
 * \param contribuyente* array
 * \param recaudacion* array
 * \param int largo del array de tipo contribuyente
 * \param int largo del array de tipo recaudacion
 * \return Retorna -1 si ERROR o 0 si EXITO
 *
 */
int refinanciarRecaudacion(recaudacion *aRecaudacion, int lenRecaudacion,
							contribuyente *aContribuyente, int lenContribuyente);

/** \brief Permite ingresar el id de la recaudacion y la pone en estado SALDADA
 * \param contribuyente* array
 * \param recaudacion* array
 * \param int largo del array de tipo contribuyente
 * \param int largo del array de tipo recaudacion
 * \return Retorna -1 si ERROR o 0 si EXITO
 *
 */
int saldarRecaudacion(recaudacion *aRecaudacion, int lenRecaudacion,
							contribuyente *aContribuyente, int lenContribuyente);



/* \brief Copia en la direccion del puntero la descripcion correspondiente al numero que le
 * paso por parametro
 * \param int estado
 * \param char *desc
 * \param int len
 * \return Retorna -1 si ERROR o 0 si EXITO
 */
int getDescEstadoRec(int estado, char *desc, int len);

/** \brief Imprime un listado de todas las recaudaciones en estado SALDADA y los datos
 * del contribuyente a quien le pertenecen
 * \param contribuyente* array
 * \param recaudacion* array
 * \param int largo del array de tipo contribuyente
 * \param int largo del array de tipo recaudacion
 * \return Retorna -1 si ERROR o 0 si EXITO
 *
 */
int listarRecaudacionesSaldadas(recaudacion *aRecaudacion, int lenRecaudacion,
		contribuyente *aContribuyente, int lenContribuyente);


/* \brief Itera por el array hasta encontrar una recaudacion saldada (campo estado igual a SALDADA)
 * \param recaudacion* array
 * \param int largo DEL ARRAY
 * \return Retorna -1 si ERROR, 0 si no hay recaudaciones activas, 1 si encuentra
 */
int hayRecaudacionesSaldadas(recaudacion *list, int len);



#endif /* RECAUDACIONES_H_ */


