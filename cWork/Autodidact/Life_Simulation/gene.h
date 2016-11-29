#include <time.h>
#include <limits.h>
#include <stdlib.h>

typedef char gene;    /* Unsigned series of bits that
                         allow for different phenotype
                         potentials. */

typedef char epigene; /* Unsigned series of bits that turn
                         on or off differnt genes */

struct _phenotype {
    gene g;
    epigene e;
};
typedef struct _phenotype phenotype;

struct _organism {
    phenotype spd;
    phenotype siz;
    phenotype lon;
    phenotype dir;
    phenotype rep;

    unsigned int age;
    unsigned int gen;
    unsigned int pos[2];
};
typedef struct _organism organism;

int expressGene(phenotype *p);

void die(organism *o);
void change(organism *o, char severity, int type);

organism * birth(organism *o);
organism * sex(organism *m, organism *f);
