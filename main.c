/**************************************************************************************************************************************************************
 *Title		  : main function(Driver function)
 *Description : This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include "rbt.h"

int main()
{
		/* Declare the root pointer */
		RBT_t* root = NULL;
		char option;//User choice to continue the program
		data_t data, minimum, maximum, operation;
		do
		{
				/* Display the menu */
				printf("\n1. Insert\n2. Delete\n3. Find node\n4. Find Minimum\n5. Delete Minimum\n6. Find Maximum\n7. Delete Maximum\nPlease select your option: ");

				/* Read the option for performing the operation */
				scanf("%d", &operation);

				/* Jump to the option entered by the user */
				switch (operation)
				{
						case 1://Insert data
								printf("\nEnter the data to be inserted into the RB-Tree: ");
								scanf("%d", &data);
								if (insert_data(&root, data))
										printf("Successfully inserted %d into the RB-Tree!\n", data);
								else
										printf("Failed to insert %d into the RB-Tree!\n", data);
								break;
						case 2://Delete data
								printf("\nEnter the data to be deleted from the RB Tree: ");
								scanf("%d", &data);
								if (delete_data(&root, data))
										printf("Successfully deleted %d from the RB-Tree!\n", data);
								else
										printf("Failed to delete %d from the RB-Tree!\n", data);
								break;
						case 3://Find node with given data
								printf("\nEnter the data which you want to find: ");
								scanf("%d", &data);
								if (find_node(root, data))
										printf("%d is found in the RB-Tree!\n", data);
								else
										printf("%d is not found in the RB-Tree!\n", data);
								break;
						case 4://Find minimum
								if (find_minimum(root, &minimum))
										printf("\nMinimum value in the RB-Tree is: %d\n", minimum);
								else
										printf("\nUnable to find the minimum value in the RB-Tree!\n");
								break;
						case 5://Delete minimum
								if (delete_minimum(&root))
										printf("\nSuccessfully deleted min value from the RB-Tree!\n");
								else
										printf("\nFailed to delete min value from the RB-Tree!\n");
								break;
						case 6://Find maximum
								if (find_maximum(root, &maximum))
										printf("\nMaximum value in the RB-Tree is: %d\n", maximum);
								else
										printf("\nUnable to find the maximum value in the RB-Tree!\n");
								break;				
						case 7://Delete maximum
								if (delete_maximum(&root))
										printf("\nSuccessfully deleted max value from the RB-Tree!\n");
								else
										printf("\nFailed to delete max value from the RB-Tree!\n");
								break;				
						default://Invalid option
								printf("\nInvalid option selected!!\n");
				}
				printf("\n---------------Printing the RB-Tree in inorder manner---------------\n");
				print_tree(root);
				(root) ? printf("\nRoot node data = %d", root -> data) : printf("\n%s", RBT_EMPTY);
				printf("\n\nWant to continue? Press [yY | nN]: ");
				scanf("\n%c", &option);
		} while (option == 'y' || option == 'Y');
		return 0;
}

