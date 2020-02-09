/*******************************************************************************************************************************************************************
 *Title			   : Rotate and Recolor
 *Description	   : This function rotates and recolors given nodes
 *Prototype		   : Status rotate_and_recolor(RBT_t* child, RBT_t* parent, RBT_t* grand_parent);
 *Input Parameters : Pointers to root, child, parent and grand parent nodes.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status rotate_and_recolor(RBT_t** root, RBT_t* child, RBT_t* parent, RBT_t* grand_parent)
{
		//There are 4 cases of rotation
		//1. L-L : Right rotaion
		if (child == parent -> left && parent == grand_parent -> left)
		{
				//Change color of parent and grand parent
				parent -> color = BLACK;
				grand_parent -> color = RED;
#if DEBUG_ON
				printf("L-L : R\n");
#endif
				//Perform 1 right rotation
				right_rotate(root, parent, grand_parent);
		}
		//2. R-L : Left rotation followed by Right rotation
		else if (child == parent -> right && parent == grand_parent -> left)
		{
				//Change color of child and grand parent
				child -> color = BLACK;
				grand_parent -> color = RED;
#if DEBUG_ON
				printf("R-L : L-R\n");
#endif
				//Perform left rotation
				left_rotate(root, child, parent);
				//Now do right rotation
				right_rotate(root, child, grand_parent);
		}
		//3. R-R : Left rotaion
		else if (child == parent -> right && parent == grand_parent -> right)
		{
				//Change color parent and grand parent
				parent -> color = BLACK;
				grand_parent -> color = RED;
#if DEBUG_ON
				printf("R-R : L\n");
#endif
				//Perform 1 left rotation
				left_rotate(root, parent, grand_parent);
		}
		//2. L-R : Right rotation followed by left rotation
		else
		{
				//Change color of child and grand parent
				child -> color = BLACK;
				grand_parent -> color = RED;
#if DEBUG_ON
				printf("L-R : R-L\n");
#endif
				//Perform right rotation
				right_rotate(root, child, parent);
				//Now do left rotation
				left_rotate(root, child, grand_parent);
		}
		return SUCCESS;
}

