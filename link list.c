#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;

 }Node;
int count=0;
 void display(Node *ptr)
 {
     Node *temp;
     if(ptr==NULL){
        printf("\n\t\tList is empty\n\n");
        return ;
     }
     temp=ptr;
     while(temp!=NULL){
        printf("\n\n\tThe number is : %d\n",temp->data);
        temp=temp->next;
     }
     printf("\nThere are %d nodes in the list\n",count);

return ;
 }

 Node *insert(Node *start,int num)
 {
     Node *temp;
     temp=(Node*)malloc(sizeof(Node));
     temp->data=num;
     temp->next=start;
     start=temp;
     count++;
     printf("\noperation Successful.\n");

     return start;



 }
 Node *insertend(Node *start,int num)
 {
     Node *temp,*ptr;
     if(start==NULL){
        printf("\n List Is empty\n please enter at least one number at the first.\n");
        return start;
     }
     temp=(Node*)malloc(sizeof(Node));
     temp->data=num;
     temp->next=NULL;
     ptr=start;
     while(ptr->next!=NULL){
        ptr=ptr->next;
     }

     ptr->next=temp;
     count++;
     printf("\nOperation Successfull\n");
     return start;



 }
 Node *deletes(Node *start,int num)
 {
     Node *temp,*ptr;
     if(start==NULL){
        printf("List is empty");
     }
     if(start->data==num){
        temp=start;
        start=start->next;
        free(temp);
        printf("\nNumber deleted successfully\n");
        count--;

        return start;
     }
     ptr=start;
     while(ptr->next!=NULL){
            if(ptr->next->data==num){
                    temp=ptr->next;
                    ptr->next=temp->next;
                    free(temp);
                    count--;
                    printf("\nNumber is deleted from the list.\n");
            return start;
            }
            ptr=ptr->next;
     }
     printf("Number is not in the list\n");
     return start;
 }
 void search(Node *pointer,int num)
 {
     int counts=0;
     Node *ptr,*temp;
     temp=pointer;
     while(temp!=NULL){
         counts++;
            if(temp->data==num){

                printf("%d found,it's the %d th position in the list\n",num,counts);
                return ;
            }
            temp=temp->next;

     }
     printf("Number is not in the list");
     return ;
 }
 void insertbetween(Node *pointer,int num,int num2)
 {
     Node *temp,*ptr;
     if(pointer==NULL){
            printf("Please enter at least one element & try again");
        return ;
     }
     temp=pointer;
     ptr=(Node *)malloc(sizeof(Node));

     while(temp!=NULL){
            if(temp->data==num2){

                ptr->next=temp->next;
                ptr->data=num;
                temp->next=ptr;
                count++;
                return ;
            }
            temp=temp->next;

     }
     return ;
 }
 Node *reverse(Node* start )
 {
     Node *temp, *ptr, *pointer;
     temp=NULL;
     ptr=start;
     while(ptr!=NULL){
        pointer=ptr->next;
        ptr->next=temp;
        temp=ptr;
        ptr=pointer;
     }
     start=temp;
     return start;
 }
 int main()
 {
     int choise,num,num2;
     Node *start;
     start=NULL;
     while(1){
        printf("\n\n1.Display\n");
        printf("2.Insert\n");
        printf("3.Insert at the End\n");
        printf("4.Insert between the nodes\n");
        printf("6.Search\n");
        printf("7.Delete\n");
        printf("8.Reverse list\n");
        printf("9.Exit\n\n");

        scanf("%d",&choise);
     switch(choise)
     {
     case 1:
        display(start);
        break;
     case 2:
        printf("ENter a number: ");
        scanf("%d",&num);
        start=insert(start,num);
        break;
     case 3:
        printf("Enter the number: \n");
        scanf("%d",&num);
        insertend(start,num);
        break;
     case 4:
         printf("Enter the number you want to insert: \n ");
        scanf("%d",&num);
        printf("Enter the position : \n");
        scanf("%d",&num2);
        insertbetween(start,num,num2);
        break;
     case 6:
        printf("Enter the number you want to search: \n");
        scanf("%d",&num);
        search(start,num);
        break;
     case 7:
          printf("Enter the number you want to delete from the list: \n");
        scanf("%d",&num);
        start=deletes(start,num);

        break;
     case 8:
         start=reverse(start);
         break;

     case 9:
        exit(1);
     default :
        printf("Invalid selection");
        break;
        }
     }
 }
