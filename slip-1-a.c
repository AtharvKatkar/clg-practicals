#include <stdio.h>
#include "doublylinkedlist.h"

void main()
{
    int da, db, dc;
    scanf("%d%d%d", &da, &db, &dc);
    Node *a = createNode(da, NULL, NULL);
    Node *b = createNode(db, NULL, a);
    Node *c = createNode(dc, NULL, b);

    a->next = b;
    b->next = c;
    c->next = NULL;

    displayLL(a);
}