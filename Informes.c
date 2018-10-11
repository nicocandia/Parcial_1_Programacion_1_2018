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

void Imprimir_clienteMenosventas(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche)
{
    int i;
    int indiceClientemenosVentas=-1;
    int menosventas;
    int auxiliarCantidadventas_lugarI;
    int auxiliarCantidadventas_lugarImasuno;
    int flagtermindeOrdenar=1;

    while(flagtermindeOrdenar==1)
    {
        flagtermindeOrdenar=0;

        for(i=0;i<tamanio_cliente-1;i++)
        {
            if(clientes[i].estaVacio==FALSE && clientes[i+1].estaVacio==FALSE)
            {
                auxiliarCantidadventas_lugarI=cantidad_Ventasposee_Cliente(afiches,tamanio_afiche,clientes[i].id);
                auxiliarCantidadventas_lugarImasuno=cantidad_Ventasposee_Cliente(afiches,tamanio_afiche,clientes[i+1].id);

                if(auxiliarCantidadventas_lugarI<=auxiliarCantidadventas_lugarImasuno)
                {
                    indiceClientemenosVentas=i;
                    menosventas=auxiliarCantidadventas_lugarI;
                    flagtermindeOrdenar=1;

                }
            }

        }
    }

    if(indiceClientemenosVentas>=0)
    {
        printf("\n NOMBRE CLIENTE:%s  APELLIDO:%s  CUIT:%s  ID:%d  ESTA VACIO:%d  CANTIDAD DE VENTAS A COBRAR:%d \n",clientes[indiceClientemenosVentas].nombre,clientes[indiceClientemenosVentas].apellido,clientes[indiceClientemenosVentas].cuit,clientes[indiceClientemenosVentas].id,clientes[indiceClientemenosVentas].estaVacio,menosventas);
    }
    else
    {
                printf("\nerror , no hay ventas cargadas\n");
    }
}

