#include "binary_trees.h"

/**
 *binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *@first: first node
 *@second: second node
 *
 *Return: lowest common ancestor of the nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *tree_f, *tree_s, **array_f, **array_s, *common;
	size_t len_f, len_s, i, j;
	int common_find;

	if (first == second->parent)
		return (second->parent);
	if (second == first->parent)
		return (first->parent);
	if (first == second)
		return (first->parent);

	tree_f = first->parent;
	tree_s = second->parent;
	len_f = len_s = 0;
	common_find = 0;
	while (tree_f != NULL)
	{
		tree_f = tree_f->parent;
		len_f++;
	}
	while (tree_s != NULL)
	{
		tree_s = tree_s->parent;
		len_s++;
	}
	tree_f = first->parent;
	tree_s = second->parent;

	array_f = malloc(len_f + 1 * (sizeof(binary_tree_t)));
	array_s = malloc(len_s + 1 * (sizeof(binary_tree_t)));
	for (i = 0; i < len_f; i++)
	{
		array_f[i] = tree_f;
		tree_f = tree_f->parent;
	}
	for (i = 0; i < len_s; i++)
	{
		array_s[i] = tree_s;
		tree_s = tree_s->parent;
	}

	for (i = 0; i < len_f; i++)
	{
		for (j = 0; j < len_s; j++)
		{
			if (array_f[i] == array_s[j])
			{
				common = array_f[i];
				common_find = 1;
				break;
			}
		}
		if (common_find == 1)
			break;
	}
	free(array_f);
	free(array_s);
	return (common);
}
