#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{

    int rollno;

    struct Node *Next;
};

struct Node *Create_List();

void show(struct Node *);

struct Node *Concat(struct Node *, struct Node *);

int main(int argc, char const *argv[])
{

    struct Node *h1, *h2, *p;

    printf("enter the number of Node to be inserted in list 1\n");

    h1 = Create_List();

    printf("enter the number of Node to be inserted in list 2\n");

    h2 = Create_List();

    printf("showing a list1\n");

    show(h1);

    printf("showing a list 2\n");

    show(h2);

    p = Concat(h1, h2);

    printf("list after concatenating\n");

    show(p);

    return 0;
}

struct Node *
Create_List()
{

    int k, n;

    scanf("%d", &n);

    struct Node *p, *h;

    for (k = 0; k < n; k++)

    {

        if (k == 0)

        {

            h = (struct Node *)malloc(sizeof(struct Node));

            p = h;
        }

        else

        {

            p->Next = (struct Node *)malloc(sizeof(struct Node));

            p = p->Next;
        }
        scanf("%d", &p->rollno);
    }
    p->Next = NULL;

    return h;
}

struct Node *
Concat(struct Node *h1, struct Node *h2)
{

    struct Node *p;

    if (h1 == NULL)

    {

        h1 = h2;

        return h1;
    }

    if (h2 == NULL)

    {

        return h1;
    }

    p = h1;

    while (p->Next != NULL)

    {

        p = p->Next;
    }

    p->Next = h2;

    return h1;
}

void show(struct Node *h)
{

    struct Node *p;

    if (h == NULL)

    {

        printf("list is empty\n");
    }

    else

    {

        p = h;

        while (p != NULL)

        {

            printf("%d  ", p->rollno);

            p = p->Next;
        }

        printf("\n");
    }
}
