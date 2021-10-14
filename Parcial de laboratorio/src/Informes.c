#include "Informes.h"

int Informes_ImprimirClientesConCantidadPedidosPendientes(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes){
	int flagClientes;
	int cantPedidos;
	flagClientes = -1;

	if (listaPedidos != NULL && tamListaPedidos > 0 && listaClientes != NULL && tamListaClientes > 0) {
		flagClientes = 0;
		for (int i = 0; i < tamListaClientes; i++) {
			if (listaClientes[i].isEmpty == FULL) {
				if (flagClientes == 0) {
					printf("ID	nombre	CUIT			direccion			localidad\n\n");
					flagClientes = 1;
				}
				eCliente_MostrarCliente(listaClientes[i]);
				ePedido_ContarCantidadDePedidosPendientesPorCliente(listaPedidos, tamListaPedidos, listaClientes[i].idCliente, &cantPedidos);
				printf("cantidad de pedidos de recolección pendientes: %d\n", cantPedidos);
				printf("--------------------------------------------------------------------------------\n");
			}
		}
	}
	return flagClientes;
}

int Informes_ImprimirPedidosConClientes(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int estado) {
	int flagPedidos;
	int indice;
	flagPedidos = -1;

	if (listaPedidos != NULL && tamListaPedidos > 0 && listaClientes != NULL && tamListaClientes > 0 && (estado == COMPLETADO || estado == PENDIENTE)) {
		flagPedidos = 0;
		for (int i = 0; i < tamListaPedidos; i++) {

			if (listaPedidos[i].isEmpty == FULL && listaPedidos[i].estado == estado) {
				flagPedidos = 1;
				indice = eCliente_BuscarClientePorId(listaClientes, tamListaClientes, listaPedidos[i].idCliente);
				printf("ID del pedido: %d\n", listaPedidos[i].idPedido);

				if (indice != -1) {
					printf("CUIT del cliente: %s\nDirección: %s\n", listaClientes[indice].cuit, listaClientes[indice].direccion);
				} else {
					printf("¡¡ERROR!! El cliente relacionado con este pedido ya no existe en la lista de clientes.\n");
				}

				if (estado == COMPLETADO) {
					printf("Cantidad de kilos de HDPE: %f\nCantidad de kilos de LDPE: %f\nCantidad de kilos de PP: %f\n", listaPedidos[i].cantidadKilosHDPE, listaPedidos[i].cantidadKilosLDPE, listaPedidos[i].cantidadKilosPP);
				}
				if (estado == PENDIENTE) {
					printf("Cantidad de kilos a recolectar: %f\n", listaPedidos[i].cantidadKilosTotales);
				}

				printf("--------------------------------------------------------------------------------\n");
			}
		}
	}
	return flagPedidos;
}

int Informes_ContarPedidosPendientesPorLocalidad(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int localidad, int* contador) {
	int retorno;
	int contadorAux;
	int contadorPorCliente;
	contadorAux = 0;
	retorno = 0;

	if (listaPedidos != NULL && tamListaPedidos > 0 && listaClientes != NULL && tamListaClientes > 0 && contador != NULL) {
		retorno = -1;
		for (int i = 0; i < tamListaClientes; i++) {
			if (listaClientes[i].idLocalidad == localidad && listaClientes[i].isEmpty == FULL) {
				retorno = 1;
				ePedido_ContarCantidadDePedidosPendientesPorCliente(listaPedidos, tamListaPedidos, listaClientes[i].idCliente, &contadorPorCliente);
				contadorAux += contadorPorCliente;
			}
		}
		if (retorno == 1) {
			*contador = contadorAux;
		}
	}

	return retorno;
}

int Informes_ImprimirPedidosPendientesParaLocalidad(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes) {
	int retorno;
	int localidad;
	int cantidadPedidosPendientes;
	retorno = 0;

	if (listaPedidos != NULL && tamListaPedidos > 0 && listaClientes != NULL && tamListaClientes > 0) {
			retorno = IngresarEnteroConIntentos(&localidad, "Ingrese la localidad para consultar pedidos pendientes: ", "ERROR. Reingrese la localidad para consultar pedidos pendientes: ", 5);
			if (retorno == 1) {
				retorno = Informes_ContarPedidosPendientesPorLocalidad(listaPedidos, tamListaPedidos, listaClientes, tamListaClientes, localidad, &cantidadPedidosPendientes);
				if (retorno == 1) {
					printf("Localidad: %d\nCantidad de pedidos pendientes: %d\n", localidad, cantidadPedidosPendientes);
				}
			}
	}

	return retorno;
}

int Informes_CalcularCantidadKilosPPRecicladosPorCliente(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes) {
	int retorno;
	int cantidadClientes;
	float cantidadKilosPP;
	float promedio;
	retorno = 0;

	if (listaPedidos != NULL && tamListaPedidos > 0 && listaClientes != NULL && tamListaClientes > 0) {
		eCliente_ContarCantidadDeClientes(listaClientes, tamListaClientes, &cantidadClientes);
		if (cantidadClientes > 0) {
			retorno = ePedido_AcumularKilosDePP(listaPedidos, tamListaPedidos, listaClientes, tamListaClientes, &cantidadKilosPP);
			promedio = cantidadKilosPP / cantidadClientes;
			printf("Cantidad de kilogramos promedio de polipropileno reciclados por cliente: %.4f\n", promedio);
		} else {
			retorno = -1;
		}
	}
	return retorno;
}

int eInformes_ClienteConMasPedidosPendientes (ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int* idCliente) {
	int retorno;
	int maxCliente;
	int flagCliente;
	flagCliente = 0;
	int cantPedidos;
	int idClienteMax;
	retorno = 0;

	for (int i = 0; i < tamListaClientes; i++) {
		if (listaClientes[i].isEmpty == FULL) {
			ePedido_ContarCantidadDePedidosPendientesPorCliente(listaPedidos, tamListaPedidos, listaClientes[i].idCliente, &cantPedidos);
			if (cantPedidos > maxCliente || flagCliente == 0) {
				flagCliente = 1;
				maxCliente = cantPedidos;
				idClienteMax = listaClientes[i].idCliente;
		}
	}
}
	*idCliente = idClienteMax;

	return retorno;
}

int eInformes_ClienteConMasPedidosCompletados (ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int* idCliente) {
	int retorno;
	int maxCliente;
	int flagCliente;
	flagCliente = 0;
	int cantPedidos;
	int idClienteMax;
	retorno = 0;

	for (int i = 0; i < tamListaClientes; i++) {
		if (listaClientes[i].isEmpty == FULL) {
			ePedido_ContarCantidadDePedidosCompletadosPorCliente(listaPedidos, tamListaPedidos, listaClientes[i].idCliente, &cantPedidos);
			if (cantPedidos > maxCliente || flagCliente == 0) {
				flagCliente = 1;
				maxCliente = cantPedidos;
				idClienteMax = listaClientes[i].idCliente;
		}
	}
}
	*idCliente = idClienteMax;

	return retorno;
}

int eInformes_ClienteConMasPedidos (ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int* idCliente) {
	int retorno;
	int maxCliente;
	int flagCliente;
	flagCliente = 0;
	int cantPedidos;
	int idClienteMax;
	retorno = 0;

	for (int i = 0; i < tamListaClientes; i++) {
		if (listaClientes[i].isEmpty == FULL) {
			ePedido_ContarCantidadDePedidosPorCliente(listaPedidos, tamListaPedidos, listaClientes[i].idCliente, &cantPedidos);
			if (cantPedidos > maxCliente || flagCliente == 0) {
				flagCliente = 1;
				maxCliente = cantPedidos;
				idClienteMax = listaClientes[i].idCliente;
		}
	}
}
	*idCliente = idClienteMax;

	return retorno;
}
/*
int flagClientes;
int cantPedidos;
flagClientes = -1;

if (listaPedidos != NULL && tamListaPedidos > 0 && listaClientes != NULL && tamListaClientes > 0) {
	flagClientes = 0;
	for (int i = 0; i < tamListaClientes; i++) {
		if (listaClientes[i].isEmpty == FULL) {
			if (flagClientes == 0) {
				printf("ID	nombre	CUIT			direccion			localidad\n\n");
				flagClientes = 1;
			}
			eCliente_MostrarCliente(listaClientes[i]);
			ePedido_ContarCantidadDePedidosPendientesPorCliente(listaPedidos, tamListaPedidos, listaClientes[i].idCliente, &cantPedidos);
			printf("cantidad de pedidos de recolección pendientes: %d\n", cantPedidos);
			printf("--------------------------------------------------------------------------------\n");
		}
	}
}
return flagClientes;*/










