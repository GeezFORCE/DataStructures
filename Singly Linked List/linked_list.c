#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;
void main()
{
    int choice;
    while (1)
    {
        printf("\tMENU\t\n");
        printf("-----------------------\n");
        printf("1.Creation\n2.Deletion\n3.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int ins;
            printf("1.Begining\n2.Specific\n3.End\n");
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
                printf("Not a valid choice\n");
                break;
            }
            break;
        case 2:
        {
            int ins, res;
            printf("1.Begining\n2.Specific\n2.End\n");
            scanf("%d", &ins);
            switch (ins)
            {
            case 1:
                printf("Deleted Element : %d \n", del_beg());
                break;
            case 2:
                printf("Deleted element : %d \n", del_spec());
                break;
            case 3:
                printf("Deleted Element : %d \n", del_end());
                break;
            default:
                printf("Not a valid choice\n");
                break;
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
    }
}
struct node *creation()
{
    int item;
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("No space available! Exiting!! \n");
        exit(0);
    }
    printf("Enter the data : ");
    scanf("%d", &item);
    printf("\n");
    new_node->data = item;
    new_node->link = NULL;
    return (new_node);
}
void ins_beg()
{
    struct node *new_node;
    new_node = creation();
    if (start != NULL)
        new_node->link = start;
    start = new_node;
}
void display_node()
{
    printf("List : ");
    struct node *head = start;
    while (head != NULL)
    {
        printf("%d--->", head->data);
        head = head->link;
    }
    printf("\n");
}
void ins_end()
{
    struct node *new_node = creation();
    struct node *head = start;
    while (head->link != NULL)
        head = head->link;
    head->link = new_node;
}
void ins_spec()
{
    int pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    pos--;
    printf("\n");
    struct node *new_node = creation();
    struct node *curr = start;
    while (--pos)
    {
        curr = curr->link;
    }
    struct node *next = curr->link;
    new_node->link = next;
    curr->link = new_node;
}
int del_beg()
{
    int res = start->data;
    struct node *del = start;
    start = start->link;
    free(del);
    return (res);
}
int del_end()
{
    int res;
    struct node *del = start;
    struct node *prev;
    while (del->link != NULL)
    {
        prev = del;
        del = del->link;
    }
    res = del->data;
    prev->link = NULL;
    free(del);
    return (res);
}
int del_spec()
{
    int pos, res;
    printf("Enter the positon : ");
    scanf("%d", &pos);
    printf("\n");
    struct node *curr = start;
    struct node *prev;
    while (--pos)
    {
        prev = curr;
        curr = curr->link;
    }
    res = curr->data;
    prev->link = curr->link;
    free(curr);
    return (res);
}