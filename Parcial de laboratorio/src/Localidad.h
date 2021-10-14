

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include "Input.h"
#define FULL 0
#define EMPTY 1
typedef struct {
	int idLocalidad;
	char localidad[40];
	int isEmpty;
} eLocalidad;

int InicializarListaLocalidades(eLocalidad listaLocalidades[] ,int tam);
int BuscarLocalidadPorId(eLocalidad listaLocalidades[] ,int tam, int id);
int ImprimirLocalidades(eLocalidad listaLocalidades[] ,int tam);


#endif /* LOCALIDAD_H_ */
