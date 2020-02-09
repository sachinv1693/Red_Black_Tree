/*******************************************************************************************************************************************************************
 *Title			   : Find Maximum
 *Description	   : This function finds the maximum data from the given Red Black tree.
 *Prototype		   : Status find_maximum(RBT_t* root, data_t* max);
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
                   : max – Maximum data present in the tree is collected via this pointer.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status find_maximum(RBT_t* root, data_t* max)
{
		//Check if RBT is empty
		if (root == NULL)
		{
				printf("\n%s", RBT_EMPTY);
				return FAILURE;
		}
		//Iterate till we find the rightmost node
		while (root -> right)
		{
				root = root -> right;
		}
		//Now we found the maximum node data
		*max = root -> data;
		return SUCCESS;
}

