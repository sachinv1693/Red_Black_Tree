/*******************************************************************************************************************************************************************
 *Title		   : Left Rotate
 *Description	   : This function performs left rotations of the given nodes
 *Prototype	   : void left_rotate(RBT_t** root, RBT_t* parent, RBT_t* grand_parent);
 *Input Parameters : Pointers to root, parent and grand parent nodes.
 *Output	   : Return back to caller
 *******************************************************************************************************************************************************************/
#include "rbt.h"

void left_rotate(RBT_t** root, RBT_t* parent, RBT_t* grand_parent)
{
#if DEBUG_ON
		printf("Left Rotate\n");
#endif
		/* Algorithm to make grand parent node as left child of parent. Accordingly remaining nodes are adjusted */
		grand_parent -> right = parent -> left;
		if (parent -> left)//Take care of NULL address
				parent -> left -> parent = grand_parent;
		parent -> left = grand_parent;
		//If grand parent is at root position, parent should become the root
		if (grand_parent == *root)
				*root = parent;
		else
		{
				if (grand_parent -> parent -> left == grand_parent)
						grand_parent -> parent -> left = parent;
				else
						grand_parent -> parent -> right = parent;
		}
		parent -> parent = grand_parent -> parent;
		grand_parent -> parent = parent;
}

