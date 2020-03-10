#include "binary_trees.h"

/**
 *binary_tree_height - print binary tree's height
 *@tree: pointer to the binary tree
 *
 *Return: size_t height value
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
		if (height_l >= height_r)
			return (height_l + 1);
		return (height_r + 1);
	}
	return (0);
}
