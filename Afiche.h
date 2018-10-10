#ifndef AFICHE_H_INCLUDED
#define AFICHE_H_INCLUDED
#include "Cliente.h"
typedef struct
{
    int id;
    int idCliente;
    int cantidadAfiche;
    char nombreArchivo[50];
    int zona;
    char estado[50];
    int estaVacio;
}Afiche;

/*
FUNCION VENDER_AFICHE: recibe como argumento un tipo de dato afiche, un indice como entero, un tamanio como entero
y un id como entero, pide al usuario que ingrese los datos del afiche retorna 0 si se cargaron correctamente, sino -1
*/
int vender_Afiche(Afiche*afiches,int indice,int tamanio,int id);

/*
FUNCION INICIALIZAR_AFICHE:recibe como argumentos un tipo de dato Afiche como puntero, un entero tamanio y un entero id
 retorno -1 si no se pudo inicializar afiches
y retorna 0 si se pudo inicializar poniendo el estadoVacio del afiche en TRUE es decir en 1
*/
int inicializar_Afiche(Afiche*afiches,int tamanio);

/*
FUNCION BUSCARLUGARLIBRE_AFICHE: recibe como argumento tipo de dato Afiche como puntero y un entero tamanio, retorna un entero
que es el indice del lugar libre, sino hay lugar libre retorno -1
*/
int buscarLugarlibre_Afiche(Afiche*afiches,int tamanio);

/*

*/
int modificar_Datos_Afiche(int id,Afiche*afiches,int tamanio_Afiches);

int eliminarCliente_ytodassusVentas(Afiche*afiches,int id,int tamanio);

int verificarExiste_idAfiche(int id,Afiche *afiches);

int generarID_Afiche();

int imprimir_Datos_clienteSegunIdAfiche(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches,int idAfiche);

void modificarEstadoAfiche_porId(Afiche*afiches,int tamanio_afiches,int idAfiche);

void imprimir_afiches(Afiche*afiches,int tamanio);

int utn_getArchivo(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

#endif // AFICHE_H_INCLUDED
