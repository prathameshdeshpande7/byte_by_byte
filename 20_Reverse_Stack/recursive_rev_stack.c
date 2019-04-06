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

void insert_at_bottom(STACK *stack, int x)
{
	int temp;

	if (stack == NULL || is_empty(stack)) {
		printf("insert_at_bottom pushing X: %d\n", x);
		printf("---------------------------------------\n");
		push(stack, x);
		return;
	}

	temp = pop(stack);
	printf("insert_at_bottom popping temp %d\n", temp);
	insert_at_bottom(stack, x);
	push(stack, temp);
	printf("insert_at_bottom pushing temp %d\n", temp);
}

void reverse_stack(STACK *stack)
{
	int temp;

	if (stack == NULL || is_empty(stack))
		return;

	temp = pop(stack);
	printf("reverse_stack popping %d\n", temp);

	reverse_stack(stack);
	insert_at_bottom(stack, temp);
	return;
}

int main()
{
	int arr[] = {9, 23, 77, 58, 41};
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
