#include <stdio.h>
#include <stdlib.h>

typedef struct Elements
{
    int data;
    struct Elements *next;
} Elements;

/**
 *This function adds a new Node with the given data and adds it
 *to the front of the Linked List 
 *
 * @param head Pointer to the head of the Linked List
 * @param data The integer data to add to the List
 * 
 * @return Pointer to the start of the list
*/ 
Elements* append(Elements* head, int data) {

    Elements* result = (Elements*)malloc(sizeof(Elements));
    if (result != NULL) {
        result->data = data;
        result->next = NULL;
        if (head == NULL) { //If list is empty, add node in the start
            return result;
        }
        Elements* temp = head;
        //If list != Empty, travel until the end to append the element
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = result;
    }
    return head;
}

/**
 *This function is used when you have to print the list
 *
 *@param head is the pointer to the start of the Linked List
*/
void printList(Elements* head) {
    Elements* temp = head;
    printf("[");
    

    if (temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
        
    }
    
    while (temp != NULL) {
        printf(", %d", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

/**
 * This function is used to free the memory when the program is not using it anymore
 * and it is very important to prevent the program using unecessary data
 * 
 *@param head pointer to what elements will be unallocated from memory
 */
void free_list(Elements* head) {
    /*Unallocates the memory being no longer used */
    Elements* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Function used to remove the index of a given Element:
 * Ex: list = [1,2,3,4]
 * RemoveIndex(list, 2)
 * list = [1,2,4] as it starts counting from zero
 * @param head pointer to the start of the list
 * @param index where the list is going to be removed
 * 
 * @return head pointer to the start of the list
 */
Elements* removeIndex(Elements* head, int index) {
    if (head == NULL) { //If list is empty
        return NULL;
    }
    Elements* temp = head;

    if (index == 0) {// If the head is to be removed (index 0)
        head = head->next;
        free(temp); //Unallocate memory
        return head;
    }

    // Traverse the list to find the node before the one to be removed
    int i = 0;
    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    // If index is out of bounds (index >= list size)
    if (temp == NULL || temp->next == NULL) {
        printf("Index [%d] out of bound\n", index);
        return head;
    }
    Elements* node_to_remove = temp->next;
    temp->next = node_to_remove->next; // Link to the next of the node being removed
    // Free the node to be removed
    free(node_to_remove);
    return head;
}
/**
 * Function used to remove all data given an Element from the list
 * list = [1,2,3,4,1,1]
 * removeElement(list, 1)
 * list = [2,3,4]
 * 
 * @param head pointer to the start of the list
 * @param Element_remove the data which will be removed from the List
 */
Elements* removeElement(struct Elements* head, int Element_remove) {
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }
    Elements* current = head;
     Elements* previous = NULL;

    // Handle cases where the head nodes need to be removed
    while (current != NULL && current->data == Element_remove) {
        Elements* temp = current;
        head = current->next;  // Move the head to the next node
        current = head;        // Update the current to the new head
        free(temp);            // Free the removed node
    }

    // Traverse the rest of the list to remove other occurrences
    while (current != NULL) {
        // If the current node has the element to be removed
        if (current->data == Element_remove) {
            Elements* temp = current;
            previous->next = current->next;  // Bypass the node
            current = current->next;         // Move to the next node
            free(temp);                      // Free the removed node
        } else {
            // Move both pointers forward if the current node is not to be removed
            previous = current;
            current = current->next;
        }
    }

    return head;  // Return the updated head of the list
}
/**
 * Function to calculate how long the list is
 * @param head pointer to the start of the list
 * 
 * @return the length of the list
 */
int len(Elements* head) {
    int i = 0;
    while (head != NULL) {
        head = head->next;
        i++;
    }
    return i;
}