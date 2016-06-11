#include <stdio.h> 
#include <string.h>

void sortNames(int size, char names[6000][256]);
int  readNames(FILE *fp, char names[6000][256]);
void printNames(int size, char names[6000][256]);

int main(void)
{
    FILE *fp;
    char names[6000][256];
    if((fp = fopen("p022_names.txt", "r")) == NULL)
    {
        perror("IO error");
        return -1;
    }

    int size = readNames(fp, names);
    sortNames(size, names);
    printNames(size, names);

    fclose(fp);
    return 0;
}

int readNames(FILE *fp, char names[6000][256])
{
    int n_idx = 0, name = 0;
    char c;
    while(feof(fp) == 0)
    {
        c = fgetc(fp);
        if(c == '\"')
        {
            c = fgetc(fp);
            strcpy(names[n_idx], "");
            while(c != '\"')
            {
                names[n_idx][name] = c;
                c = fgetc(fp);
                name++;
            }
            names[n_idx][name] = '\0';
            name = 0;
            n_idx++;
        }
    }
    return n_idx;
}

void sortNames(int size, char names[6000][256])
{
    int i, j, k;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size-(i+1); j++)
        {
            if(names[j][0] > names[j+1][0])
            {
                char tmp[256];
                strcpy(tmp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], tmp);
            }
        }
    }
    
    int idx = 0;
    char c = 'A';
    while(c < 91)
    {
        int section = 0;
        while(names[section+idx][0] == c)
            section++;
        for(k=0; k<section; k++)
        {
            for(i=idx; i<section+idx; i++)
            {
                for(j=idx; j<(section+idx)-(i+1); j++)
                {
                    int x;
                    if(strlen(names[j]) <= strlen(names[j+1]))
                    {
                        for(x = 0; x<strlen(names[j]); x++)
                        {
                            if(names[j][x] > names[j+1][x])
                            {
                                char tmp[256];
                                strcpy(tmp, names[j]);
                                strcpy(names[j], names[j+1]);
                                strcpy(names[j+1], tmp);
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(x = 0; x<strlen(names[j+1]); x++)
                        {
                            if(names[j][x] > names[j+1][x])
                            {
                                char tmp[256];
                                strcpy(tmp, names[j]);
                                strcpy(names[j], names[j+1]);
                                strcpy(names[j+1], tmp);
                                break;
                            }
                        }
                    }
                }
            }
        }
        idx += section;
        c++;
    }
}

void printNames(int size, char names[6000][256])
{
    int i;
    for(i=0; i<size; i++)
        printf("%s\n", names[i]);
}
