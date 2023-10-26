#include <stdio.h>
#include <stdlib.h>

struct List
{
	int data;
	struct List* Next;
} *First;

void addToList(struct List** head, int value)
{
    struct List* new_node = malloc(sizeof(struct List));
	
    new_node->data = value;
    new_node->Next = NULL;
	
    if (*head == NULL)
	{
        *head = new_node;
        return;
    }
	
    struct List* current = *head;
    while (current->Next != NULL)
	{
        current = current->Next;
    }
    current->Next = new_node;
}

int main()
{
	int array[] = {-19,11,-30,20,33,-33,20,2}; 
	int i, j;
	/*for (i = 0; i < 8; i++)
	{
		scanf("%d", &array[i]);
	}*/
	
	for(i = 0; i < 8; i++)
	{
		addToList(&First, array[i]);
	}
	
	struct List* current = First;
	while(current) // Первый вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	struct List* elem = First;
	struct List* temp = NULL;
	struct List* previous = NULL;
	
	while(elem)
	{
		if(previous && elem->data > 0 && elem->data % 2 == 0)
		{
			temp = elem->Next; // Сохраняем
			
			previous->Next = temp; // elem
			elem->Next = First; // Переставим в начало
			
			First = elem;
			elem = temp; // Следующая итерация
			continue;
		}
		previous = elem;
		elem = elem->Next;
	}
	
	printf("\n");
	current = First;
	while(current) // Второй вывод
	{
		printf("%d ", current->data);
		current = current->Next;
	}
	
	return 0;
}
