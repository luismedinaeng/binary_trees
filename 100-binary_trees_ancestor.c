#include "binary_trees.h"


/**
 *dist_to_root - calc the distance of a node to the root
 *@node: node to check
 *
 *Return: size_t of the distance of the node to the root
 */
size_t dist_to_root(binary_tree_t *node)
{
	size_t len;

	len = 0;
	while (node != NULL)
	{
		node = node->parent;
		len++;
	}
	return (len);
}


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
	binary_tree_t *tree_f, *tree_s, **array_f, **array_s, *common, *son;
	size_t len_f, len_s, i, j;

	if (first == NULL || second == NULL)
	{
		printf("retorno Null\n");
		return (NULL);
	}
	if (first == second->parent)
		return (second->parent);
	if (second == first->parent)
		return (first->parent);
	son = first->left;
	if (first == second && first->parent == NULL)
		return (son->parent);
	else
		return (first->parent);
	tree_f = first->parent;
	tree_s = second->parent;
	len_f = dist_to_root(tree_f);
	len_s = dist_to_root(tree_s);
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
				free(array_f);
				free(array_s);
				return (common);
			}
		}
	}
	return (NULL);
}
