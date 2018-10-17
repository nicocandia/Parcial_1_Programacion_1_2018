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
    int estado;
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
FUNCION MODIFICAR_DATOS_AFICHE: recibe como argumentos un entero id un array del tipo afiche, un entero tamanio y un entero tamanio afiche
y permite modificar al usuario los datos del afiche retorna 0 si se modificaron o sino -1
*/
int modificar_Datos_Afiche(int id,Afiche*afiches,int tamanio_Afiches);

/*
recibe como argumentos un array del tipo afiche un entero id y un entero tamanio y retorna 0 si se dio de baja el cliente y todas sus ventas
sino 0
*/
int eliminarCliente_ytodassusVentas(Afiche*afiches,int id,int tamanio);

/*
FUNCION VERIFICAREXISTE_IDAFICHE: recibe como argumentos un untero id, un array del tipo afiche un entero tamanioafiche
retorna 0 si existe el id del afiche sino -1
*/
int verificarExiste_idAfiche(int id,Afiche *afiches,int tamanio_afiche);

/*
FUNCION GENERARID_AFICHE genera un id unico del tipo entero para cada afiche
*/
int generarID_Afiche();

/*
FUNCION IMPRIMIRDATOSSEGUNCLIENTEID: recibe como argumentos dos array del tipo cliente y afiche ,
y tres enteros retorna 0 e imprimi los datos del cliente relacionados a ese afiche sino -1
*/
int imprimir_Datos_clienteSegunIdAfiche(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches,int idAfiche);

/*
FUNCION MODIFICAR ESTADO AFICHE POR ID: recibe como argumentos un array del tipo afiche como puntero un entero tamanio_afiches, y
otro entero id afiche. y lo que hace es cambiar el estado del afiche de a cobrar a cobrado.
*/
void modificarEstadoAfiche_porId(Afiche*afiches,int tamanio_afiches,int idAfiche);

/*
FUNCION IMPRIMIR AFICHES: recibe como argumentos un array del tipo afiche como puntero y un entero tamanio
imprime los afiches existentes en el sistema
*/
void imprimir_afiches(Afiche*afiches,int tamanio);


/*
FUNCION UTN_getArchivo: recibe como argumentos un array del tipo char como puntero,un entero limite, un entero reintentos
y dos array tipo char como punteros retorna 0 si lo que se ingreso es una cadena de la forma 'nombrearchivo.tipoimagen', sino -1
*/
int utn_getArchivo(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

/*
FUNCION AFICHE_ALTAFORZADA: recibe como argumentos un array del tipo cliente como puntero, un entero tamanio clientes,
un array del tipo afiche como puntero,un entero tamanio afiche,un en tero id cliente,un array del tipo char como puntero,
un entero cantidad afiches ,entero zona y un entero estado. Retorna cero si se dio de alta el cliente ,sino -1
*/
int afiche_altaForzada(Afiche* afiches,int tamanioAfiches,
              Cliente* clientes, int tamanioClientes,
              int idCliente,char* nombreArchivo,int cantidadAfiches,int zona,int estado);

#endif // AFICHE_H_INCLUDED
