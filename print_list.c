#include<stdio.h>
#include "list.h"

void print_list(D_list *head, D_list *tail)
{
	while(head != NULL)  // Traverse the list from head to end
    {
        printf("%d",head -> data);  	// Print current node's data
        head = head -> next;  			// Move to next node
    }
    printf("\n");
}
	
	
	/*if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{	
	    printf("Head -> ");
	    while (head)		
	    {
		   
		    printf("%d <-", head -> data);

		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }*/