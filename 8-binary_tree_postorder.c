#include "binary_trees.h"
/**
 * binary_tree_postorder - nodes post-order traversal
 * @tree: pointer to root of tree
 * @func: func pointer to each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
