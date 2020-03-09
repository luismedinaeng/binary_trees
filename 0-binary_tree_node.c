#include "binary_trees.h"


/**
 * binary_tree_node - Creates a binary tree node
 * @parent: parent is a pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: A pointer to a binary_tree_t node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
