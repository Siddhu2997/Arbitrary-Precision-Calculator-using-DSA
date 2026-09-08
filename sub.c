#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int sub_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail)
{
	printf("Subtraction function called\n");
	
	int borrow = 0, result, borrow_flag=0;
	
	D_list *temp1;
	D_list *temp2;
	
	//comparing the list, which list has more digits
	if(compare_list(*tail1, *tail2) == 1)
	{
		/*temp pointers to traverse the operands*/
		temp1 = *tail1;
		temp2 = *tail2;
	}
	else
	{
		temp1 = *tail2;
		temp2 = *tail1;
	}
	
	/*traversing the operands untill both operands reaching NULL*/
	while(temp1 != NULL || temp2 != NULL)
	{
		if(borrow_flag)
		{
			temp1->data = temp1->data - 1;
			borrow_flag = 0;
		}
		/*first operand reached null and second operand not*/
		if(temp1 == NULL && temp2 != NULL)
		{
			/*making the first operand head node as zero and adding */
			result = 0 - temp2->data + borrow;
		}
		
		/*second operand rached null and first operand not*/
		else if(temp1 != NULL && temp2 == NULL)
		{
			/*making the second operand head node as zero and adding*/
			result = temp1->data - 0 + borrow;
		}
		else
		{
			/*adding when either didnt reach the NULL*/
			result = temp1->data - temp2->data + borrow;
		}
		/*creating new result node*/
		D_list *new = malloc(sizeof(D_list));
		
		if(new == NULL)
		{
			printf("Result list not created\n");
		}
		
		/*reuslt is greater than 9 then storing only the last digit of the result*/
		if(result < 0)
		{
			borrow = 10;
			new->data = result + borrow;
			borrow_flag = 1;
			borrow = 0;
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

	}
	return SUCCESSFULL;
}
