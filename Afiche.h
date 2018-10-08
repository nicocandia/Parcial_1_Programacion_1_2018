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

int vender_Afiche(Afiche*afiches,int indice,int tamanio,int id);

int inicializar_Afiche(Afiche*afiches,int tamanio);

int buscarLugarlibre_Afiche(Afiche*afiches,int tamanio);

int modificar_Datos_Afiche(int id,Afiche*afiches,int tamanio_Afiches);

int eliminarCliente_ytodassusVentas(Afiche*afiches,int id,int tamanio);

int verificarExiste_idAfiche(int id,Afiche *afiches);

int generarID_Afiche();

int imprimir_Datos_clienteSegunIdAfiche(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches,int idAfiche);

void modificarEstadoAfiche_porId(Afiche*afiches,int tamanio_afiches,int idAfiche);

void imprimir_afiches(Afiche*afiches,int tamanio);

int utn_getArchivo(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

#endif // AFICHE_H_INCLUDED
