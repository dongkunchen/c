//模擬多項式(數學公式x的x次方+y的y次方)
#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

int main()
{
    int i;
    int a[][2]={{5,0},{2,1},{8,8},{3,16}};
    int b[][2]={{6,1},{16,6},{-8,8}};
    node *head1,*head2,*p1,*p2;

    head1 = poly_create();
    if(head1 == NULL)
        exit(1);
    head2 = poly_create();
    if(head2 == NULL)
        exit(1);

    p1 = poly_insert(head1,a,4);
    if(p1 == NULL)
        exit(1);
    p2 = poly_insert(head2,b,3);
    if(p2 == NULL)
        exit(1);
    poly_show(p1);
    poly_show(p2);

    poly_union(p1,p2);
    poly_show(p1);

    return 0;
}