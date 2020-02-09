/*******************************************************************************************************************************************************************
 *Title		       : Insertion
 *Description      : This function performs inserting the new data into the given Red Black tree.
 *Prototype	       : Status insert_data(RBT_t** root, data_t data);
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
                   : data – New data to be inserted into the Red Black tree.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status insert_data(RBT_t** root, data_t data)
{
		//Create a new node
		RBT_t* new = malloc(sizeof(RBT_t));
		//Check if memory is allocated or not
		if (new == NULL)
		{
				printf("\nUnable to allocate dynamic memory!\n");
				return FAILURE;
		}
		//Assign new node's value
		new -> data = data;
		new -> left = new -> right = NULL;
		//If tree is empty, assign this new node as root
		if (*root == NULL)
		{
				new -> color = BLACK;
				new -> parent = NULL;
				*root = new;
				return SUCCESS;
		}
		//Assign color of new node as RED
		new -> color = RED;
		//Use a temp pointer for iterating in the tree & a pointer to hold new's parent's address (Initialize to root address)
		RBT_t* temp = *root, *parent = *root;
		//A flag to know whether the new node is left child or right child
		data_t flag;
		while (temp)
		{
				parent = temp;
				//Iterate to left child if given data is smaller
				if (data < (temp -> data))
				{
						temp = temp -> left;
						flag = 1;
				}
				//Iterate to right child if given data is larger
				else if (data > (temp -> data))
				{
						temp = temp -> right;
						flag = 0;
				}
				else//There is duplicate data entry
				{
						printf("\n%s\n", DUPLICATE_FOUND);
						return FAILURE;
				}
		}
		//Based on flag, assign new node as left or right child of parent
		if (flag)
				parent -> left = new;
		else
				parent -> right = new;
		//Update new node's parent as parent
		new -> parent = parent;
		//Call to fix double red issue in the RB-Tree
		return fix_double_red(root, parent -> parent, parent, NULL, new);
}

