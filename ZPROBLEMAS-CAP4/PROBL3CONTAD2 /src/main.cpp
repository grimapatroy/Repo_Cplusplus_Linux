#include <iostream>
#include <stdio.h>
#include "../include/tads/Coll.hpp"
#include "../include/tads/testTools.hpp"
// #include "funciones/files.hpp"
// #include "../funciones/strings.hpp"
// #include "../funciones/tokens.hpp"
// #include "../tads/Coll.hpp"

using namespace std;

// Emisión de tickets (4 y 5)



int main()
{
        // Coll<RProducto> collProductos = subirProductos();
    // emcapsulo , productosCreate() es una funcion del TAD's donde ahi una coleccion de productos 
    Productos cproductos = productosCreate();


    // Coll<RRubro> collRubros = subirRubros();
    Rubros crubros = rubrosCreate();

    int nroTk{0};
    int idCliente {0}, idProducto {0}, cant {0};
    
    cout<<"INGRESE CODIGO DE CLIENTE: ";
    cin>>idCliente;
    cout<<"INGRESE NUMERO DEL TICKET ULTIMO: ";
    cin>>nroTk;

    // es como un constructor solo para iniciar el numero tikets
    Tikets Tk = tiketsCreate(nroTk);

    while (idCliente>0)
    {
        
        // creo coleccion vacia de sitems para cada compra del cliente 
        // Coll<Item> collItems = coll<Item>();
        // reseteo un tikets para la proxima venta
        tiketsReset(Tk);

        cout<<"INGRESE CODIGO DE PRODUCTO: ";
        cin>>idProducto;
        cout<<"INGRESE CANTIDAD DE PRODUCTOS: ";
        cin>>cant;

        while (idProducto>0)
        {
            // funcion del programa , parte del main
            procesar(cproductos,crubros,Tk,idProducto,cant);

            cout<<"INGRESE CODIGO DE PRODUCTO: ";
            cin>>idProducto;
            cout<<"INGRESE CANTIDAD DE PRODUCTOS: ";
            cin>>cant;
        }

        tiketsImprimir(Tk);
        cout<<"INGRESE CODIGO DE CLIENTE: ";
        cin>>idCliente;
    }
    
    rubroMostarDesct(crubros);
    productoMostrarDemanda(cproductos);
    return 0;
}

