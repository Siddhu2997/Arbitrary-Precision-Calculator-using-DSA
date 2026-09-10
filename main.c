#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"


int main(int argc, char **argv)
{
	int res, operand1flag = 0, operand2flag = 0;  // Result and operand sign flags
    int opr1sign = PLUS , opr2sign = PLUS;  // Operand signs (default positive)
    int flag  = 0;  // General flag for various purposes
	
	/*checking whether the user entered 4 arguments 1-> ./a.out 2-> 123 3-> + 4->1234 */
	if(argc > 3)
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
							opr2sign = PLUS;  // Set operand 2 sign to plus
						}
						else  // Negative sign
						{
							opr2sign = MINUS;  // Set operand 2 sign to minus
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
	
	// storing the first operand in a linked list
    int oprlen1 = strlen(argv[1]);  // Get length of first operand string
    oprlen1--;  // Adjust for zero-based indexing
    if (operand1flag == 1)  // First operand has explicit sign
    {
        int i = 1;  // Start index after sign character
        oprlen1--;  // Adjust length to exclude sign character
        while(oprlen1 >= 0)  // Process remaining characters
        {
            insert_last(argv[1][i],&head1, &tail1);  // Insert digit at end of list
            i++;  // Move to next character
            oprlen1--;  // Decrement counter
        }
    }
    else  // First operand has no explicit sign
    {
        while(oprlen1 >= 0)  // Process all characters
        {
            oprnd_list_creation(argv[1][oprlen1],&head1, &tail1);  // Insert digit at beginning of list
            oprlen1--;  // Decrement counter
        }
    }
    // storing the second operand in the linked list
    int oprlen2 = strlen(argv[3]);  // Get length of second operand string
    oprlen2--;  // Adjust for zero-based indexing
    if (operand2flag == 1)  // Second operand has explicit sign
    {
        int i = 1;  // Start index after sign character
        oprlen2--;  // Adjust length to exclude sign character
        while(oprlen2 >= 0)  // Process remaining characters
        {
            insert_last(argv[3][i],&head2, &tail2);  // Insert digit at end of list
            i++;  // Move to next character
            oprlen2--;  // Decrement counter
        }
    }
    else  // Second operand has no explicit sign
    {
        while(oprlen2 >= 0)  // Process all characters
        {
            oprnd_list_creation(argv[3][oprlen2],&head2, &tail2);  // Insert digit at beginning of list
            oprlen2--;  // Decrement counter
        }
    }
	
	// check the operation type
    if(strlen(argv[2]) != 1)  // Check if operator is single character
    {
        printf("Error: Enter valid operator\n");  // Error message
        return 0;  // Exit program
    }
    char operator = argv[2][0];  // Get operator character
    if((opr1sign == PLUS && operator == '+') && opr2sign == PLUS)  // Addition of two positive numbers
    {
        operator = '+';  // Set operator to addition
    }
    else if((opr1sign == PLUS && operator == '-') && opr2sign == PLUS)  // Subtraction: positive minus positive
    {
        operator = '-';  // Set operator to subtraction
    }
    else if((opr1sign == MINUS && operator == '-') && opr2sign == MINUS)  // Subtraction: negative minus negative
    {
        operator = '-';  // Set operator to subtraction
    }
    else if((opr1sign == PLUS && operator == '-') && opr2sign == MINUS)  // Subtraction: positive minus negative
    {
        operator = '-';  // Set operator to subtraction
    }
    else if((opr1sign == MINUS && operator == '-') && opr2sign == PLUS)  // Subtraction: negative minus positive
    {
        operator = '+';  // Set operator to subtraction
        flag = 1;  // Set flag for result sign
    }
    else if(operator == 'x' || operator =='/')  // Multiplication or division
    {
        if(opr1sign == MINUS && opr2sign == PLUS)    flag = 1;  // Negative times/divided by positive gives negative
        else if(opr1sign == MINUS && opr2sign == MINUS) flag = 0;  // Negative times/divided by negative gives positive
        else if(opr1sign == PLUS && opr2sign == MINUS) flag = 1;  // Positive times/divided by negative gives negative
        else if(opr1sign == PLUS && opr2sign == PLUS) flag = 0;  // Positive times/divided by positive gives positive
    }
    oprlen1 = strlen(argv[1]);  // Recalculate original length of first operand
    oprlen2 = strlen(argv[3]);  // Recalculate original length of second operand
    switch (operator)  // Execute operation based on operator
    {
        case '+':  // Addition case
        {
            //printf("In switch case");
            add_operation(&tail1, &tail2, &res_head, &res_tail);  // Call addition function
 
            printf("The result is -> ");  // Print result prefix
            if(flag == 1) printf("-");  // Print negative sign if needed
            print_list(res_head, res_tail);  // Print result
            break;  // Exit switch
        }
        case '-':  // Subtraction case
        {
            sub_operation(oprlen1, oprlen2, &head1, &tail1, &head2, &tail2, &res_head, &res_tail, 0, &flag);  // Call subtraction function
            
            printf("The result is -> ");  // Print result prefix
            if(flag == 1) printf("-");  // Print negative sign if needed
            print_list(res_head, res_tail);  // Print result
            break;  // Exit switch
        }
        case 'x':  // Multiplication case
        {
            multi_operation(&tail1, &tail2, &res_head, &res_tail);  // Call multiplication function
           
            printf("The result is -> ");  // Print result prefix
            if(flag == 1) printf("-");  // Print negative sign if needed
            print_list(res_head, res_tail);  // Print result
            break;  // Exit switch
        }
        /*case '/':  // Division case
        {
            res = divide_operation(oprlen1, oprlen2, &head1, &tail1, &head2, &tail2, &res_head, &res_tail);  // Call division function
           
            if(res == -1)  // Check for division by zero
            {
                printf("Error: cannot perform divide by zero operation\n");  // Error message
            }
            else  // Division successful
            {
                printf("The result is -> ");  // Print result prefix
                if(flag == 1) printf("-");  // Print negative sign if needed
                printf("%d\n",res);  // Print integer quotient
            }
            break;
        }*/
        default:
        {
            printf("Error: Enter proper operator\n");
            break;  // Exit switch
        }
    }
}


