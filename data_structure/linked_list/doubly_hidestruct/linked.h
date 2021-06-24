#ifndef LINKED_H__
#define LINKED_H__

typedef void linked;

#define LINKED_FORWARD 1
#define LINKED_BACKWARD 2

typedef void linked_op(const void *);
typedef int linked_cmp(const void *, const void *);

linked *linked_create(int);

int linked_insert(linked *, const void *, int);

void *linked_find(linked *, const void *, linked_cmp *);

int linked_delete(linked *, const void *, linked_cmp *);

int linked_fetch(linked *, const void *, linked_cmp *, void *);

void linked_travel(linked *, linked_op *);

void linked_destroy(linked *);

#endif