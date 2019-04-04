/*
 * ● Question : Given a stack, sort the elements in the stack using one additional  stack.
 * ● Eg. 
 * sort([1, 3, 2, 4]) = [1, 2, 3, 4]
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_STACK_SIZE	10

typedef struct STACK {
	int *stack_ptr;
	int top;
} STACK;

int is_full(STACK *stack)
{
	return stack->top == MAX_STACK_SIZE - 1;
}

int is_empty(STACK *stack)
{
	return stack->top == -1;
}

void push(STACK *stack, int value)
{
	assert(!is_full(stack));

	stack->top += 1;
	stack->stack_ptr[stack->top] = value;
}

int pop(STACK *stack)
{
	int temp;
	assert(!is_empty(stack));

	temp = stack->stack_ptr[stack->top];
	stack->top--;
	return temp;
}

void create_stack(STACK *stack)
{
	stack->stack_ptr = (int *)malloc(MAX_STACK_SIZE * sizeof(int));
	assert(stack->stack_ptr);
	stack->top = -1;
	return stack;
}

void destroy_stack(STACK *stack)
{
	free(stack->stack_ptr);
}

int main()
{
	int arr[] = {1, 2, 3, 4};
	int i, len_arr = sizeof(arr)/sizeof(arr[0]);
	STACK s1, s2;

	create_stack(&s1);
	create_stack(&s2);

	for (i = 0; i < len_arr; i++)
		push(&s1, arr[i]);


	while(!is_empty(&s1))
		printf("%d ", pop(&s1));

	destroy_stack(&s2);
	destroy_stack(&s1);

	return 0;
}
