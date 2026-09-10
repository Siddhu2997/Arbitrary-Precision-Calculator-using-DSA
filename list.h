
#define SUCCESSFULL 1;
#define FAILURE 0;

#define LARGE 1;
#define SMALL 2;


//structure to create a doubly linked list 
typedef struct node
{
	struct node *prev;

	struct node *next;

	int data;

}D_list;

//prototype of validation function collecting argv
int valid_number(char **);

//prototype of oprnd_list_creation function, collecting head, tail pointers and argv
int oprnd_list_creation(D_list **head, D_list **tail, char *);

//protoype of print_list function collecting the head pointer of the list that needs to be printed
void print_list(D_list *head);

//prototype of the add function
int add_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail);

//prototype of subtract function
int sub_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail);

//prototype of the multiplication function
int multi_operation(D_list **, D_list **, D_list **, D_list **, D_list **, D_list **, D_list **, D_list **);

//prototype of division operation
int divide_operation(D_list **tail1, D_list **tail2, D_list **res_head, D_list **res_tail);

//insert first operation
int insert_first(D_list **head, D_list **tail, int data);

//delete list operation
int delete_list(D_list **head, D_list **tail);

//to compare which operand has more digits
int compare_list(D_list *tail1, D_list *tail2);