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
    void atender_orden();
    void cambiar_turno();
    void descripcion();
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

//METODO NO IMPLMENTADO, PERO SER� CUBIERTO EN LA ENTREGA DE POLIMORFISMO
void Empleado::atender_orden(){

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

//METODO DE SOBREESCRITURA, QUE IMPRIME LOS ATRIBUTOS DE LAS CLASE
void Empleado::descripcion(){
    cout<<"Soy un empleado"<<endl;
    cout<<"Me llamo: "<<Empleado::get_nombre()<<endl;

    if (Empleado::get_turno()==1){
        cout<<"Estoy trabajando en la fonda"<<endl;
    }
    else{
        cout<<"Estoy tomando tiempo libre"<<endl;
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
