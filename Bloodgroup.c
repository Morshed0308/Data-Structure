#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node
{
    char id[15];
    char blood[5];
    struct node *next;
}Node;

Node *start=NULL;

int Database(char ara[],char group[])
{
    Node *temp=(Node *)malloc(sizeof(Node));

    strcpy(temp->id,ara);

    strcpy(temp->blood,group);
    temp->next=NULL;
    if(start==NULL) //if there is no data in the list.
    {

        start=temp;
        return 0;
    }
    Node *ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next; // traversing to reach the end of the list
    }
    ptr->next=temp;
    return 0;

}
int searchgroup(char group[])
{
    Node *temp;
    temp=start;

    /*creating temporary pointer
    and assigning the value of the start to the temp*/
    while(temp!=NULL)
    {
        if(strcmp(temp->blood,group)==0)
        {
            printf("%s\n",temp->id);
            //Printing all the id of the group.
        }
        temp=temp->next;

        //traversing the whole list.
    }
    return 0;


}

int main()
{
    int choice;
    char ara[15];
    char group[5];
    while(1)
    {
        printf("\n1.Enter Database: \n");
        printf("2.Search Bloodgroup:  \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the Id:\n");
            scanf("%s",ara);
            printf("Enter Bloodgroup: \n");
            scanf("%s",group);
            Database(ara,group);


            break;
        case 2:
            printf("Enter the blood group: \n\n");
            scanf("%s",group);
            searchgroup(group);

            break;

        }
    }

    return 0;

}
