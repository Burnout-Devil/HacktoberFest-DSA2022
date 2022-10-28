//Govind A
/* BINARY SEARCH TREE
datastrucure used is LinkedList
*/

#include <stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *RCHILD;
    struct node *LCHILD;
};
struct node *root = NULL;

struct node *getnode()
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    return new;
}

// Function to insert at the front of the linked list
int Insert(int item)
{
    int flag = 0;
    struct node *ptr = getnode();
    ptr = root;
    struct node *ptr1 = getnode();
    if(ptr == NULL)
    {
        root = (struct node*) malloc(sizeof(struct node));
        root->data = item;
        root->LCHILD = NULL;
        root ->RCHILD = NULL;
        printf("The element %d is inserted at the root of the binary search tree.\n",item);
    }
    else
    {
    while(ptr!=NULL && flag==0)
    {
        if(item < ptr->data)
        {
            ptr1=ptr;
            ptr = ptr->LCHILD;
        }
        else if(item > ptr->data)
        {
            ptr1=ptr;
            ptr = ptr->RCHILD;
        }
        else if(item == ptr->data)
        {
            flag = 1;
            printf("The data is already present at a node.");
        }
    }
    if(ptr==NULL)
    {
        struct node *new =  getnode();
        new->data = item;
        new->LCHILD = NULL;
        new->RCHILD = NULL;
        if(ptr1->data < item)
        {
            ptr1->RCHILD = new;
        }
        else
        {
            ptr1->LCHILD = new;
        }
        printf("The element %d is inserted.\n",item);
    }
    }
}

struct node* Search(struct node *root,int item)
{
    if(root == NULL)
    {
        printf("The tree is empty.");
    }
    else if(item == root->data)
    {
        printf("The data is present in the tree.");
    }
    else if(item < root->data)
    {
        return Search(root->LCHILD,item);
    }
    else
    {
        return Search(root->RCHILD,item);
    }
}

struct node* SUCC(struct node *ptr)
{
    struct node* ptr1 = getnode();
    ptr1 = ptr->RCHILD;
    if(ptr1 != NULL)
    {
        while(ptr1->LCHILD != NULL)
        {
            ptr1 = ptr1->LCHILD;
        }
    }
    return(ptr1);
}

// Function to delete from the front of the linked list 
struct node* Delete(int item)
{
    int data,flag=0;
    struct node *ptr = root;
    struct node *ptr1 = getnode();
    struct node *ptr2 = getnode();
    while(ptr!=NULL && flag==0)
    {
        if(item < ptr->data)
        {
            ptr1=ptr;
            ptr = ptr->LCHILD;
        }
        else if(item > ptr->data)
        {
            ptr1=ptr;
            ptr = ptr->RCHILD;
        }
        else if(ptr->data == item)
        {
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("The item is not present in the tree.");
    }
    //Decide the case of deletePosition
    if(ptr->LCHILD==NULL && ptr->RCHILD==NULL) //case 1 : Node has no child
    {
        if(ptr1->LCHILD == ptr)
        {
            ptr1->LCHILD = NULL;
        }
        else
        {
            ptr1->RCHILD = NULL;
        }
        return(ptr);
    }
    else
    {
       if(ptr->LCHILD != NULL && ptr->RCHILD != NULL) //case 3 : Node has both children
       {
           ptr2 = SUCC(ptr); //find the inorder successor of the Node
           ptr->data = ptr2->data;
           free(ptr2);
       }
       else //case 2 : Node has only one children
       {
           if(ptr1->LCHILD == ptr)
           {
               if(ptr->LCHILD == NULL)
               {
                   ptr1->LCHILD = ptr->RCHILD;
               }
               else
               {
                   ptr1->LCHILD = ptr->LCHILD;
               }
           }
           else
           {
               if(ptr1->RCHILD == ptr)
               {
                   if(ptr->LCHILD == NULL)
                   {
                       ptr1->RCHILD = ptr->RCHILD;
                   }
                   else 
                   {
                       ptr1->RCHILD = ptr->LCHILD;
                   }
               }
           }
           return(ptr);
       }
    }
}

void inorderTraverse(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorderTraverse(root->LCHILD);
    printf("%d->",root->data);
    inorderTraverse(root->RCHILD);
}

void preorderTraverse(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
    printf("%d->",root->data);
    preorderTraverse(root->LCHILD);
    preorderTraverse(root->RCHILD);
    }
}

void postorderTraverse(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorderTraverse(root->LCHILD);
    postorderTraverse(root->RCHILD);
    printf("%d->",root->data);
}

int main()
{
    int option,choice,data,key,value;
    while(1)
    {
        printf("\nBinary Search Tree operations...\n1.Insertion\n2.Deletion\n3.Traversal\n4.Search");
        printf("\nEnter option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                printf("\tEnter the data to be inserted : ");
                scanf("%d",&data);
                Insert(data);
                break;
            }
            case 2:
            {
                printf("\tEnter the data to be deleted : ");
                scanf("%d",&data);
                Delete(data);
                break;
            }
            case 3:
            {
                printf("\tTraversal options..\n\t1.Inorder\n\t2.Preorder\n\t3.Postorder\n\tEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    {
                        inorderTraverse(root);
                        break;
                    }
                    case 2:
                    {
                        preorderTraverse(root);
                        break;
                    }
                    case 3:
                    {
                        postorderTraverse(root);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                
                }
                break;
            }
            case 4:
            {
                printf("Enter the node to be searched : ");
                scanf("%d",&key);
                Search(root,key);
                break;
            }
            default:
            {
                printf("Enter the correct option.\n");
            }
        }
    }
}