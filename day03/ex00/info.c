#include "header.h"

int     big(int a, int b)
{
    return (a > b ? a:b);
}

int     small(int a, int b)
{
    return (a > b ? b:a);
}

int     max(int a, int b, int c)
{
    return (big(a,big(b,c)));
}

int     min(int a, int b, int c)
{
    return (small(a, small(b,c)));
}

int     getHeight(struct s_node *root)
{

    if(root == NULL)
        return -1;
    return big(getHeight(root->left), getHeight(root->right))+ 1;
}
int     isGreater(struct s_node *root, int value)
{ 
if(root == NULL)
        return 1;
    if(root->value > value
    && isGreater(root->left, value) != 0
    && isGreater(root->right,value) != 0)
        return 1;
    else
        return 0;
}
int     isLesser(struct s_node *root, int value)
{
    if(root == NULL)
        return 1;
    if(root->value <= value
    && isLesser(root->left, value) != 0
    && isLesser(root->right,value) != 0)
        return 1;
    else
        return 0;
}

int     isBst(struct s_node *root)
{
    if(root == NULL)
        return 1;
    if(isLesser(root->left, root->value) != 0
    && isGreater(root->right, root->value) != 0
    && isBst(root->left) != 0
    && isBst(root->right) != 0)
        return 1;
    else
        return 0;
}

int     bstMin(struct s_node *root)
{
    if(root == NULL)
        return -1;
    else if(root->left == NULL)
        return root->value;
    return bstMin(root->left);
}

int     bstMax(struct s_node *root)
{
    if(root == NULL)
        return -1;
    else if(root->right == NULL)
        return root->value;
    return bstMax(root->right);
}

int     nodeCount(struct s_node *root)
{
    if(root == NULL)
        return 0;
    else
        return (1 + nodeCount(root->left) + nodeCount(root->right));
}

int     isBalanced(struct s_node *root)
{
    int left_height;
    int right_height;
    if(root == NULL)
        return 1;
    left_height = (getHeight(root->left));
    right_height = (getHeight(root->right));
    
    return ((abs(left_height - right_height)) <= 1
        &&isBalanced(root->left)
        &&isBalanced(root->right));
}
int     nonBstMax(struct s_node *root)
{
    if(root == NULL)
        return INT_MIN;
    int res = root->value;
    int lres = nonBstMax(root->left);
    int rres = nonBstMax(root->right);

    if(lres > res)
        res = lres;
    if(rres > res)
        res = rres;
    return res;
}

int     nonBstMin(struct s_node *root)
{
     if(root == NULL)
        return INT_MAX;
    int res = root->value;
    int lres = nonBstMin(root->left);
    int rres = nonBstMin(root->right);

    if(lres < res)
        res = lres;
    if(rres < res)
        res = rres;
    return res;
}

struct s_info   getInfo(struct s_node *root)
{
    struct s_info   *info = NULL;
    if(NULL == (info = malloc(sizeof(struct s_info))))
        return *info;
    if((info->isBST = isBst(root)) == 1)
    {
        info->min = bstMin(root);
        info->max = bstMax(root);
    }
    else
    {
        info->min = nonBstMin(root);
        info->max = nonBstMax(root);
    }
    info->isBalanced = isBalanced(root);
    info->height = getHeight(root);
    info->elements = nodeCount(root);
    return *info;
}