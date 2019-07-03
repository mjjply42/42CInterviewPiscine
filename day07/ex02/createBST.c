#include "header.h"

struct s_node *create_node(int value)
{
	struct s_node *n;

	if ((n = malloc(sizeof(struct s_node))) == NULL)
		return (NULL);
	n->value = value;
	n->left = NULL;
    n->right = NULL;
	return (n);
}

struct s_node *make_tree(int *arr, int n)
{
	int		i;
	struct s_node *e;

	if (n == 0)
		return (NULL);
	i = n / 2;
	e = create_node(arr[i]);
	if (n == 1)
		return (e);
	e->left = make_tree(arr, i);
	e->right = make_tree(arr + i + 1, n - i - 1);
	return (e);
}

struct s_node *createBST(int *arr, int n)
{
	if (n == 0 || !arr)
		return (NULL);
	return (make_tree(arr, n));
}