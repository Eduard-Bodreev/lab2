#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "functions.h"

int ScanInput(char* buffer)
{
        if(*buffer == 32)
        {
                if(scanf("%c", buffer) == -1)
                {
                        return -1;
                }
                return ScanInput(buffer);
        }
        if(*buffer > 47 && *buffer < 58)
        {
                while(*buffer == 48)
                {
                        if(scanf("%c", buffer) == -1)
                        {
                                return -1;
                        }
                        if (!(*buffer > 47 && *buffer < 58))
                        {
                                return 0;
                        }
                }
                while(*buffer > 47 && *buffer < 58)
                {
                        if(scanf("%c", buffer) == -1)
                        {
                                return -1;
                        }
                        if(!(*buffer > 47 && *buffer < 58))
                        {
                                return 1;
                        }
                }
        }
        if(*buffer == 10)
        {
                return 10;
        }
        if(*buffer == 33)
        {
                if(scanf("%c", buffer) == -1)
                {
                        return -1;
                }
                return 33;
        }
        if(*buffer == 38)
        {
                if(scanf("%c", buffer) == -1)
                {
                        return -1;
                }
                if(*buffer == 38)
                {
                        if(scanf("%c", buffer) == -1)
                        {
                                return -1;
                        }
                        return 38;
                }
                return 2;
        }
        if(*buffer == 124)
        {
                if(scanf("%c", buffer) == -1)
                {
                        return -1;
                }
                if(*buffer == 124)
                {
                        if(scanf("%c", buffer) == -1)
                        {
                                return -1;
                        }
                        return 124;
                }
                return 2;
        }
        return 2;
}

int Inversion(void* stack)
{
	int num, check;
	check = Pop(stack, &num);
	if(check)
	{
		return 1;
	}
	check = Push(stack, !num);
	if(check)
	{
		return 1;
	}
	return 0;
}

int Disjunction(void* stack)
{
	int first, second, check;
	check = Pop(stack, &first);
	if(check)
	{
		return 1;
	}
	check = Pop(stack, &second);
	if(check)
	{
		return 1;
	}
	check = Push(stack, first || second);		
	if(check)
	{
		return 1;
	}
	return 0;
}

int Conjunction(void* stack)
{
        int first, second, check;
        check = Pop(stack, &first);
        if(check)
        {
                return 1;
        }
        check = Pop(stack, &second);
        if(check)
        {
                return 1;
        }
        check = Push(stack, first && second);
        if(check)
        {
                return 1;
        }
	return 0;
}
