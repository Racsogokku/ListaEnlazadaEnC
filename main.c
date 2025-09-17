#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int data;
    struct Nodo* next;
};
void iterar(struct Nodo* head) {
    while (head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
}
void insertarPrincipio(struct Nodo** direccionCabeza, int data) {
    struct Nodo* aux=malloc(sizeof(struct Nodo));
    if (aux==NULL)return;
    aux->data=data;
    aux->next=*direccionCabeza;
    *direccionCabeza=aux;
}
void insertarFinal(struct Nodo** cabeza, int data) {
    struct Nodo* punteroNodoNuevo=malloc(sizeof(struct Nodo));
    if (punteroNodoNuevo==NULL)return;
    punteroNodoNuevo->next=NULL;
    punteroNodoNuevo->data=data;
    if (*cabeza!=NULL) {
    struct Nodo* aux=*cabeza;
        while (aux->next!=NULL) {
            aux=aux->next;
        }
        aux->next=punteroNodoNuevo;
    }else {
        *cabeza=punteroNodoNuevo;
    }
}
void eliminarCabeza(struct Nodo** punteroCabeza) {
    if (*punteroCabeza==NULL){return;}
    struct Nodo* nodoABorrar = *punteroCabeza;
    *punteroCabeza=(*punteroCabeza)->next;
    free(nodoABorrar);
}
void eliminarCola(struct Nodo** punteroCabeza) {
    if (*punteroCabeza==NULL)return;
    struct Nodo* aux=*punteroCabeza;
    if (aux->next==NULL) {
        struct Nodo* nodo=aux;
        *punteroCabeza=NULL;
        free(nodo);
    }else {
        while (aux->next->next!=NULL) {
            aux=aux->next;
        }
        struct Nodo* nodo=aux->next;
        aux->next=NULL;
        free(nodo);
    }
}
void eliminar(struct Nodo** punteroCabeza, int data) {
    if (*punteroCabeza==NULL)return;
    if ((*punteroCabeza)->data==data) {
        struct Nodo* nodoABorrar=*punteroCabeza;
        *punteroCabeza=(*punteroCabeza)->next;
        free(nodoABorrar);
        return;
    }
    struct Nodo* aux=*punteroCabeza;
    bool encontrado=false;
    while (((aux)->next!=NULL)&&(!encontrado)) {
        encontrado=(aux)->next->data==data;
        if (!encontrado) {
            aux=aux->next;
        }
    }
    if (encontrado) {
        struct Nodo* nodoABorrar=aux->next;
        aux->next=aux->next->next;
        free(nodoABorrar);
    }
}
int main(void) {
struct Nodo* head=malloc(sizeof(struct Nodo));
    head->data=3;
    head->next=malloc(sizeof(struct Nodo));
    head->next->data=7;
    head->next->next=malloc(sizeof(struct Nodo));
    head->next->next->data=9;
    head->next->next->next=NULL;
    insertarPrincipio(&head,1);
    insertarFinal(&head,102);
    insertarFinal(&head,12);
    insertarFinal(&head,1042);
    insertarFinal(&head,10552);

    iterar(head);
    eliminarCabeza(&head);
    printf("\n");
    iterar(head);
    eliminarCola(&head);
    printf("\n");
    iterar(head);
    eliminar(&head,12);
    printf("\n");
    iterar(head);
    free(head->next->next);
    free(head->next);
    free(head);
}
