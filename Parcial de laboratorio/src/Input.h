#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// \fn int IngresarEntero(int*, char[])
/// \brief Solicita un numero entero al usuario y verifica que lo sea, si lo es devuelve el resultado
/// \param numero Puntero a un entero donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \return Retorna 1 si se obtuvo el numero y 0 si no
int IngresarEntero(int* numero, char mensaje[]);

/// \fn int IngresarEnteroConIntentos(int*, char[], char[], int)
/// \brief Solicita un numero entero al usuario y verifica que lo sea, si lo es devuelve el resultado. El usuario tiene
/// intentos para ingresar bien el numero.
/// \param numero Puntero a un entero donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa un dato incorrecto
/// \param intentos Cantidad de intentos que posee el usuario para intentar ingresar el numero entero
/// \return Retorna 1 si se obtuvo el numero y 0 si no
int IngresarEnteroConIntentos(int* numero, char mensaje[], char mensajeError[], int intentos);

/// \fn int IngresarEnteroEntreRangosConIntentos(int*, char[], char[], int, int, int)
/// \brief Solicita un numero entero al usuario y verifica que lo sea y que se encuentre entre dos rangos, si es valido devuelve
/// el numero. El usuario tiene intentos para ingresar bien el numero.
/// \param numero Puntero a un entero donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa un dato incorrecto
/// \param minimo Es el numero maximo a ser aceptado
/// \param maximo Es el minimo minimo a ser aceptado
/// \param intentos Cantidad de intentos que posee el usuario para intentar ingresar el numero entero
/// \return Retorna 1 si se obtuvo el numero y 0 si no
int IngresarEnteroEntreRangosConIntentos(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos);

/// \fn int getInt(int*)
/// \brief Verifica si la cadena ingresada es un entero
/// \param pResultado Puntero a entero donde se dejara el resultado de la funcion
/// \return Retorna 1 (EXITO) si se obtiene un numero entero y 0 (ERROR) si no
int getInt(int *pResultado);

/// \fn int ValidarEntero(char*)
/// \brief Verifica si la cadena ingresada es un entero
/// \param cadena Cadena de caracteres a ser analizada
/// \return Retorna 1 si la cadena es un numero entero y 0 si no lo es
int ValidarEntero(char* cadena);

/// \fn int myGets(char*, int)
/// \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
/// un máximo de 'longitud - 1' caracteres.
/// \param cadena Puntero a una cadena donde se dejara el resultado de la funcion
/// \param longitud Define el tamaño de cadena
/// \return Retorna 1 (EXITO) si se obtiene una cadena y 0 (ERROR) si no
int myGets(char *cadena, int longitud);

/// \fn int IngresarFlotanteConIntentos(float*, char[], char[], int)
/// \brief Solicita un numero flotante al usuario y verifica que lo sea, si lo es devuelve el resultado. El usuario tiene
/// intentos para ingresar bien el numero.
/// \param numero Puntero a un flotante donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa un dato incorrecto
/// \param intentos Cantidad de intentos que posee el usuario para intentar ingresar el numero flotante
/// \return Retorna 1 si se obtuvo el numero y 0 si no
int IngresarFlotanteConIntentos(float* numero, char mensaje[], char mensajeError[], int intentos);

/// \fn int IngresarFlotanteEntreRangosConIntentos(float*, char[], char[], float, float, int)
/// \brief Solicita un numero flotante al usuario y verifica que lo sea y que se encuentre entre dos rangos, si es valido devuelve
/// el numero. El usuario tiene intentos para ingresar bien el numero.
/// \param numero Puntero a un flotante donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa un dato incorrecto
/// \param minimo Es el numero maximo a ser aceptado
/// \param maximo Es el minimo minimo a ser aceptado
/// \param intentos Cantidad de intentos que posee el usuario para intentar ingresar el numero flotante
/// \return Retorna 1 si se obtuvo el numero y 0 si no
int IngresarFlotanteEntreRangosConIntentos(float* numero, char mensaje[], char mensajeError[], float minimo, float maximo, int intentos);

/// \fn int getFloat(float*)
/// \brief Verifica si la cadena ingresada es un flotante
/// \param pResultado Puntero a flotante donde se dejara el resultado de la funcion
/// \return Retorna 1 (EXITO) si se obtiene un numero flotante y 0 (ERROR) si no
int getFloat(float *pResultado);

/// \fn int ValidarFlotante(char*)
/// \brief Verifica si la cadena ingresada es un flotante
/// \param cadena Cadena de caracteres a ser analizada
/// \return Retorna 1 si la cadena es un numero flotante y 0 si no lo es
int ValidarFlotante(char* cadena);

/// \fn int IngresarCadena(char[], int, char[])
/// \brief Solicita una cadena al usuario y verifica que no esté vacia, si no lo está devuelve el resultado
/// \param cadena Puntero a una cadena donde se dejara el resultado de la funcion
/// \param tam Tamanio de la cadena
/// \param mensaje Es el mensaje a ser mostrado
/// \return Retorna 1 si se obtuvo la cadena y 0 si no
int IngresarCadena(char cadena[], int tam, char mensaje[]);

/// \fn int IngresarCadenaConIntentos(char[], int, char[], char[], int)
/// \brief Solicita una cadena al usuario y verifica que no esté vacia, si no lo está devuelve el resultado. El usuario tiene
/// intentos para ingresarla correctamente.
/// \param cadena Puntero a una cadena donde se dejara el resultado de la funcion
/// \param tam Tamanio de la cadena
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa una cadena vacía
/// \param intentos Cantidad de intentos que posee el usuario para ingresar una cadena válida
/// \return Retorna 1 si se obtuvo la cadena y 0 si no
int IngresarCadenaConIntentos(char cadena[], int tam, char mensaje[], char mensajeError[], int intentos);

/// \fn int ValidarCadena(char[])
/// \brief Verifica que la cadena ingresada no esté vacía
/// \param cadena Cadena de caracteres a ser analizada
/// \return Retorna 1 si la cadena no está vacía y 0 si lo está
int ValidarCadena(char cadena[]);

/// \fn int IngresarCadenaSoloLetras(char[], int, char[])
/// \brief Solicita una cadena al usuario y verifica que no esté vacia y que solo esté conformada por letras, si no lo está
/// devuelve el resultado
/// \param cadena Puntero a una cadena donde se dejara el resultado de la funcion
/// \param tam Tamanio de la cadena
/// \param mensaje Es el mensaje a ser mostrado
/// \return Retorna 1 si la cadena no está vacía y está conformada solo por letras, y 0 si no lo está
int IngresarCadenaSoloLetras(char cadena[], int tam, char mensaje[]);

/// \fn int IngresarCadenaSoloLetrasConIntentos(char[], int, char[], char[], int)
/// \brief Solicita una cadena al usuario y verifica que no esté vacia y que solo esté conformada por letras, si no lo está
/// devuelve el resultado
/// \param cadena Puntero a una cadena donde se dejara el resultado de la funcion
/// \param tam Tamanio de la cadena
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa una cadena inválida
/// \param intentos Cantidad de intentos que posee el usuario para ingresar una cadena válida
/// \return Retorna 1 si la cadena no está vacía y está conformada solo por letras, y 0 si no lo está
int IngresarCadenaSoloLetrasConIntentos(char cadena[], int tam, char mensaje[], char mensajeError[], int intentos);

/// \fn int ValidarCadenaSoloLetras(char[])
/// \brief Verifica que la cadena ingresada no esté vacía y solo contenga caracteres alfabéticos
/// \param cadena Cadena de caracteres a ser analizada
/// \return Retorna 1 si la cadena es válida y 0 si no lo es
int ValidarCadenaSoloLetras(char cadena[]);

/// \fn int IngresarCadenaSoloAlfanumericosConIntentos(char[], int, char[], char[], int)
/// \brief Solicita una cadena al usuario y verifica que no esté vacia y que solo esté conformada por caracteres alfanuméricos,
/// si no lo está devuelve el resultado
/// \param cadena Puntero a una cadena donde se dejara el resultado de la funcion
/// \param tam Tamanio de la cadena
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa una cadena inválida
/// \param intentos Cantidad de intentos que posee el usuario para ingresar una cadena válida
/// \return Retorna 1 si la cadena no está vacía y está conformada solo por caracteres alfanuméricos, y 0 si no lo está
int IngresarCadenaSoloAlfanumericosConIntentos(char cadena[], int tam, char mensaje[], char mensajeError[], int intentos);

/// \fn int ValidarCadenaSoloAlfanumericos(char[])
/// \brief Verifica que la cadena ingresada no esté vacía y solo contenga caracteres alfanuméricos
/// \param cadena Cadena de caracteres a ser analizada
/// \return Retorna 1 si la cadena es válida y 0 si no lo es
int ValidarCadenaSoloAlfanumericos(char cadena[]);

/// \fn int IngresarCaracter(char*, char[])
/// \brief Solicita un caracter al usuario
/// \param caracter Puntero a un caracter donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \return Retorna 1 si se obtuvo el caracter y 0 si no
int IngresarCaracter(char* caracter, char mensaje[]);

/// \fn int IngresarCaracterEntreRangos(char*, char[], char[], char, char)
/// \brief Solicita un caracter al usuario entre un rango
/// \param caracter Puntero a un caracter donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa un caracter fuera del rango
/// \param minimo Es el caracter maximo a ser aceptado
/// \param maximo Es el caracter minimo a ser aceptado
/// \return Retorna 1 si se obtuvo el caracter y 0 si no
int IngresarCaracterEntreRangos(char* caracter, char mensaje[], char mensajeError[], char minimo, char maximo);

/// \fn int IngresarCaracterEntreRangosConIntentos(char*, char[], char[], char, char, int)
/// \brief Solicita un caracter al usuario entre un rango. El usuario posee intentos para poder ingresarlo correctamente
/// \param caracter Puntero a un caracter donde se dejara el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa un caracter fuera del rango
/// \param minimo Es el caracter maximo a ser aceptado
/// \param maximo Es el caracter minimo a ser aceptado
/// \param intentos Cantidad de intentos que posee el usuario para intentar ingresar el caracter
/// \return Retorna 1 si se obtuvo el caracter y 0 si no
int IngresarCaracterEntreRangosConIntentos(char* caracter, char mensaje[], char mensajeError[], char minimo, char maximo, int intentos);

/// \fn int IngresarCUIT(char[], int, char[], char[], int)
/// \brief Solicita al usuario que ingrese con un CUIT en el formato indicado (XX-XXXXXXXX-X). El usuario posee intentos para
/// poder ingresarlo correctamente
/// \param cadena Puntero a una cadena donde se dejara el resultado de la funcion
/// \param tam Tamanio de la cadena
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa una cadena inválida
/// \param intentos Cantidad de intentos que posee el usuario para intentar ingresar el caracter
/// \return Retorna 1 si se pudo ingresar la cadena correctamente y 0 si no
int IngresarCUIT(char cadena[], int tam, char mensaje[], char mensajeError[], int intentos);

/// \fn int ValidarCUIT(char[])
/// \brief Valida que la cadena sea un CUIT en el formato correcto (XX-XXXXXXXX-X)
/// \param cadena Cadena de caracteres a ser analizada
/// \return Retorna 1 si la cadena es valida y 0 si no lo es
int ValidarCUIT(char cadena[]);

/// \fn char PedirConfirmacion(char[], char[])
/// \brief Solicita al usuario que ingrese 's' para confirmar y 'n' para denegar
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa un caracter distinto a 's' y 'n'
/// \return Retorna el caracter ingresado
char PedirConfirmacion(char mensaje[], char mensajeError[]);

/// \fn int PedirConfirmacionConIntentos(char*, char[], char[], int)
/// \brief Solicita al usuario que ingrese 's' para confirmar y 'n' para denegar
/// \param caracter Puntero a un caracter donde se va a dejar el resultado de la funcion
/// \param mensaje Es el mensaje a ser mostrado
/// \param mensajeError Es el mensaje a ser mostrado si el usuario ingresa un caracter distinto a 's' y 'n'
/// \param intentos Cantidad de intentos que tiene el usuario para ingresar el dato de manera correcta
/// \return Retorna el caracter ingresado
int PedirConfirmacionConIntentos(char* caracter, char mensaje[], char mensajeError[], int intentos);

#endif /* INPUT_H_ */
