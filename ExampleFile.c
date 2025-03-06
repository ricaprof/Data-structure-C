#include "CircularLinkedList.h"
//Import the library

int main() {

    //Create the struct
    Elements* list = NULL;

    //Add elements to the list
    list = append(list, 1);
    list = append(list, 2);
    list = append(list, 3);
    list = append(list, 423);

    // Print The list
    printList(list);
    printf("[%d] Is the length of the Data structure\n", len(list));


    list = removeIndex(list, 2);
    list = removeElement(list, 2);
    printList(list);



    //Must use after the list is used
    free_list(list);

    //Cannot Print the list again after free_list()
    //WRONG: printList(list);


    return 0;
}
