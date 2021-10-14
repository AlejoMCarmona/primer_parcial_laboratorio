#include "Cliente.h"

int eCliente_InicializarListaClientes(eCliente lista[], int tam) {
	int retorno;
	retorno = 0;
	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			lista[i].isEmpty = EMPTY;
		}
		retorno = 1;
	}
	return retorno;
}

int eCliente_BuscarPrimeraPosicionLibre(eCliente lista[], int tam){
	int indice;
	indice = -2;
	if (lista != NULL && tam > 0) {
		indice = -1;
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == EMPTY) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int eCliente_AltaCliente(eCliente lista[], int tam, eLocalidad listaLocalidades[], int tamListaLocalidades, int* contadorId) {
	int indice;
	int retorno;
	retorno = 0;
	if (lista != NULL && tam > 0 && contadorId != NULL) {
		indice = eCliente_BuscarPrimeraPosicionLibre(lista, tam);
		if (indice != -1) {
			retorno = eCliente_CargarCliente(lista, tam, listaLocalidades, tamListaLocalidades, indice, contadorId);
		} else {
			retorno = -1;
		}
	}
	return retorno;
}

int eCliente_IngresarCliente(eCliente* cliente, eLocalidad listaLocalidades[], int tamListaLocalidades, int contadorId) {
	int retorno;
	retorno = 0;
	if (cliente != NULL) {
		retorno = IngresarCadenaSoloLetrasConIntentos(cliente->nombre, sizeof(cliente->nombre), "Ingrese el nombre de la empresa (5 intentos): ", "ERROR. Solo caracteres alfabeticos. Ingrese el nombre de la empresa (5 intentos): ", 5);
		if (retorno == 1) {
			retorno = IngresarCUIT(cliente->cuit, sizeof(cliente->cuit), "Ingrese el CUIT (XX-XXXXXXXX-X) (5 intentos): ", "ERROR. Solo numeros con ese formato. Ingrese el CUIT de la empresa (XX-XXXXXXXX-X) (5 intentos): ", 5);
			if (retorno == 1) {
				retorno = IngresarCadenaSoloAlfanumericosConIntentos(cliente->direccion, sizeof(cliente->direccion), "Ingrese la dirección (5 intentos): ", "ERROR. Solo alfanumericos. Ingrese la dirección (5 intentos): ", 5);
				if (retorno == 1) {
					ImprimirLocalidades(listaLocalidades , tamListaLocalidades);
					retorno = IngresarEnteroConIntentos(&(cliente->idLocalidad), "Elija localidad: ", "ERROR. Elija localidades: ", 5);
					if (retorno == 1) {
						retorno = BuscarLocalidadPorId(listaLocalidades, tamListaLocalidades, cliente->idLocalidad);
						if (retorno != -1) {
							retorno = 1;
						} else {
							retorno = 0;
						}
					}
					if (retorno == 1) {
						cliente->isEmpty = FULL;
						cliente->idCliente = contadorId + 1;
					}
				}
			}
		}
	}
	return retorno;
}

int eCliente_CargarCliente(eCliente lista[], int tam, eLocalidad listaLocalidades[], int tamListaLocalidades, int indice, int* contadorId) {
	int retorno;
	eCliente cliente;
	int contadorAux;
	retorno = 0;
	contadorAux = *contadorId;
	if (lista != NULL && indice >= 0 && indice < tam && contadorId != NULL) {
		retorno = eCliente_IngresarCliente(&cliente, listaLocalidades, tamListaLocalidades, contadorAux);
		if (retorno == 1) {
			lista[indice] = cliente;
			*contadorId = *contadorId + 1;
		}
	}
	return retorno;
}

int eCliente_ImprimirClientes(eCliente lista[], int tam) {
	int flagNoVacio;
	flagNoVacio = -1;
	if (lista != NULL && tam > 0) {
		flagNoVacio = 0;
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == FULL) {
				if (flagNoVacio == 0) {
					printf("ID	nombre	CUIT			direccion			localidad\n");
					flagNoVacio = 1;
				}
				eCliente_MostrarCliente(lista[i]);
			}
		}
	}
	return flagNoVacio;
}

void eCliente_MostrarCliente(eCliente cliente) {
	printf("%d	%s	%s		%s			%d\n", cliente.idCliente, cliente.nombre, cliente.cuit, cliente.direccion, cliente.idLocalidad);
}

int eCliente_BajaCliente(eCliente lista[], int tam, int id){
	int retorno;
	int indice;
	char confirmacion;
	retorno = 0;

	if (lista != NULL && tam > 0) {
		indice = eCliente_BuscarClientePorId(lista, tam, id);
		if (indice != -1) {
			printf("\n");
			eCliente_MostrarCliente(lista[indice]);
			printf("\n");
			retorno = PedirConfirmacionConIntentos(&confirmacion, "¿Seguro que desea eliminar al cliente?", "ERROR. ¿Seguro que desea eliminar al cliente?", 5);
			if (retorno == 1) {
				if (confirmacion == 's') {
					lista[indice].isEmpty = EMPTY;
				} else {
					retorno = -2;
				}
			}
		} else {
			retorno = -1;
		}
	}
	return retorno;
}

int eCliente_BuscarClientePorId(eCliente lista[], int tam, int id) {
	int indice;
	indice = -1;
	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == FULL && lista[i].idCliente == id) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int eCliente_ModificarCliente(eCliente listaClientes[], eLocalidad listaLocal[], int tamListaLocal, int tam) {
	int retorno;
	int id;
	int opcion;
	int indice;
	retorno = 0;

	if (listaClientes != NULL && tam > 0) {
		if (eCliente_ImprimirClientes(listaClientes, tam) == 1) {
			printf("\n");
			retorno = IngresarEnteroConIntentos(&id, "Ingrese el ID del cliente a modificar: ", "ERROR. Reingrese el ID del cliente a modificar: ", 5);
			if (retorno == 1) {
				indice = eCliente_BuscarClientePorId(listaClientes, tam, id);
				if (indice != -1) {
					printf("CLIENTE ENCONTRADO\n¿Qué desea modificar?: \n1- Dirección\n2- Localidad\n\n");
					retorno = IngresarEnteroEntreRangosConIntentos(&opcion, "Elija una opcion: ", "ERROR. Elija una opcion valida: ", 1, 2, 5);
					if (retorno == 1) {
						retorno = eCliente_IngresarModificacion(listaClientes, tam, listaLocal, tamListaLocal, indice, opcion);
					}
				} else {
					retorno = -1;
				}
			}
		} else {
			retorno = -2;
		}
	}
	return retorno;
}

int eCliente_IngresarModificacion(eCliente listaClientes[], int tam, eLocalidad listaLocalidades[],int tamLocalidades, int indice, int opcion) {
	int retorno;
	char cadenaAux[50];
	int intAux;
	retorno = 0;
	if (listaClientes != NULL && tam > 0 && indice >= 0 && indice < tam) {
		if (opcion == 1) {
			retorno = IngresarCadenaSoloAlfanumericosConIntentos(cadenaAux, 50, "Ingrese la nueva direccion: ", "ERROR. Reingrese la nueva direccion: ", 5);
			if (retorno == 1) {
				strncpy(listaClientes[indice].direccion, cadenaAux, 50);
			}
		} else {
			if (opcion == 2) {
				ImprimirLocalidades(listaLocalidades, tamLocalidades);
				retorno = IngresarEnteroConIntentos(&intAux, "Ingrese la nueva localidad: ", "ERROR. Reingrese la nueva localidad: ", 5);
				if (retorno == 1){
					listaClientes[indice].idLocalidad = intAux;
				}
			}
		}
	}
	return retorno;
}

int eCliente_ContarCantidadDeClientes(eCliente listaClientes[], int tam, int* contadorClientes) {
	int retorno;
	int contadorAux;
	retorno = 0;
	contadorAux = 0;

	if (listaClientes != NULL && tam > 0 && contadorClientes != NULL) {
		for (int i = 0; i < tam; i++) {
			if (listaClientes[i].isEmpty == FULL) {
				contadorAux++;
			}
		}
		*contadorClientes = contadorAux;
		retorno = 1;
	}

	return retorno;
}
