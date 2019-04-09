/* ● Question: Implement N > 0 stacks using a single array to store
 * all stack data (you may use auxiliary arrays in your stack object,
 * but all of the objects in all of the stacks must be in the same array).
 * No stack should be full unless the entire array is full.
 *
 * ● Eg.
 * N = 3;
 * capacity = 10;
 * Stacks stacks = new Stacks(N, capacity);
 * stacks.put(0, 10);
 * stacks.put(2, 11);
 * stacks.pop(0) = 10;
 * stacks.pop(2) = 11;
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define N_STACKS	3
#define MAX_STACK_SIZE 10

/*
 * top1 --->        <--- top2
 *  _ _ _ _       __ ___ ___
 * |_|_|_|_| ... |__|___|___|
 *  0 1 2 3          N-2 N-1
 */
typedef struct stack {
	int *stack_ptr;
	int top[N_STACKS];
	int next[MAX_STACK_SIZE];
	int free;
} STACK;

void create_stack(STACK *stack)
{
	int i;

	stack->stack_ptr = (int *)malloc(MAX_STACK_SIZE * sizeof(int));
	assert(stack->stack_ptr != NULL);

	// initialize and store top for n stacks
	for (i = 0; i < N_STACKS; i++)
		stack->top[i] = -1;

	// next slot available
	for (i = 0; i < MAX_STACK_SIZE - 1; i++)
		stack->next[i] = i + 1;
	stack->next[MAX_STACK_SIZE - 1] = -1;

	// free is set to 0
	stack->free = 0;
}

void destroy_stack(STACK *stack)
{
	free(stack->stack_ptr);
	stack->stack_ptr = NULL;
}

int is_empty(STACK *stack, int sn)
{
	return stack->top[sn] == -1;
}

int is_full(STACK *stack)
{
	return stack->free == -1;
}

void push(STACK *stack, int value, int sn)
{
	int i;

	// assert if pushing value on a full stack
	assert(!is_full(stack));

	i = stack->free;

	stack->free = stack->next[i];

	stack->next[i] = stack->top[sn];

	stack->top[sn] = i;

	*(stack->stack_ptr + i) = value;
}

int pop(STACK *stack, int sn)
{
	int temp, i;

	// assert if popping from empty stack
	assert(!is_empty(stack, sn));

	i = stack->top[sn];

	stack->top[sn] = stack->next[i];

	stack->next[i] = stack->free;

	stack->free = i;

	temp = *(stack->stack_ptr + i);
	return temp;
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
	int arr1[] = {9, 23, 77, 58, 41};
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
		push(&s, arr1[i], 1);

	printf("Pushing: ");
	for(i = 0; i < len_arr2; i++)
		push(&s, arr2[i], 2);

	print_stack(&s);

	printf("Popping: ");
	while(!is_empty(&s, 1))
		printf("%d ", pop(&s, 1));
	printf("Popping: ");
	while(!is_empty(&s, 2))
		printf("%d ", pop(&s, 2));
	print_stack(&s);
	printf("Pushing: ");
	push(&s, 102, 2);
	print_stack(&s);
	printf("\n");
	printf("Pushing: ");
	for(i = 0; i < len_arr2; i++)
		push(&s, arr2[i], 2);

	printf("Pushing: ");
	for(i = 0; i < len_arr1 - 2; i++)
		push(&s, arr1[i], 1);
	printf("Pushing: ");
	push(&s, 33, 2);
	push(&s, 43, 2);
	push(&s, 53, 2);
	print_stack(&s);
	destroy_stack(&s);
	return 0;
}
