#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
using namespace std;

class Cliente{
  private:
    string nombre;
  public:
    Cliente();
    Cliente(string nuevo_nombre);
    void ordenar_comida();
    void pagar();
};

Cliente::Cliente(){
    nombre="";
}

Cliente::Cliente(string nuevo_nombre){
    nombre=nuevo_nombre;
}

void Cliente::ordenar_comida(){

}

void Cliente::pagar(){

}

#endif // CLIENTE_H_INCLUDED

