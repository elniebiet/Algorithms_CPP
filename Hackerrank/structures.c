#include <stdio.h>
#include <stdlib.h>

struct st {
    int id;
    char firstName[20];
    char lastName[20];
    char *myName;
};

int main()
{
    struct st me;
    me.id = 10;
    gets(me.myName);
    printf("%s", me.myName);

}
