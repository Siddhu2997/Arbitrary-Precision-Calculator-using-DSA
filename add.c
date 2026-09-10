#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int add_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail)
{
	//printf("Add function called\n");
	
	/*carry variable to store the carry when the addition result is > than 9*/
	/*result variable to store the result after performing addition operation on nodes of operand 1 and operand 2 and carry*/
	int carry = 0, result;
	
	/*temp pointers to traverse the operands*/
	D_list *temp1 = *tail1;
	D_list *temp2 = *tail2;
	
	/*traversing the operands untill both operands reaching NULL*/
	while(temp1 != NULL || temp2 != NULL)
	{
		
		/*first operand reached null and second operand not*/
		if(temp1 == NULL && temp2 != NULL)
		{
			/*making the first operand head node as zero and adding */
			result = 0 + temp2->data + carry;
		}
		
		/*second operand rached null and first operand not*/
		else if(temp1 != NULL && temp2 == NULL)
		{
			/*making the second operand head node as zero and adding*/
			result = temp1->data + 0 + carry;
		}
		else
		{
			/*adding when either didnt reach the NULL*/
			result = temp1->data + temp2->data + carry;
		}
		/*reinitializing carry at each iteration*/
		carry = 0;
		
		/*creating new result node*/
		D_list *new = malloc(sizeof(D_list));
		
		if(new == NULL)
		{
			printf("Result list not created\n");
		}
		
		/*reuslt is greater than 9 then storing only the last digit of the result*/
		if(result > 9)
		{
			new->data = result - 10;
			carry++;
		}
		else
		{
			/*storing the result as it is in new node data part*/
			new->data = result;
		}
		/*performing insert first */
		//when the list is empty
		if(*res_tail == NULL)
		{	
			new->prev = NULL;
			
			new->next = NULL;
			
			*res_head = new;
			*res_tail = new;
		}
		else
		{
			new->next = *res_head;

			new->prev = (*res_head)->prev;
			
			(*res_head)->prev = new;
			
			*res_head = new;
		}
		if(temp1 != NULL)
		temp1 = temp1->prev;
		
		if(temp2 != NULL)
		temp2 = temp2->prev;
		//printf("2\n");
	}
	/*if the carry is still 1 then creating a new node to store the carry in the result list*/
	if(carry)
	{
		D_list *new = malloc(sizeof(D_list));
		
		if(new == NULL)
		{
			printf("Result list not created\n");
		}
		
		new->data = carry;
		
		new->next = *res_head;

		new->prev = (*res_head)->prev;
		
		(*res_head)->prev = new;
		
		*res_head = new;
	}
	
	return SUCCESSFULL;
}

		
		
		
	
	