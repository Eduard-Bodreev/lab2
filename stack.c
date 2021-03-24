#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "list.h"

void* Create()
{
	#ifdef LIST
	return (void*)L_Create();
	#endif

	#ifdef VECTOR
	return (void*)V_Create();
	#endif
}

void Delete(void* stack)
{
	#ifdef LIST
	L_Delete((L_Stack*)stack);
	#endif

	#ifdef VECTOR
	V_Delete((V_Stack*)stack);
	#endif
}

int Push(void* stack, int data)
{
	#ifdef LIST
	return L_Push((L_Stack*)stack, data);
	#endif

	#ifdef VECTOR
	return V_Push((V_Stack*)stack, data);
	#endif
}

int Pop(void* stack, int* output)
{
	#ifdef LIST
	return L_Pop((L_Stack*)stack, output);
	#endif

	#ifdef VECTOR
	return V_Pop((V_Stack*)stack, output);
	#endif
}

int Check(void* stack)
{
	#ifdef LIST
	return L_Check((L_Stack*)stack);
	#endif

	#ifdef VECTOR
	return V_Check((V_Stack*)stack);
	#endif
}
