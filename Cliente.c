#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#define TRUE 1
#define FALSE 0

static int isLetras(char*pBuffer);
static int verificarCuitoCuil(char*arreglo);
static int getString(char* pBuffer, int limite);

static int getString(char* pBuffer, int limite)
{
    char bufferString [4096];
    int retorno = -1;
    if(pBuffer != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString) <= limite)
        {
            strncpy(pBuffer,bufferString,limite);
            retorno = 0;
        }
    }
    return retorno;
}

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos)

{
    int retorno=-1;
    int buffer;
    if( pInt != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getInt(&buffer) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pInt = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

int getInt(int* pBuffer)
{
    char bufferString [4096];
    int retorno = -1;


    if(getString(bufferString,4096) == 0 && verificarArregloSoloNumeros(bufferString)==0)
    {
        *pBuffer = atoi(bufferString);
        retorno = 0;
    }

    return retorno;
}

int dardeAlta_Cliente(Cliente*cliente,int indice,int tamanio)
{
    int dadodeAlta=-1;
    char nombreAuxiliar[50];
    char apellidoAuxiliar[50];
    char cuitAuxiliar[50];

        if(indice>=0 && indice<tamanio)
        {
        if(utn_getLetras(nombreAuxiliar,50,3,"\ningrese nombre\n","\nerror\n")==0

            &&utn_getLetras(apellidoAuxiliar,50,3,"\ningrese apellido\n","\nerror\n")==0

            &&utn_getCuiloCuit(cuitAuxiliar,50,3,"\ningrese cuit\n","\n error cuit no valido\n")==0)
            {
                    strncpy(cliente[indice].nombre,nombreAuxiliar,50);
                    strncpy(cliente[indice].apellido,apellidoAuxiliar,50);
                    strncpy(cliente[indice].cuit,cuitAuxiliar,50);
                    cliente[indice].id=generarID_Cliente();
                    cliente[indice].estaVacio=FALSE;
                    dadodeAlta=0;
            }
            }

    return dadodeAlta;
}

/*int pantalla_Imprimir(Pantalla*pantalla,int tamanio)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanio;i++)
        {
            if(pantalla[i].isEmpty==FALSE)
                {
                    printf("\nNOMBRE:%s \nDIRECCION:%s \nTIPO:%d \nID:%d \nPRECIO:%.2f \nISEMPTY:%d \n",pantalla[i].nombre,pantalla[i].direccion,pantalla[i].tipo,pantalla[i].id,pantalla[i].precio,pantalla[i].isEmpty);
                    retorno=0;
                }
        }
        return retorno;
    }*/

int buscarLugarlibre_Cliente(Cliente*cliente,int tamanio)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<tamanio;i++)
    {
        if(cliente[i].estaVacio==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}
int generarID_Cliente()
{
    static int contID_Cliente=0;

    return contID_Cliente++;
}

int verificarArregloSoloNumeros(char *pArreglo)
{
    int i=0;
    int retorno=0;
    char auxiliar=pArreglo[i];
    while(auxiliar!= '\0')
    {
        if(auxiliar==' ' || (auxiliar>='a' && auxiliar<='z') || (auxiliar>='A' && auxiliar<='Z') || auxiliar=='.')
            {
                retorno=-1;
                break;
            }
            i++;
            auxiliar=pArreglo[i];
    }
    return retorno;
}

int inicializar_Cliente(Cliente *cliente,int tamanio)
{
    int i;
    int retorno=-1;
    if(cliente!=NULL && tamanio>0)
    {
    for(i=0;i<tamanio;i++)
    {
        cliente[i].estaVacio=TRUE;
        retorno=0;
    }
    }
    return retorno;
}

int buscarCliente_porid(Cliente*clientes,int tamanio,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanio;i++)
    {
        if(clientes[i].estaVacio==FALSE && clientes[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError)
{
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && isLetras(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}
static int isLetras(char*pBuffer){
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL){
        do{
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer)){
            retorno=0;
        }
    }
    return retorno;
}

int modificarDatos_Cliente(Cliente*clientes,int tamanio,int indice)
 {
     int retorno=-1;
     int opcion;
     char nombreAuxiliar[50];
     char apellidoAuxiliar[50];
     char cuitAuxiliar[50];

     if (indice>=0 && indice<tamanio)
        {
            if(utn_getInt(&opcion,"\nIngrese:\n1 para modificar nombre\n2 para modificar apellido\n3 para modificar cuit\n","\Error, ingrese opcion valida\n",1,3,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            if(utn_getLetras(nombreAuxiliar,50,3,"\nIngrese nuevo nombre\n","\nError, nombre no valido")==0)
                                {
                                    strncpy(clientes[indice].nombre,nombreAuxiliar,50);
                                    retorno=0;
                                }
                            break;

                        case 2:
                            if(utn_getLetras(apellidoAuxiliar,50,3,"\ningrese nuevo apellido\n","\n error apellido no valido\n")==0)
                                {
                                    strncpy(clientes[indice].apellido,apellidoAuxiliar,50);
                                    retorno=0;
                                }
                            break;

                        case 3:
                            if(utn_getCuiloCuit(cuitAuxiliar,50,3,"\nIngrese nuevo cuit\n","\nError cuit no valido\n")==0)
                                {
                                    strncpy(clientes[indice].cuit,cuitAuxiliar,50);
                                    retorno=0;
                                }
                            break;



                    }
                }
        }

     return retorno;
 }

 int dardeBaja_Cliente(Cliente*clientes,int id,int tamanio)
{
    int i=0;
    int retorno=-1;
    if(clientes!=NULL && id>=0)
        {
            for (i=0;i<tamanio;i++)
                {
                    if(clientes[i].id==id)
                        {
                            clientes[i].estaVacio=TRUE;
                            retorno=0;
                            break;
                        }
                }
        }
        return retorno;
}

static int verificarCuitoCuil(char*arreglo)
{
    int retorno;
    int i=0;
    int contadorDigito=0;
    int contadorGuion=0;
    char auxiliar=arreglo[i];
    while(auxiliar!='\0')
        {
            if(!((auxiliar>='0' && auxiliar<='9')|| auxiliar=='-'))
                {
                    retorno=-1;
                    break;
                }
                else{contadorDigito++;}
                 if(auxiliar=='-')
                    {
                        contadorGuion++;
                    }
                i++;
                auxiliar=arreglo[i];
            }
    if(contadorGuion==2 && arreglo[0]>='0' && arreglo[1]>=0 && arreglo[2]=='-' && arreglo[12]>=0 && arreglo[11]=='-' && contadorDigito==13)
        {
            retorno=0;
        }
    return retorno;
}

int utn_getCuiloCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError)
{
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && verificarCuitoCuil(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}

int verificarExiste_idCliente(int id,Cliente *clientes)
{
    int i;
    int retorno=-1;
    for(i=0;i<100;i++)
        {
            if(clientes[i].id==id && clientes[i].estaVacio==FALSE)
                {
                    retorno=0;
                    break;
                }
        }
        return retorno;
}

void imprimir_cliente_porIdcliente(Cliente*clientes,int tamanio,int id)
{
    int i=0;
    for(i=0;i<tamanio;i++)
        {
            if(clientes[i].estaVacio==FALSE && clientes[i].id==id)
                {
                    printf("\n NOMBRE CLIENTE:%s  APELLIDO:%s  CUIT:%s  ID:%d  ESTA VACIO:%d\n",clientes[i].nombre,clientes[i].apellido,clientes[i].cuit,clientes[i].id,clientes[i].estaVacio);
                    break;
                }
        }
}


