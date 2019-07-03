#include "header.h"

struct  s_node  *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
    int node_count = 0;
    struct s_node *tmp = NULL;
    struct s_node *parent;
    int i = -1;
    if(!strcmp(root->name, firstSpecies) || !strcmp(root->name, secondSpecies))
        return root;
    while(root->children[++i])
    {
        parent = findParent(root->children[i], firstSpecies, secondSpecies);
        if(parent == NULL)
            continue;
        else if(parent && ++node_count)
            tmp = parent;
        else
            break;
    }
    return (node_count == 2? root:tmp);
}