#ifndef INFORMES_H_
#define INFORMES_H_
#include "Pedido.h"
#include "Cliente.h"

int eInformes_ClienteConMasPedidosPendientes (ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int* idCliente);
int eInformes_ClienteConMasPedidosCompletados (ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int* idCliente);
int eInformes_ClienteConMasPedidos (ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int* idCliente);

/// \fn int Informes_ImprimirClientesConCantidadPedidosPendientes(ePedido[], int, eCliente[], int)
/// \brief Imprime los clientes junto con la cantidad de pedidos pendientes de cada uno
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param listaClientes Puntero hacia el array de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \return Retorna 1 si se pudieron imprimir los clientes, o 0 si no habia clientes para imprimir, o si hubo un puntero nulo o tamanio invalido
int Informes_ImprimirClientesConCantidadPedidosPendientes(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes);

/// \fn int Informes_ImprimirPedidosConClientes(ePedido[], int, eCliente[], int)
/// \brief Imprime los pedidos pendientes o procesados, segun se especifique en el parametro "estado", junto con los datos pertinentes a cada caso.
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param listaClientes Puntero hacia el array de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \param estado Estado de los pedidos que se desea imprimir - 0 para pedidos PENDIENTES - 1 para pedidos PROCESADOS
/// \return Retorna 1 si se pudieron imprimir los pedidos especificados - (-1) si hubo un puntero nulo, tamanio o estado invalido - 0 si no hay pedidos de ese tipo
/// actualmente para imprimir
int Informes_ImprimirPedidosConClientes(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int estado);

/// \fn int Informes_ImprimirPedidosPendientesParaLocalidad(ePedido[], int, eCliente[], int)
/// \brief Imprime la cantidad de pedidos pendientes que posee la localidad ingresada por el usuario
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param listaClientes Puntero hacia el array de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \return Retorna 1 si se pudieron contar y mostrar los pedidos pendientes para la localidad ingresada - (-1) si no se pudo encontrar la localidad
/// en la lista de clientes - 0 por puntero nulo o tamanio invalido
int Informes_ImprimirPedidosPendientesParaLocalidad(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes);

/// \fn int Informes_ContarPedidosPendientesPorLocalidad(ePedido[], int, eCliente[], int, char[], int*)
/// \brief Cuenta la cantidad de pedidos pendientes por localidad
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param listaClientes Puntero hacia el array de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \param localidad Localidad para la cual se van a contar sus pedidos pendientes
/// \param contador Puntero hacia el entero donde se va a almacenar la cantidad de pedidos pendientes
/// \return Retorna 1 si se pudieron contar los pedidos pendientes por localidad - (-1) si no se encontró la localidad en el array de clientes - 0 por
/// puntero nulo, o tamanio invalido
int Informes_ContarPedidosPendientesPorLocalidad(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int localidad, int* contador);

/// \fn int Informes_CalcularCantidadKilosPPRecicladosPorCliente(ePedido[], int, eCliente[], int)
/// \brief Calcula y muestra la cantidad promedio polipropileno reciclados por cliente
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param listaClientes Puntero hacia el array de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \return Retorna 1 si pudo calcularse el promedio correctamente - (-1) si no hay clientes para calcular el promedio - 0 por puntero nulo o tamanio invalido
int Informes_CalcularCantidadKilosPPRecicladosPorCliente(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes);

#endif /* INFORMES_H_ */
