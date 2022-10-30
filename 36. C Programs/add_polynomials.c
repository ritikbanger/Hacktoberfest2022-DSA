#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coeff;
    int pow;
    struct node* next;
}nodetype;
nodetype* addpolynomial(nodetype*,nodetype*);
int main()
{
   nodetype *l1=NULL,*r1=NULL,*p=NULL,*l2=NULL,*r2=NULL,*sum=NULL;
   int ch,c,e;
   printf("Enter the first polynomial:\n");
   while(1)
   {
       p=(nodetype*)malloc(sizeof(nodetype));
       if(p!=NULL)
       {
           printf("Enter the coefficient: ");
           scanf("%d",&c);
           printf("Enter the power: ");
           scanf("%d",&e);
           p->coeff=c;
           p->pow=e;
           if(l1==NULL && r1==NULL)
           l1=r1=p;
           else
           {
               r1->next=p;
               r1=p;
           }
           printf("Press 1 to continue adding terms and 0 if you have added all the terms of the polynomial in the linked list: ");
           scanf("%d",&ch);
           if(ch==0)
           break;
       }
    }
    r1->next=NULL;
    printf("Enter the second polynomial:\n");
    while(1)
    {
       p=(nodetype*)malloc(sizeof(nodetype));
       if(p!=NULL)
       {
           printf("Enter the coefficient: ");
           scanf("%d",&c);
           printf("Enter the power: ");
           scanf("%d",&e);
           p->coeff=c;
           p->pow=e;
           if(l2==NULL && r2==NULL)
           l2=r2=p;
           else
           {
               r2->next=p;
               r2=p;
           }
           printf("Press 1 to continue adding terms and 0 if you have added all the terms of the polynomial in the linked list: ");
           scanf("%d",&ch);
           if(ch==0)
           break;
       }
    }
    r2->next=NULL;
    sum = addpolynomial(l1,l2);
    nodetype *temp=sum;
    printf("The polynomial after addition is: ");
    int f=0;
    while(temp!=NULL)
    {
        if(f!=0)
        printf(" + ");
        printf("%dx^%d",temp->coeff,temp->pow);
        f=1;
        temp=temp->next;
    }
}
nodetype* addpolynomial(nodetype *str1,nodetype *str2)
{
    nodetype *f=NULL,*r=NULL;
    nodetype *p=NULL;
    while(str1!=NULL && str2!=NULL)
    {
        p=(nodetype*)malloc(sizeof(nodetype));
        if(str1->pow==str2->pow)
        {
            p->coeff=str1->coeff + str2->coeff;
            p->pow=str1->pow;
            str1=str1->next;
            str2=str2->next;
        }
        else if(str1->pow > str2->pow)
        {
            p->coeff=str1->coeff;
            p->pow=str1->pow;
            str1=str1->next;
        }
        else
        {
            p->coeff=str2->coeff;
            p->pow=str2->pow;
            str2=str2->next;
        }
        if(f==NULL && r==NULL)
        {
            f=r=p;
        }
        else{
            r->next=p;
            r=p;
        }
        r->next=NULL;
    }
    if(str1==NULL)
    {
        while(str2!=NULL)
        {
            p=(nodetype*)malloc(sizeof(nodetype));
            p->coeff=str2->coeff;
            p->pow=str2->pow;
            r->next=p;
            r=p;
            r->next=NULL;
            str2=str2->next;
        }
    }
    else
    {
       while(str1!=NULL)
        {
            p=(nodetype*)malloc(sizeof(nodetype));
            p->coeff=str1->coeff;
            p->pow=str1->pow;
            r->next=p;
            r=p;
            r->next=NULL;
            str1=str1->next;
        }
    }
    return f;
}