/*******************************************************************************************************************************************************************
 *Title			   : Deletion
 *Description	   : This function performs deletion of the given data from the Red Black tree.
 *Prototype		   : Status delete_data(RBT_t** root, data_t data); 
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
 : data – Data to be deleted from the Red Black tree.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status delete_data(RBT_t** root, data_t data)
{
		if (*root == NULL)
		{
				printf("%s\n", RBT_EMPTY);
				return FAILURE;
		}
		//Find the node to be deleted & store its address into a pointer
		RBT_t* del_node = find_node(*root, data);
		//If node is not found, return FAILURE
		if (del_node == NULL)
		{
				printf("%d is not present in this RB-tree\n", data);
				return FAILURE;
		}
#if DEBUG_ON
		printf("%d is found in the RB-Tree\n", data);
#endif
		//If node is root leaf node simply delete it and update root value
		if (del_node == *root && del_node -> left == NULL && del_node -> right == NULL)
		{
#if DEBUG_ON
				printf("%d is the root leaf node\n", data);
#endif
				free(del_node);
				*root = NULL;
				return SUCCESS;
		}
		//Check if node to be deleted is left child or right child of its parent or is a root node
		WHICH_CHILD left_or_right = which_child(del_node, del_node -> parent);
#if DEBUG_ON
		if (left_or_right == LEFT)
				printf("%d is left child of its parent\n", data);
		else if (left_or_right == RIGHT)
				printf("%d is right child of its parent\n", data);
		else if (left_or_right == ROOT)
				printf("%d is the root node\n", data);
#endif
		//Delete the found node by calling delete_node function
		return delete_node(root, del_node, left_or_right);
}

