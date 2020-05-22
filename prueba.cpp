#include<iostream>
using namespace std;
#include "Orden.h"
#include "comida.h"
#include "empleado.h"
#include "mesero.h"
#include "chef.h"

//Romel Aldair Vázquez Molina
//A01700519
//En esta parte del main solo estamos creando varios objetos, para probar las clases

int main (){
//ejemplo de Agregacion en la clase Orden
Comida platillo1("Sopa de estrellas", "Enchilada","Agua de Jamaica", "Helado", 70);
Comida platillo2("Sopa azteca", "Carne asada","Agua de horchata","Pastel imposible", 150);
Comida pedido[100];
pedido[0]=platillo1;
pedido [1]=platillo2;
Orden orden1(1);
orden1.agregar_comida(pedido);
orden1.calcular_total();
cout<<orden1.get_total()<<endl;

//Sobrecarga de constructores
Mesero vacio;
Mesero lleno ("Luis Angel",0);

//Ejemplo de sobreescritura
Empleado panchito("Francisco Rojas", 1);
panchito.descripcion();
cout<<endl;
Chef eme("Eme", 0);
eme.descripcion();
cout<<endl;
Mesero peddy ("Luis Edgar", 1);
peddy.set_orden(1);
peddy.agregar_comida_en_orden(0,pedido);
peddy.descripcion();
cout<<endl;
}
