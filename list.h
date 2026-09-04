
#define SUCCESSFULL 1;
#define FAILURE 0;

//structure to create a doubly linked list 
typedef struct node
{
	struct node *prev;

	struct node *next;

	int data;

}oprnd_list;

//prototype of validation function collecting argv
int validation(char **);

//prototype of oprnd_list_creation function, collecting head, tail pointers and argv
int oprnd_list_creation(oprnd_list **head, oprnd_list **tail, char *);

//protoype of print_list function collecting the head pointer of the list that needs to be printed
void print_list(oprnd_list *head);