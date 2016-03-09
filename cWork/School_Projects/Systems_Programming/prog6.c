#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#define  DEBUG   1

#define  BUF     11 //Highest possible digit with an unsigned int

const char *PMSG = "Product ";
#define  PMSGL   9

const char *QMSG = " Quantity ";
#define  QMSGL   10

const char *SMSG = " Serial ";
#define  SMSGL   8

struct product {
    int type;
    int number;
};

void printProduct(struct product p, unsigned serial, int fd, size_t nbytes);
int intToStr(int x, char str[], int d);
void reverse(char *str, int len);

int main(int argc, char *argv[])
{
    int fd;              //file descriptor
    size_t nbytes;       //number of bytes read
    struct product p;    //product struct to read into
    unsigned serial;     //serial number for product
    
    if ( argc != 2 ) {
        perror("Usage: ");
        printf("Error occured at %d\n", __LINE__ - 2);
        perror(argv[0]);
        perror(" <product-file>\n");
        exit(1);
    }

    if ( ( fd = open(argv[1], O_RDONLY) ) < 0 ) {
        perror("Error opening file\n");
        printf("Error occured at %d\n", __LINE__ - 2);
        exit(1);
    }

    while ( ( nbytes = read(fd, &p, sizeof(struct product)) ) > 0 ) {
        if ( nbytes != sizeof(struct product) ) {
            perror("Incomplete entry\n");
            printf("Error occured at %d\n", __LINE__ - 2);
            exit(1);
        }
        if ( ( nbytes = read(fd, &serial, sizeof(unsigned)) ) < 0 ) {
            perror("Incopmlete entry\n");
            printf("Error occured at %d\n", __LINE__ - 2);
            exit(1);
        }
        
        printProduct(p, serial, fd, nbytes);
    }

    close(fd);
    exit(0);
}

void printProduct(struct product p, unsigned serial, int fd, size_t nbytes)
{
    char str[BUF];
    int strlength;

    if(DEBUG) {
        printf("Printf: Product %d Quantity %d Serial %d\n", p.type, p.number, serial);
    }
    
    if ( write(STDOUT_FILENO, PMSG, PMSGL) <  PMSGL ) {
        perror("Error writing\n");
        printf("Error occured at %d\n", __LINE__ - 2);
        printf("File descriptor : %d\n", fd);
        exit(1);
    }

    strlength = intToStr(p.type, str, 0);
    if ( write(STDOUT_FILENO, str, strlength) != strlength ) {
        perror("Error writing\n");
        printf("Error occured at %d\n", __LINE__ - 2);
        exit(1);
    } 

    if ( write(STDOUT_FILENO, QMSG, QMSGL) != QMSGL ) {
        perror("Error writing\n");
        printf("Error occured at %d\n", __LINE__ - 2);
        exit(1);
    }

    strlength = intToStr(p.number, str, 0);
    if ( write(STDOUT_FILENO, str, strlength) != strlength ) {
        perror("Error writing\n");
        printf("Error occured at %d\n", __LINE__ - 2);
        exit(1);
    }

    if ( write(STDOUT_FILENO, SMSG, SMSGL) != SMSGL ) {
        perror("Error writing\n");
        printf("Error occured at %d\n", __LINE__ - 2);
        exit(1);
    }
 
    strlength = intToStr(p.number, str, 0);
    if ( write(STDOUT_FILENO, str, strlength) != strlength ) {
        perror("Error writing\n");
        printf("Error occured at %d\n", __LINE__ - 2);
        exit(1);
    }

    if ( write(STDOUT_FILENO, "\n", 1) != 1 ) {
        perror("Error writing\n");
        printf("Error occured at %d\n", __LINE__ - 2);
        exit(1);
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
