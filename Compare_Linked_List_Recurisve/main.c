#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node linkedlist;

struct node
{
    int data;
    linkedlist *next;
};
bool compare_lists(linkedlist* head1, linkedlist* head2);
int main()
{
    //first linked list
    linkedlist* head = malloc(sizeof(linkedlist));
    linkedlist* first = malloc(sizeof(linkedlist));
    linkedlist* second = malloc(sizeof(linkedlist));
    linkedlist* third = malloc(sizeof(linkedlist));
    head->data = 1;
    head->next = first;
    first->data = 2;
    first->next = second;
    second->data = 3;
    second->next = third;
    third->data = 4;
    third->next = NULL;

    //second linked list
    linkedlist* head2 = malloc(sizeof(linkedlist));
    linkedlist* first2 = malloc(sizeof(linkedlist));
    linkedlist* second2 = malloc(sizeof(linkedlist));
    linkedlist* third2 = malloc(sizeof(linkedlist));
    head2->data = 1;
    head2->next = first2;
    first2->data = 2;
    first2->next = second2;
    second2->data = 3;
    second2->next = third2;
    third2->data = 4;
    third2->next = NULL;
    bool is_equal = compare_lists(head,head2);
    printf("The two linked lists are %s\n", is_equal ? "equal" : "not equal");
    return 0;
}

bool compare_lists(linkedlist* head1, linkedlist* head2) {
        //base case
        if (head1 == NULL && head2 == NULL)
        {
            return true;
        }

        if (head1->data == head2->data)
        {
           return compare_lists(head1->next,head2->next);
        }
        else
        {
            return false;
        }
}
