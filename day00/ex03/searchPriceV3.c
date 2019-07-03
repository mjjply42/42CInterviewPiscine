#include "header.h"

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
    struct s_item *tmp;
    tmp = dict->items[hash(key) % dict->capacity];
    if(dict != NULL && key != NULL)
    {
        if(strcmp(tmp->key, key) != 0)
        {
            while(tmp->next != NULL)
            {
                tmp = tmp->next;
                if(strcmp(tmp->key, key) == 0)
                    return tmp->value;
            }
            return NULL;
        }
        else
            return tmp->value;
    }
    return NULL;
}

int     dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
    struct s_item *item;

    if(dict->items[hash(key) % dict->capacity] != NULL)
    {
        item = dict->items[hash(key) % dict->capacity];
        while(item->next != NULL)
            item = item->next;
        if(NULL == (item->next = malloc(sizeof(struct s_item))))
            return (-1);
        item = item->next;
    }
    else
    {
        if(NULL == (dict->items[hash(key) % dict->capacity] = malloc(sizeof(struct s_item))))
            return -1;
        item = dict->items[hash(key) % dict->capacity];
    }
    item->key = strdup(key);
    item->value = value;
    item->next = NULL;    
    return 1;
}

struct s_dict *dictInit(int capacity)
{
    struct  s_dict  *dict = NULL;

    if(capacity > 0)
        if(NULL == (dict = malloc(sizeof(struct s_dict*))))
            return NULL;
    dict->capacity = capacity;
    if(NULL == (dict->items = malloc(sizeof(struct s_item*) * capacity + 1)))
        return NULL;
    for (int i = 0; i < capacity; i += 1)
		dict->items[i] = NULL;
    return dict;
}

size_t hash(char *input)
{
    int i = 0;
    size_t hashval = 0;
    if (input != NULL)
    {
	    while( hashval < INT_MAX && i < (int)strlen( input ) ) {
		    hashval = hashval << 8;
		    hashval += input[ i ];
		    i++;
        }
	}
    return (hashval);
}