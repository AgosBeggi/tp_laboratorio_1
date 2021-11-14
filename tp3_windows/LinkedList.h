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
//Esta lista debe manejarse como un puntero. Básicamente
//gestiona punteros, como si fuera un array de punteros
#endif

//Publicas
//CREA UNA NUEVA LISTA
//Básicamente es la F que va a fijarse que haya espacio en el Heap y si hay crea la lista.
LinkedList* ll_newLinkedList(void);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//GUARDAR ELEMENTO
//recibe la lista y el elemento que quiero gurdar dentro de la lista.
//esta F, ya resuelve por sí sola verificar que haya espacio disponible,
//guardar el dato, etc.
int ll_add(LinkedList* this, void* pElement);

//OBTENER EL LARGO DE LA LISTA
int ll_len(LinkedList* this);

//DEVUELVE EL DATO QUE ESTÁ GUARDADO EN ESE INDICIE DE LA LISTA.
void* ll_get(LinkedList* this, int index);
//AGREGA O MODIFICA
int ll_set(LinkedList* this, int index,void* pElement);



//REMUEVE UN ELEMENTO Y AVISA SI SE PUDO REMOVER.
int ll_remove(LinkedList* this,int index);
//REMUEVE UN ELEMENTO Y DEVUELVE EL ELEMENTO REMOVIDO.
//saca el elemento de la lista, pero el puntero que devuelve
//sigue apuntando a donde está el dato guardado, por más de que
//ya no forme parte de la lista.
//Tener en cuenta esta F, porque puede pasar que dos listas
//apunten al mismo dato, entonces si libero memoria en alguna lista
//puede que se borre el dato y en la otra lista se perdería el dato.
//No se puede hacer free sobre los datos.
void* ll_pop(LinkedList* this,int index);


//LIMPIA TODA LA LISTA, PERO LA LISTA SIGUE EXISTIENDO EN MEMORIA
int ll_clear(LinkedList* this);
//LIBERA LA LISTA, LA BORRA DE LA MEMORIA
int ll_deleteLinkedList(LinkedList* this);

//DEVUELVE EL INDICE DEL DATO QUE SE QUIERE ENCONTRAR, PASANDOLE EL PUNTERO A ESE DATO
int ll_indexOf(LinkedList* this, void* pElement);
//SE FIJA SI LA LISTA ESTÁ VACÍA
int ll_isEmpty(LinkedList* this);
//CORRE LOS ELEMNTOS DE LA LISTA
int ll_push(LinkedList* this, int index, void* pElement);
//SE FIJA SI EL ELEMENTO QUE SE LE PASA POR PARAMETRO
//ESTÁ INCLUÍDO EN LA LISTA
int ll_contains(LinkedList* this, void* pElement);
//SE FIJA SI LA LISTA QUE SE LE PASA POR PARAMETRO
//CONTIENE TODOS LOS ELEMENTOS DE LA OTRA LISTA, ES DECIR
//SI LA LISTA 2 ESTÁ CONTENIDA EN LA LISTA 1
int ll_containsAll(LinkedList* this,LinkedList* this2);

//DEVUELVE UN PEDAZO DE LA LISTA, DESDE Y HASTA LOS PARÁMETRO QUE SE LE PASEN
LinkedList* ll_subList(LinkedList* this,int from,int to);
//DUPLICA LA LISTA EN MEMORIA
//Los datos no se tocan, es decir, crea una lista nueva en otro espacio de memoria,
//que apunta a ya estaban guardados los datos, quedando dos listas que apuntan al
//mismo espacio en memoria donde están los datos.
//Esto sirve, por ejemplo, para ordenar una y que la otra no sea moficicada en nada.
LinkedList* ll_clone(LinkedList* this);
//ORDENA LA LISTA CON UN CRITERIO. ((*pFunc)(void* ,void*) ESTO DESPUES LO VAN A EXPLICAR)
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
