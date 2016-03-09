#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#define	BUF	64
#define NUM	8
#define ERR     17
#define PMSG    16
#define VMSG    19

#define DEBUG   1
#define DATA    1

struct vector {
   float x;
   float y;
   float z;
};

struct particle {
   float mass;
   struct vector pos;
   struct vector vel;
};

void printParticle(struct particle p, char buf[], char cpar[], size_t nbytes);
void ftoa(float n, char *res, int afterpoint);
int intToStr(int x, char str[], int d);
void reverse(char *str, int len);


int main(int argc, char *argv[])
{
    int    fd;         //file descriptor
    char   buf[BUF];   //buffer
    char   cpar[2];    //string for whatever particle your on
    size_t nbytes;     //number of bytes read
    struct particle p; //particle structure in the end

    int i;
    for( i = 1; i < argc; i++) {

        

        if( ( fd = open(argv[i], O_RDONLY) ) == -1 ) {
             perror("Could not open file");
    	     exit(1);
        }

        int pcount = 0;
        while ( ( nbytes = read(fd, &p, sizeof(struct particle)) ) > 0) {

            pcount++;

            if(pcount < 10) {
                cpar[0] = pcount + '0';
                cpar[1] = ' ';
            }
            else {
                cpar[0] = ((pcount/10)%10) + '0';
                cpar[1] = (pcount%10) + '0';
            }

            printParticle(p, buf, cpar, nbytes);

            if ( nbytes < 0 ) {
                perror("Read error\n");
                exit(1);
            }
        }

    }

    exit(0);
}

void printParticle(struct particle p, char buf[], char cpar[], size_t nbytes)
{
    if(DEBUG) {
        printf("Particle %s\n", cpar);
        printf("\tmass\t%f\n", p.mass);
        printf("\tpos.x\t%f\n", p.pos.x);
        printf("\tpos.y\t%f\n", p.pos.y);
        printf("\tpos.z\t%f\n", p.pos.z);
        printf("\tvel.x\t%f\n", p.vel.x);
        printf("\tvel.y\t%f\n", p.vel.y);
        printf("\tvel.z\t%f\n\n", p.vel.z);
    }

if(DATA) {
    if( nbytes != sizeof(struct particle) ) {
        perror("Entry incomplete\n");
        exit(1);
    }
    if ( write(STDOUT_FILENO, "Particle        ", PMSG) != PMSG) {
        perror("Write error\n");
        exit(1);
    }
    if ( write(STDOUT_FILENO, cpar, 2) != 2 ) {
        perror("Write error\n");
        exit(1);
    }
    if ( write(STDOUT_FILENO, "\n", 1) != 1 ) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, "        mass    ", VMSG - 2) != VMSG-2 ) {
        perror("Write error\n");
        exit(1);
    }
    ftoa(p.mass, buf, NUM);
    if ( write(STDOUT_FILENO, buf, NUM) != NUM) {
        perror("Write error\n");
        exit(1);
    }
    if ( write(STDOUT_FILENO, "\n", 1) != 1 ) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, "        pos     (", VMSG) != VMSG ) {
        perror("Write error\n");
        exit(1);
    }

    ftoa(p.pos.x, buf, NUM);
    if ( write(STDOUT_FILENO, buf, NUM) != NUM) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, ",", 1) != 1 ) {
        perror("Write error\n");
        exit(1);
    }

    ftoa(p.pos.y, buf, NUM);
    if ( write(STDOUT_FILENO, buf, NUM) != NUM) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, ",", 1) != 1 ) {
        perror("Write error\n");
        exit(1);
    }

    ftoa(p.pos.z, buf, NUM);
    if ( write(STDOUT_FILENO, buf, NUM) != NUM) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, ")\n", 2) != 2 ) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, "        vel     (", VMSG) != VMSG ) {
        perror("Write error\n");
        exit(1);
    }

    ftoa(p.vel.x, buf, NUM);
    if ( write(STDOUT_FILENO, buf, NUM) != NUM) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, ",", 1) != 1 ) {
        perror("Write error\n");
        exit(1);
    }

    ftoa(p.vel.y, buf, NUM);
    if ( write(STDOUT_FILENO, buf, NUM) != NUM) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, ",", 1) != 1 ) {
        perror("Write error\n");
        exit(1);
    }

    ftoa(p.vel.z, buf, NUM);
    if ( write(STDOUT_FILENO, buf, NUM) != NUM) {
        perror("Write error\n");
        exit(1);
    }

    if ( write(STDOUT_FILENO, ")\n", 2) != 2 ) {
        perror("Write error\n");
        exit(1);
    }
}
}

void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
 
// Converts a given integer x to string str[].  d is the number
// of digits required in output. If d is more than the number
// of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    if(x == 0) {
        str[0] = '0';
        i = 1;
    }

    if(x < 0) {
        str[0] = '-';
        i = 1;
        if((int)x == 0) {
            str[1] = '0';
            i = 2;
        }
    }

    while (x) {
        str[i++] = (x%10) + '0';
        x = x/10;
    }
 
    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
 
    reverse(str, i);
    str[i] = '\0';
    return i;
}
 
// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;
 
    // Extract floating part
    float fpart = n - (float)ipart;
 
    // convert integer part to string
    int i = intToStr(ipart, res, 0);
 
    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot
 
        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);
 
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
