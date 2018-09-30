/**
@author Jaime Jimenez Serrano
@version 1.0
@brief File that implements all functions to create a simple linked list.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"


struct nodo* cab=NULL;

/**
Method that print the list
*/
void printList()
{
    struct nodo* p = cab;
    while(p)
    {
        printf("El nombre es: %s\nEl id es: %d\n\n",p->nombre,p->docId);
        p = p->liga;
    }
}

/**
 * Insert a new node as first element in the list
 * @param char* nombre User name
 * @param int id User identification
 *  */
int insertIntoFirst(char* nombre, int id)
{
    struct nodo* nuevo = malloc(sizeof(struct nodo));
    nuevo->nombre = malloc(sizeof(char)*strlen(nombre));
    memcpy(nuevo->nombre,nombre,strlen(nombre));
    nuevo->docId= id;
    nuevo->liga= NULL;
    if(cab)
    {
        nuevo->liga = cab;
    }
    cab = nuevo;
    return 0;
}

/*
 * Insert a new node sortly into the list
 * char* nombre User name
 * int id User identification
 */
int insertSortDesc(char *nombre, int id)
{
    struct nodo* p = cab;
    struct nodo* ant = NULL;
    struct nodo* nuevo = malloc(sizeof(struct nodo));
    nuevo->nombre = malloc(sizeof(char)*strlen(nombre));
    memcpy(nuevo->nombre,nombre,strlen(nombre));
    nuevo->docId= id;
    nuevo->liga= NULL;
    if(!p)
    {
        cab = nuevo;
    }
    while(p)
    {
        if(p->docId < id)
        {
            nuevo->liga = p;
            if(!ant)
            {
                cab = nuevo;
            }
            else
            {
                ant->liga = nuevo;
            }
            return 0;
        }
        else if(p->docId == id)
        {
            free(nuevo->nombre);
            free(nuevo);
            printf("El id %d, ya existe!\n",id);
            return 1;
        }
        else
        {
            ant = p;
            p = p->liga;
            if(!p)
            {
                ant->liga = nuevo;
                return 0;
            }
        }
    }
    return -2;
}

int insertSortAsc(char *nombre, int id){
    struct nodo* p = cab;
    struct nodo* ant = NULL;
    struct nodo* nuevo = malloc(sizeof(struct nodo));
    nuevo->nombre = malloc(sizeof(char)*strlen(nombre));
    memcpy(nuevo->nombre,nombre,strlen(nombre));
    nuevo->docId= id;
    nuevo->liga= NULL;
    if(!p)
    {
        cab = nuevo;
    }
    while(p)
    {
        if(p->docId < id)
        {
            nuevo->liga = p;
            if(!ant)
            {
                cab = nuevo;
            }
            else
            {
                ant->liga = nuevo;
            }
            return 0;
        }
        else if(p->docId == id)
        {
            free(nuevo->nombre);
            free(nuevo);
            printf("El id %d, ya existe!\n",id);
            return 1;
        }
        else
        {
            ant = p;
            p = p->liga;
            if(!p)
            {
                ant->liga = nuevo;
                return 0;
            }
        }
    }
    return -2;
}

int deleteNodeByStruct(struct nodo *toDelete, struct nodo *previousNode){
    if(!previousNode)
    {
        cab = toDelete->liga;
    }
    else
    {
        previousNode->liga = toDelete->liga;
    }
    free(toDelete->nombre);
    free(toDelete);
    return 0;
}

int deleteNode(int id)
{
    struct nodo* p=cab;
    struct nodo* ant=NULL;
    while(p)
    {
        if(p->docId == id)
        {
            if(!ant)
            {
                cab = p->liga;
            }
            else
            {
                ant->liga = p->liga;
            }
            free(p->nombre);
            free(p);
            printf("El nodo %d fue eliminado!\n",id);
            return 0;
        }
        ant = p;
        p = p->liga;
    }
    printf("El nodo %d no existe!!\n",id);
    return 1;
}

void sortList(bool asc){
    if(!isSort(asc)){
        if(cab){
            struct nodo* p = cab->liga;
            struct nodo* ant =cab;
            while (p){
                if(!asc && ant->docId < p->docId){
                    char* tempNombre = malloc(sizeof(char)*strlen(p->nombre));
                    memcpy(tempNombre,p->nombre,strlen(p->nombre));
                    int tempId = p->docId;
                    deleteNodeByStruct(p,ant);
                    insertSortDesc(tempNombre,tempId);
                    p = ant->liga;
                }else if(asc && ant->docId > p->docId){
//                    TODO
                 /*   char* tempNombre = malloc(sizeof(char)*strlen(p->nombre));
                    memcpy(tempNombre,p->nombre,strlen(p->nombre));
                    int tempId = p->docId;
                    deleteNode(p->docId);
                    //insertSortAsc(tempNombre,tempId);
                    p = ant->liga;*/
                }else {
                    ant = p;
                    p = p->liga;
                }
            }
        }

    }
}

bool isSort(bool asc)
{
    if(cab)
    {
        struct nodo* p=cab->liga;
        struct nodo* ant=cab;
        while(p)
        {
            if(asc && (ant->docId>p->docId))
            {
                printf("la lista NO esta ordenada!\n");
                return false;
            }
            else if(!asc && (ant->docId<p->docId))
            {
                printf("la lista NO esta ordenada!\n");
                return false;
            }
            ant = p;
            p = p->liga;
        }
        printf("la lista esta ordenada!\n");
        return true;
    }
    printf("La lista esta vacia!\n");
    return false;
}

void freeList(){
    struct nodo* p=cab;
    while(p)
    {
        cab = p->liga;
        free(p->nombre);
        free(p);
        p = cab;
    }
}
