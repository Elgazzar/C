#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// This program demonstrates how to compare two linked lists in C.
typedef struct node linkedlist;
// Function to create a linked list node
linkedlist * create_linked_list(int data, linkedlist *next);



struct node
{
    int data;
    linkedlist *next;
};

// Function to compare two linked lists
bool compare_lists(linkedlist* head1, linkedlist* head2);

int main()
{
    // Create two linked lists and compare them
    linkedlist* head;
    linkedlist* first;
    linkedlist* second;
    linkedlist* third;


    //first linked list
    third = create_linked_list(4,NULL);
    second = create_linked_list(3,third);
    first = create_linked_list(2,second);
    head = create_linked_list(1,first);

    //second linked list
    linkedlist* head2;
    linkedlist* first2;
    linkedlist* second2;
    linkedlist* third2;
    //second linked list
    third2 = create_linked_list(4,NULL);
    second2 = create_linked_list(2,third2);
    first2 = create_linked_list(2,second2);
    head2 = create_linked_list(1,first2);
    
    // Compare the two linked lists
    // The function compare_lists will return true if the lists are equal, false otherwise
    bool result = compare_lists(head,head2);
    printf("The linked lists are %s.\n", result ? "equal" : "not equal");

    // Free the allocated memory for the linked lists
    // linkedlist *current = head;
    // linkedlist *next_node;
    // while (current != NULL) {
    //     next_node = current->next;
    //     free(current);
    //     current = next_node;
    // }
    // current = head2;
    // while (current != NULL) {
    //     next_node = current->next;
    //     free(current);
    //     current = next_node;
    // }

    return 0;
}
// Function to create a linked list node
linkedlist * create_linked_list(int data, linkedlist *next) 
{
    linkedlist *linkedlist = malloc(sizeof(linkedlist));
    linkedlist->data = data;
    linkedlist->next = next;
    return linkedlist;
}

bool compare_lists(linkedlist* head1, linkedlist* head2) {


    bool is_equal = true;
    // Traverse the first linked list

    while(head1 !=NULL && head2 !=NULL )
    {
        if (head1->data == head2->data)
        {
            // If the data is equal, continue to the next node
            // This is a valid case, so we do nothing
           //do nothing
        }
        else
        {
            // If the data is not equal, set is_equal to false
            // and break the loop
            //printf("The linked lists are not equal.\n");
            is_equal = false;
        }
        // Move to the next nodes in both linked lists
        head1 = head1->next;
        head2 = head2->next;
    }
    return is_equal;
}
