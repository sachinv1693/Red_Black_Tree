/*******************************************************************************************************************************************************************
 *Title			   : Delete Minimum
 *Description	   : This function deletes the minimum data from the given Red Black tree.
 *Prototype		   : Status delete_minimum(RBT_t** root);
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status delete_minimum(RBT_t** root)
{
		//A variable to hold the min value in the RB-Tree
		data_t min;
		//Return FAILURE if min value is not found
		if (!find_minimum(*root, &min))
		{
				return FAILURE;
		}
		//A pointer to store the address of node to be deleted
		RBT_t* del_node = find_node(*root, min);
		//If node to be deleted is root node then, jusy delete it and update root node's value to its right child's value
		if (del_node == *root)
		{
				*root = del_node -> right;
				free(del_node);
				return SUCCESS;
		}
		//If node is not found then return FAILURE
		else if (del_node == NULL)
		{
				printf("\nUnable to find the min node in the RB-Tree");
				return FAILURE;
		}
		//Otherwise delete the node by passing arguments to delete_node()
		else
				return delete_node(root, del_node, LEFT);
}

