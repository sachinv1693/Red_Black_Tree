/*******************************************************************************************************************************************************************
 *Title			   : Recolor
 *Description	   : This function recolors given nodes
 *Prototype		   : Status recolor(RBT_t* parent, RBT_t* grand_parent, RBT_t* uncle);
 *Input Parameters : Pointers to parent, grand parent & uncle nodes.
 *Output		   : Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "rbt.h"

Status recolor(RBT_t* parent, RBT_t* grand_parent, RBT_t* uncle)
{
		//Change the color of parent and uncle to BLACK
		parent -> color = uncle -> color = BLACK;
		//If grand parent is root then return SUCCESS, otherwise change his color & return FAILURE
        //If grand parent's parent is a NULL address then, grand parent is at root position
		if (grand_parent -> parent)
		{
				//Change grand parent's color to RED and rechecking is required. So return FAILURE
				grand_parent -> color = RED;
				return FAILURE;
		}
		else
				return SUCCESS;
}

