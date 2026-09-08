#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"list.h"

int multi_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail, D_list **R1_head, D_list **R1_tail, D_list **R2_head, D_list **R2_tail)
{
	printf("Multi fucntion called\n");
	
	int carry = 0, result, count=0, flag = 0;
	
	D_list *temp1 = NULL;
	D_list *temp2 = NULL;
	
	temp1 = *tail1;
	temp2 = *tail2;
	
	/*using nested while loop to traverse through the list*/
	while(temp1 != NULL)
	{
		//adding trailing zeros to r1 list
		while(flag < count)
		{
			insert_first(R1_head, R1_tail, 0);
			flag++;
		}
		
		while(temp2 != NULL)
		{
			result = (temp1->data * temp2->data) + carry;
			
			carry = 0;
			
			if(result > 9)
			{
				carry = result / 10;
				result = result % 10;
			}
			
			/*performing insert first operation*/
			//storing the result in result list
			if(count == 0)
			{
				if(insert_first(res_head, res_tail, result))
				{
					printf("Stored the result in res\n");
				}
			}
			else
			{
				//printf("VAl1 -> %d\n",result);
				insert_first(R1_head, R1_tail, result);
				printf("Stored the result in R1\n");
			}
			//iterating the inner loop 	
			temp2 = temp2->prev;
		}
		count++;
		//storing the carry 
		if(carry && count == 0)
		{
			insert_first(res_head, res_tail, carry);
		}
		else if(carry && count)
		{
			insert_first(R1_head, R1_tail, carry);
		}
	
		if(*res_head != NULL && *R1_head != NULL)
		{
			insert_first(res_head, res_tail, 0);
			/*
			print_list(*res_head);
			print_list(*R1_head);
			print_list(*R2_head);
			*/
			if(add_operation(res_tail, R1_tail, R2_head, R2_tail))
			{
				printf("Result added to R2\n");
				print_list(*R2_head);
				
				delete_list(res_head, res_tail);
				delete_list(R1_head, R1_tail);
				
				printf("Deleted successfully\n");
				
			}
			printf("After add func\n");
			*res_head = *R2_head;
			*res_tail = *R2_tail;
			
			
			R2_head = NULL;
			R2_tail = NULL;
			printf("Aftre deletion\n");
			print_list(*res_head);
		}
		//iterating the outer loop
		temp1 = temp1->prev;
	}
	
	return SUCCESSFULL;
}
					
	
	
	
	
	
	

