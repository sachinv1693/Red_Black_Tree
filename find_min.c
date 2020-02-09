/*******************************************************************************************************************************************************************
 *Title			   : Find Minimum
 *Description	   : This function finds the minimum data from the given Red Black tree.
 *Prototype		   : Status find_minimum(RBT_t* root, data_t* min);
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
                   : min – Minimum data present in the tree is collected via this pointer.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status find_minimum(RBT_t* root, data_t* min)
{
		//Check if RBT is empty
		if (root == NULL)
		{
				printf("\n%s", RBT_EMPTY);
				return FAILURE;
		}
		//Iterate till we find the leftmost node
		while (root -> left)
		{
				root = root -> left;
		}
		//Now we found the minimum node data
		*min = root -> data;
		return SUCCESS;
}

