#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <iostream>
using namespace std;

//CLASE PADRE, QUE HEREDAN CHEF Y MESERO
class Empleado{
  protected:
    //ATRIBUTOS
    string nombre;
    bool turno;
  public:
    //CONSTRUCTORES
    Empleado();
    Empleado(string nuevo_nombre, bool nuevo_turno);
    //DESTRUCTOR
    ~Empleado();
    //METODOS
    virtual void atender_orden(int indice)=0;   //Definición de clase abstracta
    void cambiar_turno();
    virtual void descripcion()=0; //Definición de clase abstracta
    //GETTERS
    string get_nombre();
    bool get_turno();
};
//CONSTRUCTOR DEFAULT
Empleado::Empleado(){
  nombre="";
  turno=0;
}
//CONSTRUCTOR CON ATRIBUTOS
Empleado::Empleado(string nuevo_nombre, bool nuevo_turno){
  nombre=nuevo_nombre;
  turno=nuevo_turno;
}
//DESTRUCTOR
Empleado::~Empleado(){
}


//METODO QUE CAMBIA EL TURNO ACTUAL DEL EMPLEADO
void Empleado::cambiar_turno(){
    if (turno==0){
        turno=1;
    }
    else {
        turno=0;
    }
}


//GETTERS
string Empleado::get_nombre(){
    return nombre;
}

bool Empleado::get_turno(){
    return turno;
}
#endif
