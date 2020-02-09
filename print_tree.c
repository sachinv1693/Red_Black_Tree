/*******************************************************************************************************************************************************************
 *Title			   : Print Red-Black Tree
 *Description	   : This function prints the given Red-Black tree in in-order form on the console.
 *Prototype		   : Status print_tree(RBT_t* root);
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

void print_tree(RBT_t* root)
{
		//If root is not NULL, perform the operation
		if (root)
		{
				//Recursively print left child's data
				print_tree(root -> left);
				//printing current child's data along with its color
				if (root -> color == RED)
						printf("%d--(RED->0) ", root -> data);
				else
						printf("%d--(BLACK->1) ", root -> data);
				//Recursively print right child's data
				print_tree(root -> right);
		}
}

