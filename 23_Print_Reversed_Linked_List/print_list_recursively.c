/*
 * Given a linked list, write a function that prints the
 * list in reverse order.
 *
 * print_reversed_list(1, 2, 3) => 3 2 1
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;

node *create_node(int data)
{
	node *temp;

	temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	return temp;
}

node *create_list(node *head)
{
	int i;
	node *datum, *tail;

	for (i = 0; i < 10; i++) {
		datum = create_node(i + 1);
		if (head == NULL) {
			head = tail = datum;
		} else {
			tail->next = datum;
			tail = tail->next;
		}
	}

	return head;
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

void print_rev_list(node *head)
{
	if (head == NULL)
		return;

	print_rev_list(head->next);

	printf("%d ", head->data);
}

int main()
{
	node *head = NULL;

	head = create_list(head);

	printf("List: ");
	print_list(head);

	printf("Reversed List: ");
	print_rev_list(head);
	printf("\n");

	return 0;
}
