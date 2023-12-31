#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/*****************************************************************************/
/*************************** stack (pile) ****************************/
/*****************************************************************************/
// Data structure to represent a stack
struct stack
{
	int maxsize;	// define max capacity of the stack
	int top; //sommet
	Node* *items; 
};

// Utility function to initialize the stack
struct stack* newStack(int capacity)
{
	struct stack *pt = (struct stack*)malloc(sizeof(struct stack));  //allocation dynamique

	pt->maxsize = capacity;
	pt->top = -1;
	pt->items = (Node**)malloc(sizeof(int) * capacity);

	return pt;
}

// Utility function to return the size of the stack
int size(struct stack *pt) {
	return pt->top + 1;
}

// Utility function to check if the stack is empty or not
int isEmpty(struct stack *pt) {
	return pt->top == -1;   				// or return size(pt) == 0;
}

// Utility function to check if the stack is full or not
int isFull(struct stack *pt) {
	return pt->top == pt->maxsize - 1;  	// or return size(pt) == pt->maxsize;
}

// Utility function to add an element `x` to the stack
void push(struct stack *pt, Node* x)
{
	// check if the stack is already full. Then inserting an element would
	// lead to stack overflow
	if (isFull(pt))
	{
		printf("Overflow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	//printf("Inserting %d\n", x->elem);

	// add an element and increment the top's index
	pt->items[++pt->top] = x;
}

// Utility function to return the top element of the stack
Node* peek(struct stack *pt)
{
	// check for an empty stack
	if (!isEmpty(pt)) {
		return pt->items[pt->top];
	}
	else {
		exit(EXIT_FAILURE);
	}
}

// Utility function to pop a top element from the stack
Node* pop(struct stack *pt)
{
	// check for stack underflow
	if (isEmpty(pt))
	{
		printf("Underflow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	//printf("Removing %d\n", peek(pt));

	// decrement stack size by 1 and (optionally) return the popped element
	return pt->items[pt->top--];
}



void TourHanoi(int i, int j, )

int main(){


    return 0;
}