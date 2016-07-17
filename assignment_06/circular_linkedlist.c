#include <stdio.h> 
#include <stdlib.h> 

struct node{ //structure for node
	int info;
	struct node *next; 
};
typedef struct node NodeType;  //initiallizing user define datatpe
NodeType *rear=0,*front=0; //initillizing value of rear and front  
void insert(int);
void display(); 
int main(){
	int choice, item;
	do
	{
	printf("\n1.Insert \n2.Display\n3:Exit\n"); 
	printf("enter ur choice\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter the data:\n"); 
			scanf("%d",&item); 
			insert(item);
			break;
		
		case 2:
			display();
			break; 
		//case 3:
		//	exit(1);
		//	break; 
		default:
			printf("invalid choice\n");
			break; 
		}
	}while(choice<3);
	return 0;
}
void insert(int item) {
NodeType *nnode;
nnode=( NodeType *)malloc(sizeof(NodeType));
if(rear==0) {   			//condotion where there is no data inseated yet
	nnode->info=item; //inseating the value in nnode
			//initilizing null value at nnode->next
	rear=front=nnode;		//changing the position of rear and front fron null to nnode
	rear->next=front;
} 
else{
	nnode->info=item;
	nnode->next=front; //initilizing the nnode-> to null so more data can be inserted later 
	rear->next=nnode; //replacing the value of rear->next with address of nnode so new node points to previous node
	rear=nnode;			//changing rear to new node
	} 
}
void display()
 {
	NodeType *temp;  		//initilizing temp variable

	temp=front;	
	front=front->next;		// replacing the vall=ue of tem with front
	printf("\n items are:\t"); 
	while(temp!=front){			//loop which display all items of queue until temp reaches to last item i.e null
		printf("%d\t",temp->info);
		temp=temp->next; 
	}
}
