#include <stdio.h>
#include "slip-29-a.h"

void main()
{
    int s = initStack(10);
    int pointer = -1;

    printf("%d pushed", push(s, 10, &pointer));
    printf("%d pushed", push(s, 20, &pointer));
    printf("%d pushed", push(s, 30, &pointer));
    printStack(s, &pointer);

    printf("%d poped", pop(s, &pointer));
    printf("%d poped", pop(s, &pointer));
    printStack(s, &pointer);
}