#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//heman sakthivel

typedef struct node
{
	struct node *prev;

	struct node *next;

	int data;

}op1_list, op2_list;

void print_list(op1_list *head);
int op1_list_creation(op1_list **head, op1_list **tail, char **);
int op2_list_creation(op2_list **head, op2_list **tail, char **);

int main(int argc, char **argv)
{
	
	op1_list *head1 = NULL;
	op1_list *tail1 = NULL;

	op2_list *head2 = NULL;
	op2_list *tail2 = NULL;

	if(argc == 4)
	{
		const char *str = "+-/xX";

		int op1_flag=0, op2_flag =0;

		for(int i=0; argv[1][i] != '\0'; i++)
		{
			if(isdigit(argv[1][i]) == 0)
			{
				op1_flag=1;
			}
		}
		for(int i=0; argv[3][i]!= '\0'; i++)
		{
			if(isdigit(argv[3][i]) == 0)
			{
				op2_flag=1;
			}
		}

		if(!op1_flag && !op2_flag)
		{
			if((strstr(str, argv[2])) != NULL)
			{
				printf("Validation SuccessFull\n");

				if(op1_list_creation(&head1, &tail1, argv) && op2_list_creation(&head2, &tail2, argv))
				{
					printf("Both operands list created successfully\n");

					//printing the list
					printf("First operand: ");
					print_list(head1);
					
					printf("Second operand: ");
					print_list(head2);

					return 0;
				}
			}
			printf("Please enter a valid operator(+, -, /, x, X)\n");
		}
		else
		{
			printf("Please enter only interger values\n");
		}
	}
	else
	{
		printf("Insufficient arguments\n");
	}
}

int op1_list_creation(op1_list **head1, op1_list **tail1, char **argv)
{

	for(int i=0; argv[1][i] != '\0'; i++)
	{
		op1_list *new = malloc(sizeof(op1_list));

		if(new == NULL)
		{
			return 0;
		}


		//case 1:when the list is empty
		if(*head1 == NULL)
		{
			new->data = argv[1][i]-'0';

			new->prev = NULL;

			new->next = NULL;

			*head1 = new;

			*tail1 = new;
		}
		else
		{
			new->data = argv[1][i]-'0';

			new->next = (*tail1)->next;

			new->prev = *tail1;

			(*tail1)->next = new;

			*tail1 = new;
		}
	}
	return 1;
}

int op2_list_creation(op2_list **head2, op2_list **tail2, char **argv)
{

	for(int i=0; argv[3][i] != '\0'; i++)
	{
		op2_list *new = malloc(sizeof(op2_list));

		if(new == NULL)
		{
			return 0;
		}


		//case 1:when the list is empty
		if(*head2 == NULL)
		{
			new->data = argv[3][i]-'0';

			new->prev = NULL;

			new->next = NULL;

			*head2 = new;

			*tail2 = new;
		}
		else
		{
			new->data = argv[3][i]-'0';

			new->next = (*tail2)->next;

			new->prev = *tail2;

			(*tail2)->next = new;

			*tail2 = new;
		}
	}
	return 1;
}

void print_list(op1_list *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d <-", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}
