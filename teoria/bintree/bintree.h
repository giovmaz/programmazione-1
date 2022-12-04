#ifndef BINTREE_H
#define BINTREE_H

// Abstract Data Types
// Binary tree (altezza = lunghezza massima rami compresa tra log2(n+1) e n)
struct nodo {
    int val;
    nodo *left;
    nodo *right;
};

typedef nodo *albero;

void init(albero &a);
void deinit(albero &a);
void insert(albero &a, int n);
albero search(const albero &a, int n);
void print(const albero &a);

#endif
