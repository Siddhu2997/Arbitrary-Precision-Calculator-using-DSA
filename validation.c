#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "list.h"

int valid_number(char *str)
{
	if (str == NULL || str[0] == '\0') {
        return 0;  // NULL or empty string
    }
    
    int i = 0;
    // Check for optional sign at the beginning
    if (str[i] == '+' || str[i] == '-') {
        i++;
        // If only sign with no digits, it's invalid
        if (str[i] == '\0') {
            return 0;
        }
    }
    
    // Check all remaining characters are digits
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    
    return 1;  // Valid number
}
	/*//creating a string consist of valid operators used to perform calculation
	const char *str = "+-/xX";
	
	//creating flags to check whether the operands contains only digits
	int op1_flag=0, op2_flag =0;

	// for loop to determine whether operand 1 contains only numbers using isdigit function
	for(int i=0; argv[1][i] != '\0'; i++)
	{
		if(isdigit(argv[1][i]) == 0)
		{
			op1_flag=1;
		}
	}
	
	//to check whether operand 2 contains only numbers using isdigit function
	for(int i=0; argv[3][i]!= '\0'; i++)
	{
		if(isdigit(argv[3][i]) == 0)
		{
			op2_flag=1;
		}
	}
	// and if both operand are digits then checking whether the operator is among the above created string
	if(!op1_flag && !op2_flag)
	{
		//using strstr to check if the user operator is valid using the above string created
		if((strstr(str, argv[2])) != NULL)
		{
			return SUCCESSFULL;
		}
		printf("Please enter a valid operator(+, -, /, x, X)\n");
		return FAILURE;
	}
	else
	{
		printf("Please enter only interger values\n");
		return FAILURE;
	}*/