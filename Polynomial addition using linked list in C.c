#include<stdio.h> 
#include<stdlib.h>
struct list{
     int coeff;
     int pow;
     struct list *next;
    };
struct list *poly1=NULL,*poly2=NULL,*poly=NULL;
void create(struct list *node)
{
    int n,i;
    printf("enter number of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter coeff:");
        scanf("%d",&node->coeff);
        printf("enter power:");
        scanf("%d",&node->pow);
        node->next=(struct list*)malloc(sizeof(struct list));
        node=node->next;
        node->next=NULL;
    }
} 
void show(struct list *node)
{
    while(node->next!=NULL)
    {
        printf("%dx^%d",node->coeff,node->pow);
        node=node->next;
        if (node->next!=NULL)
        printf("+");
    }
}
void polyadd(struct list *poly1,struct list *poly2,struct list *poly)
{
    while(poly1->next && poly2->next)
    {
        if(poly1->pow>poly2->pow)
        {
             poly->pow=poly1->pow;
             poly->coeff=poly1->coeff;
             poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow)
        {
             poly->pow=poly2->pow;
             poly->coeff=poly2->coeff;
             poly2=poly2->next;
        }
        else
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff+poly2->coeff;
             poly1=poly1->next;
            poly2=poly2->next;
        }
         poly->next=(struct list *)malloc(sizeof(struct list));
        poly=poly->next;
        poly->next=NULL;
}
while(poly1->next || poly2->next)
{
    if(poly1->next)
    {
        poly->pow=poly1->pow;
        poly->coeff=poly1->coeff;
        poly1=poly1->next;
    }
    if(poly2->next)
    {
        poly->pow=poly2->pow;
        poly->coeff=poly2->coeff;
        poly2=poly2->next;
    }
    poly->next=(struct list *)malloc(sizeof(struct list));
    poly=poly->next;
    poly->next=NULL;
 }
 }
 void sort(struct list*node)
 {
    struct list *i,*j;
    int t;
    for(i=node;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->pow<=j->pow)
                {
                     t=i->pow;
                     i->pow=j->pow;
                     j->pow=t;
                     t=i->coeff;
                     i->coeff=j->coeff;
                     j->coeff=t;
                }
        }
    }
}
int main()
{
     poly1=(struct list *)malloc(sizeof(struct list));
     poly2=(struct list*)malloc(sizeof(struct list));
     poly=(struct list*)malloc(sizeof(struct list));
     printf("\nenter 1st number:\n");
     create(poly1);
     sort(poly1);
     printf("\nenter 2nd number:\n");
     create(poly2);
     sort(poly2);
     printf("\n1st Number:");
     show(poly1);
     printf("\n2nd Number:");
     show(poly2);
     polyadd(poly1,poly2,poly);
     printf("\nAdded polynomial:");
     show(poly);
}
