/*******************************************************************************************************************************************************************
 *Title			   : Fix Double Red nodes in the RB-Tree
 *Description	   : This function balances the RB-Tree
 *Prototype		   : Status fix_double_red(RBT_t** grand_parent, RBT_t* parent, RBT_t** uncle, RBT_t** child);
 *Input Parameters : Address of root, grand parent, parent, uncle and child node.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status fix_double_red(RBT_t** root, RBT_t* grand_parent, RBT_t* parent, RBT_t* uncle, RBT_t* child)
{
#if DEBUG_ON
		printf("Fixing double red issue..\n");
#endif
		//If parent's color is BLACK, RB-Tree is balanced. Return SUCCESS
		if (parent -> color == BLACK)
				return SUCCESS;
		//Now check if new node's uncle is present and also check his position (left or right to that of grand parent)
		if (which_child(parent, grand_parent) == LEFT && grand_parent -> right)
		{
				//Uncle is right child of grand parent
				uncle = grand_parent -> right;
#if DEBUG_ON
				printf("Uncle is grand parent's right child\n");
#endif
		}
		else if (which_child(parent, grand_parent) == RIGHT && grand_parent -> left)
		{
				//Uncle is left child of grand parent
				uncle = grand_parent -> left;
#if DEBUG_ON
				printf("Uncle is grand parent's right child\n");
#endif
		}
		//Check if uncle is present and also check his color for DEBUG purpose
#if DEBUG_ON
		if (uncle == NULL)
				printf("Uncle is absent\n");
#endif
		//If uncle is absent or he is present and his color is black then, perform rotation and recoloring
		if (uncle == NULL || (uncle && (uncle -> color == BLACK)))
		{
#if DEBUG_ON
				printf("Uncle is BLACK: Rotate_recolor\n");
#endif
				return rotate_and_recolor(root, child, parent, grand_parent);
		}
		//Otherwise if uncle is present and his color is RED then, perform recoloring
		//Note that grand parent's color must be BLACK
		else if (uncle && uncle -> color == RED)
		{
#if DEBUG_ON
				printf("Uncle is RED: Recolor\n");
#endif
				//Return SUCCESS if Red-Red parent-child relationship is fixed
				if (recolor(parent, grand_parent, uncle))
						return SUCCESS;
				//Note that grand parent's parent exists. So he is not at root position.
				//Make recursive call to fix violations by considering grand parent at child's place
				return fix_double_red(root, grand_parent -> parent -> parent, grand_parent -> parent, NULL, grand_parent);
		}

}

