#include "binary_trees.h"
/**
 * binary_tree_inorder - nodes in-order traversal
 * @tree: pointer to root of tree
 * @func: func pointer to each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
