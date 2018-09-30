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

void setAscendant();
void setDescendant();
bool getSortSense();
void printList();
int insertIntoFirst(char* nombre, int id);
int insertSort(char *nombre, int id);
int insertSortChangeSense(char *nombre, int id, bool asc);
int deleteNode(int id);
int deleteNodeByStruct(struct nodo *toDelete, struct nodo *previousNode);
void sortList();
void sortListSpecifyingSense(bool asc);
bool isSort();
void freeList();
#endif //LISTT_LIST_H
