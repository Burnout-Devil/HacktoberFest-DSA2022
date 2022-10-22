#include <stdio.h>
#include<malloc.h>
void push();
void pop();
int peek();
int isfull();
int isempty();
int size,top=-1,st[200],i,x;
int main(void) {
    int n;
    printf("enter the size of the stack:\n");
    scanf("%d",&size);
    int st[size];
    printf("Enter the function choice:\n");
    printf("1.Push()\n2.Pop()\n3.Peek()\n4.isempty()\n5.isfull()\n\n");
    while(n<=6){
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            isempty();
            break;
            case 5:
            isfull();
            break;
            default:
            printf("Enter a valid choice\n");
        }
    }
    return 0;
}
void push(){
    if(top==size-1){
        printf("Overflow\n");
    }
    else{
        printf("enter the element to be pushed in the stack :\n");
        scanf("%d",&x);
        top++;
        st[top]=x;
    }
}
void pop(){
    if (top==-1){
        printf("Underflow\n");
    }
    else{
        x=st[top];
        printf("The popped item from the stack is %d.",x);
        top--;
    }
}
int peek(){
    if(top==-1)
    {
        printf("underflow\n");
    }
    else
    {
        printf("Peek item is %d.",st[top]);
    }
}
int isempty(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        printf("Stack is not empty.\n");
    }
    return 0;
}
int isfull(){
    if(top==size-1){
        printf("Stack is full.\n");
    }
    else{
        printf("Stack is not full.\n");
    }
    return 0;
}
