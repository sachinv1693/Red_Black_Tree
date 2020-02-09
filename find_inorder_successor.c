/*******************************************************************************************************************************************************************
 *Title			   : Find Inorder Successor
 *Description	   : This function finds the inorder successor of the given node and returns its address. If not found, it returns NULL
 *Prototype		   : RBT_t* find_inorder_successor(RBT_t* current);
 *Input Parameters : A pointer to the given node
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

RBT_t* find_inorder_successor(RBT_t* current)
{
		if (current)
		{
				//Look for min value node by moving towards the leftmost possible node
				while (current -> left)
				{
						current = current -> left;
				}
		}
		return current;
		/*
		//This part is not needed in Red-Black Tree
		else
		{
				while (current -> parent)
				{
						//Look for the first left ancestor
						if (which_child(current, current -> parent) == LEFT)
								return current -> parent;
						current = current -> parent;
				}
				return current;
		}
		*/
}

