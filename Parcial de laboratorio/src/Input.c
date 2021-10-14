#include "Input.h"

//REEMPLAZO DE FGETS:
int myGets(char cadena[], int longitud) {
	int retorno;
	retorno = 0;

	fflush(stdin);
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena) {
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 1;
	}
	return retorno;
}

//--INGRESO DE NUMERO ENTEROS
int IngresarEntero(int* numero, char mensaje[]) {
	int retorno;
	int bufferInt;
	retorno = 0;
	if (numero != NULL && mensaje != NULL) {
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 1) {
			*numero = bufferInt;
			retorno = 1;
		}
	}
	return retorno;
}

int IngresarEnteroConIntentos(int* numero, char mensaje[], char mensajeError[], int intentos) {
	int retorno;
	int bufferInt;
	retorno = 0;
	if (numero != NULL && mensaje != NULL) {
		printf("%s", mensaje);
		do {
			intentos--;
			if (getInt(&bufferInt) == 1) {
				*numero = bufferInt;
				retorno = 1;
				break;
			}
			if (intentos != 0) {
				printf("%s", mensajeError);
			}
		} while(intentos > 0);
	}
	return retorno;
}

int IngresarEnteroEntreRangosConIntentos(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos) {//utn_getNumero
	int retorno;
	int bufferInt;
	retorno = 0;

	if (numero != NULL && mensaje != NULL && mensajeError != NULL && intentos > 0 && minimo <= maximo) {
		printf("%s", mensaje);
		while (intentos > 0) {
			intentos--;
			if (getInt(&bufferInt) == 1) {
				if (bufferInt <= maximo && bufferInt >= minimo){
					*numero = bufferInt;
					retorno = 1;
					break;
				}
			}
			if (intentos != 0) {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

int getInt(int *numeroInt) {
	char buffer[64];
	int retorno;
	retorno = 0;
	if (numeroInt != NULL && myGets(buffer, sizeof(buffer)) == 1 && ValidarEntero(buffer)) {
		*numeroInt = atoi(buffer);
		retorno = 1;
	}
	return retorno;
}

int ValidarEntero(char cadena[]) { //esNumerica
	int i;
	int retorno;
	i = 0;
	retorno = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				i++;
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				break;
			}
			i++;
		}
		if (strlen(cadena) == i) {
			retorno = 1;
		}
	}
	return retorno;
}

//--INGRESO DE NUMEROS FLOTANTES
int IngresarFlotante(float* numero, char mensaje[]) {
	int retorno;
	float bufferFloat;
	retorno = 0;

	if (numero != NULL && mensaje != NULL) {
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 1) {
			*numero = bufferFloat;
			retorno = 1;
		}
	}
	return retorno;
}

int IngresarFlotanteConIntentos(float* numero, char mensaje[], char mensajeError[], int intentos) {
	int retorno;
	float bufferFloat;
	retorno = 0;

	if (numero != NULL && mensaje != NULL && mensajeError != NULL && intentos > 0) {
		printf("%s", mensaje);
		while (intentos > 0) {
			intentos--;
			if (getFloat(&bufferFloat) == 1) {
				*numero = bufferFloat;
				retorno = 1;
				break;
			}
			if (intentos != 0) {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

int IngresarFlotanteEntreRangosConIntentos(float* numero, char mensaje[], char mensajeError[], float minimo, float maximo, int intentos) {//utn_getNumero
	int retorno;
	float bufferFloat;
	retorno = 0;

	if (numero != NULL && mensaje != NULL && mensajeError != NULL && intentos > 0 && minimo <= maximo) {
		printf("%s", mensaje);
		while (intentos > 0) {
			intentos--;
			if (getFloat(&bufferFloat) == 1) {
				if (bufferFloat <= maximo && bufferFloat >= minimo) {
					*numero = bufferFloat;
					retorno = 1;
					break;
				}
			}
			if (intentos != 0) {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

int getFloat(float *numeroFloat) {
	int retorno;
	char buffer[64];
	retorno = 0;

	if (numeroFloat != NULL && myGets(buffer, sizeof(buffer)) == 1 && ValidarFlotante(buffer)) {
		*numeroFloat = atof(buffer);
		retorno = 1;
	}
	return retorno;
}

int ValidarFlotante(char cadena[]) {
	int i;
	int retorno;
	int contadorPuntos;
	contadorPuntos = 0;
	i = 0;
	retorno = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				i++;
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				if (cadena[i] == '.' && contadorPuntos == 0) {
					contadorPuntos++;
				} else {
					break;
				}
			}
			i++;
		}
		if (strlen(cadena) == i) {
			retorno = 1;
		}
	}
	return retorno;
}

//INGRESO DE CADENAS:
int IngresarCadena(char cadena[], int tam, char mensaje[]) {
	char cadenaAux[1000];
	int retorno;
	retorno = 0;
	if (cadena != NULL && tam > 0 && mensaje != NULL) {
		printf("%s",mensaje);
		myGets(cadenaAux, sizeof(cadenaAux));
		if (strlen(cadenaAux) < tam) {
			retorno = ValidarCadena(cadenaAux);
			if (retorno == 1) {
				strncpy(cadena, cadenaAux, tam);
			}
		}
	}
	return retorno;
}

int IngresarCadenaConIntentos(char cadena[], int tam, char mensaje[], char mensajeError[], int intentos) {
	char cadenaAux[1000];
	int retorno;
	retorno = 0;

	if (cadena != NULL && tam > 0 && mensaje != NULL && mensajeError != NULL && intentos > 0){
		printf("%s", mensaje);
		do {
			intentos--;
			myGets(cadenaAux, sizeof(cadenaAux));
			if (strlen(cadenaAux) < tam) {
				retorno = ValidarCadena(cadenaAux);
				if (retorno == 1) {
					strncpy(cadena, cadenaAux, tam);
					break;
				}
			}
			if (intentos != 0) {
				printf("%s", mensajeError);
			}
		} while (intentos > 0);
	}
	return retorno;
}

int ValidarCadena(char cadena[]) {
	int i;
	int retorno;
	int flagCaracter;
	i = 0;
	retorno = 0;
	flagCaracter = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (flagCaracter == 0 && isspace(cadena[i]) == 0) {
				flagCaracter = 1;
			}
			i++;
		}
		if (flagCaracter == 1) {
			retorno = 1;
		}
	}
	return retorno;
}

//INGRESO DE CADENAS SOLO ALFABETICAS:
int IngresarCadenaSoloLetras(char cadena[], int tam, char mensaje[]) {
	char cadenaAux[1000];
	int retorno;
	retorno = 0;
	if (cadena != NULL && tam > 0 && mensaje != NULL) {
		printf("%s",mensaje);
		retorno = myGets(cadenaAux, sizeof(cadenaAux));
		if (strlen(cadenaAux) < tam) {
			retorno = ValidarCadenaSoloLetras(cadenaAux);
			if (retorno == 1) {
				strncpy(cadena, cadenaAux, tam);
			}
		}
	}
	return retorno;
}

int IngresarCadenaSoloLetrasConIntentos(char cadena[], int tam, char mensaje[], char mensajeError[], int intentos) {
	char cadenaAux[1000];
	int retorno;
	retorno = 0;

	if (cadena != NULL && tam > 0 && mensaje != NULL && mensajeError != NULL && intentos > 0){
		printf("%s", mensaje);
		do {
			intentos--;
			myGets(cadenaAux, sizeof(cadenaAux));
			if (strlen(cadenaAux) < tam) {
				retorno = ValidarCadenaSoloLetras(cadenaAux);
				if (retorno == 1) {
					strncpy(cadena, cadenaAux, tam);
					break;
				}
			}
			if (intentos != 0) {
				printf("%s", mensajeError);
			}
		} while(intentos > 0);
	}
	return retorno;
}

int ValidarCadenaSoloLetras(char cadena[]) {
	int i;
	int flagUnaLetra;
	int retorno;
	i = 0;
	flagUnaLetra = 0;
	retorno = 0;

	while (cadena[i] != '\0') {
		if ((isspace(cadena[i]) == 0 && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && cadena[i] != 'ñ' && cadena[i] != 'Ñ')) {
			return retorno;
		}
		if (flagUnaLetra == 0 && isspace(cadena[i]) == 0) {
			flagUnaLetra = 1;
		}
		i++;
	}
	if (flagUnaLetra == 1) {
		retorno = 1;
	}
	return retorno;
}

//INGRESO DE CADENAS SOLO ALFANUMERICAS:
int IngresarCadenaSoloAlfanumericosConIntentos(char cadena[], int tam, char mensaje[], char mensajeError[], int intentos) {
	char cadenaAux[1000];
	int retorno;
	retorno = 0;

	if (cadena != NULL && tam > 0 && mensaje != NULL && mensajeError != NULL && intentos > 0){
		printf("%s", mensaje);
		do {
			intentos--;
			myGets(cadenaAux, sizeof(cadenaAux));
			if (strlen(cadenaAux) < tam) {
				retorno = ValidarCadenaSoloAlfanumericos(cadenaAux);
				if (retorno == 1) {
					strncpy(cadena, cadenaAux, tam);
					break;
				}
			}
			if (intentos != 0) {
				printf("%s", mensajeError);
			}
		} while(intentos > 0);
	}
	return retorno;
}

int ValidarCadenaSoloAlfanumericos(char cadena[]) {
	int i;
	int retorno;
	int flagNoVacio;
	retorno = 0;
	i = 0;
	flagNoVacio = 0;//////////////////////////
	while (cadena[i] != '\0') {
		if ((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9')) {
			return retorno;
		}
		if (flagNoVacio == 0 && cadena[i] != ' ') {
			flagNoVacio = 1;
		}
		i++;
	}
	if (flagNoVacio == 1) {
		retorno = 1;
	}
	return retorno;
}

int IngresarCUIT(char cadena[], int tam, char mensaje[], char mensajeError[], int intentos) {
	char cadenaAux[1000];
	int retorno;
	retorno = 0;

	if (cadena != NULL && tam > 0 && mensaje != NULL && mensajeError != NULL && intentos > 0){
		printf("%s", mensaje);
		do {
			intentos--;
			myGets(cadenaAux, sizeof(cadenaAux));
			if (strlen(cadenaAux) < tam) {
				retorno = ValidarCUIT(cadenaAux);
				if (retorno == 1) {
					strncpy(cadena, cadenaAux, tam);
					break;
				}
			}
			if (intentos != 0) {
				printf("%s", mensajeError);
			}
		} while(intentos > 0);
	}
	return retorno;
};

int ValidarCUIT(char cadena[]) {
	int i;
	int retorno;
	i = 0;
	retorno = 0;

	if (cadena != NULL && strlen(cadena) == 13) {
		while (cadena[i] != '\0') {
			if ((cadena[i] < '0' || cadena[i] > '9')) {
				if ((i == 2 || i == 11) && cadena[i] == '-') {
					i++;
					continue;
				}
				return retorno;
			}
			i++;
		}
		if (i == strlen(cadena)) {
			retorno = 1;
		}
	}
	return retorno;
}

//INGRESAR CARACTERES:
int IngresarCaracter(char* caracter, char mensaje[]) {
	int retorno;
	char bufferChar;
	retorno = 0;
	if (caracter != NULL && mensaje != NULL) {
		printf("%s", mensaje);
		scanf("%c", &bufferChar);
		*caracter = bufferChar;
		retorno = 1;
	}
	return retorno;
}

int IngresarCaracterEntreRangos(char* caracter, char mensaje[], char mensajeError[], char minimo, char maximo) {
	int retorno;
	char bufferChar;
	retorno = 0;

	if (caracter != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo) {
		printf("%s", mensaje);
		scanf("%c", &bufferChar);
		if (bufferChar >= minimo && bufferChar <= maximo) {
			*caracter = bufferChar;
			retorno = 1;
		}
	}
	return retorno;
}

int IngresarCaracterEntreRangosConIntentos(char* caracter, char mensaje[], char mensajeError[], char minimo, char maximo, int intentos) {
	int retorno;
	char bufferChar;
	retorno = 0;

	if (caracter != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos > 0) {
		do {
			printf("%s", mensaje);
			scanf("%c", &bufferChar);
			if (bufferChar >= minimo && bufferChar <= maximo) {
				*caracter = bufferChar;
				retorno = 1;
				break;
			}
			printf("%s", mensajeError);
			intentos--;
		} while(intentos > 0);

	}

	return retorno;
}

char PedirConfirmacion(char mensaje[], char mensajeError[]) {
	char caracter;
	printf("%s (s/n)", mensaje);
	fflush(stdin);
	scanf("%c", &caracter);
	caracter = tolower(caracter);
	while (caracter != 's' && caracter != 'n') {
		printf("%s (s/n): ", mensajeError);
		fflush(stdin);
		scanf("%c", &caracter);
		caracter = tolower(caracter);
	}
	return caracter;
}

int PedirConfirmacionConIntentos(char* caracter, char mensaje[], char mensajeError[], int intentos) {
	int retorno;
	char caracterAux;
	retorno = 0;

	if (caracter != NULL && mensaje != NULL && mensajeError != NULL && intentos > 0) {
		intentos--;
		printf("%s (s/n): ", mensaje);
		fflush(stdin);
		scanf(" %c", &caracterAux);
		caracterAux = tolower(caracterAux);
		while ((caracterAux != 's' && caracterAux != 'n') && intentos > 0) {
			intentos--;
			printf("%s (s/n): ", mensajeError);
			fflush(stdin);
			scanf(" %c", &caracterAux);
			caracterAux = tolower(caracterAux);
		}
		if (caracterAux == 's' || caracterAux == 'n') {
			*caracter = caracterAux;
			retorno = 1;
		}
	}
	return retorno;
}
