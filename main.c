#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"


int main(int argc, char **argv)
{
	int res, operand1flag = 0, operand2flag = 0;  // Result and operand sign flags
    int opr1sign = plus , opr2sign = plus;  // Operand signs (default positive)
    int flag  = 0;  // General flag for various purposes
	
	/*checking whether the user entered 4 arguments 1-> ./a.out 2-> 123 3-> + 4->1234 */
	if(argc <= 3)
	{
		/* calling the validation function by passing argv */
		if(valid_number(argv[1]))
		{
			printf("Operand1 Validation Successfull\n");
			
			if(valid_number(argv[3]))
			{
				printf("Operand2 validation Successfull\n");
				
				if(!(isdigit(argv[1][0])))
				{
					if(argv[1][0] == '+' || argv[1][0] == '-')
					{
						operand1flag = 1;  // Set flag indicating operand has explicit sign
						if(argv[1][0] == '+')  // Positive sign
						{
							opr1sign = PLUS;  // Set operand 1 sign to plus
						}
						else  // Negative sign
						{
							opr1sign = PLUS;  // Set operand 1 sign to minus
						}
					}
					else
					{
						printf("Error: Starting of the operand 1 should be a digit or + or - only\n");
						return 0;
					}
				}
				if(!(isdigit(argv[3][0])))
				{
					if(argv[3][0] == '+' || argv[3][0] == '-')
					{
						operand2flag = 1;  // Set flag indicating operand has explicit sign
						if(argv[3][0] == '+')  // Positive sign
						{
							opr2sign = plus;  // Set operand 2 sign to plus
						}
						else  // Negative sign
						{
							opr2sign = minus;  // Set operand 2 sign to minus
						}
					}
					else  // Invalid starting character
					{
						printf("Error: Starting of the operand 2 should be a digit or + or - only\n");
						return 0;
					}
				}
			}
			else
			{
				printf("Error: Operand 2 validation failed\n");
				return 0;
			}
        }
		else
		{
			printf("Error: Operand 1 validation failed\n");
			return 0;
		}		
	}
	else
	{
		printf("Error: Insufficient Arguments passed\n");
		return FAILURE;
	}
	
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
}


