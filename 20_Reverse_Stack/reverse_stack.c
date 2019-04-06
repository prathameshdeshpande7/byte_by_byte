/*
 * Given a stack, reverse the items without creating
 * any additional data structures
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_STACK_SIZE 10

typedef struct stack {
	int *stack_ptr;
	int top;
} STACK;

void create_stack(STACK *stack)
{
	stack->stack_ptr = (int *)malloc(MAX_STACK_SIZE * sizeof(int));
	assert(stack->stack_ptr != NULL);
	stack->top = -1;
}

void destroy_stack(STACK *stack)
{
	free(stack->stack_ptr);
	stack->stack_ptr = NULL;
}

int is_empty(STACK *stack)
{
	return stack->top == -1;
}

int is_full(STACK *stack)
{
	return stack->top == MAX_STACK_SIZE - 1;
}

void push(STACK *stack, int value)
{
	// assert if pushing value on a full stack
	assert(!is_full(stack));

	stack->top++;
	*(stack->stack_ptr + stack->top) = value;
}

int pop(STACK *stack)
{
	int temp;

	// assert if popping from empty stack
	assert(!is_empty(stack));

	temp = *(stack->stack_ptr + stack->top);
	stack->top--;
	return temp;
}

int top(STACK *stack)
{
	// peek top element
	return stack->top == -1 ? -1 : *stack->stack_ptr;
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void reverse_stack(STACK *stack)
{
	int start, end;

	if (stack == NULL || is_empty(stack))	return;

	for (start = 0, end = stack->top; start <= stack->top / 2; start++, end--)
		swap( (stack->stack_ptr + start), (stack->stack_ptr + end) );
}

int main()
{
	int arr[] = {5, 77, 39, 17, 28, 59, 93, 47, 69, 23};
	int len_arr = sizeof(arr)/sizeof(arr[0]);
	int i;

	STACK s;

	create_stack(&s);

	printf("Stack values(top first): ");
	for(i = len_arr - 1; i >= 0; i--)
		printf("%d ", arr[i]);
	printf("\n");

	for(i = 0; i < len_arr; i++)
		push(&s, arr[i]);

	reverse_stack(&s);

	printf("Reversed stack values(top first): ");
	while(!is_empty(&s))
		printf("%d ", pop(&s));
	printf("\n");

	destroy_stack(&s);
	return 0;
}
