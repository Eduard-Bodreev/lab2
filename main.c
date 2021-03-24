#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "functions.h"

int main()
{
        void* stack;
	char buffer = 32;
	stack = Create();
	while(1)
        {
		switch (ScanInput(&buffer))
		{
			case -1:
				Delete(stack);
				return -1;
			case 0:
				if(Push(stack, 0))
				{
					Delete(stack);
					return -1;
				}
				continue;
			case 1:
				if(Push(stack, 1))
				{
					Delete(stack);
					return -1;
				}
				continue;
			case 2:
				printf("Wrong inpute. Try again.\n>>> ");
				Delete(stack);
				stack = Create();
				scanf("%*10000[^\n]");
				buffer = 32;
				continue;
			case 10:
				if(Check(stack))
				{
					Delete(stack);
					stack = Create();
					buffer = 32;
					continue;
				}
				int result;
				Pop(stack, &result);
				printf("Result: %d\n", result);
				Delete(stack);
				return 0;
			case 33:
				if(Inversion(stack))
				{
					Delete(stack);
					stack = Create();
					buffer = 32;
					continue;
				}
				continue;
			case 38:
				if(Disjunction(stack))
				{
					Delete(stack);
                                        stack = Create();
                                        buffer = 32;
                                        continue;
				}
				continue;
			case 124:
				if(Conjunction(stack))
				{
					Delete(stack);
                                        stack = Create();
                                        buffer = 32;
                                        continue;
				}
				continue;
		}
	}
}
