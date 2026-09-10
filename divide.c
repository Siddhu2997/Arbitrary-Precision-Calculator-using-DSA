#include <stdio.h>  
#include <string.h>  
#include <stdlib.h> 
#include "list.h"

int greater(D_list *res_head,D_list *headr2)  // Function to compare two numbers represented as linked lists
{
    int h1count = 0;  // Counter for first number's digit count
    int h2count = 0;  // Counter for second number's digit count
    D_list *tempr = res_head;  // Temporary pointer for first number
    D_list *temp2 = headr2;  // Temporary pointer for second number
    
    while(tempr)  // Count digits in first number
    {
        tempr = tempr -> next;  // Move to next digit
        h1count++;  // Increment counter
    }
    while(temp2)  // Count digits in second number
    {
        temp2 = temp2 -> next;  // Move to next digit
        h2count++;  // Increment counter
    }

    if(h1count < h2count)  // First number has fewer digits
    {
        return 0;  // Return 0 (first number is smaller)
    }
    else if(h1count > h2count)  // First number has more digits
    {
        return 1;  // Return 1 (first number is greater)
    }
    else if(h1count == h2count)  // Both numbers have same digit count
    {
        tempr = res_head;  // Reset pointer to first number's head
        temp2 = headr2;  // Reset pointer to second number's head
        while(temp2)  // Compare digit by digit
        {
            //printf("hi2\n");
            if(tempr -> data >= temp2 -> data) return 1;  // First number's digit is greater or equal
            
            else if(tempr -> data < temp2 -> data) return 0;

            else  // Digits need further comparison
            {
                tempr = tempr -> next;  // Move to next digit in first number
                temp2 = temp2 -> next;  // Move to next digit in second number
            }
        }
    }
    else 
    {
        return 0;
    }
}

/*-------------------------------------------------------division function------------------------------------------------------------------------*/

int division(int opr1len, int opr2len, D_list ** head1, D_list **tail1, D_list ** head2, D_list **tail2, D_list **res_head ,D_list **res_tail)
{
    D_list *headr1 = NULL, *tailr1 = NULL;  // Intermediate result list pointers
    int count = 0;  // Quotient counter
    if((*head2) -> next == NULL && (*head2) -> data == 0)  // Check for division by zero
    {
        return -1;  // Return -1 for division by zero error
    }
    if((*head1) -> next == NULL && (*head1) -> data == 0)  // Check if dividend is zero
    {
        return 0;  // Return 0 (zero divided by anything is zero)
    }
    if(opr1len < opr2len) return 0;  // If dividend has fewer digits than divisor, quotient is 0
    if(greater(*head1, *head2) == 0)
    {
        return 0;
    }
    sub_operation(opr1len, opr2len, head1, tail1, head2, tail2, res_head, res_tail, 1,NULL);  // First subtraction
    
}