#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *ptr;
}Node;
Node *start ;
int count=0;
int push(int num)
{
    Node *temp;
    temp=(Node*)malloc(sizeof(Node));
    if(start==NULL)
    {
        temp->data=num;
        temp->ptr=NULL;
        start=temp;
        count++;
        return 0;
    }
    temp->data=num;
    temp->ptr=NULL;
    Node *pointer=start;
    while(pointer->ptr!=NULL)
    {
        pointer=pointer->ptr;
    }
    pointer->ptr=temp;
    count++;
    return 0;

}
int pop()
{
    if(start==NULL)
        {
            printf("Stack underflow\n\n");
            return 0;


        }
    Node *temp,*pointer;
    temp=start;
    if(temp->ptr==NULL)
    {
        free(temp);
        start=NULL;
        return 0;
    }
    start=start->ptr;
    free(temp);
    count--;
    return 0;

}
int topup()
{
    if(start==NULL)
    {
        printf("Stack empty\n");
        return 0;
    }
    Node *temp=start;
    while(temp->ptr!=NULL)
    {
        temp=temp->ptr;
    }
    printf("%d\n",temp->data);
    return 0;

}
int display()
{
    if(start==NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    Node *temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->ptr;
    }
    return 0;


}

int main()
{
    int choice,num;
    start=NULL;
    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Top\n");
        printf("4.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the number: \n");
            scanf("%d",&num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            topup();
            break;
        case 4:
            display();
            break;
        default :
            printf("Wrong choice\n");
            break;

        }
    }
}
