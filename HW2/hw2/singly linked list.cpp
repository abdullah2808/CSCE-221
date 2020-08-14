#include<list>
#include <iostream>

using namespace std;

int num = 0;

struct Node
{
	int value;
	struct Node* next;
};

void Insert(struct Node** head, int value) 
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->value = value;
	temp->next = (*head);
	(*head) = temp;
}



int NodeCount(struct Node* head) {
	if (head != NULL)
	{
		num++;
		NodeCount(head->next);
	}
	else 
		return num;
}

int main() 
{
	struct Node* head = NULL;
	struct Node* head2 = NULL;
	Insert(&head, 1);
	Insert(&head, 2);
	Insert(&head, 2);
	Insert(&head, 3);
	Insert(&head, 4);

	Insert(&head2, 1);
	Insert(&head2, 2);
	Insert(&head2, 2);
	Insert(&head2, 3);
	Insert(&head2, 4);
	Insert(&head2, 5);
	Insert(&head2, 6);
	cout << "The total number of nodes: " << NodeCount(head) << endl;
	cout << "The total number of nodes: " << NodeCount(head2) << endl;

	return 0;
}