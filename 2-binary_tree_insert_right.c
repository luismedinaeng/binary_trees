#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of anotehr node
 * If parent already has a right-child, the new node must take its place, and the
 * old right-child must be set as the right-child of the new one.
 * @parent: parent is a pointer to the parent node
 * @value: Value to put in the new node
 *
 *
 * Return: A pointer to a binary_tree_t node
 * NULL if fails or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *r_node;
	binary_tree_t *new_node;

	r_node = NULL;
	if (parent == NULL)
		return (NULL);

	if (parent->right != NULL)
		r_node = parent->right;

	new_node = binary_tree_node(parent, value);
	new_node->right = r_node;
	parent->right = new_node;

	return (new_node);
}
