/*******************************************************************************************************************************************************************
 *Title			   : Delete Node
 *Description	   : This function performs deletion of the given node from the Red-Black Tree
 *Prototype		   : Status delete_node(RBT_t** root, RBT_t* del_node, WHICH_CHILD left_or_right); 
 *Input Parameters : root – Pointer to the root node of the Red Black tree.
                   : del_node - Pointer to the node to be deleted/replaced.
                   : left_or_right - Variable to know which child of parent
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status delete_node(RBT_t** root, RBT_t* del_node, WHICH_CHILD left_or_right)
{
		if (del_node == NULL)
				return FAILURE;
		//Node to store address of the inorder successor
		RBT_t* inorder_successor = del_node -> right;
		//If node to be deleted is RED node
		if (del_node -> color == RED)
		{
#if DEBUG_ON
				printf("%d is RED\n", del_node -> data);
#endif
				//RED node can never be root node
				if (del_node -> right == NULL && del_node -> left == NULL)
				{
#if DEBUG_ON
						printf("Deleting RED leaf child..\n");
#endif
						//Assign NULL to respective parent node's pointer
						if (left_or_right == LEFT)
								del_node -> parent -> left = NULL;
						else
								del_node -> parent -> right = NULL;
						//Free the node to be deleted & return SUCCESS
						free(del_node);
						return SUCCESS;
				}
		}
		else//Node to be deleted is BLACK node
		{
#if DEBUG_ON
				printf("Node to be deleted is BLACK\n");
#endif
				//Note that BLACK node cannot have a single left BLACK child
				//Check if it has only 1 left child and it's RED
				if ((del_node -> right == NULL) && (del_node -> left) && (del_node -> left -> right == NULL && del_node -> left -> left == NULL) && (del_node -> left -> color == RED))
				{
#if DEBUG_ON
						printf("Replacing %d with single left RED leaf child %d..\nDeleting RED leaf child..\n", del_node -> data, del_node -> left -> data);
#endif
						del_node -> data = del_node -> left -> data;
						free(del_node -> left);
						del_node -> left = NULL;
						return SUCCESS;
				}
				//Else check if it has only 1 right child and it's RED
				else if ((del_node -> left == NULL) && (del_node -> right) && (del_node -> right -> right == NULL && del_node -> right -> left == NULL) && (del_node -> right -> color == RED))
				{
#if DEBUG_ON
						printf("Replacing %d with single right RED leaf child %d..\nDeleting RED leaf child..\n", del_node -> data, del_node -> right -> data);
#endif
						del_node -> data = del_node -> right -> data;
						free(del_node -> right);
						del_node -> right = NULL;
						return SUCCESS;
				}
				//If node is having 2 RED leaf children then don't find inorder successor, directly go for fixing double BLACK issue
				if (del_node -> left && del_node -> left -> color == RED && del_node -> right && del_node -> right -> color == RED && del_node -> left -> left == NULL && del_node -> left -> right == NULL && del_node -> right -> left == NULL && del_node -> right -> right == NULL)
				{
#if DEBUG_ON
				printf("%d has 2 RED leaf nodes..\n", del_node -> data);
#endif
						goto FIX_DB;
				}
		}
		//If node to be deleted is not leaf node then check recursively
		if (del_node -> left || del_node -> right)
		{
				//Find the inorder successor of the node
				inorder_successor = find_inorder_successor(inorder_successor);
				//Replace the del_node value with this inorder_successor node's value
				//Note that inorder successor cannot be NULL in our case. It can be the immediate right child.
				del_node -> data = inorder_successor -> data;
#if DEBUG_ON
				printf("Replacing with inorder successor..\nInorder successor is %d\n", inorder_successor -> data);
#endif
				//Recursively check 
				return delete_node(root, inorder_successor, which_child(inorder_successor, inorder_successor -> parent));
		}
FIX_DB:
		//Now we have to resolve the Double BLACK issue
		return fix_double_black(root, del_node, del_node -> parent, NULL, left_or_right);
}

