/* Doubly Linked List implementation */no5 ko
#include<stdio.h>
#include<stdlib.h>

struct Node  { //creating structure for node
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(int x) { //creating newnode
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(int x) {
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void Print() {
	struct Node* temp = head;
	printf("Forward: ");
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {

	head = NULL; // empty list. set head as NULL.
int choice, item;
	do {
		printf("\n1.insert from head \n2.inseart from tail \n3.Display\n4:Exit\n");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("\nEnter the data:\n"); scanf("%d",&item); InsertAtHead(item);
			break;
		case 2:
			printf("\nEnter the data:\n"); scanf("%d",&item); InsertAtTail(item);
			break;
			break;
		case 3:
			print();
			break;
		//case 4:
			//exit(1);
			//break;
		default:
			printf("invalid choice\n");
			break;
		}
	}while(choice<5);
return 0;
}

