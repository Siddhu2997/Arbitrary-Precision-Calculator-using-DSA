
#define SUCCESSFULL 1;
#define FAILURE 0;

#define LARGE 1;
#define SMALL 2;

typedef enum
{
	PLUS,
	MINUS
}operators;

//structure to create a doubly linked list 
typedef struct node
{
	struct node *prev;

	struct node *next;

	int data;

}D_list;

//prototype of validation function collecting argv
int valid_number(char *str);

//prototype of oprnd_list_creation function, collecting head, tail pointers and argv
int oprnd_list_creation(char ch, D_list **head, D_list **tail);

//protoype of print_list function collecting the head pointer of the list that needs to be printed
void print_list(D_list *head, D_list *tail);

//prototype of the add function
int add_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail);

//prototype of subtract function
int sub_operation(int opr1len, int opr2len, D_list **head1, D_list **tail1, D_list **head2, D_list **tail2, D_list **res_head, D_list **res_tail, int div_flag, int *flag);

//prototype of the multiplication function
int multi_operation(D_list **, D_list **, D_list **, D_list **);

//prototype of division operation
int divide_operation(int opr1len, int opr2len, D_list **head1, D_list **tail1, D_list **head2, D_list **tail2, D_list **res_head, D_list **res_tail);

//insert last opearation prototype
int insert_last(char ch, D_list **head, D_list **tail);

//insert first operation
int insert_first(D_list **head, D_list **tail, int data);

//delete list operation
int delete_list(D_list **head, D_list **tail);

//to compare which operand has more digits
//int compare_list(D_list *tail1, D_list *tail2);

//to determine which list is greater
int greater(D_list *res_head, D_list *headr2); 

//to remove the leading zeros from the list
int clear_leading_zero(D_list **head,D_list **tail);

// Function to determine which operand is larger for subtraction
int change_link(int opr1len,int opr2len,D_list ** head1,D_list **tail1, D_list **head2,D_list **tail2, D_list **temp1, D_list **temp2,int *flag);