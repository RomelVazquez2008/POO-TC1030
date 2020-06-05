#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
using namespace std;
#include "mesero.h"
#include "menu.h"

//CLASE TODAVÌA NO IMPLEMENTADA
class Cliente{
  private:
    //ATRIBUTOS
    string nombre;
  public:
    //CONSTRUCTORES
    Cliente();
    Cliente(string nuevo_nombre);
    //DESTRUCTORES
    ~Cliente();
    //METODOS
    void ordenar_comida(Mesero *nuevo_mesero, Menu nuevo_menu);
    void pagar(Mesero *nuevo_mesero);
};

//CONSTRUCTOR DEFAULT
Cliente::Cliente(){
    nombre="";
}

//CONSTRUCTOR CON PARÀMETROS
Cliente::Cliente(string nuevo_nombre){
    nombre=nuevo_nombre;
}

//DESTRUCTOR
Cliente::~Cliente(){
}

//MÈTODOS
void Cliente::ordenar_comida(Mesero *nuevo_mesero,Menu nuevo_menu){
    int opcion;
    Comida pedido[100];
    int j=0;
    int total=0;
    for (int i=0;i<=nuevo_menu.get_indice_lista();i++){
        cout<<"Cuantas comidas "<<i+1<<" Desea ordenar?"<<endl;
        cin>>opcion;
        total=total+opcion;
        for (j;j<total;j++){
            pedido[j]=nuevo_menu.get_elemento_lista(i);
        }
    }
    int indice=dynamic_cast<Mesero*>(nuevo_mesero)->get_indice_orden();
    dynamic_cast<Mesero*>(nuevo_mesero)->incrementar_indice_orden();
    dynamic_cast<Mesero*>(nuevo_mesero)->set_orden(indice);
    dynamic_cast<Mesero*>(nuevo_mesero)->agregar_comida_en_orden(indice,pedido);
}

void Cliente::pagar(Mesero *nuevo_mesero){
    dynamic_cast<Mesero*>(nuevo_mesero)->get_orden(0).calcular_total();
    float total=dynamic_cast<Mesero*>(nuevo_mesero)->get_orden(0).get_total();
    cout<<Cliente::nombre<<" paga: $"<<total<<endl;
}

#endif // CLIENTE_H_INCLUDED

