#ifndef PEDIDO_H_
#define PEDIDO_H_
#include "Cliente.h"
#include <float.h>
#define PENDIENTE 0
#define COMPLETADO 1

typedef struct {
	int idPedido;
	int idCliente;
	float cantidadKilosTotales;
	float cantidadKilosHDPE;
	float cantidadKilosLDPE;
	float cantidadKilosPP;
	int estado;
	int isEmpty;
} ePedido;

int ePedido_ContarCantidadDePedidosCompletadosPorCliente(ePedido listaPedidos[], int tamListaPedidos, int idCliente, int* cantPedidos);
int ePedido_ContarCantidadDePedidosPendientesPorCliente(ePedido listaPedidos[], int tamListaPedidos, int idCliente, int* cantPedidos);
int ePedido_ContarCantidadDePedidosPorCliente(ePedido listaPedidos[], int tamListaPedidos, int idCliente, int* cantPedidos);

/// \fn int ePedido_VerificarPedidosPendientes(ePedido[], int, eCliente[], int, int*)
/// \brief Verifica si un cliente tiene pedidos pendientes o no
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param listaClientes Puntero hacia el array de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \param id Puntero a entero que almacena el id del cliente ingresado
/// \return Retorna 1 si tiene pedidos pendientes - (-1) si no se pudo encontrar el cliente con el ID ingresado en la lista - (-2) si no hay clientes en la lista
/// - (-3) si no tiene pedidos pendientes - 0 si no se pudo verificar, por puntero nulo o tamanio invalido de la lista de clientes
int ePedido_VerificarPedidosPendientes(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, int* id);

/// \fn int ePedido_InicializarListaPedidos(ePedido[], int)
/// \brief Inicializa la lista de pedidos, colocando su campo isEmpty en 1
/// \param lista Puntero hacia el array de pedidos a inicializar
/// \param tam Tamanio de la lista de pedidos
/// \return Retorna 1 si pudo inicializarla, y 0 si no pudo (puntero nulo o tamanio invalido)
int ePedido_InicializarListaPedidos(ePedido lista[], int tam);

/// \fn int ePedido_BuscarPrimeraPosicionLibre(ePedido[], int)
/// \brief Busca la primera posicion libre (campo isEmpty en 1) y retorna el indice donde se encuentra
/// \param lista Puntero hacia el array de pedidos
/// \param tam Tamanio de la lista de pedidos
/// \return Retorna la posicion de la lista donde encontró un campo libre, -(-1) si no encontró un campo libre - (-2) si el puntero es nulo o el tamanio invalido
int ePedido_BuscarPrimeraPosicionLibre(ePedido lista[], int tam);

/// \fn int ePedido_CrearPedido(ePedido[], int, int*, eCliente[], int)
/// \brief Crea un pedido para la lista de pedidos. Busca si hay espacio dispnible en la lista de pedidos, y si lo hay, procede a cargar uno en la lista
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param contadorIdPedidos Puntero hacia un entero  que es el contador de los ids para la lista de pedidos
/// \param listaClientes Puntero hacia el array de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \return Retorna 1 si pudo crear un pedido correctamente - (-1) si no hay espacio disponible en la lista de pedidos - (-2) si no hay clientes para cargar pedidos
/// - (-3) si no se encontró un cliente con el ID ingresado - 0 por puntero nulo, tamanio invalido, o mal ingreso de alguno de los datos solicitados
int ePedido_CrearPedido(ePedido listaPedidos[], int tamListaPedidos, int* contadorIdPedidos, eCliente listaClientes[], int tamListaClientes);

/// \fn int ePedido_CargarPedido(ePedido[], int, int, int*, eCliente[], int)
/// \brief Carga un nuevo pedido en la lista de pedidos. Imprime los clientes por pantalla y se le pide al usuario el ID del cliente. Se lo muestra para luego
/// proceder a ingresar los datos del mismo.
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param indice Indice que indica la posicion donde se va a almacenar el nuevo pedido en la lista
/// \param contadorIdPedidos Puntero hacia un entero que es el contador de los ids para la lista de pedidos
/// \param listaClientes Puntero hacia el arraya de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \return Retorna 1 si se pudo cargar el pedido correctamente - (-2) si no hay clientes para cargar un pedido - (-3) si no se encontró el cliente con el ID ingresado
/// - 0 si se ingresó mal un dato solicitado o si algun puntero fue nulo, o tamanio invalido
int ePedido_CargarPedido(ePedido listaPedidos[], int tamListaPedidos, int indice, int* contadorIdPedidos, eCliente listaClientes[], int tamListaClientes);

/// \fn int ePedido_IngresarPedido(ePedido[], int, int*, int)
/// \brief Ingresa los datos para cargar un nuevo pedido en la lista. Se le pregunta al usuario cuantos KG de residuos se van a recolectar en ese pedido de recolección,
/// luego se le asigna un ID al nuevo pedido, se le cambia el valor del campo isEmpty a 0, se lo relaciona con el ID del cliente y cambia su estado a pendiente.
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param indice Indice que indica la posicion donde se va a almacenar el nuevo pedido en la lista
/// \param contadorIdPedidos Puntero hacia un entero que es el contador de los ids para la lista de pedidos
/// \param idCliente Id del cliente para el que se van a ingresar los datos de un nuevo pedido
/// \return Retorna 1 si se pudieron ingresar y cargar los datos del pedido correctamente - 0 si no se pudo, ya sea por datos mal ingresados, punteros invalidos o indice
/// menor a 0
int ePedido_IngresarPedido(ePedido* pedido, int contadorIdPedidos, int idCliente);////////////////////////////////////////////

/// \fn int ePedido_ImprimirPedidos(ePedido[], int)
/// \brief Imprime todos los pedidos de la lista de pedidos
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \return Retorna 1 si pudo imprimir los pedidos - (-1) si no hay pedidos para imprimir - 0 si hubo un puntero nulo, o tamanio invalido
int ePedido_ImprimirPedidos(ePedido listaPedidos[], int tamListaPedidos);

/// \fn int ePedido_ProcesarPedidos(ePedido[], int)
/// \brief Procesa un pedido pendiente de la lista. Imprime los pedidos pendientes y se le pide al usuario que ingresa el ID del pedido
/// a procesar. Luego busca que ese proceso exista para ingresar los datos del mismo
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \return Retorna 1 si el pedido se pudo procesar de manera correcta - (-1) si no se encontró un pedido con el ID ingresado - (-2) si no
/// hay pedidos para ser procesados - (-3) si los KG de plastico ingresados superan los del total ingreasdo previamente - 0 si no se pudo
/// procesar el pedido, ya sea por puntero nulo, tamanio invalido o un mal ingreso de los datos
int ePedido_ProcesarPedidos(ePedido listaPedidos[], int tamListaPedidos);

/// \fn int ePedido_IngresarProceso(ePedido[], int)
/// \brief Se ingresan los datos para procesar un pedido. Se le pide al usuario que ingrese la cantidad de KG de cada plastico recolectado,
/// y permite finalizar el proceso de manera correcta si entre los 3 no superan el total ingresado durante la carga del pedido.
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param indice Indice que indica la posicion donde se almacena el pedido a ser procesado
/// \return Retorna 1 si se pudo cargar el proceso - (-3) si la suma de los 3 tipos de plastico reciclados superan el total ingresado
/// durante la carga del pedido - 0 si hubo un puntero nulo, tamanio invalido, o si el indice fue menor a 0 o mayor al tamanio
int ePedido_IngresarProceso(ePedido listaPedidos[], int tam, int indice);//////////////////////////////////////////

/// \fn int ePedido_BuscarPorId(ePedido[], int, int)
/// \brief Busca un pedido de la lista por ID
/// \param lista Puntero hacia el array de pedidos
/// \param tam Tamanio de la lista de pedidos
/// \param id ID del pedido a buscar en la lista
/// \return Retorna la posicion donde se encuentra el pedido en el array - (-1) si no se pudo encontrar el pedido, o si el puntero fue nulo o el tamanio invalido
int ePedido_BuscarPorId(ePedido lista[], int tam, int id);

/// \fn int ePedido_ContarCantidadDePedidosPendientesPorCliente(ePedido[], int, int, int*)
/// \brief Cuenta la cantidad de pedidos pendientes que posee un cliente
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// \param idCliente ID del cliente a contar sus pedidos pendientes
/// \param cantPedidos Puntero hacia un entero que almacena la cantidad de pedidos pendientes
/// \return Retorna 1 se pudieron contar los pedidos pendientes, o 0 por puntero nulo o tamanio invalido
int ePedido_ContarCantidadDePedidosPendientesPorCliente(ePedido listaPedidos[], int tamListaPedidos, int idCliente, int* cantPedidos);

/// \fn int ePedido_AcumularKilosDePP(ePedido[], int, float*)
/// \brief Acumula los kilos totales desechados por los clientes de polipropileno, teniendo en cuenta solo aquellos que se encuentran activos
/// \param listaPedidos Puntero hacia el array de pedidos
/// \param tamListaPedidos Tamanio de la lista de pedidos
/// /// \param listaClientes Puntero hacia el array de clientes
/// \param tamListaClientes Tamanio de la lista de clientes
/// \param cantPedidos Puntero hacia un entero donde se va a almacenar la cantidad de kilos de propileno
/// \return Retorna 1 se pudieron acumular los kg correctamente, o 0 por puntero nulo o tamanio invalido
int ePedido_AcumularKilosDePP(ePedido listaPedidos[], int tamListaPedidos, eCliente listaClientes[], int tamListaClientes, float* cantKilosPP);

#endif /* PEDIDO_H_ */
