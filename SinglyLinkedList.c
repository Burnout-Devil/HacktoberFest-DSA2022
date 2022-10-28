
/*
 The Data Structure used here is a singly linked List.
 Here instead of using a predefined linked list, I have used user input system of linked list 
 in which the linked list need not to be predefined and the user can create a linked list and 
 add new nodes to the linked list at the front, rear or any position and can also remove nodes 
 from the front, rear or any position of the linked list.
*/

#include <stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *link;
};
struct node* header = NULL;

struct node *getnode()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
}

// Function to insert at the front of the linked list
void insertAtFront(int data)
{
    struct node* new = getnode();
    new->data = data;
    // Pointer of new will be assigned to previous header
    new->link = header;
    header = new;
}

// Function to insert at the end of the linked list
void insertAtEnd(int data)
{
    struct node *new = getnode();
    struct node *temp = getnode();

    new->data = data;
    new->link = NULL;
    if(header==NULL)
    {
        header = new;
    }
    else
    {
       temp = header;
       while (temp->link != NULL)
       {
           temp = temp->link;
       }
       temp->link = new;
    }
}
 
// Function to insert at a position in the linked list
void insertAtPosition(int data)
{
    int pos,i = 1;
    struct node *new = getnode();
    struct node *temp = getnode();
  
    new->data = data;
    new->link = NULL;
    temp = header;
    
    printf("\tEnter position : ");
	scanf("%d", &pos);
	
	if (header == NULL)
    {
        if(pos == 1)
        {
            insertAtFront(data);
        }
        else
        {
            printf("\nList is empty\n");
        }
    }
	else if(pos == 1)
    {
	    insertAtFront(data);
	}
	else
	{
       while (i < pos - 1)
       {
           temp = temp->link;
	   	   i++;
	   }
	   new->link = temp->link;
	   temp->link = new;
	}
}

// Function to delete from the front of the linked list 
int deleteFirst()
{
    int data;
    struct node* temp = getnode();
    if (header == NULL)
    {
        printf("\nList is empty\n");
    }
    else 
    {
        temp = header;
        data = temp->data;
        header = header->link;
        free(temp);
        //Return the deleted value
        return data;
    }
}

// Function to delete from the end of the linked list
int deleteEnd()
{
    int data;
    struct node *temp1 = getnode();
    struct node *temp2 = getnode();
    if (header == NULL)
    {
        printf("\nList is Empty\n");
    }
    else 
    {
        temp1 = header;
        while (temp1->link != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->link;
        }
        data = temp1->data;
        temp2->link = NULL;
        free(temp1);
        return data;
    }
}
 
// Function to delete from a position in the linked list
int deletePosition()
{
    int pos,data,i = 1;
    struct node *temp = getnode();
    struct node *position = getnode();
    
    printf("\tEnter position : ");
	scanf("%d", &pos);
    
    if (header == NULL)
    {
        printf("\nList is empty\n");
    }
    else if(pos == 1)
    {
	    deleteFirst();
	}
    else 
    {
        temp = header;
        // Traverse till position
        while (i < pos - 1)
        {
           temp = temp->link;
	   	   i++;
	    }
	    position = temp->link;
	    data = position->data;
        // Change Links
        temp->link = position->link;
        // Free memory
        free(position);
        return(data);
    }
}

// Function to display the linked list
int displaylist()
{
    struct node* temp = getnode();
    // List is not empty
    if (header != NULL)
    {
        printf("\nThe linked list is : ");
        temp = header;
        printf("[header]");
        while (temp != NULL) 
        {
            printf("-->[%d]",temp->data);
            temp = temp->link;
        }
        printf("[/]");
    }
    printf("\n");
}

int main()
{
    int option,choice,data,value;
    while(1)
    {
        printf("\nLinked list operations...\n1.Insert\n2.Delete\n3.Displaylist\n4.Exit");
        printf("\nEnter option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                printf("\t1.Insert at Front\n\t2.Insert at End\n\t3.Insert at a position");
                printf("\n\tEnter your choice : ");
                scanf("%d",&choice);
                printf("\tEnter the data to be inserted : ");
                scanf("%d",&data);
                switch(choice)
                {
                    case 1:
                    {
                        insertAtFront(data);
                        break;
                    }
                    case 2:
                    {
                        insertAtEnd(data);
                        break;
                    }
                    case 3:
                    {
                        insertAtPosition(data);
                        break;
                    }
                    default:
                    {
                        printf("\tEnter the right choice.");
                        break;
                    }
                }
                displaylist();
                break;
            }
            case 2:
            {
                printf("\t1.Delete from Front\n\t2.Delete from End\n\t3.Delete from a position");
                printf("\n\tEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    {
                        value = deleteFirst();
                        break;
                    }
                    case 2:
                    {
                        value = deleteEnd();
                        break;
                    }
                    case 3:
                    {
                        value = deletePosition();
                        break;
                    }
                    default:
                    {
                        printf("\nEnter the right choice.");
                    }
                }
                displaylist();
                break;
            }
            case 3:
            {
                displaylist();
                break;
            }
            case 4:
            {
                exit(1);
                break;
            }
            default:
            {
                printf("Enter the correct option.\n");
            }
        }
    }
}