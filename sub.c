#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int sub_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail)
{
	 D_list *temp1 = *tail1,*temp2 = *tail2;  // Pointers to traverse operands from LSD
    
	int result, zero_flag = 0,borrow = 0;  // Result, zero flag, borrow flag
    
	clear_leading_zero(head1, tail1);  // Remove leading zeros from first operand
    clear_leading_zero(head2, tail2);  // Remove leading zeros from second operand
    
	if(div_flag != 1) change_link(opr1len, opr2len, head1, tail1, head2, tail2, &temp1, &temp2, flag);  // Determine larger operand for non-division subtraction

    while(temp1 || temp2)  // Loop while either operand has digits
    {
        int d1 = temp1 ? temp1 -> data : 0;  // Get digit from first operand or 0 if none
        int d2 = temp2 ? temp2 -> data : 0;  // Get digit from second operand or 0 if none
        d1 -= borrow;  // Subtract any borrow from previous step
        borrow = 0;  // Reset borrow flag
        if(d1 < d2)  // Need to borrow
        {
            d1 += 10;  // Borrow 10 from next higher digit
            borrow = 1;  // Set borrow flag for next iteration
        }
        result = d1 - d2;  // Compute subtraction result
        if(temp1) temp1 = temp1 -> prev;  // Move to next more significant digit in first operand
        if(temp2) temp2 = temp2 -> prev;  // Move to next more significant digit in second operand
        insert_at_first(res_head, res_tail, result);  // Insert result digit at beginning of result list
    }
    clear_leading_zero(res_head, res_tail);  // Remove any leading zeros from result
	
	return SUCCESSFULL;
}
