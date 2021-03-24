#include <stdio.h>
#include <stdlib.h>
#include "list.h"

L_Stack* L_Create()
{
	return (L_Stack*)calloc(1, sizeof(L_Stack));
}

void L_Delete(L_Stack* stack)
{
	Item*  ptr = stack->head, *prev;
	while (ptr)
	{
		prev = ptr;
		ptr = ptr->next;
		free(prev);
	}
	free(stack);
}

int L_Push(L_Stack* stack, int data)
{
	Item* new = (Item*)malloc(sizeof(Item));

	if(!new)
	{
		return -1;
	}

	new->data = data;
	new->next = stack->head;
	stack->head = new;
	return 0;
}

int L_Pop(L_Stack* stack, int* output)
{
	if(!stack->head)
	{
		return -1;
	}

	*output = stack->head->data;
	Item* head = stack->head;
	stack->head = head->next;
	free(head);
	return 0;
}

int L_Check(L_Stack* stack)
{
	if(stack->head == NULL)		
	{
		return -1;
	}

	if(stack->head->next)
	{
		return -1;
	}
	return 0;
}
