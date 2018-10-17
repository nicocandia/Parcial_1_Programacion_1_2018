#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Afiche.h"
#include "Informes.h"
#define FALSE 0
#define TRUE 1
#define A_COBRAR 1
#define COBRADO 0
/*
FUNCION CANTIDAD_AFICHESVENDIDOSSEGUNIDCLIENTE: recibe como argumentos un array del tipo afiche como puntero,un
entero tamanioafiche, un entero idcliente y retorna la cantidad de afiches vendidos segun id cliente
*/
static int cantidadAfiches_Vendidos_segunIdcliente(Afiche*afiches,int tamanio_afiches,int idcliente);

/*
FUNCION CANTIDAD_AFICHESVENDIDOSPORZONA: recibe como argumentos un array del tipo afiche como puntero,un
entero tamanioafiche un entero zonaElegida y retorna la cantidad de afiches vendidos segun la zona elegida
segun id cliente
*/
static int cantidad_Afichesvendidospor_Zona(Afiche*afiches,int tamanio_afiche,int zonaElegida);

/*
FUNCION CANTIDAD_VENTASTOTALPOSEECLIENTE: recibe como argumentos un array del tipo afiche como puntero,un
entero tamanioafiche un entero idcliente y retorna la cantidad de ventas totales tanto cobradas como no cobradas
segun id cliente
*/
static int cantidad_VentasaTotalPosee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente);

/*
FUNCION CANTIDADAFICHES_ACOBRARSEGUNIDCLIENTE: recibe como argumentos un array del tipo afiche como puntero,un
entero tamanioafiche un entero idcliente y retorna la cantidad de afiches a cobrar segun el id del cliente
*/
static int cantidadAfiches_acobrarsegunIdcliente(Afiche*afiches,int tamanio_afiches,int idcliente);

/*
FUNCION CANTIDAD_VENTASACOBRARPOSEECLIENTE: recibe como argumentos un array del tipo afiche como puntero
entero tamanioafiche un entero idcliente y retorna la cantidad de ventas a cobrar posee el cliente
*/
static int cantidad_VentasaCobrarPosee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente);

/*
FUNCION CANTIDAD_VENTASCOBRADASPOSEECLIENTE: recibe como argumentos un array del tipo afiche como puntero
entero tamanioafiche un entero idcliente y retorna la cantidad de ventas cobradas posee el cliente
*/
static int cantidad_VentasCobradas_Posee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente);

static int cantidad_VentasaCobrarPosee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente)
{
    int i;
    int acumuladorVenta=0;

    for(i=0;i<tamanio_Afiche;i++)
    {
        if(afiches[i].idCliente==idCliente && afiches[i].estaVacio==FALSE && afiches[i].estado==A_COBRAR)
            {
                acumuladorVenta++;
            }
    }
    return acumuladorVenta;
}

static int cantidad_VentasCobradas_Posee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente)
{
    int i;
    int acumuladorVenta=0;

    for(i=0;i<tamanio_Afiche;i++)
    {
        if(afiches[i].idCliente==idCliente && afiches[i].estaVacio==FALSE && afiches[i].estado==COBRADO)
            {
                acumuladorVenta++;
            }
    }
    return acumuladorVenta;
}

static int cantidad_VentasaTotalPosee_Cliente(Afiche*afiches,int tamanio_Afiche,int idCliente)
{
    int acumuladorVenta=0;

    acumuladorVenta=cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_Afiche,idCliente)+cantidad_VentasCobradas_Posee_Cliente(afiches,tamanio_Afiche,idCliente);

    return acumuladorVenta;
}

int imprimir_clientes_ConventasAcobrarquePosee(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches)
{
    int j=0;
    int ventas;
    int retorno=-1;
    for(j=0;j<tamanio_clientes;j++)
        {
            if(clientes[j].estaVacio==FALSE && cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiches,clientes[j].id)>0)
            {
                ventas=cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiches,clientes[j].id);
                printf("\nNOMBRE CLIENTE:%s -- APELLIDO:%s -- CUIT:%s -- ID:%d -- ESTA VACIO:%d -- CANTIDAD DE VENTAS A COBRAR:%d\n",clientes[j].nombre,clientes[j].apellido,clientes[j].cuit,clientes[j].id,clientes[j].estaVacio,ventas);
                retorno=0;
            }
        }
return retorno;
}
void imprimirCliente_conMenosventasaCobrar(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche)
{
    int i;
    int menosventas=0;
    int idClientemenosVentas;
    int flagPrimeraCantidadminima=0;

        for(i=0;i<tamanio_cliente;i++)
        {
                if( clientes[i].estaVacio==FALSE && flagPrimeraCantidadminima==0 && cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiche,clientes[i].id)>0)
                {
                    idClientemenosVentas=clientes[i].id;
                    menosventas=cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiche,idClientemenosVentas);
                    flagPrimeraCantidadminima=1;

                }
                else if(clientes[i].estaVacio==FALSE && cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiche,clientes[i].id)<menosventas && cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiche,clientes[i].id)>0)
                {
                     menosventas=cantidad_VentasaCobrarPosee_Cliente(afiches,tamanio_afiche,idClientemenosVentas);
                    idClientemenosVentas=clientes[i].id;
                }
        }

        if(menosventas>0)
        {
            printf("\nel cliente con menos ventas a cobrar es:\n");
            imprimir_cliente_porIdcliente(clientes,tamanio_cliente,idClientemenosVentas);
        }
        else{printf("\nno hay ventas a cobrar\n");}
}

void imprimirCliente_conMenosventas_Cobradas(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche)
{
    int i;
    int menosventas=0;
    int idClientemenosVentas;
    int flagPrimeraCantidadminima=0;

        for(i=0;i<tamanio_cliente;i++)
        {
                if( clientes[i].estaVacio==FALSE && flagPrimeraCantidadminima==0 &&cantidad_VentasCobradas_Posee_Cliente(afiches,tamanio_afiche,clientes[i].id)>0)
                {
                    idClientemenosVentas=clientes[i].id;
                    menosventas=cantidad_VentasCobradas_Posee_Cliente(afiches,tamanio_afiche,clientes[i].id);
                    flagPrimeraCantidadminima=1;
                }
                else if(clientes[i].estaVacio==FALSE && cantidad_VentasCobradas_Posee_Cliente(afiches,tamanio_afiche,clientes[i].id)<menosventas && cantidad_VentasCobradas_Posee_Cliente(afiches,tamanio_afiche,clientes[i].id)>0)
                {
                    menosventas=cantidad_VentasCobradas_Posee_Cliente(afiches,tamanio_afiche,clientes[i].id);
                    idClientemenosVentas=clientes[i].id;
                }
            }

        if(menosventas>0 )
        {
            printf("\nel cliente con menos ventas cobradas es:\n");
            imprimir_cliente_porIdcliente(clientes,tamanio_cliente,idClientemenosVentas);
        }
        else{printf("\nno hay ventas cobradas\n");}
}

void imprimirCliente_conMenosventas(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche)
{
    int i;
    int menosventas=0;
    int idClientemenosVentas;
    int flagPrimeraCantidadminima=0;

        for(i=0;i<tamanio_cliente;i++)
        {
                if( clientes[i].estaVacio==FALSE && flagPrimeraCantidadminima==0 && cantidad_VentasaTotalPosee_Cliente(afiches,tamanio_afiche,clientes[i].id)>0)
                {
                    menosventas=cantidad_VentasaTotalPosee_Cliente(afiches,tamanio_afiche,clientes[i].id);
                    idClientemenosVentas=clientes[i].id;
                    flagPrimeraCantidadminima=1;
                }
                else if(clientes[i].estaVacio==FALSE && cantidad_VentasaTotalPosee_Cliente(afiches,tamanio_afiche,clientes[i].id)<menosventas && cantidad_VentasaTotalPosee_Cliente(afiches,tamanio_afiche,clientes[i].id)>0)
                {
                    menosventas=cantidad_VentasaTotalPosee_Cliente(afiches,tamanio_afiche,clientes[i].id);
                    idClientemenosVentas=clientes[i].id;
                }
            }

        if(menosventas>0)
        {
            printf("\nel cliente con menos ventas es:\n");
            imprimir_cliente_porIdcliente(clientes,tamanio_cliente,idClientemenosVentas);
        }
        else{printf("\n no hay ventas \n");}
}

static int cantidadAfiches_acobrarsegunIdcliente(Afiche*afiches,int tamanio_afiches,int idcliente)
{
   int i;
   int acumuladorAfiches=0;
   for(i=0;i<tamanio_afiches;i++)
    {
        if(afiches[i].idCliente==idcliente && afiches[i].estaVacio==FALSE && afiches[i].estado==A_COBRAR)
            {
                acumuladorAfiches=acumuladorAfiches+afiches[i].cantidadAfiche;
            }
    }
   return acumuladorAfiches;
}

void imprimircliente_conMasAfiches_aCobrar(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche)
{
    int i;
    int mayorCantidadAcobrar=0;
    int idClienteMasafiches;
    int flag=0;

        for(i=0;i<tamanio_cliente;i++)
        {
                if( clientes[i].estaVacio==FALSE && flag==0)
                {
                    mayorCantidadAcobrar=cantidadAfiches_acobrarsegunIdcliente(afiches,tamanio_afiche,clientes[i].id);
                    idClienteMasafiches=clientes[i].id;
                    flag=1;
                }
                else if(clientes[i].estaVacio==FALSE && cantidadAfiches_acobrarsegunIdcliente(afiches,tamanio_afiche,clientes[i].id)>mayorCantidadAcobrar)
                {
                    mayorCantidadAcobrar=cantidadAfiches_acobrarsegunIdcliente(afiches,tamanio_afiche,clientes[i].id);
                    idClienteMasafiches=clientes[i].id;
                }
            }

        if(mayorCantidadAcobrar>0)
        {
            printf("\nel cliente con mas afiches a cobrar es:\n");
            imprimir_cliente_porIdcliente(clientes,tamanio_cliente,idClienteMasafiches);
        }
        else{printf("\nno hay afiches a cobrar\n");}
}

static int cantidad_Afichesvendidospor_Zona(Afiche*afiches,int tamanio_afiche,int zonaElegida)
{
    int acumuladorCantidad=0;
    int i;

    for(i=0;i<tamanio_afiche;i++)
        {
            if(afiches[i].estaVacio==FALSE && afiches[i].zona==zonaElegida &&(afiches[i].estado==COBRADO||afiches[i].estado==A_COBRAR))
                {
                    acumuladorCantidad=acumuladorCantidad+afiches[i].cantidadAfiche;
                }
        }
    return acumuladorCantidad;
}

void imprimir_Zona_conmasAfichesVendidos(Afiche*afiches,int tamanio_afiche)
{
    int i;
    int arreglo_afiches_vendidos[3];
    int arreglo_zonas[3];
    int cantidadMaxima=0;
    int zona;
    int flag=0;

    for(i=0;i<3;i++)
        {
            arreglo_afiches_vendidos[i]=cantidad_Afichesvendidospor_Zona(afiches,tamanio_afiche,i+1);
            arreglo_zonas[i]=i+1;
        }
    for(i=0;i<3;i++)
        {
            if(flag==0 && arreglo_afiches_vendidos[i]>0)
                {
                    cantidadMaxima=arreglo_afiches_vendidos[i];
                    zona=arreglo_zonas[i];
                    flag=1;
                }else if(arreglo_afiches_vendidos[i]>cantidadMaxima && arreglo_afiches_vendidos[i]>0)
                {
                    cantidadMaxima=arreglo_afiches_vendidos[i];
                    zona=arreglo_zonas[i];
                }
        }

        if(cantidadMaxima>0)
        {
        printf("\n la zona con mas afiches vendidos es:%d\n",zona);
        }
        else{printf("\n no existe zona con mas afiches vendidos\n");}
}

static int cantidadAfiches_Vendidos_segunIdcliente(Afiche*afiches,int tamanio_afiches,int idcliente)
{
   int i;
   int acumuladorAfiches=0;
   for(i=0;i<tamanio_afiches;i++)
    {
        if(afiches[i].idCliente==idcliente && afiches[i].estaVacio==FALSE &&(afiches[i].estado==COBRADO||afiches[i].estado==A_COBRAR))
            {
                acumuladorAfiches=acumuladorAfiches+afiches[i].cantidadAfiche;
            }
    }
   return acumuladorAfiches;
}

void imprimircliente_conMenosAfiches_vendidos(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche)
{
    int i;
    int menorCantidad=0;
    int idClienteMenosfiches;
    int flag=0;

        for(i=0;i<tamanio_cliente;i++)
        {
                if( clientes[i].estaVacio==FALSE && flag==0 && cantidadAfiches_Vendidos_segunIdcliente(afiches,tamanio_afiche,clientes[i].id)>0)
                {
                    menorCantidad=cantidadAfiches_Vendidos_segunIdcliente(afiches,tamanio_afiche,clientes[i].id);
                    idClienteMenosfiches=clientes[i].id;
                    flag=1;
                }
                else if(clientes[i].estaVacio==FALSE && cantidadAfiches_Vendidos_segunIdcliente(afiches,tamanio_afiche,clientes[i].id)<menorCantidad && cantidadAfiches_Vendidos_segunIdcliente(afiches,tamanio_afiche,clientes[i].id)>0)
                {
                    menorCantidad=cantidadAfiches_Vendidos_segunIdcliente(afiches,tamanio_afiche,clientes[i].id);
                    idClienteMenosfiches=clientes[i].id;
                }
            }

        if(menorCantidad>0)
        {
            printf("\nel cliente con menos afiches comprados es:\n");
            imprimir_cliente_porIdcliente(clientes,tamanio_cliente,idClienteMenosfiches);
        }
        else{printf("\nno hay cliente con menos compras de afiches\n");}
}

void cantidad_clientes_Compraronmasde_500_afiches(Cliente*clientes,int tamanio_clientes,Afiche*afiches,int tamanio_afiches)
{
    int i=0;
    int acumuluadorClientes=0;

    for(i=0;i<tamanio_clientes;i++)
        {
            if(clientes[i].estaVacio==FALSE && cantidadAfiches_Vendidos_segunIdcliente(afiches,tamanio_afiches,clientes[i].id)>500)
                {
                    acumuluadorClientes++;
                }
        }
    if(acumuluadorClientes>0)
        {
            printf("\nla cantidad de clientes que compraron mas de 500 afiches es:%d\n",acumuluadorClientes);
        }else{printf("\nno hay clientes que compraron mas de 500 afiches\n");}
}

void Imprimir_cantidad_Afiches_vendidos_porlas3zonas(Afiche*afiches,int tamanio_afiche)
{
    int cantidadAfichesVendidos_Zona1=cantidad_Afichesvendidospor_Zona(afiches,tamanio_afiche,1);
    int cantidadAfichesVendidos_Zona2=cantidad_Afichesvendidospor_Zona(afiches,tamanio_afiche,2);
    int cantidadAfichesVendidos_Zona3=cantidad_Afichesvendidospor_Zona(afiches,tamanio_afiche,3);

    printf("\ncantidad afiches vendidos CABA:%d\n\ncantidad afiches vendidos ZONA SUR:%d\n\ncantidad afiches vendidos ZONA OESTE:%d\n",cantidadAfichesVendidos_Zona1,cantidadAfichesVendidos_Zona2,cantidadAfichesVendidos_Zona3);
}

int ordenarVentas_Porzona(Afiche*afiches,int tamanio_afiches)
{
    int i;
    Afiche aficheAuxiliar;
    int retorno=-1;
    int flagtermineDeordenar=1;

    while(flagtermineDeordenar==1)
        {
            flagtermineDeordenar=0;
            for(i=0;i<tamanio_afiches-1;i++)
                {
                    if( afiches[i].estaVacio==FALSE && afiches[i+1].estaVacio==FALSE && afiches[i].zona>afiches[i+1].zona)
                        {
                            aficheAuxiliar=afiches[i];
                            afiches[i]=afiches[i+1];
                            afiches[i+1]=aficheAuxiliar;
                            flagtermineDeordenar=1;
                            retorno=0;
                        }
                    if(afiches[i].estaVacio==FALSE)
                        {
                            retorno=0;
                        }
                }
        }
return retorno;
}

void promedioAfiches_vendidosporCliente(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches)
{
    int i;
    int sumaAfiches=0;
    int acumuladorClientes=0;
    int promedio;
    for(i=0;i<tamanio_clientes;i++)
        {
            if(clientes[i].estaVacio==FALSE && cantidadAfiches_Vendidos_segunIdcliente(afiches,tamanio_afiches,clientes[i].id)>0)
                {
                    sumaAfiches+=cantidadAfiches_Vendidos_segunIdcliente(afiches,tamanio_afiches,clientes[i].id);
                    acumuladorClientes++;
                }
        }
    if(acumuladorClientes>0)
        {
            promedio=sumaAfiches/acumuladorClientes;
            printf("\nel promedio de afiches vendidos por cliente es:%d\n",promedio);
        }else
        {printf("\nerror no hay clientes cargados\n");}
}
