#include "Pedido.h"

int ePedido_InicializarListaPedidos(ePedido lista[], int tam){
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

int ePedido_BuscarPrimeraPosicionLibre(ePedido lista[], int tam){
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

int ePedido_CrearPedido(ePedido listaPedidos[], int tamListaPedidos, int* contadorIdPedidos, eCliente listaClientes[], int tamListaClientes){
	int retorno;
	int indice;
	retorno = 0;
	if (listaPedidos != NULL && tamListaPedidos > 0 && contadorIdPedidos != NULL && listaClientes != NULL && tamListaClientes > 0) {
		indice = ePedido_BuscarPrimeraPosicionLibre(listaPedidos, tamListaPedidos);
		if (indice != -1) {
			retorno = ePedido_CargarPedido(listaPedidos, tamListaPedidos, indice, contadorIdPedidos, listaClientes, tamListaClientes);
		} else {
			retorno = -1;
		}
	}
	return retorno;
}


int ePedido_IngresarPedido(ePedido* pedido, int contadorIdPedidos, int idCliente) {
	int retorno;
	float kg;
	retorno = 0;
	if (pedido != NULL) {
		retorno = IngresarFlotanteEntreRangosConIntentos(&kg, "Ingrese la cantidad de kg totales de residuos que se recolectarán del cliente: ", "ERROR. Reingrese la cantidad de kg totales de residuos que se recolectarán del cliente: ", 1 , FLT_MAX, 5);
		if (retorno == 1) {
			pedido->idPedido = contadorIdPedidos + 1;
			pedido->idCliente = idCliente;
			pedido->cantidadKilosTotales = kg;
			pedido->estado = PENDIENTE;
			pedido->isEmpty = FULL;
		}
	}
	return retorno;
}

int ePedido_CargarPedido(ePedido listaPedidos[], int tamListaPedidos, int indice, int* contadorIdPedidos, eCliente listaClientes[], int tamListaClientes) {
	int retorno;
	ePedido pedidoAux;
	int indiceCliente;
	int idCliente;
	int contadorAux;
	retorno = 0;
	contadorAux = *contadorIdPedidos;
	if (listaPedidos != NULL && tamListaPedidos > 0 && contadorIdPedidos != NULL && listaClientes != NULL && tamListaClientes > 0 && indice >= 0 && indice < tamListaPedidos) {
		if (eCliente_ImprimirClientes(listaClientes, tamListaClientes) == 1) {
			printf("\n");
			retorno = IngresarEnteroConIntentos(&idCliente, "Ingrese el ID del cliente para cargar un pedido: ", "ERROR. Solo enteros. Reingrese el ID del cliente para cargar un pedido: ", 5);
			if (retorno == 1) {
				indiceCliente = eCliente_BuscarClientePorId(listaClientes, tamListaClientes, idCliente);
				if (indiceCliente != -1) {
					printf("\n");
					eCliente_MostrarCliente(listaClientes[indiceCliente]);
					printf("\n");
					retorno = ePedido_IngresarPedido(&pedidoAux, contadorAux, idCliente);
					if (retorno == 1) {
						listaPedidos[indice] = pedidoAux;
						*contadorIdPedidos = *contadorIdPedidos + 1;
					}
				} else {
					retorno = -3;
				}
			}
		} else {
			retorno = -2;
		}
	}
	return retorno;
}

int ePedido_BuscarPorId(ePedido lista[], int tam, int id) {
	int indice;
	indice = -1;
	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == FULL && lista[i].idPedido == id) {
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int ePedido_VerificarPedidosPendientes(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int* idCliente) {
	int retorno;
	int idAux;
	int indice;
	int cantPedidos;
	retorno = 0;
	if (listaPedidos != NULL && tamListaPedidos > 0 && listaClientes != NULL && tamListaClientes > 0 && idCliente != NULL) {
		if (eCliente_ImprimirClientes(listaClientes, tamListaClientes) == 1) {
			printf("\n");
			retorno = IngresarEnteroConIntentos(&idAux, "Ingrese el ID del cliente: ", "ERROR. Solo enteros. Reingrese el ID del cliente: ", 5);
			if (retorno == 1) {
				indice = eCliente_BuscarClientePorId(listaClientes, tamListaClientes, idAux);
				if (indice != -1) {
					ePedido_ContarCantidadDePedidosPendientesPorCliente(listaPedidos, tamListaPedidos, idAux, &cantPedidos);
					*idCliente = idAux;
					if (cantPedidos > 0) {
						retorno = 1;
					} else {
						retorno = -3;
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

int ePedido_ImprimirPedidos(ePedido listaPedidos[], int tamListaPedidos){////////////////////////////////////////////
	int retorno;
	int flagPedidos;
	retorno = 0;
	flagPedidos = 0;
	if (listaPedidos != NULL && tamListaPedidos > 0) {
		retorno = 1;
		for (int i = 0; i < tamListaPedidos; i++) {
			if (listaPedidos[i].isEmpty == FULL) {
				if (flagPedidos == 0) {
					printf("Lista de pedidos: \n");
					flagPedidos = 1;
				}
				printf("ID del pedido: %d\n"
					   "Cantidad de kilos totales: %f\n"
					   "Estado: %d\n",
					   listaPedidos[i].idPedido,
					   listaPedidos[i].cantidadKilosTotales,
					   listaPedidos[i].estado);
				printf("--------------------\n");
			}
		}
		if (flagPedidos == 0) {
			retorno = -1;
		}
	}
	return retorno;
}

int ePedido_IngresarProceso(ePedido listaPedidos[], int tam, int indice) {
	int retorno;
	float auxHDPE;
	float auxLDPE;
	float auxPP;
	retorno = 0;

	if (listaPedidos != NULL && indice >= 0 && indice < tam) {
		retorno = IngresarFlotanteEntreRangosConIntentos(&auxHDPE, "Ingrese la cantidad de kilogramos de HDPE procesados: ", "ERROR. Solo numeros positivos. Ingrese la cantidad de kilogramos de HDPE procesados: ", 0, FLT_MAX, 5);
		if (retorno == 1) {
			retorno = IngresarFlotanteEntreRangosConIntentos(&auxLDPE, "Ingrese la cantidad de kilogramos de LDPE procesados: ", "ERROR. Solo numeros positivos. Ingrese la cantidad de kilogramos de LDPE procesados: ", 0, FLT_MAX, 5);
			if (retorno == 1) {
				retorno = IngresarFlotanteEntreRangosConIntentos(&auxPP, "Ingrese la cantidad de kilogramos de PP procesados: ", "ERROR. Solo numeros positivos. Ingrese la cantidad de kilogramos de PP procesados: ", 0, FLT_MAX, 5);
				if (retorno == 1) {
					if (auxHDPE + auxLDPE + auxPP <= listaPedidos[indice].cantidadKilosTotales) {
						listaPedidos[indice].cantidadKilosHDPE = auxHDPE;
						listaPedidos[indice].cantidadKilosLDPE = auxLDPE;
						listaPedidos[indice].cantidadKilosPP = auxPP;
						listaPedidos[indice].estado = COMPLETADO;
					} else {
						retorno = -3;
					}
				}
			}
		}
	}
	return retorno;
}

int ePedido_ImprimirPedidosPendientes(ePedido listaPedidos[], int tamListaPedidos) {
	int retorno;
	retorno = -1;
	if (listaPedidos != NULL && tamListaPedidos > 0) {
		retorno = 0;
		for (int i = 0; i < tamListaPedidos; i++) {
			if (listaPedidos[i].isEmpty == FULL && listaPedidos[i].estado == PENDIENTE) {
				retorno = 1;
				printf("ID del pedido: %d\nID del cliente: %d\nCantidad de kg a recolectar: %f\n", listaPedidos[i].idPedido, listaPedidos[i].idCliente, listaPedidos[i].cantidadKilosTotales);
				printf("----------------------------------------\n");
			}
		}
	}
	return retorno;
}

int ePedido_ProcesarPedidos(ePedido listaPedidos[], int tamListaPedidos) {
	int retorno;
	int indice;
	int idPedido;
	retorno = 0;

	if (listaPedidos != NULL && tamListaPedidos > 0) {
		if (ePedido_ImprimirPedidosPendientes(listaPedidos, tamListaPedidos) == 1) {
			retorno = IngresarEnteroConIntentos(&idPedido, "Ingrese el ID del pedido a procesar: ", "ERROR. Solo enteros. Ingrese el ID del pedido a procesar: ", 5);
			if (retorno == 1) {
				indice = ePedido_BuscarPorId(listaPedidos, tamListaPedidos, idPedido);
				if (indice != -1 && listaPedidos[indice].estado == PENDIENTE) {
					retorno = ePedido_IngresarProceso(listaPedidos, tamListaPedidos, indice);
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

int ePedido_ContarCantidadDePedidosPendientesPorCliente(ePedido listaPedidos[], int tamListaPedidos, int idCliente, int* cantPedidos) {
	int cantPedidosAux;
	int retorno;
	cantPedidosAux = 0;
	retorno = 0;

	if (listaPedidos != NULL && tamListaPedidos > 0 && cantPedidos != NULL) {
		for (int i = 0; i < tamListaPedidos; i++) {
			if (listaPedidos[i].idCliente == idCliente && listaPedidos[i].estado == PENDIENTE && listaPedidos[i].isEmpty == FULL) {
				cantPedidosAux++;
			}
		}
		*cantPedidos = cantPedidosAux;
		retorno = 1;
	}

	return retorno;
}

int ePedido_ContarCantidadDePedidosPorCliente(ePedido listaPedidos[], int tamListaPedidos, int idCliente, int* cantPedidos) {
	int cantPedidosAux;
	int retorno;
	cantPedidosAux = 0;
	retorno = 0;

	if (listaPedidos != NULL && tamListaPedidos > 0 && cantPedidos != NULL) {
		for (int i = 0; i < tamListaPedidos; i++) {
			if (listaPedidos[i].idCliente == idCliente && listaPedidos[i].isEmpty == FULL) {
				cantPedidosAux++;
			}
		}
		*cantPedidos = cantPedidosAux;
		retorno = 1;
	}

	return retorno;
}

int ePedido_ContarCantidadDePedidosCompletadosPorCliente(ePedido listaPedidos[], int tamListaPedidos, int idCliente, int* cantPedidos) {
	int cantPedidosAux;
	int retorno;
	cantPedidosAux = 0;
	retorno = 0;

	if (listaPedidos != NULL && tamListaPedidos > 0 && cantPedidos != NULL) {
		for (int i = 0; i < tamListaPedidos; i++) {
			if (listaPedidos[i].idCliente == idCliente && listaPedidos[i].estado == COMPLETADO && listaPedidos[i].isEmpty == FULL) {
				cantPedidosAux++;
			}
		}
		*cantPedidos = cantPedidosAux;
		retorno = 1;
	}

	return retorno;
}

int ePedido_AcumularKilosDePP(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, float* cantKilosPP) {
	int retorno;
	int acumuladorAux;

	retorno = 0;
	acumuladorAux = 0;
	if (listaPedidos != NULL && tamListaPedidos > 0 && cantKilosPP != NULL && listaClientes != NULL && tamListaClientes > 0) {
		for (int i = 0; i < tamListaPedidos; i++) {
			if (listaPedidos[i].isEmpty == FULL && listaPedidos[i].estado == COMPLETADO) {
				if (eCliente_BuscarClientePorId(listaClientes, tamListaClientes, listaPedidos[i].idCliente) != -1) {
					acumuladorAux += listaPedidos[i].cantidadKilosPP;
				}
			}
		}
		*cantKilosPP = acumuladorAux;
		retorno = 1;
	}
	return retorno;
}
