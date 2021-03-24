#ifndef list_H
#define list_H

typedef struct Item
{
	int data;
	struct Item* next;
} Item;

typedef struct L_Stack
{
	struct Item* head;
} L_Stack;

struct L_Stack* L_Create();

void L_Delete(struct L_Stack*);

int L_Push(struct L_Stack*, int);

int L_Pop(struct L_Stack*, int*);

int L_Check(struct L_Stack*);

#endif
