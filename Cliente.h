#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int id;
    int estaVacio;
}Cliente;

/*
FUNCION INICIALIZAR_CLIENTE:recibe como argumentos un tipo de dato Cliente como puntero y un entero tamanio retorno -1 si no se pudo inicializar clientes
y retorna 0 si se pudo inicializar poniendo el estadoVacio del cliente en TRUE es decir en 1
*/
int inicializar_Cliente(Cliente *cliente,int tamanio);

/*
FUNCION DARDEALTA_CLIENTE recibe como argumento tipo de dato cliente como puntero, un entero indice y un entero tamanio y pide al usuario
que ingrese los datos del empleado retorna 0 si salio todo bien , sino -1
*/
int dardeAlta_Cliente(Cliente*cliente,int indice,int tamanio);

/*
FUNCION BUSCARLUGARLIBRE_CLIENTE: recibe como argumento tipo de dato Cliente como puntero y un entero tamanio, retorna un entero
que es el indice del lugar libre, sino hay lugar libre retorno -1
*/
int buscarLugarlibre_Cliente(Cliente*cliente,int tamanio);

/*
FUNCION GENERARID_CLIENTE: retorna un entero que se incrementa en cada llamada de la funcion,y ese entero es el id del cliente
*/
int generarID_Cliente();

/*
FUNCION UTN_GETINT recibe como argumento un entero como puntero, dos char como puntero,y tres enteros, minimo ,maximo y reintentos
retorna 0 si se obtuvo un entero ,sino -1
*/
int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos);

int getInt(int* pBuffer);

int verificarArregloSoloNumeros(char *pArreglo);

/*
FUNCION UTN_GETLETRAS recibe como argumentos 3 char como punteros y dos tipos de datos enteros
retorna 0 si el *pbuffer es una palabra , sino retorna -1
*/
int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

/*FUNCION UTN_GETCUILOCUIT recibe como argumentos 3 char como punteros y dos tipos de datos enteros
retorna 0 si el *pbuffer es un cuit de la forma xx-xxxxxxxx-xx  , sino retorna -1
*/
int utn_getCuiloCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

/*
FUNCION BUSCARCLIENTE_PORID: recibe como argumentos tipo de dato Cliente como puntero, un entero tamanio ,otro entero id
retorna 0 si lo encontro , sino -1
*/
int buscarCliente_porid(Cliente*clientes,int tamanio,int id);

/*
FUNCION MODIFICARDATOS_CLIENTE: recibe como argumentos tipo de dato Cliente como puntero, un entero tamanio, un entero indice
retorna 0 si se modificaron los datos del cliente, sino -1
*/
int modificarDatos_Cliente(Cliente*clientes,int tamanio,int indice);

/*
FUNCION DARDEBAJA_CLIENTE: recibe como argumentos un tipo de dato Cliente como puntero, un entero id y un entero tamanio
retorna 0 si se dio de baja el cliente, sino -1
*/
int dardeBaja_Cliente(Cliente*clientes,int id,int tamanio);

/*
FUNCION VERIFICAREXISTE_IDCLIENTE: recibe como argumentos un id del tipo entero y un cliente del tipo de dato Cliente como puntero
retorna 0 si existe cliente , sino -1
*/
int verificarExiste_idCliente(int id,Cliente *clientes);

/*
FUNCION IMPRIMIR_CLIENTE_PORIDCLIENTE: recibe como argumentos un tipo de dato cliente, un entero tamanio y un entero id
y muestra por pantalla el cliente con todos sus datos, solo un cliente
*/
void imprimir_cliente_porIdcliente(Cliente*clientes,int tamanio,int id);

int cliente_altaForzada(Cliente* clientes,int tamanio,char* nombre,char* apellido, char *cuit);



#endif // CLIENTE_H_INCLUDED
