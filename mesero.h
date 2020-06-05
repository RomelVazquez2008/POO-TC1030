#ifndef MESERO_H_INCLUDED
#define MESERO_H_INCLUDED

#include<iostream>
using namespace std;
#include "Orden.h"
#include "comida.h"
#include "chef.h"
//ESTA CLASE HEREDA DE LA CLASE EMPLEADO
class Mesero: public Empleado{
    private:
        //ATRIBUTOS
        Orden orde[20];
        int indice_orden;
        Chef copia_chef;
        //METIMOS ESTA CLASE AQUÍ PARA QUE GUARDE LAS ORDENES DEL MESERO, Y LUEGO PASEN AL CHEF ORIGINAL
    public:
        //CONSTRUCTORES
        Mesero ();
        Mesero (string nuevo_nombre, int nuevo_turno);
        //DESTRUCTOR
        ~Mesero();
        //SETTER
        void set_orden(int nuevo_numero_orden);
        //GETTERS
        int get_numero();
        Chef get_copia_chef();
        Orden get_orden(int indice);
        int get_indice_orden();
        //METODOS
        void descripcion();
        void agregar_comida_en_orden(int indice, Comida nuevo_comida[100]);
        void copiar_datos_chef(Chef* nuevo_chef);
        void atender_orden(int indice);
        void incrementar_indice_orden();

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

//GETTERS
Chef Mesero::get_copia_chef(){
    return copia_chef;
}

int Mesero::get_numero(){
    return copia_chef.get_indice_comid();
}

int Mesero::get_indice_orden(){
    return indice_orden;
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
    orde[indice].calcular_total();
}

//METODO QUE INVOLUCRA POLIMORFISMO, PARA QUE EL MESERO SEPA DISTRIBUIR LOS PEDIDOS
void Mesero::atender_orden(int indice){
    if (orde[indice].get_estado()==0){
        for (int j=0;j<100;j++){
            if(orde[indice].get_comida(j).get_precio()==0){
                break;
            }
            else{
                copia_chef.copiar_comida(orde[indice].get_comida(j));
            }
        }
        cout<<"Mesero: Entregada orden a chef"<<endl;
        orde[indice].completar_orden();
    }
    else{
        cout<<"Mesero: Entregando orden a cliente"<<endl;
    }
}

//METODO TODAVIA NO TERMINADO, DONDE EL CHEF DE ESTA CLASE, PUEDE COPIARSE A UN CHEF EXTERNO
void Mesero::copiar_datos_chef(Chef* nuevo_chef){
    for (int j=0;j<100;j++){
            if(copia_chef.get_comid(j).get_precio()==0){
                break;
            }
            else{
                nuevo_chef->set_comid(copia_chef.get_comid(j),j);
            }
    }
    nuevo_chef->set_indice_comid(copia_chef.get_indice_comid());
}

Orden Mesero::get_orden(int indice){
    return orde[indice];
}

void Mesero::incrementar_indice_orden(){
    indice_orden++;
}

#endif // MESERO_H_INCLUDED
