/**
@author Jaime Jimenez Serrano
@version 1.0
@brief File that implements all functions to create a simple linked list.
*/

#ifndef LISTT_LIST_H
#define LISTT_LIST_H
#include <stdbool.h>
struct nodo
{
    char* nombre;
    int docId;
    struct nodo* liga;
};

void printList();
int insertIntoFirst(char* nombre,int id);
int insertSortDesc(char *nombre, int id);
int insertSortAsc(char *nombre, int id);
int deleteNode(int id);
int deleteNodeByStruct(struct nodo *toDelete, struct nodo *previousNode);
void sortList(bool asc);
bool isSort(bool asc);
void freeList();
#endif //LISTT_LIST_H
