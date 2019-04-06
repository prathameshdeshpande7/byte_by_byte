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

int top(STACK *stack)
{
	return stack->top == -1 ? -1 : stack->stack_ptr[stack->top];
}

void create_stack(STACK *stack)
{
	stack->stack_ptr = (int *)malloc(MAX_STACK_SIZE * sizeof(int));
	assert(stack->stack_ptr);
	stack->top = -1;
}

void destroy_stack(STACK *stack)
{
	free(stack->stack_ptr);
}

int sort_stack(STACK *s1, STACK *s2)
{
	int temp = 0;

	if (s1 == NULL ||is_empty(s1))	return -1;

	while(!is_empty(s1)) {
		// If s1 not empty
		// Pop the top element of s1
		temp = pop(s1);

		/*
		 * while s2 not empty, check if temp can be pushed
		 * else go on popping from s2 and pushing to s1
		 */
		while(!is_empty(s2) && temp > top(s2)) {
			push(s1, pop(s2));
		}
		push(s2, temp);
	}
}

int main()
{
	//int arr[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int arr[] = {10, 9, 8, 7, 6, 1, 3, 2, 4, 5};
	//int arr[] = {0};
	int i, len_arr = sizeof(arr)/sizeof(arr[0]), ret = -1;
	STACK s1, s2;

	create_stack(&s1);
	create_stack(&s2);

	printf("Stack: ");
	for (i = len_arr - 1; i >= 0; i--)
		printf("%d ", arr[i]);

	printf("\n");

	for (i = 0; i < len_arr; i++)
		push(&s1, arr[i]);

	ret = sort_stack(&s1, &s2);
	if (ret != -1) {
		printf("Sorted stack: ");
		while(!is_empty(&s2))
			printf("%d ", pop(&s2));
		printf("\n");
	}

	destroy_stack(&s2);
	destroy_stack(&s1);

	return 0;
}
