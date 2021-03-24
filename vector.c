#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

V_Stack* V_Create()
{
	V_Stack* s = (V_Stack*)calloc(1, sizeof(V_Stack));
	s->place = 0;
	return s;
}

void V_Delete(V_Stack* stack)
{
	free(stack);
}

int V_Push(V_Stack* stack, int data)
{
	if(stack->place >= MAX)
	{
		printf("Out of memory.\n");
		return -1;
	}
	stack->item[stack->place] = data;
	stack->place++;
	return 0;
}

int V_Pop(V_Stack* stack, int* output)
{
	if(stack->place == 0)
	{
		printf("Empty stack.\n");
		return -1;
	}

	*output = stack->item[--stack->place];
	return 0;
}

int V_Check(V_Stack* stack)
{
	if(stack->place == 0)
	{
		printf("Empty stack.\n");
		return -1;
	}
	if(stack->place > 1)
	{
		printf("Srack contains more than one item.\n");
		return -1;
	}
	return 0;
}
