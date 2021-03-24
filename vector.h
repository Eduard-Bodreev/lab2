#ifndef vector_H
#define vector_H

#define MAX 10

typedef struct V_Stack
{
	int item[MAX];
	int place;
} V_Stack;

struct V_Stack* V_Create();

void V_Delete(struct V_Stack*);

int V_Push(struct V_Stack*, int);

int V_Pop(struct V_Stack*, int*);

int V_Check(struct V_Stack*);

#endif
