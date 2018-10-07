#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Afiche.h"
#define TAMANIO_CLIENTE 100
#define TAMANIO_AFICHE 1000

int main()
{
    Cliente clientes[TAMANIO_CLIENTE];
    Afiche afiches[TAMANIO_AFICHE];
    inicializar_Afiche(afiches,TAMANIO_AFICHE);
    inicializar_Cliente(clientes,TAMANIO_CLIENTE);

    int opcion;
    int indice;
    int id;
    int respuesta;

    printf("\n <<<<<<BIENVENIDO>>>>>>\n");
    do
        {
            if(utn_getInt(&opcion,"\n1-ALTA CLIENTE \n\n2-MODIFICAR DATOS DEL CLIENTE \n\n3-BAJA DE CLIENTE \n\n4-VENDER AFICHES\n\n5-EDITAR VENTA\n\n6-COBRAR VENTA\n\n7-IMPRIMIR CLIENTES\n\n8-SALIR\n\nOPCION??\n","\nError,opcion invalida\n",1,8,3)==0)
                {
                    switch(opcion)
                    {
                    case 1:
                        indice=buscarLugarlibre_Cliente(clientes,TAMANIO_CLIENTE);
                        if(indice>=0)
                            {
                                if(dardeAlta_Cliente(clientes,indice,TAMANIO_CLIENTE)==0)
                                    {
                                        printf("\nAlta exitosa, el id del cliente es: %d\n",clientes[indice].id);

                                    }
                                    else
                                        {printf("\nNo se pudo cargar cliente\n");}
                            }else
                            {printf("\nEl id no existe\n");}
                            break;

                    case 2:
                        if(utn_getInt(&id,"\nIngrese numero id el cliente\n","\nError no es un id correcto\n",0,99,3)==0)
                            {
                                indice=buscarCliente_porid(clientes,TAMANIO_CLIENTE,id);

                                if(indice>=0)
                                    {
                                        if(modificarDatos_Cliente(clientes,TAMANIO_CLIENTE,indice)==0)
                                            {
                                                printf("\nSe modificaron los datos correctamente\n");
                                            }
                                            else{printf("\nNo se modificaron los datos correctamente\n");}
                                    }
                                    else{printf("\nID no existe\n");}
                            }
                            else{printf("\nNo se pudo cargar id");}
                            break;

                    case 3:
                        if(utn_getInt(&id,"\nIngrese id cliente a dar de baja\n","\nerror id no valido\n",0,99,3)==0)
                                            {
                                                indice=buscarCliente_porid(clientes,TAMANIO_CLIENTE,id);

                                                if(indice>=0)
                                                {
                                                    if(utn_getInt(&respuesta,"\nSEGURO QUE DESEA CONFIRMAR??\nDIGITE 1 PARA CONFIRMAR - 2 PARA NO CONFIRMAR\n","\nERROR DIGITE 1 O 2\n",1,2,3)==0)
                                                        {
                                                            switch(respuesta)
                                                            {
                                                                case 1:
                                                                    if(dardeBaja_Cliente(clientes,id,TAMANIO_CLIENTE)==0 && eliminarCliente_ytodassusVentas(afiches,id,TAMANIO_AFICHE)==0)
                                                                    {
                                                                        printf("\nSe ha dado de baja el cliente y todas sus ventas\n");
                                                                    }
                                                                break;

                                                                case 2:
                                                                    printf("\nNo se dio de baja el cliente y todas sus ventas\n");
                                                                    break;
                                                            }
                                                        }else{printf("\nerror,no se pudo confirmar\n");}
                                                }
                                                else
                                                {
                                                    printf("\nEl id no existe\n");
                                                }
                                            }
                                                else
                                                {
                                                    printf("\nNo se pudo cargar id\n");
                                                }
                                                break;
                    case 4:
                        if(utn_getInt(&id,"\nIngrese numero id del cliente\n","\nError no es un id correcto\n",0,99,3)==0)
                        {
                            if(verificarExiste_idCliente(id,clientes)==0)
                            {
                            indice=buscarLugarlibre_Afiche(afiches,TAMANIO_AFICHE);
                            if(indice>=0)
                            {
                                printf("\nHay lugar disponible\n");
                                if(vender_Afiche(afiches,indice,TAMANIO_AFICHE,id)==0)
                                {
                                    printf("\nel id del afiche es:%d\n",afiches[indice].id);
                                }
                                else{printf("\nNo se pudo cargar afiche\n");}
                            }
                            else{printf("\nNo hay lugar disponible para afiches\n");}
                            }else{printf("\nNo esta registrado el id\n");}
                        }
                        else{printf("\nDato no valido\n");}
                        break;

                    case 5:
                            imprimir_afiches(afiches,TAMANIO_AFICHE);

                           if(utn_getInt(&id,"\n ingrese id de afiche\n","\n error id no valido\n",0,1000,3)==0)
                            {
                                if(verificarExiste_idAfiche(id,afiches)==0)
                                    {
                                        if(modificar_Datos_Afiche(id,afiches)==0)
                                        {
                                            printf("\nse modificaron correctamente los datos\n");
                                        }
                                            else
                                            {
                                                printf("\nno se pudieron modificar los datos\n");
                                            }
                            }else
                            {
                                printf("\n no existe id afiche\n");
                            }
                            }
                            else
                            {
                                    printf("\nse cargo mal id");
                            }

                        break;

                   /* case 6:
                    if(utn_getCuiloCuit(cuit,TAMANIO_CUIT,3,"\nIngrese cuit del cliente\n","\nError")==0)
                        {   if(verificarExisteCuitPublicidad(publicidades,cuit)==0)
                            {
                            buscariddePantalla_enPublicidad(cuit,LEN_PUBLICIDAD,publicidades,pantallas);
                            if(utn_getInt(&id,"\nIngrese id de la pantalla\n","error",0,99,3)==0)
                            {
                                if(dardeBaja_Publicidad(publicidades,cuit,id)==0)
                                {
                                    printf("\nSe ha dado de baja la contratacion\n");
                                }
                                else
                                    {printf("\nNo se pudieron modificar los datos\n");}
                            }
                            else{printf("\nNo se pudo cargar id\n");}
                        }else{printf("\nNo existe cuit registrado");}
                        }
                        else{printf("\nNo se pudo cargar cuit\n");}
                        break;

                    case 8:
                        listar_Publicidades(publicidades);
                        break;

                    case 7:
                        if(utn_getCuiloCuit(cuit,TAMANIO_CUIT,3,"\nIngrese cuit del cliente\n","\nError")==0)
                        {
                            if(verificarExisteCuitPublicidad(publicidades,cuit)==0)
                                {
                                    imprimirImporte_Facturacionapagar(publicidades,pantallas,cuit);
                                }
                            else{printf("\nNo existe cuit registrado");}
                        }
                    break;

                    case 9:
                    pantalla_Imprimir(pantallas,LEN_PANTALLAS);
                    break;*/
                    case 7:
                        imprimir_clientes(clientes,TAMANIO_CLIENTE);
                        imprimir_afiches(afiches,TAMANIO_AFICHE);
                        break;
                        }
                        }
                }while(opcion!=8);

    return 0;
}
