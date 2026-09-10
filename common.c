#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//performing insert last operation
int oprnd_list_creation(char ch, D_list **head, D_list **tail)
{
	int data = ch - 48;  // Convert ASCII character to integer (0-9)
	
	//creating a new node
    D_list *new_node = malloc(sizeof(D_list));  // Allocate memory for new node
    
	new_node -> data = data;  // Set node data
    
	new_node -> prev = NULL;  // Set prev pointer to NULL
    
	new_node -> next = NULL;  // Set next pointer to NULL
    
	if(*head == NULL)  // List is empty
    {
        *head = new_node;  // New node becomes head
        *tail = new_node;  // New node becomes tail
    }
    else  // List has existing nodes
    {
        (*head) -> prev = new_node;  // Current head's prev points to new node
        new_node -> next = *head;  // New node's next points to current head
        *head = new_node;  // New node becomes new head
    }
	return SUCCESSFULL;
}

//performing inser last operation
int insert_last(char ch, D_list **head, D_list **tail) // Function to insert character digit at end of list (preserve order)
{
    //printf("ch - %c\n",ch); // Debug print statement to display the character being inserted
    int data = ch - 48; // Convert ASCII character to integer by subtracting '0' (ASCII 48)
    
	D_list *new_node = malloc(sizeof(D_list)); // Allocate memory for new node using malloc
    
	
	new_node -> data = data; // Set the data field of new node to converted integer
    
	new_node -> prev = NULL; // Initialize previous pointer to NULL for new node
    
	new_node -> next = NULL; // Initialize next pointer to NULL for new node
    
	if(*head == NULL && *tail == NULL) // Check if both head and tail pointers are NULL (list is empty)
    {
        *head = new_node; // Set head pointer to point to the new node
        *tail = new_node; // Set tail pointer to point to the new node
    }
    else // Linked list already contains at least one node
    {
        (*tail) -> next = new_node; // Set current tail node's next pointer to new node
        new_node -> prev = *tail; // Set new node's previous pointer to current tail node
        *tail = new_node; // Update tail pointer to point to new node (insert at end)
    }
}

//performing insert first operation
int insert_first(D_list **head, D_list **tail, int data)
{
    //creating a new node when list is empty and also not empty bcoz creating new node is common for both part
    D_list *new = malloc(sizeof(D_list));
    
    if(new == NULL)
    {
        return FAILURE;
    }
    
    //case 1: when the list is empty
    if(*head == NULL)
    {
        //storing the data in the new node data part
        new->data = data;
    
        //storing null in the new node prev part
        new->prev = *head;
    
        //storing NULL in the new node next part
        new->next = *head;

        //making the *head and *tail point to the newly created node
        *head = new;
        *tail = new;
        
        return SUCCESSFULL;
    }
    
    //case 2: when the list is having n elements
    //storing the data in the newly created node data part
    new->data = data;
    
    //storing NULL in the new node prev part
    new->prev = (*head)->prev;
    
    //storing the *head address in the new next part
    new->next = *head;
    
    //updating the (*head)->prev with new
    (*head)->prev = new;
    
    //updating the *head with new node address
     *head = new;
     
     return SUCCESSFULL;
}
    
//performing deflete list function
int delete_list(D_list **head, D_list **tail)
{
    //case 1: when the list is empty
    if(*head == NULL)
    {
        return FAILURE;
    }
    
    //case 2: when the list is having only one node
    if(*head == *tail)
    {
        free(*head);
        
        *head = *tail = NULL;
        
        return SUCCESSFULL;
    }
    
    //case 3: when the list contains n nodes
    
    //creating a temp struct node pointer 
    D_list *temp = *head;
    
    //traversing the list untill temp bcomes NULL
    while(temp != NULL)
    {
        //updating the head with temp next part address so that head points to second node
        *head = temp->next;
        
        //then free the current node
        free(temp);
        
        //updating the temp with next node address
        temp = *head;
    }
    //at the end making the tail as NULL
    *tail = NULL;
    return SUCCESSFULL;

}

// Function to remove leading zeros from number
int clear_leading_zero(D_list **head,D_list **tail)  
{
    if(*head == NULL)  // Check if list is empty
    {
        return 0;  // Return 0 for empty list
    }
    else  // List has nodes
    {
        while(*head)  // Loop through nodes from head
        {
            if((*head) -> next == NULL) break;  // Stop if only one digit remains (preserve last zero)

            if((*head) -> data == 0)  // Check if current node has zero
            {
                D_list *temp = *head;  // Store current node pointer
                *head = (*head) -> next;  // Move head to next node
                (*head) -> prev = NULL;  // Set new head's prev to NULL
                free(temp);  // Free the leading zero node
            }
            else  // Found non-zero digit
            {
                return 0;  // Return 0 indicating completion
            }
        }
    }
}


// Function to determine which operand is larger for subtraction
int change_link(int opr1len,int opr2len,D_list ** head1,D_list **tail1, D_list **head2,D_list **tail2, D_list **temp1, D_list **temp2,int *flag)  
{
    if(opr1len < opr2len)  // First operand has fewer digits
    {
        *temp1 = *tail2;  // Set temp1 to point to larger number (second operand)
        *temp2 = *tail1;  // Set temp2 to point to smaller number (first operand)
        *flag = 1;  // Set flag to indicate swap occurred
        return SUCCESSFULL;  // Return success
    }
    else if(opr1len == opr2len)  // Both operands have same number of digits
    {
        while(*head1 != NULL && *head2 != NULL)  // Compare digit by digit from most significant
        {
            if((*head1) -> data < (*head2) -> data)  // First operand is smaller at this digit
            {
                *temp1 = *tail2;  // Set temp1 to point to larger number
                *temp2 = *tail1;  // Set temp2 to point to smaller number
                *flag = 1;  // Set flag to indicate swap occurred
                return SUCCESSFULL; 
            }
            else if((*head1) -> data == (*head2) -> data)  // Digits are equal, check next digit
            {
                *head1 = (*head1) -> next;  // Move to next digit in first operand
                *head2 = (*head2) -> next;  // Move to next digit in second operand
            }
            else break;  // First operand is larger, no swap needed
        }
    }
    *temp1 = *tail1;  // Default: temp1 points to first operand
    *temp2 = *tail2;  // Default: temp2 points to second operand
    *flag = 0;  // No swap occurred   
}