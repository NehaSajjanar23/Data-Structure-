#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertatfirst(struct Node**head,int data)
{
    struct Node*newNode=createNode(data);
    newNode->next=*head;
    *head=newNode;
}
void insertatend(struct Node**head,int data)
{
    struct Node*newNode=createNode(data);
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        struct Node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void insertAtposition(struct Node**head,int data,int position)
{
    struct Node*newNode=createNode(data);
    if(position==0)
    {
        insertatfirst(head,data);
        return;
    }
     struct Node*temp=*head;
     for(int i=0;temp!=NULL&&i<position-1;i++)
     {
         temp=temp->next;
     }
     newNode->next=temp->next;
     temp->next=newNode;
}
void print(struct Node**head)
{
    struct Node*temp=*head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    struct Node*head=NULL;
    int choice,value,position;
    do
    {
        printf("choice a otion 1.insert at first,2.insert at end,3.insert at position,4.print,5.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter value to insert");
                   scanf("%d",&value);
                   insertatfirst(&head,value);
                   break;
            case 2:printf("enter value to insert");
                   scanf("%d",&value);
                   insertatend(&head,value);
                   break;
            case 3:printf("enter value to insert");
                   scanf("%d",&value);
                   printf("enter position at which you want to insert");
                   scanf("%d",&position);
                   insertAtposition(&head,value,position);
                   break;
            case 4:print(&head);
                   break;
            case 5:printf("exiting...");
                   break;
            default:printf("invalid option ,choice again");

        }
    }while(choice!=5);
}
