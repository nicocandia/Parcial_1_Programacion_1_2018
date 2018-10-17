#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/*
FUNCION IMPRIMIRCLIENTESCONVENTASACOBRARPOSEE: recibe como argumentos dos array del tipo afiche y cliente como punteros,
un entero tamanio clientes un entero tamanio afiches  e imprime todos los clientes que posean al menos una venta a cobrar
*/
int imprimir_clientes_ConventasAcobrarquePosee(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches);

/*
FUNCION imprimirCliente_conMenosventasaCobrar: recibe como argumentos dos array del tipo cliente y afiche como puntero,
un entero tamaniocliente, un entero tamanio afiche e imprime el cliente con menos ventas a cobrar
*/
void imprimirCliente_conMenosventasaCobrar(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

/*
FUNCION imprimirCliente_conMenosventas_Cobradas: recibe como argumentos dos array del tipo cliente y afiche como puntero,
un entero tamaniocliente, un entero tamanio afiche e imprime el cliente con menos ventas cobradas
*/
void imprimirCliente_conMenosventas_Cobradas(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

/*
FUNCION imprimirCliente_conMenosventas: recibe como argumentos dos array del tipo cliente y afiche como puntero,
un entero tamaniocliente, un entero tamanio afiche e imprime el cliente con menos ventas
*/
void imprimirCliente_conMenosventas(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

/*
FUNCION imprimircliente_conMasAfiches_aCobrar: recibe como argumentos dos array del tipo cliente y afiche como puntero,
un entero tamaniocliente, un entero tamanio afiche e imprime el cliente con mas afiches cobrados
*/
void imprimircliente_conMasAfiches_aCobrar(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

/*
FUNCION imprimir_Zona_conmasAfichesVendidos: recibe como argumentos un array del tipo afiche como puntero
,un entero tamanio afiche e imprime la zona con mas afiches vendidos
*/
void imprimir_Zona_conmasAfichesVendidos(Afiche*afiches,int tamanio_afiche);

/*
FUNCION imprimircliente_conMenosAfiches_vendidos: recibe como argumentos dos array del tipo cliente y afiche como puntero,
un entero tamaniocliente, un entero tamanio afiche e imprime el cliente con menos afiches vendidos
*/
void imprimircliente_conMenosAfiches_vendidos(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

/*
FUNCION cantidad_clientes_Compraronmasde_500_afiches: recibe como argumentos dos array del tipo cliente y afiche como puntero,
un entero tamaniocliente, un entero tamanio afiche e imprime la cantidad de clientes que compraron mas de 500 afiches
*/
void cantidad_clientes_Compraronmasde_500_afiches(Cliente*clientes,int tamanio_clientes,Afiche*afiches,int tamanio_afiches);

/*
FUNCION Imprimir_cantidad_Afiches_vendidos_porlas3zonas:recibe como argumentos dos array del tipo cliente y afiche como puntero,
un entero tamaniocliente, un entero tamanio afiche e imprime por cada zona la cantidad de afiches vendidos
*/
void Imprimir_cantidad_Afiches_vendidos_porlas3zonas(Afiche*afiches,int tamanio_afiche);

/*
FUNCION ordenarVentas_Porzona: recibe como argumentos un array del tipo afiche como puntero y un entero tamanioafiches
retorna 0 si se ordeno, sino -1
*/
int ordenarVentas_Porzona(Afiche*afiches,int tamanio_afiches);

/*
FUNCION promedioAfiches_vendidosporCliente: recibe como argumentos dos array del tipo cliente y afiche como puntero,
un entero tamaniocliente, un entero tamanio afiche e imprime promedio de afiches vendidos por cliente
*/
void promedioAfiches_vendidosporCliente(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches);

#endif // INFORMES_H_INCLUDED
