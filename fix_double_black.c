/*******************************************************************************************************************************************************************
 *Title			   : Fix Double Black node in the RB-Tree
 *Description	   : This function balances the RB-Tree
 *Prototype		   : Status fix_double_black(RBT_t** root, RBT_t* del_node, RBT_t* parent, RBT_t* sibling, WHICH_CHILD left_or_right);
 *Input Parameters : Address of root, node to be deleted, its parent & sibling node.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status fix_double_black(RBT_t** root, RBT_t* del_node, RBT_t* parent, RBT_t* sibling, WHICH_CHILD left_or_right)
{
#if DEBUG_ON
		printf("Fixing double black issue..\n");
#endif
		//if del_node is root node, the issue is resolved
		if (del_node == *root)
		{
#if DEBUG_ON
				printf("Fixed root double black issue.\n");
#endif
				return SUCCESS;
		}
		//Determine whether the sibling is on left or right of the parent
		if (left_or_right == LEFT && parent -> right)
		{
				sibling = parent -> right;
#if DEBUG_ON
				printf("Sibling is right child of parent\n");
#endif
		}
		else if (left_or_right == RIGHT && parent -> left)
		{
				sibling = parent -> left;
#if DEBUG_ON
				printf("Sibling is left child of parent\n");
#endif
		}
		//Sibling can never be NULL node as we are fixing issue of a BLACK node
		//If sibling is BLACK and both its children are BLACK
		if (left_or_right == RIGHT && sibling -> color == BLACK && ((sibling -> left && sibling -> left -> color == BLACK && sibling -> right && sibling -> right -> color == BLACK) || (sibling -> left == NULL && sibling -> right == NULL)))
		{
#if DEBUG_ON
				printf("Sibling is BLACK and both its children are BLACK\n");
#endif
				//Delete the node if it is the leaf node
				if (del_node -> right == NULL && del_node -> left == NULL)
				{
						//Free the node to be deleted
						free(del_node);
						//Make right child of parent as NULL and turn the color of sibling to RED
						parent -> right = NULL;
				}
				sibling -> color = RED;
				//If parent's color is RED, convert it to black and return SUCCESS otherwise recursively fix the double black issue by treating parent node at del_node's position
				if (parent -> color == RED) 
				{ 
						parent -> color = BLACK;
						return SUCCESS;
				}
				//Otherwise pass the double black issue to parent and recheck
				else
						return fix_double_black(root, parent, parent -> parent, NULL, which_child(parent, parent -> parent));
		}
		//Mirror case of the above
		else if (left_or_right == LEFT && sibling -> color == BLACK && ((sibling -> left && sibling -> left -> color == BLACK && sibling -> right && sibling -> right -> color == BLACK) || (sibling -> left == NULL && sibling -> right == NULL)))
		{
#if DEBUG_ON
				printf("Sibling is BLACK and both its children are BLACK\n");
#endif
				//Delete the node if it is the leaf node
				if (del_node -> right == NULL && del_node -> left == NULL)
				{
						//Free the node to be deleted
						free(del_node);
						//Make left child of parent as NULL and turn the color of sibling to RED
						parent -> left = NULL;
				}
				sibling -> color = RED;
				//If parent's color is RED, convert it to black and return SUCCESS otherwise recursively fix the double black issue by treating parent node at del_node's position
				if (parent -> color == RED) 
				{ 
						parent -> color = BLACK;
						return SUCCESS;
				}
				//Otherwise pass the double black issue to parent and recheck
				else
						return fix_double_black(root, parent, parent -> parent, NULL, which_child(parent, parent -> parent));
		}
		//If sibling is RED in color
		if (left_or_right == RIGHT && sibling -> color == RED)
		{
#if DEBUG_ON
				printf("Sibling is RED\n");
#endif
				//Swap the color of parent and sibling
				parent -> color = RED;
				sibling -> color = BLACK;
				//Rotate parent in del_node's direction
				right_rotate(root, sibling, parent);
				//Now check recursively
				return fix_double_black(root, del_node, parent, NULL, RIGHT); 
		}
		//Mirror case of the above
		else if (left_or_right == LEFT && sibling -> color == RED)
		{
#if DEBUG_ON
				printf("Sibling is RED\n");
#endif
				//Swap the color of parent and sibling
				parent -> color = RED;
				sibling -> color = BLACK;
				//Rotate parent in del_node's direction
				left_rotate(root, sibling, parent);
				//Now check recursively
				return fix_double_black(root, del_node, parent, NULL, LEFT); 
		}
		//If sibling is BLACK and sibling's child who is far from del_node is BLACK but its child who is near to del_node is RED
		if (left_or_right == RIGHT && sibling -> color == BLACK && (sibling -> left && sibling -> left -> color == BLACK || sibling -> left == NULL) && sibling -> right && sibling -> right -> color == RED)
		{
#if DEBUG_ON
				printf("Sibling is BLACK and its near child is RED, far child is BLACK\n");
#endif
				//Swap color of sibling and its child who is near to del_node
				sibling -> right -> color = BLACK;
				sibling -> color = RED;
				//Rotate sibling in opposite direction of del_node
				left_rotate(root, sibling -> right, sibling);
				//Now check recursively
				return fix_double_black(root, del_node, parent, NULL, RIGHT); 
		}
		//Mirror case of the above
		else if (left_or_right == LEFT && sibling -> color == BLACK && (sibling -> right && sibling -> right -> color == BLACK || sibling -> right == NULL) && sibling -> left && sibling -> left -> color == RED)
		{
#if DEBUG_ON
				printf("Sibling is BLACK and its near child is RED, far child is BLACK\n");
#endif
				//Swap color of sibling and its child who is near to del_node
				sibling -> left -> color = BLACK;
				sibling -> color = RED;
				//Rotate sibling in opposite direction of del_node
				right_rotate(root, sibling -> left, sibling);
				//Now check recursively
				return fix_double_black(root, del_node, parent, NULL, RIGHT); 
		}
		//If sibling is BLACK and its far child is RED
		if (left_or_right == RIGHT && sibling -> color == BLACK && sibling -> left && sibling -> left -> color == RED)
		{
#if DEBUG_ON
				printf("Sibling is BLACK and its far child is RED\n");
#endif
				//Free the node to be deleted
				free(del_node);
				//Make left child of parent as NULL and turn the color of sibling to RED
				parent -> right = NULL;
				//Swap the color of parent and sibling if those are unequal
				if (parent -> color != sibling -> color)
				{
						parent -> color = BLACK;
						sibling -> color = RED;
				}
				//Change the color of RED child to BLACK
				sibling -> left -> color = BLACK;
				//Rotate parent in del_node's direction
				right_rotate(root, sibling, parent);
				return SUCCESS; 
		}
		//Mirror case of the above
		else if (left_or_right == LEFT && sibling -> color == BLACK && sibling -> right && sibling -> right -> color == RED)
		{
#if DEBUG_ON
				printf("Sibling is BLACK and its far child is RED\n");
#endif
				//Free the node to be deleted
				free(del_node);
				//Make left child of parent as NULL and turn the color of sibling to RED
				parent -> left = NULL;
				//Swap the color of parent and sibling if those are unequal
				if (parent -> color != sibling -> color)
				{
						parent -> color = BLACK;
						sibling -> color = RED;
				}
				//Change the color of RED child to BLACK
				sibling -> right -> color = BLACK;
				//Rotate parent in del_node's direction
				left_rotate(root, sibling, parent);
				return SUCCESS; 
		}
}

