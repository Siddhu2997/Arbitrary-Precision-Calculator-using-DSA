#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//performing insert last operation
int oprnd_list_creation(D_list **head, D_list **tail, char *argv)
{
	/* traversing each digit of the operand to create a seperate node for each digt of operand*/
	for(int i=0; argv[i] != '\0'; i++)
	{
		//creating node
		D_list *new = malloc(sizeof(D_list));

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

//performing insert first operation
int insert_first(D_list **head, D_list **tail, int data)
{
    //creating a new node when list is empty and also not empty bcoz creating new node is common for both part
    D_list *new = malloc(sizeof(D_list));
    
    if(new == NULL)
    {
        return FAILURE;
    }
    
    //case 1: when the list is empty
    if(*head == NULL)
    {
        //storing the data in the new node data part
        new->data = data;
    
        //storing null in the new node prev part
        new->prev = *head;
    
        //storing NULL in the new node next part
        new->next = *head;

        //making the *head and *tail point to the newly created node
        *head = new;
        *tail = new;
        
        return SUCCESSFULL;
    }
    
    //case 2: when the list is having n elements
    //storing the data in the newly created node data part
    new->data = data;
    
    //storing NULL in the new node prev part
    new->prev = (*head)->prev;
    
    //storing the *head address in the new next part
    new->next = *head;
    
    //updating the (*head)->prev with new
    (*head)->prev = new;
    
    //updating the *head with new node address
     *head = new;
     
     return SUCCESSFULL;
}
    
    
    


//performing deflete list function
int delete_list(D_list **head, D_list **tail)
{
    //case 1: when the list is empty
    if(*head == NULL)
    {
        return FAILURE;
    }
    
    //case 2: when the list is having only one node
    if(*head == *tail)
    {
        free(*head);
        
        *head = *tail = NULL;
        
        return SUCCESSFULL;
    }
    
    //case 3: when the list contains n nodes
    
    //creating a temp struct node pointer 
    D_list *temp = *head;
    
    //traversing the list untill temp bcomes NULL
    while(temp != NULL)
    {
        //updating the head with temp next part address so that head points to second node
        *head = temp->next;
        
        //then free the current node
        free(temp);
        
        //updating the temp with next node address
        temp = *head;
    }
    //at the end making the tail as NULL
    *tail = NULL;
    return SUCCESSFULL;

}

int compare_list(D_list *tail1, D_list *tail2)
{
	int list1_count = 0;
	int list2_count = 0;
	
	while(tail1 != NULL)
	{
		list1_count++;
		tail1 = tail1->prev;
	}
	while(tail2 != NULL)
	{
		list2_count++;
		tail2 = tail2->prev;
	}
	printf("Operand 1 count = %d\n",list1_count);
	printf("Operand 2 count = %d\n", list2_count);
	if(list1_count > list2_count)
		return 1;
	else
		return 2;
}
	