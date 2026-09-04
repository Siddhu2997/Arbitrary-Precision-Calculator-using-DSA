#include<stdlib.h>
#include"list.h"

//performing insert last operation
int oprnd_list_creation(oprnd_list **head, oprnd_list **tail, char *argv)
{
	/* traversing each digit of the operand to create a seperate node for each digt of operand*/
	for(int i=0; argv[i] != '\0'; i++)
	{
		//creating node
		oprnd_list *new = malloc(sizeof(oprnd_list));

		if(new == NULL)
		{
			return FAILURE;
		}


		//case 1:when the list is empty
		if(*head == NULL)
		{
			//storing the digit in the new node data part
			new->data = argv[i]-'0';	//converting the character to a digit by subtracting the char by '0' or 48

			//storing null in the prev and next part of the new node bcoz its the first node
			new->prev = NULL;

			new->next = NULL;
			
			//initializing the head and tail pointer of the list with new node address
			*head = new;

			*tail = new;
		}
		else			
		{
			/*case 2: when the list is not empty*/
			
			//storing the digit in the new node data part
			new->data = argv[i]-'0';
			
			//storing the current node next address into new node next address (aka storing null in the newly created node next part)
			new->next = (*tail)->next;

			//storing the adrress of the current node into new node prev part
			new->prev = *tail;
			
			//updating the current node next part with new address
			(*tail)->next = new;
			
			//updating tail pointer with new node address
			*tail = new;
		}
	}
	return SUCCESSFULL;
}
