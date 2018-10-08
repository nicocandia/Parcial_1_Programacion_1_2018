#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Afiche.h"
#define FALSE 0
#define TRUE 1

static int cantidad_Ventasposee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente);

static int cantidad_Ventasposee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente)
{
    int i;
    int acumuladorVenta=0;

    for(i=0;i<tamanio_Afiche;i++)
    {
        if(afiches[i].idCliente==idCliente && afiches[i].estaVacio==FALSE && strcmp(afiches[i].estado,"a cobrar")==0)
            {
                acumuladorVenta++;
            }
    }
    return acumuladorVenta;
}

void imprimir_clientes_ConventasAcobrarquePosee(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches)
{
    int j=0;
    int ventas;
    for(j=0;j<tamanio_clientes;j++)
        {
            if(clientes[j].estaVacio==FALSE )
                {
                ventas=cantidad_Ventasposee_Cliente(afiches,tamanio_afiches,clientes[j].id);
                printf("\n NOMBRE CLIENTE:%s  APELLIDO:%s  CUIT:%s  ID:%d  ESTA VACIO:%d  CANTIDAD DE VENTAS A COBRAR:%d \n",clientes[j].nombre,clientes[j].apellido,clientes[j].cuit,clientes[j].id,clientes[j].estaVacio,ventas);
                }
    }
}
