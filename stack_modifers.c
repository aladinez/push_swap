#include "push_swap.h"

// t_stack *newNode(int data)
// {
//     t_stack* newStackNode;
//     newStackNode = (t_stack *)malloc(sizeof(t_stack));
//     newStackNode->data = data;
//     newStackNode->next = NULL;
//     return (newStackNode);
// }

void push(t_stack** root, int data)
{
    t_stack* newStackNode;
    newStackNode = (t_stack *)malloc(sizeof(t_stack));
    newStackNode->data = data;
    newStackNode->next = *root;
    *root = newStackNode;
    // printf("%d pushed to stack\n", data);
}

// int main()
// {
//     t_stack *root = NULL;
 
//     push(&root, 10);
//     push(&root, 20);
//     push(&root, 30);
 
//     while (root)
//     {
//         printf("%d --> ", root->data);
//         root = root->next;
//     }
//     return 0;
// }