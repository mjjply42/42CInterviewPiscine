#include "header.h"

struct s_node   *setBST(int *nums, int start, int end)
{
    struct s_node *tree = NULL;
    if(start > end)
        return NULL;
    int mid = (start+end) / 2;
    tree = malloc(sizeof(struct s_node));
    tree->value = nums[mid];
    tree->left = setBST(nums,start,mid-1);
    tree->right = setBST(nums,mid+1,end);
    return tree;
}

struct s_node   *createBST(int *arr, int n)
{
    struct s_node *tree = setBST(arr,0,n-1);
    return tree;
}