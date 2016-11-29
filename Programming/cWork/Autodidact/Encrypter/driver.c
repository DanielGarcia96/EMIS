#include "ecrypt.h"

int main(int argc, char *argv[])
{
    int op, fd, cipher;

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <option> [-d | -e] <file> <numerical-cipher>\n", argv[0]);
        fprintf(stderr, "CAUTION: This only works reliably with ascii textfiles\n");
        return -1;
    }

    if(strcmp(argv[1], "-d") == 0)
        op = DCY;
    else if(strcmp(argv[1], "-e") == 0)
        op = ECY;
    else
        op = UNK;
        
    
    if((fd = open(argv[2], O_RDWR)) < 0)
    {
        perror("Error opening file");
        return -1;
    }

    cipher = atoi(argv[3]);

    switch(op)
    {
        case DCY:
            if (decrypt(fd, cipher) != 0)
                return -1;
        break;
        case ECY:
            if (encrypt(fd, cipher) != 0)
                return -1;
        break;
        default:
            fprintf(stderr, "Illegal option\n");
            return -1;
    }

    close(fd);
    return 0;
}
