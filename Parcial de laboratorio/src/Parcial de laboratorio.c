/*
============================================================================
 Name        : Parcial.c
 Author      : Alejo Martin Carmona
 Version     : V1
 Copyright   : Your copyright notice
 Description : Primer parcial de Laboratorio I. UTN FRA.
 Fecha		 : 14/10/21
============================================================================
*/

#include "Informes.h"
#define TAMC 100
#define TAMP 1000
#define TAML 5

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int resultado;
	int auxInt;
	int retornoFuncion;
	int contadorIdCliente;
	int contadorIdPedidos;
	contadorIdCliente = 0;
	contadorIdPedidos = 0;

	eCliente listaClientes[TAMC];
	eCliente_InicializarListaClientes(listaClientes, TAMC);
	ePedido listaPedidos[TAMP];
	ePedido_InicializarListaPedidos(listaPedidos, TAMP);
	eLocalidad listaLocalidades[TAML] = {{1, "Lanus", FULL}, {2, "Lomas", FULL}, {4, "Banfield", FULL}, {5, "Caballito", FULL}, {5, "Adrogue", FULL} };
	ePedido_InicializarListaPedidos(listaPedidos, TAMP);

	do {
		printf("|||||||||||||||||||||||||||||||||||||||||||\n||||RECOLECCION Y RECICLADO DE RESIDUOS||||\n|||||||||||||||||||||||||||||||||||||||||||\n"
				"1. Alta de cliente\n"
				"2. Modificar datos de cliente\n"
				"3. Baja de cliente\n"
				"4. Crear pedido de recolección\n"
				"5. Procesar residuos\n"
				"6. Imprimir clientes con sus pedidos pendientes\n"
				"7. Imprimir pedidos pendientes\n"
				"8. Imprimir pedidos procesados\n"
				"9. Consultar pedidos pendientes para una localidad\n"
				"10. Consultar cantidad de kilos de PP por cliente\n"
				"0. Salir\n\n");

		resultado = IngresarEntero(&opcion, "Elija una opcion: ");
		printf("--------------------------------------------------\n");

		if (resultado == 1) {
			switch(opcion){
				case 1:
					retornoFuncion = eCliente_AltaCliente(listaClientes, TAMC, listaLocalidades, TAML, &contadorIdCliente);
					printf("--------------------------------------------------\n");
					if (retornoFuncion == 1) {
						printf("El alta se realizó con éxito.\nID del cliente generado: %d\n", contadorIdCliente);
					} else {
						if (retornoFuncion == 0){
							printf("¡¡ERROR!! No se pudo realizar el alta del cliente.\n");
						} else {
							printf("¡¡ERROR!! No hay espacio disponible en la lista de clientes.\n");
						}
					}
				break;
				case 2:
					retornoFuncion = eCliente_ModificarCliente(listaClientes, listaLocalidades, TAML, TAMC);
					printf("--------------------------------------------------\n");
					if (retornoFuncion == 1) {
						printf("Modificacion realizada con éxito.\n");
					} else {
						if (retornoFuncion == -1) {
							printf("¡¡ERROR!! Cliente no encontrado en la lista.\n");
						} else {
							if (retornoFuncion == -2) {
								printf("¡¡ERROR!! No hay clientes para modificar.\n");
							} else {
								printf("¡¡ERROR!! No se pudo realizar la modificación.\n");
							}
						}
					}
				break;
				case 3:
					retornoFuncion = ePedido_VerificarPedidosPendientes(listaPedidos, TAMP, listaClientes, TAMC, &auxInt);
					if (retornoFuncion == -3) {
						retornoFuncion = eCliente_BajaCliente(listaClientes, TAMC, auxInt);
						printf("--------------------------------------------------\n");
						if (retornoFuncion == 1) {
							printf("Cliente dado de baja con éxito.\n");
						} else {
							if (retornoFuncion == -2) {
								printf("Operacion cancelada.\n");
							}
						}
					} else {
						if (retornoFuncion == -1) {
							printf("¡¡ERROR!! Cliente no encontrado en la lista.\n");
						} else {
							if (retornoFuncion == -2) {
								printf("¡¡ERROR!! No hay clientes para dar de baja.\n");
							} else {
								if (retornoFuncion == 1) {
									printf("¡¡ERROR!! El cliente tiene pedidos pendientes y no puede darse de baja.\n");
								}
							}
						}
					}
					if (retornoFuncion == 0) {
						printf("¡¡ERROR!! No se pudo dar de baja al cliente.\n");
					}
				break;
				case 4:
					retornoFuncion = ePedido_CrearPedido(listaPedidos, TAMP, &contadorIdPedidos, listaClientes, TAMC);
					printf("--------------------------------------------------\n");
					if (retornoFuncion == 1) {
						printf("El pedido se pudo cargar con éxito.\n");
					} else {
						if (retornoFuncion == 0) {
							printf("¡¡ERROR!! El pedido no se pudo cargar correctamente.\n");
						} else {
							if (retornoFuncion == -1) {
								printf("¡¡ERROR!! No hay espacio disponible en la lista de pedidos.\n");
							} else {
								if (retornoFuncion == -2) {
									printf("¡¡ERROR!! No hay clientes para crear pedidos.\n");
								} else {
									printf("¡¡ERROR!! No se encontró un cliente con ese ID.\n");
								}
							}
						}
					}
					break;
				case 5:
					retornoFuncion = ePedido_ProcesarPedidos(listaPedidos, TAMP);
					printf("--------------------------------------------------\n");
					if (retornoFuncion == 1) {
						printf("El pedido se ha procesado correctamente.\n");
					} else {
						if (retornoFuncion == -2) {
							printf("¡¡ERROR!! No hay pedidos para ser procesados.\n");
						} else {
							if (retornoFuncion == -1) {
								printf("¡¡ERROR!! No se ha encontrado el pedido a procesar con ese ID o ya se ha procesado previamente.\n");
							} else {
								if (retornoFuncion == -3) {
									printf("¡¡ERROR!! La cantidad de plástico supera la total ingresada previamente.\n");
								} else {
									printf("¡¡ERROR!! No se ha podido procesar el pedido.\n");
								}
							}
						}
					}
				break;
				case 6:
					retornoFuncion = Informes_ImprimirClientesConCantidadPedidosPendientes(listaPedidos, TAMP, listaClientes, TAMC);
					if (retornoFuncion == 0) {
						printf("¡¡ERROR!! No hay clientes en la lista para informar sobre sus pedidos pendientes.\n");
					} else {
						if (retornoFuncion == -1) {
							printf("¡¡ERROR!! No se pudieron imprimir los clientes con la cantidad de pedidos pendientes de cada uno.\n");
						}
					}
				break;
				case 7:
					retornoFuncion = Informes_ImprimirPedidosConClientes(listaPedidos, TAMP, listaClientes, TAMC, PENDIENTE);
					if (retornoFuncion == 0) {
						printf("¡¡ERROR!! No hay pedidos pendientes actualmente.\n");
					} else {
						if (retornoFuncion == -1) {
							printf("¡¡ERROR!! No se pudieron imprimir los pedidos pendientes.\n");
						}
					}
				break;
				case 8:
					retornoFuncion = Informes_ImprimirPedidosConClientes(listaPedidos, TAMP, listaClientes, TAMC, COMPLETADO);
					if (retornoFuncion == 0) {
						printf("¡¡ERROR!! No hay pedidos procesados actualmente.\n");
					} else {
						if (retornoFuncion == -1) {
							printf("¡¡ERROR!! No se pudieron imprimir los pedidos procesados.\n");
						}
					}
				break;
				case 9:
					retornoFuncion = Informes_ImprimirPedidosPendientesParaLocalidad(listaPedidos, TAMP, listaClientes, TAMC);
					printf("--------------------------------------------------\n");
					if (retornoFuncion == -1) {
						printf("¡¡ERROR!! No se pudo encontrar la localidad ingresada en la lista de clientes.\n");
					} else {
						if (retornoFuncion == 0) {
							printf("¡¡ERROR!! No se pudo realizar el informe.\n");
						}
					}
				break;
				case 10:
					retornoFuncion = Informes_CalcularCantidadKilosPPRecicladosPorCliente(listaPedidos, TAMP, listaClientes, TAMC);
					if (retornoFuncion == 0) {
						printf("¡¡ERROR!! Hubo un fallo a la hora de calcular el promedio.\n");
					} else {
						if (retornoFuncion == -1) {
							printf("¡¡ERROR!! No hay clientes cargados en la lista.\n");
						}
					}
				break;
				case 11:
					retornoFuncion = IngresarEntero(&auxInt, "Ingrese id: ");
					eInformes_ClienteConMasPedidosPendientes(listaPedidos, TAMP, listaClientes, TAMC, &auxInt);
				break;
				case 12:
				break;
				case 13:
				break;
				case 0:
					printf("¡Gracias por utilizar el programa!\n");
				break;
				default:
					printf("Por favor. Ingrese una opcion válida.\n");
				break;
			}
		} else {
			printf("ERROR. Ingrese solo números enteros.\n");
		}
		printf("--------------------------------------------------\n");

	} while(opcion != 0);

	return EXIT_SUCCESS;
}
