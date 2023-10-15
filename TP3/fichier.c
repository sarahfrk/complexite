#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.c"
#include <time.h>



// QST 3---------------------------------------------------------
//*********************************recursive************************/
int findElemRec(BTree bt,Element e){
	if(isEmptyBTree(bt))
		return 0;
	else {
		if(root(bt)==e)
			return 1;
		else
			return findElemRec(leftChild(bt),e) ||  findElemRec(rightChild(bt),e);
	}
}
//************************************iterative********************
int findElemIter(Node*x , Element e)
{
     if (x== NULL) {
		return 0;
	}
	// create a stack to hold `Node*`  --PILE
     // create a stack of capacity 15
	struct stack *pt = newStack(15);
     push(pt, x);

	// loop till stack is empty
	while (!isEmpty(pt))
	{
		// pop the top from the stack 
		Node* x = pop(pt);

          // tester si le premier element d la pile = element
		if (x->elem == e) {
			return 1;
		}

          //empiler les element gauche dans la pile s'ils existent
		if (x->left) {
               push(pt, x->left);
		}
		
          //empiler les element droit dans la pile s'ils existent
		if (x->right) {
			push(pt, x->right);
		}	
	}

	// we reach here if the value doesn't find
	return 0;
}


// QST 4---------------------------------------------------------
//*********************************recursive************************
Element findMinRec(BTree bt){
	if(isEmptyBTree(bt))
		printf("finfMin impossible!");
	if(isLeaf(bt))
	 	return root(bt);
	else {
		Element m=root(bt);
		if(!isEmptyBTree(leftChild(bt)))
			m=min(m,findMinRec(leftChild(bt)));
		if(!isEmptyBTree(rightChild(bt)))
			m=min(m,findMinRec(rightChild(bt)));
		
		return m;
	}
}
/************************************iterative********************/
int findMinIter(Node*y)
{
     int min;
     Node* x = y;
     if (x== NULL) {
		return 0;
	}else{
          min = root(x);
     }
	// create a stack to hold `Node*` 
     // create a stack of capacity 15
	struct stack *pt = newStack(15);
     push(pt, x);

	// loop till stack is empty
	while (!isEmpty(pt))
	{
		// pop the top from the stack 
		Node* x = pop(pt);

          // tester si le premier element d la pile < min
		if (x->elem < min) {
			min = x->elem;
		}

          //empiler les element gauche dans la pile s'ils existent
		if (x->left) {
               push(pt, x->left);
		}
		
          //empiler les element droit dans la pile s'ils existent
		if (x->right) {
			push(pt, x->right);
		}
		
	}

	// we reach here if the value doesn't find
	return min;
}


// QST 5---------------------------------------------------------
//*********************************recursive************************
void printCurrentLevel(Node* root, int level);
int height(Node* node);
struct node* newNode(int data);

/* Function to print level order traversal a tree*/
void printWidthOrderREc(Node* root)
{
	int h = height(root);
	int i;
     //pour chaque niveau je fait appel recursive --complexite O(n*n)
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}   
/* Print nodes at a current level */
void printCurrentLevel(Node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		//printf("%d ", root->elem);
		printf("");
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}
/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(Node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

/************************************iterative********************/
//version 1-----------------------
void printWidthOrder(BTree B){
     queue *q;
     q = queue_new();
     BTree bt=B;
     queue_send(q, bt);
     while(q != NULL) {
        Node* n = queue_receive(q);
		printf("%d ", root(n));		// Traitement du noeud courant 
		if (!isEmptyBTree(leftChild(n))) 
               queue_send(q, leftChild(n));
		if (!isEmptyBTree(rightChild(n))) 
               queue_send(q, rightChild(n));
	}
	printf("\n");
}

//version 2----------------------
void printWidthOrderIter(Node*y)
{
	Node* x=y;
     if (x == NULL) {
		printf("L\'arbre est vide");
	}else{
          // create a file to hold `Node*` --FILE
          queue *q;
          q = queue_new();
          queue_send(q, x);

          // loop till stack is empty
          while (q != NULL)
          {
               // pop the top from the file
               Node* n = queue_receive(q);
               //printf("%d ", root(n));	
			   printf("");	

               if (n->left) {
                    queue_send(q, n->left);
               }

               if (n->right) {
                    queue_send(q, n->right);
               }  
          }
     }
}



int main(){
	BTree Arbres[10];
	unsigned long k, i, j;
	unsigned long taille[] = {10000, 50000, 70000, 80000, 100000, 500000, 900000, 1000000};
	int trouve1, trouve2;
	Element min;
	int min2;
	clock_t t1,t2;
    double delta;
	
	for(k=0; k<10; k++){
        Arbres[k] = NULL;
    }
    
    for(i=0; i<8; i++){
    	for(j=0; j<taille[i]; j++){
    		int x = 1 + rand() % (50 + 1 - 1);
    		addNode(&Arbres[i], x);
		}
	}
    
    for(i=0; i<8; i++){
    	printf("Arbre %lu\n",i+1);
        //printTree(Arbres[i]);
        t1 = clock();
        
        
        /******************************************************************
        
		il suffit de decommenter la ligne que vous voulez tester
		
		******************************************************************/
        
        
        /*l execution de la fonction findElemRec*/
        trouve1 = findElemRec(Arbres[i], 10);
        
        /*l execution de la fonction findElemIter*/
        //trouve2 = findElemIter(Arbres[i], 10);
        
        /*l execution de la fonction findMinRec*/
        //min = findMinRec(Arbres[i]);
        
        /*l execution de la fonction findMinIter*/
        //min2 = findMinIter(Arbres[i]);
        
        /*l execution de la procedure printWidthOrderREc*/
        //printWidthOrderREc(Arbres[i]);
        
        /*l execution de la procedure printWidthOrderIter*/
        //printWidthOrderIter(Arbres[i]);
        
        
        t2 = clock();
        delta = (double)(t2-t1)/CLOCKS_PER_SEC;
        printf("Son temps est %lf\n", delta);
	}
	
	
	
	
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	
	
	
	return 0;
}
