#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"list.h"

int multi_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail)
{
	D_list *headr1 = NULL, *tailr1 = NULL;  // First intermediate result list
    D_list *headr2 = NULL, *tailr2 = NULL;  // Second intermediate result list
    int count = 0, carry = 0, result;  // Position counter, carry flag, multiplication result
    D_list *temp1 = *tail1;  // Pointer to traverse first operand from LSD
    D_list *temp2 = *tail2;  // Pointer to traverse second operand from LSD
    
    // Initialize result list with 0
    insert_first(res_head, res_tail, 0);  // Start with result 0
    
    while(temp1 != NULL)  // Outer loop for each digit of first operand
    {
        // Create a new intermediate result list for this digit of multiplier
        delete_list(&headr2, &tailr2);  // Clear previous intermediate result
        headr2 = NULL;  // Reset pointer
        tailr2 = NULL;  // Reset pointer
        
        // Add zeros based on position (for place value)
        for(int i = 0; i < count; i++)  // Add zeros for place value
        {
            insert_first(&headr2, &tailr2, 0);  // Insert zero at beginning
        }
        
        temp2 = *tail2;  // Reset to LSD of second operand
        carry = 0;  // Reset carry
        
        // Multiply current digit of temp1 with all digits of temp2
        while(temp2 != NULL)  // Inner loop for each digit of second operand
        {
            result = (temp1->data * temp2->data) + carry;  // Multiply digits and add carry
            carry = result / 10;  // Calculate new carry
            result = result % 10;  // Keep only units digit
            
            insert_first(&headr2, &tailr2, result);  // Insert result digit
            temp2 = temp2->prev;  // Move to next more significant digit
        }
        
        // If there's any remaining carry, add it
        if(carry > 0)  // Check if carry remains after all multiplications
        {
            insert_first(&headr2, &tailr2, carry);  // Insert carry as new digit
        }
        
        // Add the intermediate result to the final result
        if(count == 0)  // First iteration
        {
            // First iteration - just copy headr2 to headr1
            delete_list(&headr1, &tailr1);  // Clear previous intermediate
            headr1 = headr2;  // Assign new intermediate to headr1
            tailr1 = tailr2;  // Assign tail
            headr2 = NULL;  // Reset pointer
            tailr2 = NULL;  // Reset pointer
        }
        else  // Subsequent iterations
        {
            // Add headr1 and headr2, store result in headr1
            D_list *sum_head = NULL, *sum_tail = NULL;  // Temporary sum result
            add_operation(&tailr1, &tailr2, &sum_head, &sum_tail);  // Add intermediate results
            
            delete_list(&headr1, &tailr1);  // Clear old intermediate
            headr1 = sum_head;  // Assign sum to headr1
            tailr1 = sum_tail;  // Assign tail
            
            delete_list(&headr2, &tailr2);  // Clear second intermediate
        }
        
        count++;  // Increment position counter
        temp1 = temp1->prev;  // Move to next more significant digit
    }
    
    // Copy final result to output parameters
    delete_list(res_head, res_tail);  // Clear original result list
    *res_head = headr1;  // Assign final result to output
    *res_tail = tailr1;  // Assign tail to output
    
    return SUCCESSFULL;
}
					
	
	
	
	
	
	

