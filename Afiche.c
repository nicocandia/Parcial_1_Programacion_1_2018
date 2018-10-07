#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Afiche.h"
#include "Cliente.h"
#define TRUE 1
#define FALSE 0

int vender_Afiche(Afiche*afiches,int indice,int tamanio,int id)
{
    int dadodeAlta=-1;
    int cantidadAficheAuxiliar;
    char nombreArchivoAuxiliar[50];
    int zonaAuxiliar;


        if(indice>=0 && indice<tamanio)
        {
        if(utn_getInt(&cantidadAficheAuxiliar,"\nIngrese cantidad\n","\nerror\n",1,1000,3)==0
            &&
            utn_getLetras(nombreArchivoAuxiliar,50,3,"\ningrese nombre de archivo\n","\nnerror nombre no valido\n")==0
            &&

            utn_getInt(&zonaAuxiliar,"\ningrese 1 para CABA , 2 para ZONA SUR , 3 para ZONA OESTE\n","\nerror, zona no valida\n",1,3,3)==0)
                    {
                        strncpy(afiches[indice].nombreArchivo,nombreArchivoAuxiliar,50);
                        afiches[indice].cantidadAfiche=cantidadAficheAuxiliar;
                        afiches[indice].zona=zonaAuxiliar;
                        afiches[indice].idCliente=id;
                        afiches[indice].estaVacio=FALSE;
                        afiches[indice].id=generarID_Afiche();
                        strncpy(afiches[indice].estado,"a cobrar",50);
                        dadodeAlta=0;
                    }
            }
    return dadodeAlta;
}

int inicializar_Afiche(Afiche*afiches,int tamanio)
{
    int i;
    int retorno=-1;
    if(afiches!=NULL && tamanio>0)
    {
    for(i=0;i<tamanio;i++)
    {
        afiches[i].estaVacio=TRUE;
        retorno=0;
    }
    }
    return retorno;
}

int buscarLugarlibre_Afiche(Afiche*afiches,int tamanio)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<tamanio;i++)
    {
        if(afiches[i].estaVacio==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}

int modificar_Datos_Afiche(int id,Afiche*afiches)
{
    int i;
    int cantidadAuxiliar;
    int zonaAuxiliar;
    int opcion;
    int retorno=-1;

    for(i=0;i<1000;i++)
    {
        if(afiches[i].id==id )
        {

            if(utn_getInt(&opcion,"\nIngrese 1 para cambiar cantidad de afiches, 2 para cambiar zona,  3 para ambos \n","\nError opcion no valida",1,3,3)==0)
            {
                switch(opcion)
                {
                    case 1:
                        if(utn_getInt(&cantidadAuxiliar,"\ningrese nueva cantidad\n","\n error cantidad no valida\n",1,1000,3)==0)
                            {
                                afiches[i].cantidadAfiche=cantidadAuxiliar;
                                retorno=0;
                            }
                        break;

                    case 2:
                        if(utn_getInt(&zonaAuxiliar,"\ningrese nueva zona\n","\nerror zona no valida, debe ser entre 1 y 3",1,3,3)==0)
                            {
                                afiches[i].zona=zonaAuxiliar;
                                retorno=0;
                            }
                            break;

                    case 3:
                        if(utn_getInt(&cantidadAuxiliar,"\ningrese nueva cantidad\n","\n error cantidad no valida\n",1,1000,3)==0
                           &&
                           utn_getInt(&zonaAuxiliar,"\ningrese nueva zona\n","\nerror zona no valida, debe ser entre 1 y 3",1,3,3)==0
                           )
                            {
                                afiches[i].cantidadAfiche=cantidadAuxiliar;
                                afiches[i].zona=zonaAuxiliar;
                                retorno=0;
                            }
                            break;

                }
                retorno=0;
                break;
            }
        }
    }
return retorno;
}

void imprimir_afiches(Afiche*afiches,int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(afiches[i].estaVacio==FALSE)
        {
        printf("\nNOMBRE ARCHIVO:%s \nESTADO:%s \nZONA:%d \nCANTIDAD AFICHES:%d \nID:%d \nID CLIENTE:%d \nESTA VACIO:%d \n",afiches[i].nombreArchivo,afiches[i].estado,afiches[i].zona,afiches[i].cantidadAfiche,afiches[i].id,afiches[i].idCliente,afiches[i].estaVacio);

        }
    }

}

int eliminarCliente_ytodassusVentas(Afiche*afiches,int id,int tamanio)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanio;i++)
    {
        if(afiches[i].idCliente==id && afiches[i].estaVacio==FALSE)
        {
            afiches[i].estaVacio=TRUE;
            retorno=0;
        }
    }
    return retorno;
}

int verificarExiste_idAfiche(int id,Afiche *afiches)
{
    int i;
    int retorno=-1;
    for(i=0;i<100;i++)
        {
            if(afiches[i].id==id && afiches[i].estaVacio==FALSE)
                {
                    retorno=0;
                    break;
                }
        }
        return retorno;
}

int generarID_Afiche()
{
    static int contID_Afiche=0;

    return contID_Afiche++;
}
