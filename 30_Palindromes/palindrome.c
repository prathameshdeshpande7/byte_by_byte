/*
 * Given a  singly linked list, write a function to
 * determine whether the list is a palindrome
 *
 * E.g.
 * palindrome(1, 2, 3) ==> false
 * palindrome(1, 2, 1) ==> true
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define STACK_SIZE 10
#define STACK_TYPE int

typedef struct node {
	int data;
	struct node *next;
}node;

STACK_TYPE *stack;
STACK_TYPE stack_top;
int top_element = -1;

void create_stack()
{
	stack = (STACK_TYPE *)malloc(STACK_SIZE *sizeof(STACK_TYPE));
	assert(stack);
}

void destroy_stack(STACK_TYPE *stack)
{
	free(stack);
}

int is_empty()
{
	return top_element == -1;
}

int is_full(STACK_TYPE *stack)
{
	printf("TOP %d\n", top_element);
	return top_element == STACK_SIZE - 1;
}

void push(STACK_TYPE value)
{
	if (is_full(stack))
		return;
	printf("!FULL\n");

	top_element += 1;
	printf("top %d, value %d, stack %d\n", top_element, value, *stack);
	*(stack + top_element) = value;
	printf("PUSH top %d, value %d, stack %d\n", top_element, value, *(stack+top_element));
}

int pop()
{
	if (is_empty())	return 0;

	top_element--;
	printf("POP top %d, stack %d\n", top_element, *(stack+top_element+1));
	return *(stack + top_element + 1);
}

node *create_node(int data)
{
	node *temp;

	temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	return temp;
}

void destroy_node(node *elem)
{
	free(elem);
}

node *create_list(node *head)
{
	int i;
	node *datum, *tail;

	for (i = 0; i < 11; i++) {
		datum = (i < 5) ? create_node(i + 1) : create_node(11 - i);
		//datum = create_node(i + 1);
		if (head == NULL) {
			head = tail = datum;
		} else {
			tail->next = datum;
			tail = tail->next;
		}
	}

	return head;
}

void destroy_list(node *head)
{
	node *temp;

	while(head != NULL) {
		temp = head;
		head = head->next;
		destroy_node(temp);
	}
}

void print_list(node *head)
{
	node *temp = head;

	while(temp != NULL) {
		if (temp->next != NULL)
			printf("%d->", temp->data);
		else
			printf("%d\n", temp->data);

		temp = temp->next;
	}
}

int palindrome(node *head)
{
	node *curr, *fast;

	/*
	 * Point curr and fast pointers to head of list
	 * Move fast twice the speed of curr. For even elements
	 * in list, fast will point to NULL. Whereas for odd elements
	 * fast will point to last node of list.
	 */
	curr = fast = head;

	while(fast != NULL && fast->next != NULL) {
		push(curr->data);
		curr = curr->next;
		fast = fast->next->next;
	}

	printf("CURR %d, fast 0x%p\n", curr->data, fast);
	if (fast != NULL)
		curr = curr->next;

	while (curr != NULL) {
		if (pop() != curr->data)
			return 0;
		curr = curr->next;
	}
	return 1;
}

int main()
{
	int ret = 0;
	node *head = NULL;

	create_stack();
	head = create_list(head);

	printf("List: ");
	print_list(head);

	ret = palindrome(head);
	if (ret == 1)
		printf("Is palindrome\n");
	else
		printf("Not a palindrome\n");

	destroy_list(head);
	destroy_stack(stack);
	return 0;
}
