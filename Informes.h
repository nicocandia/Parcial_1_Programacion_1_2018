#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void imprimir_clientes_ConventasAcobrarquePosee(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches);

void imprimirCliente_conMenosventasaCobrar(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

void imprimirCliente_conMenosventas_Cobradas(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

void imprimirCliente_conMenosventas(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

void imprimircliente_conMasAfiches_aCobrar(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

void imprimir_Zona_conmasAfichesVendidos(Afiche*afiches,int tamanio_afiche);

void imprimircliente_conMenosAfiches_vendidos(Cliente*clientes,Afiche*afiches,int tamanio_cliente,int tamanio_afiche);

void cantidad_clientes_Compraronmasde_500_afiches(Cliente*clientes,int tamanio_clientes,Afiche*afiches,int tamanio_afiches);

void Imprimir_cantidad_Afiches_vendidos_porlas3zonas(Afiche*afiches,int tamanio_afiche);

int ordenarVentas_Porzona(Afiche*afiches,int tamanio_afiches);

void promedioAfiches_vendidosporCliente(Cliente*clientes,Afiche*afiches,int tamanio_clientes,int tamanio_afiches);

#endif // INFORMES_H_INCLUDED
