/*******************************************************************************************************************************************************************
 *Title			   : Which child
 *Description	   : This function tells whether child node is left child or right child of its parent node or it's a root node
 *Prototype		   : WHICH_CHILD which_child(RBT_t* child, RBT_t* parent);
 *Input Parameters : Pointers to child and parent nodes.
 *Output		   : WHICH_CHILD (ROOT / LEFT / RIGHT / NO_CHILD)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

WHICH_CHILD which_child(RBT_t* child, RBT_t* parent)
{
		//If child address is NULL, return NO_CHILD value
		if (child == NULL)
				return NO_CHILD;
		//If parent node is NULL then, this is root node
		else if (parent == NULL)
                return ROOT;
		//If child is left node of parent, return LEFT
		else if (parent -> left == child)
                return LEFT;
		//else child is right node of parent, return RIGHT
		else
                return RIGHT;
}

