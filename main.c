#include <stdio.h>
#include "biblioteca/list.h"

int main(int argc, char* argv[]) {
//    insertSortDesc("jaime", 1);
//    insertSortDesc("ricardo", 4);
//    insertSortDesc("carlos", 2);
//    insertIntoFirst("laura",3);
//    insertSortDesc("juan", 1);
    insertIntoFirst("jaime", 1);
    insertIntoFirst("ricardo", 4);
    insertIntoFirst("carlos", 21);
    insertIntoFirst("laura",32);
    insertIntoFirst("juan", 13);
    printList();
    isSort();
    deleteNode(3);
//    printf("is short %d\n",getSortSense());
    sortList();
    isSort();
    printList();
    isSort();
    setDescendant();
    sortList();
    printList();
    isSort();
    freeList();
    return 0;
}