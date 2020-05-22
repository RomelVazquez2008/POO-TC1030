#ifndef CHEF_H_INCLUDED
#define CHEF_H_INCLUDED

#include<iostream>
using namespace std;
#include "Orden.h"
//CLASE QUE HEREDA DE LA CLASE EMPLEADO
class Chef: public Empleado{
    public:
        //CONSTRUCTORES
        Chef ();
        Chef (string nuevo_nombre, int nuevo_turno);
        //DESTRUCTOR
        ~Chef();
        //METODO
        void descripcion();
};
//CONSTRUCTOR DEFAULT
Chef::Chef():Empleado(){
}

//CONSTRUCTOR CON ATRIBUTOS
Chef::Chef(string nuevo_nombre, int nuevo_turno):Empleado(nuevo_nombre, nuevo_turno){
}

//DESTRUCTOR
Chef::~Chef(){
}
//METODO DE SOBREESCRITURA, QUE IMPRIME LOS ATRIBUTOS DE LAS CLASE
void Chef::descripcion(){
    cout<<"Soy un Chef"<<endl;
    cout<<"Me llamo: "<<Empleado::get_nombre()<<endl;

    if (Empleado::get_turno()==1){
        cout<<"Estoy trabajando en la fonda"<<endl;
    }
    else{
        cout<<"Estoy tomando tiempo libre"<<endl;
    }
}



#endif // CHEF_H_INCLUDED
