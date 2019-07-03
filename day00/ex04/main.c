#define FILENAME "book.txt"
#include "header.h"

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
unsigned int    goodHash(char *str, int len)
{
    char *p = str;
    unsigned int h = 0;
    int i;

    for (i = 0; i < len; i++)
        h += p[i]*(pow(7,i));
    return h;
}

int     howManyJesus(char *bible, char *jesus)
{
    unsigned int text_hash;
    int length = strlen(jesus);
    unsigned int patt_hash = goodHash(jesus, length);
    int count = 0;
    int j = 0;
    if(bible != NULL && jesus != NULL)
    {
        text_hash = goodHash(bible, length);
        while(bible[length-1] != '\0')
        {
            if (text_hash == patt_hash)
            {   
                j = 0;
                while(jesus[j] != '\0')
                {
                    if(jesus[j] != bible[j])
                        break;
                    j++;
                }
                if(jesus[j] == '\0')
                    count++;
            }
            text_hash -= bible[0]*(pow(7,0));
            text_hash /= 7;
            bible++;
            text_hash += bible[length-1]*(pow(7,length-1));
        }
    }
    return count;
}

int     main()
{
    char *file_content;

    file_content = readFile();
    int count = howManyJesus(file_content, "God");
    return (1);
}