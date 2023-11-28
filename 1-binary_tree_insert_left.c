#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts left-child node.
 * @parent: pointer to left-child.
 * @value: left-child node value.
 *
 * Return: NULL or - pointer to new node.
 *
 * Description: update left node with new one if exists
 *              or set left-child of new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
