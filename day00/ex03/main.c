#include <time.h>
#include "header.h"
#define FILENAME "art.txt"

int		getSize(struct s_art **arts)
{
	int				size;

	size = 0;
	while (arts[size] != NULL)
		size += 1;
	return (size);
}

static int			getPartition(struct s_art **arts, int left, int right)
{
	int				i;
	int				j;
	struct s_art	*pivot;
	struct s_art	*tmp;

	i = left;
	j = right;
	pivot = arts[left];
	while (1)
	{
		while (strcmp(arts[i]->name, pivot->name) < 0)
			i += 1;
		while (strcmp(arts[j]->name, pivot->name) > 0)
			j -= 1;
		if (i < j)
		{
			tmp = arts[i];
			arts[i] = arts[j];
			arts[j] = tmp;
			if (strcmp(arts[i]->name, arts[j]->name) == 0)
				j -= 1;
		}
		else
			break;
	}
	return (j);
}

void				quickSort(struct s_art **arts, int left, int right)
{
	int				partition;

	if (left < right)
	{
		partition = getPartition(arts, left, right);
		quickSort(arts, left, partition);
		quickSort(arts, partition + 1, right);
	}
	return ;
}

void  				sortArts(struct s_art **arts)
{
	return (quickSort(arts, 0, getSize(arts) - 1));
}


struct s_art *setArtStructure(char *list)
{
    struct s_art *piece;
    char **tab;
    int string_length = 0;
    int i = 0;
    int j = 0;
    if(NULL == (piece = malloc(sizeof(struct s_art))))
        return NULL;
    if(NULL == (tab = malloc(sizeof(char*) * 2 + 1)))
        return NULL;
    while(list[i] != '=')
    {
        string_length++;
        i++;
    }
    if(NULL == (tab[0] = malloc(sizeof(char) * string_length)))
        return NULL;
    i += 2;
    while(list[i] != '\0')
    {
        string_length++;
        i++;
    }
    if(NULL == (tab[1] = malloc(sizeof(char) * string_length)))
        return NULL;
    i = 0;
    while(list[j + 1] != '=')
    {
        tab[0][j] = list[j];
        j++;
    }
    tab[0][j] = '\0';
    j += 4;
    while(list[j] != '\0')
    {
        tab[1][i] = list[j];
        i++;
        j++;
    }
    tab[1][j] = '\0';
    piece->name = strdup(tab[0]);
    piece->price = atoi(tab[1]);
    return piece;
}

char    **split(char *file, char delimiter, int size)
{
    int i = 0;
    int j = 0;
    int index = 0;
    char **tab;
    int length = 0;

    if (NULL == (tab = (char**)malloc(sizeof(char*) * size + 1)))
        return (NULL);
    tab[size + 1] = 0;
    while(size >= 0)
    {
        while(file[i] != '\n' && file[i] != '\0')
        {
            length++;
            i++;
        }
        i++;
        if (NULL == (tab[j] = (char*)malloc(sizeof(char) * length + 1)))
            return NULL;
        length = 0;
        size--;
        j++;
    }
    i = 0;
    j = 0;
    while(file[index] != '\0')
    {
        if(file[index] == delimiter)
        {
            tab[i][j] = '\0';
            i++;
            j = 0;
            index++;
        }
        tab[i][j] = file[index];
        index++;
        j++;
    }
    return tab;
}
char    *readFile()
{
    FILE *fp;
    char *file_content;
    int size = 0;

    if(NULL == (fp = fopen(FILENAME, "r")))
        return NULL;
    fseek(fp, 0 , SEEK_END);
    size = ftell(fp);
    fseek(fp, 0 , SEEK_SET);
    if (NULL == (file_content = malloc(sizeof(char) * size + 1)))
        return NULL;
    fread(file_content, 1, size , fp);
    fclose(fp);
    return (file_content);
}

struct  s_art **getArts()
{
    char *file = NULL;
    char **name_price = NULL;
    int array_size = 0;
    int i = 0;
    struct s_art **art_list = NULL;
    struct s_art *tmp = NULL;

    if( NULL == (file = readFile()))
        return NULL;
    while(file[i] != '\0')
    {
        if(file[i] == '\n')
            array_size++;
        i++;
    }
    if(NULL == (art_list = malloc(sizeof(struct s_art) * array_size + 1)))
        return NULL;
    name_price = split(file, '\n', array_size);
    i = 0;
    while(array_size >= 0)
    {
        tmp = setArtStructure(name_price[i]);
        if(tmp)
            art_list[i] = tmp;
        array_size--;
        i++;
    }
    return (art_list);
}

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

int         main()
{
    struct s_art **art_list;
    struct s_dict   *dict;
    art_list = getArts();
    /*sortArts(art_list);*/quickSort(art_list, 0, getSize(art_list) - 1);
    dict = dictInit(getSize(art_list) - 1);
    int test = dictInsert(dict, art_list[300]->name, art_list[300]);
    printf("%i\n", test);
    dictSearch(dict, art_list[300]->name);

    
    /*/Runtime testing function
    clock_t t; 
    t = clock();
    dictSearch(dict, art_list[300]->name);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("dictSearch() took %f seconds to execute \n", time_taken);*/
    return (0);
}