// Este programa crea y maneja listas enlazadas 

// Fecha: 04/10/2020
#include "MyLinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

/*
    Descripcion: Constructor de la lista enlazada donde apunta los nodos head y tail a nullptr y el size se iguala a 0
    Input: n/a
    Output: n/a
    Complejidad: O(1).
*/
MyLinkedList::MyLinkedList(){
    this->head = nullptr;
    this->tail = head;
    this->size = 0;
}

/*
    Descripcion: Destruye la lista enlazada borrando el primer nodo hasta que ya no haya nodos
    Input: n/a
    Output: n/a
    Complejidad: O(n).
*/
MyLinkedList::~MyLinkedList(){
    while (this->head != nullptr){
        cout<<"Borrando head con valor " + to_string(first())<<endl;
        removeFirst();
    }
    cout<<"Objeto destruido"<<endl;
}

/*
    Descripcion: Regresa el numero de nodos que tiene la lista enlazada
    Input: n/a
    Output: numero entero de nodos que tiene la lista enlazada
    Complejidad: O(1).
*/
int MyLinkedList::length(){
    return this->size;
}

/*
    Descripcion: Inserta un nodo al inicio de la lista enlazada y aumenta el tamaño de la lista enlazada
    Input: data -> entero con el dato a guardar en ese nodo
    Output: n/a
    Complejidad: O(1).
*/
void MyLinkedList::insertFirst(int data){
    this->head = new NodoLL(data, this->head);
    if(this->size == 0){
        this->tail = this->head;
    }
    this->size++;
}

/*
    Descripcion: Inserta un nodo al final de la lista enlazada y aumenta el tamaño de la lista enlazada
    Input: data -> entero con el dato a guardar en ese nodo
    Output: n/a
    Complejidad: O(1).
*/
void MyLinkedList::insertLast(int data){
    if(this->size == 0){
        insertFirst(data);
    }else{
        this->tail->next = new NodoLL(data);
        this->tail = this->tail->next;
        this->size++;
    }
}

/*
    Descripcion: Cambia el dato de un nodo en una posicion especifica de la lista enlazada 
    Input: data -> entero con el dato a guardar en ese nodo, pos -> entero con el indice donde se va a cambiar el dato del nodo
    Output: Es void, pero puede arrojar una excepcion de argumento invalido si el indice no se encuentra en la lista
    Complejidad: O(n).
*/
void MyLinkedList::setAt(int data, int pos){
    if(pos < size && pos >= 0){
        NodoLL* actual = this->head;
        for(int i = 0; i<pos; i++){
            actual = actual->next;
        }
        actual->dato = data;
    }else{
        throw invalid_argument("No se puede acceder al elemento " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
}

/*
    Descripcion: Inserta un nodo en una posicion especifica de la lista enlazada y aumenta el tamaño de la lista enlazada
    Input: data -> entero con el dato a guardar en ese nodo, pos -> entero con el indice donde se va a insertar el nuevo nodo
    Output: Es void, pero puede arrojar una excepcion de argumento invalido si el indice no se encuentra en la lista
    Complejidad: Mejor caso: O(1), Peor caso: O(n).
*/
void MyLinkedList::insertAt(int data, int pos){
    if(pos < this->size && pos >= 0){
        NodoLL* actual = this->head;
        NodoLL* temp = new NodoLL(data);
        if(pos == 0){
            insertFirst(data);
        }else if(pos == (this->size - 1)){
            insertLast(data);
        }else{
            for(int i = 1; i<pos; i++){
                actual = actual->next;
            }
            temp->next = actual->next;
            actual->next = temp;
            size++;
        }
    }else{
        throw invalid_argument("No se puede acceder al elemento con indice " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
}

/*
    Descripcion: Devuelve el dato en cierta posicion de la lista enlazada 
    Input: pos -> entero con el indice donde esta el nodo 
    Output: Entero con el dato del nodo en la posicion especificada,
            Es void, pero puede arrojar una excepcion de argumento invalido si el indice no se encuentra en la lista
    Complejidad: O(n).
*/
int MyLinkedList::getAt(int pos){
    if(pos >= 0 && pos < this->size){
        NodoLL* current = this->head;
        for(int i = 0; i<pos; i++){
            current = current->next;
        }
        return current->dato;
    }else{
        throw invalid_argument("No se puede acceder al elemento con indice " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
}

/*
    Descripcion: Devuelve el dato del primer nodo
    Input: n/a
    Output: Entero con el dato del primer nodo
    Complejidad: O(1).
*/
int MyLinkedList::first(){
    return this->head->dato;
}

/*
    Descripcion: Devuelve el dato del ultimo nodo
    Input: n/a
    Output: Entero con el dato del ultimo nodo
    Complejidad: O(1).
*/
int MyLinkedList::last(){
    return this->tail->dato;
}

/*
    Descripcion: Devuelve si la lista esta vacia o no, revisando si el tamaño es igual a 0
    Input: n/a
    Output: Bool es true si la lista esta vacia, es falso si la lista tiene algun nodo
    Complejidad: O(1).
*/
bool MyLinkedList::isEmpty(){
    return this->size == 0;
}

/*
    Descripcion: Elimina el nodo al inicio de la lista enlazada y disminuye el tamaño de la lista enlazada
    Input: n/a
    Output: n/a
    Complejidad: O(1).
*/
void MyLinkedList::removeFirst(){
    if(this->isEmpty()){
        return;
    }else if(this->size == 1){
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;
        return;
    }else{
        NodoLL* tmp = this->head;
        this->head = this->head->next;
        delete tmp;
        this->size--;
        return;
    }
}

/*
    Descripcion: Elimina el nodo al final de la lista enlazada y disminuye el tamaño de la lista enlazada
    Input: n/a
    Output: n/a
    Complejidad: Mejor caso: O(1), Peor caso: O(n).
*/
void MyLinkedList::removeLast(){
    if(this->isEmpty()){
        return;
    }else if(this-> size == 1){
        this->tail = nullptr;
        delete this->head;
        this->head = nullptr;
        this->size--;
        return;
    }else{
        NodoLL* current = this->head;
        for(int i = 1; i < this->size-1; i++){
            current = current->next;
        }
        current->next = nullptr;
        delete this->tail;
        this->tail = current;
        this->size--;
        return;
    }
}

/*
    Descripcion: Elimina el nodo en cierta posicion de la lista enlazada y disminuye el tamaño de la lista enlazada
    Input: pos -> entero con el indice donde esta el nodo a eliminar
    Output: Es void, pero puede arrojar una excepcion de argumento invalido si el indice no se encuentra en la lista
    Complejidad: Mejor caso: O(1), Peor caso: O(n).
*/
void MyLinkedList::removeAt(int pos){
    if(pos < this->size && pos >= 0){
        NodoLL* actual = this->head;
        if(pos == 0){
            removeFirst();
        }else if(pos == (this->size - 1)){
            removeLast();
        }else{
            for(int i = 1; i<pos; i++){
                actual = actual->next;
            }
            NodoLL* tmp = actual->next;
            actual->next = tmp->next;
            delete tmp;
            this->size--;  
        }
    }else{
        throw invalid_argument("No se puede acceder al elemento con indice " + to_string(pos) + " en una lista de tamaño " + to_string(this->size));
    }
}

int main(){
    MyLinkedList lista;
    try
    {
        /*
            Caso de prueba #1
            Se inserta al final de la lista un multiplo de 3 en cada iteracion
        */
        for(int i = 0; i<5; i++){
            lista.insertLast(i*3);
        }
        cout<<"Caso de prueba #1 insertar al final 5 veces\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
        /*
            Caso de prueba #2
            Se inserta al inicio de la lista un multiplo de 3 en cada iteracion
        */
        for(int i = 0; i<5; i++){
            lista.insertFirst(i*3);
        }
        cout<<"Caso de prueba #2 insertar al inicio 5 veces\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
        /*
            Caso de prueba #3
            Se inserta en la posicion 0, el valor 60; en la posicion 5, el valor 75; en la posicion 4, el valor 99
            observaciones: se debe de tener en cuenta el orden en el que se insertan los datos porque las posiciones cambian
        */
        lista.insertAt(60,0);
        lista.insertAt(75,5);
        lista.insertAt(99,4);
        cout<<"Caso de prueba #3 insertar en 3 posiciones diferentes\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
        /*
            Caso de prueba #4
            Se borra el primer nodo de la lista 3 veces
        */
        for(int i = 0; i<3; i++){
            lista.removeFirst();
        }
        cout<<"Caso de prueba #4 borrar el inicio 3 veces\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
        /*
            Caso de prueba #5
            Se borra el ultimo nodo de la lista 5 veces
        */
        for(int i = 0; i<5; i++){
            lista.removeLast();
        }
        cout<<"Caso de prueba #5 borrar el final 5 veces\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
        /*
            Caso de prueba #6
            Se borra el nodo en la posicion 1 y en la posicion 2
            observaciones: se debe de tener en cuenta el orden en el que se eliminan los datos porque las posiciones cambian
        */
        lista.removeAt(1);
        lista.removeAt(2);
        cout<<"Caso de prueba #6 borrar en la posicion 1 y posicion 2\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
        /*
            Caso de prueba #8
            Se obtiene el dato del primer nodo, del ultimo nodo y en la pos 1
            observaciones: se debe de tener en cuenta el orden en el que se eliminan los datos porque las posiciones cambian
        */
        cout<<"Caso de prueba #8\nprimer dato: " + to_string(lista.first());
        cout<<"\nultimo dato: " + to_string(lista.last()) + "\ndato en la posicion 1: ";
        cout<<to_string(lista.getAt(1)) + "\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
        /*
            Caso de prueba #9
            Se cambia el valor de un nodo a 5,6,7 en la posicion 0,1,2,3, pero como no hay
            posicion 3 se hace el manejo de excepcion
        */
        for(int i = 0; i<4; i++){
            lista.setAt(5 + i,i);
        }
        cout<<"Caso de prueba #9 cambiar el valor del nodo a 5,6,7 y manejo de exepcion\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
        
    }
    catch(exception& e)
    {
        cout << e.what() <<endl;
        cout<<"Caso de prueba #9 cambiar el valor del nodo a 5,6,7 y manejo de exepcion\n"<<lista;
        cout<<"La lista enlazada queda de size: "<<lista.length()<<"\n"<<endl;
    }
    
    
    return 0;
}