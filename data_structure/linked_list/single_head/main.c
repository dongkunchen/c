//Simulation function(CRUD)
#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

int main()
{
    linked *l;
    datatype arr[] = {10,5,20,15,30,25,40,35,50};
    int i;

    l = linked_create();
    if(l == NULL)
        exit(1);

    for ( i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        // if(linked_insert_at(l,i,&arr[i]))
        if(linked_insert_order(l,&arr[i]))
            exit(1);
    }
    
    linked_display(l);

    // linked_delete(l,30);
    int err;
    datatype value;
    err = linked_delete_at(l,2,&value);
    if(err)
        exit(1);
    
    printf("delete:%d\n",value);

    linked_display(l);

    linked_destroy(l);

    return 0;
}