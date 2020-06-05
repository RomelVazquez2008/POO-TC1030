#include<iostream>
using namespace std;
#include "Orden.h"
#include "comida.h"
#include "empleado.h"
#include "mesero.h"
#include "chef.h"
#include "menu.h"
#include "cliente.h"

//Romel Aldair Vazquez Molina A01700519

//En esta entrega, ya completé lo del metodo de la semana pasada del polimorfismo
//Este es un prototipo de lo que debe hacer el programa, aunque todavía me hace falta implemtentarlo como menu de opciones
// Así mismo ya definí a la clase Empleado como clase abstracta

//NOTA: para responder a las preguntas solo usar numeros enteros, no negativos.
int main(){
Comida platillo1("Sopa de estrellas", "Enchilada","Agua de Jamaica", "Helado", 70);
Comida platillo2("Sopa azteca", "Carne asada","Agua de horchata","Pastel imposible", 150);
Comida platillo3("Espaguetti", "Milanesa", "Agua de limon", "Conejo Turin", 80);
Comida foraneo("Maruchan", "Huevo", "Agua natural (servida en la Maruchan)", "Galleta Maria",20.99);
Comida listado[10]={platillo1,platillo2,platillo3,foraneo};
Menu dia(listado);
dia.mostrar_lista();
Cliente patron("Elfo Raneo");
Empleado *prueba_a=new Mesero("Luis Edgar",1);
patron.ordenar_comida(dynamic_cast<Mesero*>(prueba_a),dia);
Empleado *prueba_b=new Chef("Francisco Rojas",1);
prueba_a->atender_orden(0);
dynamic_cast<Mesero*>(prueba_a)->copiar_datos_chef(dynamic_cast<Chef*>(prueba_b));
prueba_b->atender_orden(0);
prueba_a->atender_orden(0);
patron.pagar(dynamic_cast<Mesero*>(prueba_a));
delete prueba_a,prueba_b;

//A continuación esta linea de código no se puede compilar debido a que Empleado es una clase abstracta
// Empleado no_se_puede;
}
