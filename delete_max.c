/*******************************************************************************************************************************************************************
 *Title			   : Delete Maximum
 *Description	   : This function deletes the maximum data from the given Red Black tree.
 *Prototype		   : Status delete_maximum(RBT_t** root);
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status delete_maximum(RBT_t** root)
{
		//A variable to hold the max value in the RB-Tree
		data_t max;
		//Return FAILURE if max value is not found
        if (!find_maximum(*root, &max))
        {
                return FAILURE;
        }
		//A pointer to store the address of node to be deleted
        RBT_t* del_node = find_node(*root, max);
		//If node to be deleted is root node then, just delete it and update root node's value to its left child's value
        if (del_node == *root)
        {
                *root = del_node -> left;
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
                return delete_node(root, del_node, RIGHT);

}

