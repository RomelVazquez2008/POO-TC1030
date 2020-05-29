#include<iostream>
using namespace std;
#include "Orden.h"
#include "comida.h"
#include "empleado.h"
#include "mesero.h"
#include "chef.h"

//Romel Aldair Vàzquez Molina A01700519

int main(){
//EJEMPLO 1 polimorfismo
//Este es un ejemplo simple de polimorfismo, el cual imprime los atributos de cada clase
cout<<"INICIO PRUEBA 1"<<endl;
Empleado *prueba_1=new Mesero("Veyarel Vazquez",1);
Empleado *prueba_2=new Chef("Emereli Vazquez",1);
prueba_1->descripcion();
prueba_2->descripcion();
delete prueba_1, prueba_2;
cout<<"FIN PRUEBA 1"<<endl;

//EJEMPLO 2 polimorfismo
//Estos métodos, por parte del mesero, distribuye las ordenes, mientras que el chef las prepara
//NOTA: Este ejemplo todavía no está del todo completado, ya que el chef va a imprimiendo
//      una lista de todos los platillos que prepara, pero por falta de tiempo en debuggear
//      errores de lógica, todavía no está terminado al 100%

//Se crea un ejemplo de platillos, que se van a mandar a preparar
cout<<"INICIO PRUEBA 2"<<endl;
Comida platillo1("Sopa de estrellas", "Enchilada","Agua de Jamaica", "Helado", 70);
Comida platillo2("Sopa azteca", "Carne asada","Agua de horchata","Pastel imposible", 150);
Comida pedido[100];
pedido[0]=platillo1;
pedido [1]=platillo2;

//Mandamos a crear objetos de tipo apuntador, para poder efectuar el polimorfismo del método atender_orden
Empleado *prueba_a=new Mesero("Luis Edgar",1);

//Usamos los dynamic cast, para hacer un switch entre las clases padres e hijas
dynamic_cast<Mesero*>(prueba_a)->set_orden(0);
dynamic_cast<Mesero*>(prueba_a)->agregar_comida_en_orden(0,pedido);
Empleado *prueba_b=new Chef("Francisco Rojas",1);

//Se mandan a llamar lo métodos que involucran polimorfismo
prueba_a->atender_orden(0);
prueba_b->atender_orden(0);
prueba_a->atender_orden(0);
delete prueba_a,prueba_b;
cout<<"FIN PREUBA 2"<<endl;
}
