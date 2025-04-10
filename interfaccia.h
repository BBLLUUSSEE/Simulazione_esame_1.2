#ifndef INTERFACCIA_H
#define INTERFACCIA_H

typedef struct stack * StackPtr;  //Dichiarazione della struttura, per l'incapsulamento completo qua dichiaro solo la struttura

//Solo dichiarazione delle funzioni
StackPtr createStack();
int push(StackPtr s, int val); //Dichiarazione della funzione push
int pop(StackPtr s, int* out); //Dichiarazione della funzione pop
void printStack(StackPtr s); //Dichiaraziobne per stampare
#endif
