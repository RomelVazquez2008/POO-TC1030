#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <iostream>
using namespace std;

//CLASE TODAV�A NO IMPLEMENTADA
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
    void ordenar_comida();
    void pagar();
};

//CONSTRUCTOR DEFAULT
Cliente::Cliente(){
    nombre="";
}

//CONSTRUCTOR CON PAR�METROS
Cliente::Cliente(string nuevo_nombre){
    nombre=nuevo_nombre;
}

//DESTRUCTOR
Cliente::~Cliente(){
}

//M�TODOS
void Cliente::ordenar_comida(){

}

void Cliente::pagar(){

}

#endif // CLIENTE_H_INCLUDED

