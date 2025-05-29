#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* head  = NULL;
unsigned int count = 0;

void insert (int data);
void delete();
void print_num_elements();


int main()
{
    head = (node*) malloc(sizeof(node*));
    head->data = 0;
    head->next = NULL;

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print_num_elements();
    delete();
    print_num_elements();
    insert(6);
    print_num_elements();
    return 0;
}


void insert (int data)
{
    node* element = (node*)malloc(sizeof(node*));
    node* temp = (node*)malloc(sizeof(node*));

    
    // Traverse to the end of the linked list
    while(head->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = element;
    element->data = data;
    element->next = NULL;
    count++;
}


void delete()
{
    // Traverse to the second last node
    node* temp = head;
    while (temp->next->next != NULL) 
    {
        temp = temp->next;
    }
        // Free the last node and update the second last node's next pointer
    free(temp->next);
    temp->next = NULL;

}

// Function to print the number of elements in the linked list
void print_num_elements()
{
    printf("number of elements in the linked list: %d\n", count);
}
