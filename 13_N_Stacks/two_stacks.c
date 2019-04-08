/*
 * Implement 2 stacks using a single array
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_STACK_SIZE 10
#define FIRST_STACK	1
#define SECOND_STACK	2

/*
 * top1 --->        <--- top2
 *  _ _ _ _       __ ___ ___
 * |_|_|_|_| ... |__|___|___|
 *  0 1 2 3          N-2 N-1
 */
typedef struct stack {
	int *stack_ptr;
	int top1, top2;
} STACK;

void create_stack(STACK *stack)
{
	stack->stack_ptr = (int *)malloc(MAX_STACK_SIZE * sizeof(int));
	assert(stack->stack_ptr != NULL);
	stack->top1 = -1;
	stack->top2 = MAX_STACK_SIZE;
}

void destroy_stack(STACK *stack)
{
	free(stack->stack_ptr);
	stack->stack_ptr = NULL;
}

int is_empty(STACK *stack, int sn)
{
	if (sn == FIRST_STACK)
		return stack->top1 == -1;
	else if (sn == SECOND_STACK)
		return stack->top2 == MAX_STACK_SIZE;
}

int is_full(STACK *stack)
{
	printf("TOP2 %d, TOP1 %d\n", stack->top2, stack->top1);
	return stack->top2 == stack->top1 + 1;
}

void push(STACK *stack, int value, int sn)
{
	// assert if pushing value on a full stack
	assert(!is_full(stack));

	if (sn == FIRST_STACK) {
		stack->top1++;
		*(stack->stack_ptr + stack->top1) = value;
	} else if (sn == SECOND_STACK) {
		stack->top2--;
		*(stack->stack_ptr + stack->top2) = value;
	}
}

int pop(STACK *stack, int sn)
{
	int temp;

	// assert if popping from empty stack
	assert(!is_empty(stack, sn));

	if (sn == FIRST_STACK) {
		temp = *(stack->stack_ptr + stack->top1);
		stack->top1--;
	} else if (sn == SECOND_STACK) {
		temp = *(stack->stack_ptr + stack->top2);
		stack->top2++;
	}
	return temp;
}

int top(STACK *stack, int sn)
{
	// peek top element
	if (sn == FIRST_STACK)
		return stack->top1 == -1 ? -1 : *(stack->stack_ptr + stack->top1);
	else if (sn == SECOND_STACK)
		return stack->top2 == MAX_STACK_SIZE ? -1 : *(stack->stack_ptr + stack->top2);
}

void print_stack(STACK *s)
{
	int i;
	printf("\nArray: ");
	for(i = 0; i < MAX_STACK_SIZE; i++)
		printf("%d ", s->stack_ptr[i]);

	printf("\n");
}

int main()
{
	int arr1[] = {9, 23, 77, 58, 41, 217};
	int arr2[] = {96, 31, 84, 7, 67};
	int len_arr1 = sizeof(arr1)/sizeof(arr1[0]);
	int len_arr2 = sizeof(arr2)/sizeof(arr2[0]);
	int i;

	STACK s;

	create_stack(&s);

	printf("Stack 1 values(top first): ");
	for(i = len_arr1 - 1; i >= 0; i--)
		printf("%d ", arr1[i]);
	printf("\n");

	printf("Stack 2 values(top first): ");
	for(i = len_arr2 - 1; i >= 0; i--)
		printf("%d ", arr2[i]);
	printf("\n");

	printf("Pushing: ");
	for(i = 0; i < len_arr1; i++)
		push(&s, arr1[i], FIRST_STACK);

	printf("Pushing: ");
	for(i = 0; i < len_arr2; i++)
		push(&s, arr2[i], SECOND_STACK);

	print_stack(&s);

	printf("Popping: ");
	while(!is_empty(&s, FIRST_STACK))
		printf("%d ", pop(&s, FIRST_STACK));
	printf("Popping: ");
	while(!is_empty(&s, SECOND_STACK))
		printf("%d ", pop(&s, SECOND_STACK));
	print_stack(&s);
	printf("Pushing: ");
	push(&s, 102, SECOND_STACK);
	print_stack(&s);
	printf("\n");
	printf("Pushing: ");
	for(i = 0; i < len_arr2; i++)
		push(&s, arr2[i], SECOND_STACK);

	printf("Pushing: ");
	for(i = 0; i < len_arr1 - 2; i++)
		push(&s, arr1[i], FIRST_STACK);
	printf("Pushing: ");
	push(&s, 33, SECOND_STACK);
	push(&s, 43, SECOND_STACK);
	push(&s, 53, SECOND_STACK);
	print_stack(&s);
	destroy_stack(&s);
	return 0;
}
