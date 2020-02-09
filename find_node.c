/*******************************************************************************************************************************************************************
 *Title			   : Find node
 *Description	   : This function finds the node for the given data in Red Black tree. If data is absent, a NULL value is returned.
 *Prototype		   : RBT_t* find_node(RBT_t* root);
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
                   : data – Data to be found in the RB-Tree.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

RBT_t* find_node(RBT_t* root, data_t data)
{
		//Search as long as NULL address is not encountered
		if (root == NULL)
				//No data found
				return FAILURE;
		//Return address of the node if data is found
		if (root -> data == data)
		{
				return root;
		}
		//check if data is smaller than current node's data
		else if (data < (root -> data))
				//Then move to the left node
				return find_node(root -> left, data);
		else
				//Move to right node if data is greater
				return find_node(root -> right, data);
}

