#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int id;
    int estaVacio;
}Cliente;

int inicializar_Cliente(Cliente *cliente,int tamanio);

int dardeAlta_Cliente(Cliente*cliente,int indice,int tamanio);

int buscarLugarlibre_Cliente(Cliente*cliente,int tamanio);

int generarID_Cliente();

int getString(char* pBuffer, int limite);

int utn_getInt(  int* pInt, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos);

int getInt(int* pBuffer);

int verificarArregloSoloNumeros(char *pArreglo);

int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int utn_getCuiloCuit(char *pBuffer,int limite,int reintentos,char* msj,char*msjError);

int buscarCliente_porid(Cliente*clientes,int tamanio,int id);

int modificarDatos_Cliente(Cliente*clientes,int tamanio,int indice);

int dardeBaja_Cliente(Cliente*clientes,int id,int tamanio);

void imprimir_clientes(Cliente*clientes,int tamanio);

int verificarExiste_idCliente(int id,Cliente *clientes);


#endif // CLIENTE_H_INCLUDED
