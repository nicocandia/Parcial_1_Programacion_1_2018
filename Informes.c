#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Afiche.h"
#define FALSE 0
#define TRUE 1

static int cantidad_VentasaCobrarPosee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente);

static int cantidad_VentasaCobrarPosee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente)
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
    return (acumuladorVenta);
}

void imprimir_clientes_ConventasAcobrarquePosee(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches)
{
    int j=0;
    int ventas;
    for(j=0;j<tamanio_clientes;j++)
        {
            if(clientes[j].estaVacio==FALSE )
                {
                ventas=cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiches,clientes[j].id);
                printf("\n NOMBRE CLIENTE:%s  APELLIDO:%s  CUIT:%s  ID:%d  ESTA VACIO:%d  CANTIDAD DE VENTAS A COBRAR:%d \n",clientes[j].nombre,clientes[j].apellido,clientes[j].cuit,clientes[j].id,clientes[j].estaVacio,ventas);
                }
    }
}
void imprimirCliente_conMenosventasaCobrar(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche)
{
    int i;
    int menosventas=0;
    int idClientemenosVentas=-1;
    int flagPrimeraCantidadminima=0;

        for(i=0;i<tamanio_cliente;i++)
        {
            if(clientes[i].estaVacio==FALSE)
            {
                if(flagPrimeraCantidadminima==0)
                {
                    menosventas=cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiche,clientes[i].id);
                    idClientemenosVentas=clientes[i].id;
                    flagPrimeraCantidadminima=1;
                }
                else if(cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiche,clientes[i].id<menosventas))
                {
                    menosventas=cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiche,clientes[i].id);
                    idClientemenosVentas=clientes[i].id;
                    printf("\nid:%d -menosventas:%d\n",idClientemenosVentas,menosventas);
                }
            }
        }


    /*if(idClientemenosVentas>=0)
        {
            printf("\nel cliente con menos ventas es:\n");
            imprimir_cliente_porIdcliente(clientes,tamanio_cliente,idClientemenosVentas);
        }
        else{printf("\nno hay ventas cargadas\n");}*/
}
