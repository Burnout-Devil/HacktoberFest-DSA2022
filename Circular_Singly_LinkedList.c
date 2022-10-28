#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_beg(struct node **head) {
    int value;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp2 = *head;
    printf("\nEnter the value : ");
    scanf("%d",&value);
    temp->data = value;
    if(*head == NULL) {
        *head = temp;
        temp->link = *head;
    }
    else {
        do {
            temp2 = temp2->link;
        }while(temp2 != *head);
        temp2 = temp2->link;
        temp->link = *head;
        *head = temp;
        temp2->link = temp;
    }
    printf("\nValue entered successfully....");
}

void insert_end(struct node **head) {
    int value;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *temp2 = *head;
    printf("\nEnter the value : ");
    scanf("%d",&value);
    temp->data = value;
    if(*head == NULL) {
        *head = temp;
        temp->link = *head;
    }
    else {
        do{
            temp2 = temp2->link;
        }while(temp2 != *head);
        temp2 = temp2->link;
        temp->link = temp2->link;
        temp2->link = temp;
    }
}

void delete_sp(struct node **head){
    int index,count = 0,countb = 1;
    struct node *temp = *head;
    struct node *tempb = *head;

    if(*head == NULL) 
    printf("\nList is empty....");
    else {
        printf("\nEnter the index of element to be deleted : ");
        scanf("%d",&index);
        while(count != index) {
            temp = temp->link;
            count++;
        }
        while(countb != index) {
            tempb = tempb->link;
            countb++;
        }
        tempb->link = temp->link;
        free(temp);
        printf("\nElement in index %d is deleted.",index);
    }
}
void display(struct node **head) {
    struct node *temp1 = *head;
    if(*head == NULL)
    printf("\nList is empty....");
    else {
        printf("\nThe elements in the list are : ");
        do {
            printf("%d ,",temp1->data);
            temp1 = temp1->link;
        }while(temp1 != *head); 
    }
}

int main() {
    struct node *head = NULL;
    int option;
    printf("\n<--Circular queue implementation-->");
    while(1) {
        printf("\n1.insert at beginning\n2.insert at end\n3.delete at specified position\n4.display\n5.exit\nEnter an option : ");
        scanf("%d",&option);
        
        if(option == 1)
        insert_beg(&head);
        else if(option == 2)
        insert_end(&head);
        else if(option == 3)
        delete_sp(&head);
        else if(option == 4)
        display(&head);
        else
        break;
    }
    return 0;
}
