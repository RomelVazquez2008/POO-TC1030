#ifndef MESERO_H_INCLUDED
#define MESERO_H_INCLUDED

#include<iostream>
using namespace std;
#include "Orden.h"
#include "comida.h"
//ESTA CLASE HEREDA DE LA CLASE EMPLEADO
class Mesero: public Empleado{
    private:
        //ATRIBUTOS
        Orden orde[20];
        int indice_orden;
    public:
        //CONSTRUCTORES
        Mesero ();
        Mesero (string nuevo_nombre, int nuevo_turno);
        //DESTRUCTOR
        ~Mesero();
        //METODOS
        void descripcion();
        void agregar_comida_en_orden(int indice, Comida nuevo_comida[100]);
        //SETTER
        void set_orden(int nuevo_numero_orden);
};
//CONSTRUCTOR DEFAULT
Mesero::Mesero():Empleado(){
    indice_orden=0;
}
//CONSTRUCTOR CON ATRIBUTOS
Mesero::Mesero(string nuevo_nombre, int nuevo_turno):Empleado(nuevo_nombre,nuevo_turno){
    indice_orden=0;
}

//DESTRUCTOR
Mesero::~Mesero(){
}

//SETTER
void Mesero::set_orden(int nuevo_numero_orden){
    Orden nuevo_orden(nuevo_numero_orden);
    orde[indice_orden]=nuevo_orden;
    indice_orden++;
}

//METODO DE SOBREESCRITURA, QUE IMPRIME LOS ATRIBUTOS DE LAS CLASE
void Mesero::descripcion(){
    cout<<"Soy un Mesero"<<endl;
    cout<<"Me llamo: "<<Empleado::get_nombre()<<endl;

    if (Empleado::get_turno()==1){
        cout<<"Estoy trabajando en la fonda"<<endl;
    }
    else{
        cout<<"Estoy tomando tiempo libre"<<endl;
    }
    cout<<"Tengo: "<<indice_orden<<" ordenes en este momento"<<endl;
}

//METODO QUE AYUDA AL ATRIBUTO ORDEN, A AGREGAR COMIDA EN LA ORDEN
void Mesero::agregar_comida_en_orden(int indice, Comida nuevo_comida[100]){
    orde[indice].agregar_comida(nuevo_comida);
}

#endif // MESERO_H_INCLUDED
