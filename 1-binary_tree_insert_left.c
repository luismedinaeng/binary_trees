#include "binary_trees.h"

/**
 *binary_tree_insert_left - inserts a node at left
 *@parent: parent of the left node
 *@value: value of the new node
 *
 *Return: Pointer of the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;

	left_node = malloc(sizeof(binary_tree_t));
	if (parent == NULL || left_node == NULL)
		return (NULL);
	left_node->n = value;
	left_node->right = NULL;
	left_node->parent = parent;
	if (parent->left != NULL)
	{
		parent->left->parent = left_node;
		left_node->left = parent->left;
		parent->left = left_node;
	}
	else
		parent->left = left_node;
	return (left_node);
}
