#include <stdio.h>
#include <stdlib.h>
#include "interfaccia.h"
#define TRUE 1
#define FALSE 0

//Implementazione struttura
typedef struct stack {
    int *numeri;  //Puntatore a array dinamico
    int size;     //Dimensione array
    int cap;      //Capacità array
} Stack;


//Allocazione dinamica di un array di 5 interi
StackPtr createStack() {
    StackPtr stack_p;
    stack_p = malloc(sizeof(*stack_p));

    //Inizializzazione dei valori
    stack_p->size = 0; //inizializza la dimensione della pila
    stack_p->cap = 5;  //inizializza la capacità della pila
    
    //Allocazione memoria per l'array numeri
    stack_p->numeri = malloc(stack_p->cap * sizeof(int));
    if (stack_p->numeri == NULL) {
        printf("Errore di allocazione memoria per l'array numeri.\n");
        return NULL;
    }
    
    int valori_iniziali[] = {2, 5, 3, 7, 6};  //valori da inserire nell'array
    for (int i = 0; i < stack_p->cap; i++) {
        stack_p->numeri[i] = valori_iniziali[i]; //Assegno i valori iniziali all'array
    }
    
    return stack_p;
}


int push(StackPtr s, int val) {
    //sposto tutti i valori a destra
    for(int i = s->size; i > 0; i--) {
        s->numeri[i] = s->numeri[i - 1]; 
    }
    //inserisco il valore nella prima posizione dell'array
    s->numeri[0] = val;
    
    return TRUE;
}


int pop(StackPtr s, int* out) {
    if (s->size == 0) {
        return FALSE; //Underflow
    }

    //Assegniamo il valore della prima posizione a out
    *out = s->numeri[0];

    //Spostiamo tutti i valori a sinistra
    for (int i = 0; i < s->size - 1; i++) {
        s->numeri[i] = s->numeri[i + 1];
    }

    //Impostiamo l'ultima posizione a 0
    s->numeri[s->size - 1] = 0;
    s->size--;
    
    return TRUE;
}


void printStack(StackPtr s) {
    for (int i = 0; i < s->size; i++) {
        printf("%d ", s->numeri[i]);  //Accesso a ciascun elemento dell'array
    }
    printf("\n");  //Aggiungi una nuova riga alla fine della stampa
}
