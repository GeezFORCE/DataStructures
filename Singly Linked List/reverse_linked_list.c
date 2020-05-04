#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *start=NULL;
void main(){
    int choice;
    while(1)
    {   printf("MENU\n------------\n1.Inserion\n2.Reverse\n3.Display\n");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
            case 1:ins_node();break;
            case 2:rev_node();break;
            case 3:display_node();break;
            default:{   printf("Invalid Choice \n");
                        exit(0);
                    }break;
        }
    }
}
struct node *creation(){
    int item;
    struct node *new_node=malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&item);
    printf("\n");
    new_node->data=item;
    new_node->link=NULL;
    return(new_node);
}
void ins_node(){
    struct node *new_node=creation();
    if(start!=NULL)
        new_node->link=start;
    start=new_node;
}
void display_node(){
    struct node *head=start;
    while (head!=NULL)
    {   printf("%d----->",head->data);
        head=head->link;
    }
}
void rev_node(){
    struct node *curr=start;
    struct node *prev=NULL;
    struct node *next;
    while(curr!=NULL){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
    display_node();
}