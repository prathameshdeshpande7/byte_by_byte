/*
 * Given a  singly linked list, write a function to
 * determine whether the list is a palindrome
 *
 * E.g.
 * palindrome(1, 2, 3) ==> false
 * palindrome(1, 2, 1) ==> true
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
		datum = (i < 5) ? create_node(i + 1) : create_node(10 - i);
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

int main()
{
	node *head = NULL;

	head = create_list(head);

	printf("List: ");
	print_list(head);
	
	return 0;
}
