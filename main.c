#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"


int main(int argc, char **argv)
{
	/*creating the head and tail struct pointer*/
	
	/*creating head1 & tail1 pointer for storing the starting and tail node address of operand1*/
	D_list *head1 = NULL;
	D_list *tail1 = NULL;

	/*creating head2 & tail2 pointer for storing the starting and tail node address of operand2*/
	D_list *head2 = NULL;
	D_list *tail2 = NULL;
	
	/*creating res_head & res_tail pointer for storing the starting  and tail node address of result*/
	D_list *res_head = NULL;
	D_list *res_tail = NULL;
	
	/*creating R1 and R2 list to store the result */
	D_list *R1_head = NULL;
	D_list *R1_tail = NULL;
		
	D_list *R2_head = NULL;
	D_list *R2_tail = NULL;

	/*checking whether the user entered 4 arguments 1-> ./a.out 2-> 123 3-> + 4->1234 */
	if(argc == 4)
	{
		/* calling the validation function by passing argv */
		if(validation(argv))
		{
			printf("Validation Successfull\n");
			
			/*passing the head and tail pointers of both list to oprnd_list_creation function to create two list*/
			if(oprnd_list_creation(&head1, &tail1, argv[1]) && oprnd_list_creation(&head2, &tail2, argv[3]))
			{
				printf("Both operands list created successfully\n");

				/* printing the list by calling print_list function and passing the head pointers of both list */
				print_list(head1);
			
				print_list(head2);
				
				/*if the operator is + then calling the add_operation function by passing the tail pointers of the two operands list and tail pointer of result list*/
				if(*(argv[2]) == '+')
				{
					/*calling the add_operation*/
					if(add_operation(&tail1, &tail2, &res_head, &res_tail))
					print_list(res_head);
				}
				else if(*(argv[2]) == '-')
				{
					/*calling sub_operation fucntion*/
					if(sub_operation(&tail1, &tail2, &res_head, &res_tail))
					print_list(res_head);
				}
				/*if the operator is x or X calling multiplication operation function*/
				else if(*(argv[2]) == 'x' || *(argv[2]) == 'X')
				{
					
					/*calling the multi_operation*/
					if(multi_operation(&tail1, &tail2, &res_head, &res_tail, &R1_head, &R1_tail, &R2_head, &R2_tail))
					print_list(res_head);
				}
				return 0;
			}
		}
		else 
		{
			printf("Validation Failed\n");
			return FAILURE;
		}		
	}
	else
	{
		printf("Insufficient arguments\n");
		return FAILURE;
	}
}


