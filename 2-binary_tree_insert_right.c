#include "binary_trees.h"
/**
 * binary_tree_insert_right - insert right-child in binary tree
 * @parent: pointer of node to right-child
 * @value: value of new node
 * Return: Null or pointer to new node
 * Description: update right-child if exists else
 *		insert new at right - child
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
