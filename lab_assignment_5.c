// Logan Boyd
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char letter;
	struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head)
{
	node *tmp = head;
	int counter = 0;

	while (tmp != NULL)
	{
		counter++;
		tmp = tmp->next;
	}

	return counter;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char *toCString(node *head)
{
	char *str = (char *)malloc((length(head) + 1) * sizeof(char));

	node *tmp = head;
	int i = 0;

	while (tmp != NULL)
	{
		str[i] = tmp->letter;
		tmp = tmp->next;
		i++;
	}

	str[i] = '\0';
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c)
{
	node* newNode = (node *)malloc(sizeof(node)); // create node 
	if (newNode == NULL)
	{
		return;
	}
	newNode->letter = c; // take in char
	newNode->next = NULL;

	if (*pHead == NULL)
	{
		*pHead = newNode;
	}
	else {
		node* current = *pHead;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead)
{
	if (*pHead == NULL) 
	{
		return; // the list is already empty
	}
	
	node* current = *pHead;
	node* nextNode = NULL;

	while (current != NULL)
	{
		nextNode = current->next; // set reference to the next node
		free(current); // free the current node
		current = nextNode; // move to next node
	}

	*pHead = NULL; // set the head to null 
	
}

int main(void)
{
	int i, strLen, numInputs;
	node *head = NULL;
	char *str;
	char c;
	FILE *inFile = fopen("input.txt", "r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile, " %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}