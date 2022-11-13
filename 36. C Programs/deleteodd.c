#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}nodetype;
int main()
{
   nodetype *l=NULL,*r=NULL,*p=NULL;
   int ch,x;
   while(1)
   {
       p=(nodetype*)malloc(sizeof(nodetype));
       if(p!=NULL)
       {
           printf("Enter the value: ");
           scanf("%d",&x);
           p->info=x;
           if(l==NULL && r==NULL)
           l=r=p;
           else
           {
               r->next=p;
               r=p;
           }
           printf("Press 1 to continue and press 0 if you have added the desired elements in the linked list: ");
           scanf("%d",&ch);
           if(ch==0)
           break;
       }
    }
    r->next=NULL;
    nodetype* temp=NULL;
    temp=l;
    while(temp!=NULL)
    {
    if((temp->info)%2!=0)
    {
    p=l;
    if(l->info==(temp->info))
    {
        l=l->next;
        temp=l;
    }
    else
    {
    while(((p->next)->info!=(temp->info) && p!=NULL))
       p=p->next;
       if((p->next)->info==(temp->info))
       {
       nodetype* q=p->next;
       temp=q->next;
       p->next=q->next;
       free(q);
       }
    }
    }
    else
    temp=temp->next;
    }
    p=l;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    free(p);
}