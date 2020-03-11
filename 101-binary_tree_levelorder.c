#include "binary_trees.h"

void binary_tree_level(const binary_tree_t *tree, size_t d, void (*func)(int));

/**
 * binary_tree_levelorder - Goes trough a bin-tree using levelorder traversal
 * @tree: Pointer node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, depth;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	depth = 0;

	while (depth <= height)
	{
		binary_tree_level(tree, depth, func);
		depth++;
	}
}

/**
 * binary_tree_height - print binary tree's height
 * @tree: pointer to the binary tree
 *
 * Return: size_t height value
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_r, height_l;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
	{
		height_l = binary_tree_height(tree->left);
		height_r = binary_tree_height(tree->right);
		return (1 + (height_l > height_r ? height_l : height_r));
	}
	return (0);
}

/**
 * binary_tree_level - Applies the function given to the node at the level
 * @tree: Pointer to the root of the tree
 * @d: Level to apply the function
 * @func: Function to apply to the nodes at given level
 *
 * Return: Nothing
 */
void binary_tree_level(const binary_tree_t *tree, size_t d, void (*func)(int))
{

	if (tree == NULL)
		return;
	if (d == 0)
	{
		func(tree->n);
		return;
	}
	else
	{
		binary_tree_level(tree->left, d - 1, func);
		binary_tree_level(tree->right, d - 1, func);
	}
}
