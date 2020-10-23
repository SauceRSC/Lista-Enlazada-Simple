// Este programa crea y maneja listas enlazadas 

// Fecha: 04/10/2020
#ifndef MYLINKEDLIST
#define MYLINKEDLIST
#include <iostream>
using namespace std;

struct NodoLL{
    int dato;
    NodoLL* next;

    /*
        Descripcion: Constructor del nodo donde se igualan sus atributos dato y next
        Input: data -> entero con el valor a guardar en ese nodo, nxt -> apuntador al siguiente nodo 
        Output: n/a
        Complejidad: O(1).
    */
    NodoLL(int data, NodoLL* nxt){
        this->dato=data;
        this->next=nxt;
    }

    /*
        Descripcion: Constructor del nodo donde recibe solamente el dato a guardar y llama al constructor original pasando
                     como argumentos el dato y nullptr
        Input: data -> entero con el valor a guardar en ese nodo 
        Output: n/a
        Complejidad: O(1).
    */
    NodoLL(int data):NodoLL(data, nullptr){}
};

class MyLinkedList{
    private:
        NodoLL* head;
        NodoLL* tail;
        int size;
    public:
        MyLinkedList();
        ~MyLinkedList();
        int length();
        bool isEmpty();
        int first();
        int last();
        int getAt(int pos);
        void setAt(int data, int pos);
        void insertFirst(int data);
        void insertLast(int data);
        void insertAt(int data, int pos);
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        friend ostream& operator<<(ostream& os, const MyLinkedList& ll){
            NodoLL* actual = ll.head;
            for(int i=0; i<ll.size; i++){
                os<<actual->dato<<",";
                actual = actual->next;
            }
            os<<endl;
            return os;
        }
};
#endif