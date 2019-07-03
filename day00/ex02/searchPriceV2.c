int searchPrice(struct s_art **arts, int n, char *name)
  {
    int start = 0;
    int end = n;
    int middle;

    while(start <= end)
    {
        middle = ((start + end)/2);
        if(strcmp(name, arts[middle]->name) == 0)
            return (arts[middle]->price);
        else if (strcmp(name, arts[middle]->name) < 0)
            end = middle - 1;
        else
            start = middle + 1;
    }
    return (-1);
  }