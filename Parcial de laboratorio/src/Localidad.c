/*
 * Localidad.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Alejo
 */

#include "Localidad.h"

int ImprimirLocalidades(eLocalidad listaLocalidades[] ,int tam) {
	int flagNoVacio;
	flagNoVacio = -1;
	if (listaLocalidades != NULL && tam > 0) {
		flagNoVacio = 0;
		for (int i = 0; i < tam; i++) {
			if (listaLocalidades[i].isEmpty == FULL) {
				if (flagNoVacio == 0) {
					printf("LOCALIDADES\n");
					flagNoVacio = 1;
				}
				printf("%d %s", listaLocalidades[i].idLocalidad, listaLocalidades[i].localidad);
			}
		}
	}
	return flagNoVacio;
}


int BuscarLocalidadPorId(eLocalidad listaLocalidades[] ,int tam, int id){
	int indice;
	indice = -1;
	if (listaLocalidades != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (listaLocalidades[i].isEmpty == FULL && listaLocalidades[i].idLocalidad == id) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int InicializarListaLocalidades(eLocalidad listaLocalidades[] ,int tam) {/////////////////
	int retorno;
	retorno = 0;
	if (listaLocalidades != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			listaLocalidades[i].isEmpty = EMPTY;
		}
		retorno = 1;
	}
	return retorno;
}
