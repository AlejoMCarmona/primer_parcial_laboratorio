#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "Input.h"
#include "Localidad.h"

typedef struct {
	int idCliente;
	int idLocalidad;
	char nombre[40];
	char cuit[15];
	char direccion[50];
	int isEmpty;
} eCliente;

/// \fn int eCliente_InicializarListaClientes(eCliente[], int)
/// \brief Inicializa la lista de clientes, colocando su campo isEmpty en 1
/// \param lista Puntero hacia el array de clientes a inicializar
/// \param tam Tamanio de la lista de clientes
/// \return Retorna 1 si pudo inicializarla, y 0 si no pudo (puntero nulo o tamanio invalido)
int eCliente_InicializarListaClientes(eCliente lista[], int tam);

/// \fn int eCliente_BuscarPrimeraPosicionLibre(eCliente[], int)
/// \brief Busca la primera posicion libre (campo isEmpty en 1) y retorna el indice donde se encuentra
/// \param lista Puntero hacia el array de clientes
/// \param tam Tamanio de la lista de clientes
/// \return Retorna la posicion de la lista donde encontró un campo libre, (-1) si no encontró un campo libre - (-2) si el puntero es nulo o el tamanio invalido
int eCliente_BuscarPrimeraPosicionLibre(eCliente lista[], int tam);

/// \fn int eCliente_AltaCliente(eCliente[], int, int*)
/// \brief Realiza el alta de un cliente en la lista de clientes
/// \param lista Puntero hacia el array de clientes
/// \param tam Tamanio de la lista de clientes
/// \param contadorId Puntero hacia un entero que es el contador que se utiliza para generar los ids, y se incrementa en uno cada vez que se ingresa un cliente
/// \return Retorna 1 si se pudo hacer el alta de un cliente - (-1) si no hay espacio disponible en la lista - 0 si no se pudo realizar el alta (puntero nulo, tamanio invalido, fallo
///  en el ingreso de los datos del cliente, o indice menor a 0)
int eCliente_AltaCliente(eCliente lista[], int tam , eLocalidad listaLocalidades[], int tamListaLocalidades, int* contadorId);

/// \fn int eCliente_IngresarCliente(eCliente*, int)
/// \brief Ingresa los datos de un cliente, incrementando el contador de ID en uno
/// \param cliente Puntero hacia un cliente, donde se almacenarán los datos
/// \param contadorId Puntero hacia un entero que es el contador que se utiliza para generar los ids, y se incrementa en uno cada vez que se ingresa un cliente
/// \return Retorna 1 si se ingresaron los datos del cliente correctamente, 0 si hubo un fallo en el ingreso
int eCliente_IngresarCliente(eCliente* cliente, eLocalidad listaLocalidades[], int tamListaLocalidades, int contadorId);

/// \fn int eCliente_CargarCliente(eCliente[], int, int*)
/// \brief Carga un cliente en la lista de clientes
/// \param lista Puntero hacia el array de clientes
/// \param tam Tamanio de la lista de clientes
/// \param indice Indice que indica la posicion dentro de la lista donde se va a cargar el cliente
/// \param contadorId Puntero hacia un entero que es el contador que se utiliza para generar los ids, y se incrementa en uno cada vez que se ingresa un cliente
/// \return Retorna 1 si se pudo cargar un cliente en la lista, - 0 si no se pudo (fallo en el ingreso de los datos del cliente, puntero nulo, tamanio invalido o indice menor a 0)
int eCliente_CargarCliente(eCliente lista[], int tam, eLocalidad listaLocalidades[], int tamListaLocalidades, int indice, int* contadorId);

/// \fn int eCliente_ImprimirClientes(eCliente[], int)
/// \brief Imprime la lista de clientes
/// \param lista Puntero hacia el array de clientes
/// \param tam Tamanio de la lista de clientes
/// \return Retorna 1 si pudo imprimir la lista de clientes - 0 si no hay clientes para imprimir - (-1) si el puntero fue nulo o el tamanio invalido
int eCliente_ImprimirClientes(eCliente lista[], int tam);

/// \fn void eCliente_MostrarCliente(eCliente)
/// \brief Muestra todos los datos de un cliente
/// \param cliente Cliente a ser mostrado
void eCliente_MostrarCliente(eCliente cliente);

/// \fn int eCliente_BajaCliente(eCliente[], int, int)
/// \brief Realiza la baja de un cliente de la lista de clientes, pidiendo confirmacion para realizar la operacion
/// \param lista Puntero hacia el array de clientes
/// \param tam Tamanio de la lista de clientes
/// \param id Id del cliente a dar de baja
/// \return Retorna 1 si se pudo realizar la baja con éxito - (-1) si no se encontró un cliente con el ID pasado por parámetros - (-2) si el usuario canceló la operación
/// - 0 si no se pudo dar de baja porque el puntero fue nulo o el tamanio invalido
int eCliente_BajaCliente(eCliente lista[], int tam, int id);

/// \fn int eCliente_BuscarClientePorId(eCliente[], int, int)
/// \brief Busca un cliente en la lista por id
/// \param lista Puntero hacia el array de clientes
/// \param tam Tamanio de la lista de clientes
/// \param id Id del cliente a buscar
/// \return Retorna la posicion del array donde se encuentra el cliente con ese id, o -1 si no pudo, ya sea porque no encontro ese cliente, el puntero es nulo, o el tamanio invalido.
int eCliente_BuscarClientePorId(eCliente lista[], int tam, int id);

/// \fn int eCliente_ModificarCliente(eCliente[], int)
/// \brief Le da a elegir al usuario si quiere modificar el campo direccion o el campo localidad de un cliente, a traves de ingresar el id del mismo previamente.
/// \param lista Puntero hacia el array de clientes
/// \param tam Tamanio de la lista de clientes
/// \return Retorna 1 se pudo realizar la modificacion - (-1) si el cliente no fue encontrado en la lista - (-2) si no hay clientes en la lista - (0) si no se pudo realizar la modificacion,
/// ya sea por puntero nulo, tamanio invalido o por no ingresar un dato correctamente
int eCliente_ModificarCliente(eCliente listaClientes[], eLocalidad listaLocal[], int tamListaLocal, int tam);

/// \fn int eCliente_IngresarModificacion(eCliente[], int, int)
/// \brief
/// \param listaClientes Puntero hacia el array de clientes
/// \param tam Tamanio del vector
/// \param indice Indice donde se va almacena el cliente a modificar en la lista de clientes
/// \param opcion Opcion elegida por el usuario, que indica que campo va a modificar (1- Direccion; 2- Localidad)
/// \return Retorna 1 si se pudo realizar la modificacion con éxito - 0 si no se pudo, ya sea por puntero nulo, indice menor a 0 o un mal ingreso de los datos
int eCliente_IngresarModificacion(eCliente listaClientes[], int tam, eLocalidad listaLocalidades[],int tamLocalidades, int indice, int opcion);

/// \fn int eCliente_ContarCantidadDeClientes(eCliente[], int, int*)
/// \brief Cuenta la cantidad de clientes existentes y activos en la lista de clientes
/// \param listaClientes Puntero hacia la lista de clientes
/// \param tam Tamanio de la lista de clientes
/// \param contadorClientes Puntero hacia un entero donde se va a almacenar la cantidad de clientes
/// \return Retorna 1 si pudo contar los clientes - 0 si algun puntero fue nulo o el tamanio invalido
int eCliente_ContarCantidadDeClientes(eCliente listaClientes[], int tam, int* contadorClientes);

#endif /* CLIENTE_H_ */
