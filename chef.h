#ifndef CHEF_H_INCLUDED
#define CHEF_H_INCLUDED

#include<iostream>
using namespace std;
#include "Orden.h"
#include "mesero.h"
//CLASE QUE HEREDA DE LA CLASE EMPLEADO
class Chef: public Empleado{
    private:
        Comida comid[100];
        int indice_comid;
    public:
        //CONSTRUCTORES
        Chef ();
        Chef (string nuevo_nombre, int nuevo_turno);
        //DESTRUCTOR
        ~Chef();
        //METODO
        void descripcion();
        void atender_orden(int indice);
        void copiar_comida(Comida nuevo_comid);
        //SETTER
        void set_indice_comid(int nuevo_indice);
        void set_comid(Comida nuevo_comid, int nuevo_indice);
        //GETTER
        int get_indice_comid();
        Comida get_comid(int nuevo_indice);

};
//CONSTRUCTOR DEFAULT
Chef::Chef():Empleado(){
    indice_comid=0;
}

//CONSTRUCTOR CON ATRIBUTOS
Chef::Chef(string nuevo_nombre, int nuevo_turno):Empleado(nuevo_nombre, nuevo_turno){
    indice_comid=0;
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


void Chef::atender_orden(int indice){
    cout<<"Chef: Preparando orden "<<indice+1<<endl;
    for (int i=0;i<indice_comid;i++){
        cout<<"Cocinado: "<<comid[i].get_sopa()<<endl;
        cout<<"Cocinado: "<<comid[i].get_plato_fuerte()<<endl;
        cout<<"Sirviendo: "<<comid[i].get_bebida()<<endl;
        cout<<"Cocinado: "<<comid[i].get_postre()<<endl;
    }
    cout<<"Chef: Lista orden "<<indice+1<<endl;
}

void Chef::copiar_comida(Comida nuevo_comid){
    comid[indice_comid]=nuevo_comid;
    indice_comid++;
}

int Chef::get_indice_comid(){
    return indice_comid;
}

void Chef::set_indice_comid(int nuevo_indice){
    indice_comid=nuevo_indice;
}

void Chef::set_comid(Comida nuevo_comid, int nuevo_indice){
    comid[nuevo_indice]=nuevo_comid;
}

Comida Chef::get_comid(int nuevo_indice){
    return comid[nuevo_indice];
}

#endif // CHEF_H_INCLUDED
