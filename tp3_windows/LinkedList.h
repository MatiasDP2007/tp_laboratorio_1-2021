/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas

// Crea fisicamente la lista en el heap
LinkedList* ll_newLinkedList(void);

//Cuenta la cantidad de elementos que tenes dentro de la lista y retorna el tamaño de la lista
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);

int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//Agrega un elemento directamente en la lista, se le pasa como parametro un puntero generico lo que permite manejar cualquier tipo de dato mientras sea de tipo punteri
int ll_add(LinkedList* this, void* pElement);

//devuelve un dato dentro de la lista, le pasas el indice y te devuelve el empleado en esa posicion
void* ll_get(LinkedList* this, int index);

//reemplaza un elemento con otro, le pasas el indice que queres reemplazar y le pasa el elemento que queres reemplazar
int ll_set(LinkedList* this, int index,void* pElement);

//Remueve uno del indice especificado, rompe el enlaze con el nodo, el dato deja de ser apuntado y queda son referencia
int ll_remove(LinkedList* this,int index);

//borra la lista completa pero la lista sigue existiendo. Deja sin referencia a los datos
int ll_clear(LinkedList* this);

//borra completamente la lista enlazada
int ll_deleteLinkedList(LinkedList* this);

//se le pasa el elemento de un dato y la funcion te dice en que indice se encuentra
int ll_indexOf(LinkedList* this, void* pElement);

//se fija si la lista se encuentra vacia
int ll_isEmpty(LinkedList* this);

//El push te permite ingresar un elemento en la posicion del indice que le pases
int ll_push(LinkedList* this, int index, void* pElement);

//Permite remover un elemento, a diferencia con el remove, esta funcion devuelve el elemento sacado de la lista, sirve para mostrar el elemento borrado, pasarlo a otra lista etc
void* ll_pop(LinkedList* this,int index);

//pregunta si el elemento que se le pasa se encuentra en la lista
int ll_contains(LinkedList* this, void* pElement);

//Sirve para verificar si una lista se encuentra dentro de otra lista
int ll_containsAll(LinkedList* this,LinkedList* this2);

//Te crea una copia desde un indice especificado al otro
LinkedList* ll_subList(LinkedList* this,int from,int to);

//Te crea una copia de la lista completa, (llama al sublist desde el 0 al len de la lista)
LinkedList* ll_clone(LinkedList* this);

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

