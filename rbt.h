/***************************************************************************************************************************************************************
 *Title		: This the header file for the Red Black Tree
 ****************************************************************************************************************************************************************/
#ifndef RBT_H
#define RBT_H

#include <stdio.h>
#include <stdlib.h>

//enum of Status having SUCCESS(1) and FAILURE(0) values
typedef enum
{
		FAILURE,
		SUCCESS
}Status;

//Macros
#define DEBUG_ON             0
#define RED                  0
#define BLACK                1
#define DUPLICATE_FOUND      "Duplicate data cannot be inserted"
#define RBT_EMPTY            "This Red-Black Tree is empty"

//Typedefines
typedef int data_t;

//Basic node structure of a Red-Black Tree
typedef struct node
{
		struct node* left;
		data_t data;
		data_t color;
		struct node* right;
		struct node* parent;
}RBT_t;

typedef enum
{
		ROOT,
		LEFT,
		RIGHT,
		NO_CHILD
}WHICH_CHILD;

/* Prototypes of all the functions */
Status insert_data(RBT_t** root, data_t data);
Status delete_data(RBT_t** root, data_t data);
Status delete_node(RBT_t** root, RBT_t* del_node, WHICH_CHILD left_or_right);
Status find_minimum(RBT_t* root, data_t* min);
Status find_maximum(RBT_t* root, data_t* max);
Status delete_minimum(RBT_t** root);
Status delete_maximum(RBT_t** root);
Status fix_double_red(RBT_t** root, RBT_t* grand_parent, RBT_t* parent, RBT_t* uncle, RBT_t* child);
Status fix_double_black(RBT_t** root, RBT_t* del_node, RBT_t* parent, RBT_t* sibling, WHICH_CHILD left_or_right);
Status rotate_and_recolor(RBT_t** root, RBT_t* child, RBT_t* parent, RBT_t* grand_parent);
void left_rotate(RBT_t** root, RBT_t* parent, RBT_t* grand_parent);
void right_rotate(RBT_t** root, RBT_t* parent, RBT_t* grand_parent);
Status recolor(RBT_t* parent, RBT_t* grand_parent, RBT_t* uncle);
RBT_t* find_node(RBT_t* root, data_t data);
RBT_t* find_inorder_successor(RBT_t* current);
WHICH_CHILD which_child(RBT_t* child, RBT_t* parent);
void print_tree(RBT_t* root);

#endif

