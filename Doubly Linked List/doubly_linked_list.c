#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL;
void main()
{
    int choice;
    while (1)
    {
        printf("\tMENU\t\n----------------\n1.Creation\n2.Deletion\n3.Display\nChoice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
        {
            int ins;
            printf("\n1.Begining\n2.Specific\n3.End\nChoice : ");
            scanf("%d", &ins);
            switch (ins)
            {
            case 1:
                ins_beg();
                break;
            case 2:
                ins_spec();
                break;
            case 3:
                ins_end();
                break;
            default:
                exit(0);
                break;
            }
        }
        break;
        case 2:
        {
            int ins;
            printf("\n1.Begining\n2.Specific\n3.End\nChoice : ");
            scanf("%d", &ins);
            printf("\n");
            switch (ins)
            {
            case 1:
                printf("Deleted Element : %d \n", del_beg());
                break;
            case 2:
                printf("Deleted Element : %d \n", del_spec());
                break;
            case 3:
                printf("Deleted Element : %d \n", del_end());
                break;
            default:
                exit(0);
                break;
            }
        }
        break;
        case 3:
            display_node();
            break;
        default:
            exit(0);
            break;
        }
    }
}
struct node *creation()
{
    int item;
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("No space available!! Exiting!!");
        exit(0);
    }
    printf("Enter the data: ");
    scanf("%d", &item);
    printf("\n");
    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}
void ins_beg()
{
    struct node *new_node = creation();
    if (start != NULL)
        new_node->next = start;
    start = new_node;
}
void display_node()
{
    struct node *head = start;
    while (head != NULL)
    {
        printf("%d<----->", head->data);
        head = head->next;
    }
}
void ins_spec()
{
    int pos;
    printf("Enter the positon : ");
    scanf("%d", &pos);
    struct node *new_node = creation();
    pos--;
    printf("\n");
    struct node *curr = start;
    while (--pos)
        curr = curr->next;
    new_node->next = curr->next;
    curr->next = new_node;
    new_node->prev = curr;
}
void ins_end()
{
    struct node *new_node = creation();
    struct node *head = start;
    while (head->next != NULL)
        head = head->next;
    new_node->prev = head;
    head->next = new_node;
}
int del_beg()
{
    int res = start->data;
    struct node *head = start;
    start = start->next;
    start->prev = NULL;
    free(head);
    return (res);
}
int del_spec()
{
    int res, pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    struct node *del = start;
    struct node *prec;
    while (--pos)
    {
        prec = del;
        del = del->next;
    }
    res = del->data;
    prec->next = del->next;
    del->next->prev = prec;
    free(del);
    return (res);
}
int del_end()
{
    int res;
    struct node *del = start;
    struct node *prec;
    while (del->next != NULL)
    {
        prec = del;
        del = del->next;
    }
    res = del->data;
    del->prev = NULL;
    prec->next = NULL;
    free(del);
    return (res);
}