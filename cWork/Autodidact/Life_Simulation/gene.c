#include "gene.h"

int expressGene(phenotype *p)
{
    return (int) ((int)p->g & (int)p->e);
}

void die(organism *o)
{
    free(o);
}

void change(organism *o, char severity, int type)
{
    int i,k;
    for(k=0; k<4; k++)
    {
        int n = 0;
        for(i=0; i<severity; i++)
        {
            
        }
    }
}

organism * sex(organism *m, organism *f)
{
    organism *o = (organism *) malloc(sizeof(organism));
    return o;
}
