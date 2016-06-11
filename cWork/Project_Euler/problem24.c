#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define STOP 1000000

#define BUF 256

#define READ_ERR  1
#define WRITE_ERR 2
#define SEEK_ERR  3
#define OPEN_ERR  4
#define DUP_ERR   5

int    factorial(int n);
void   generate_permutations(int len, int tmp[], int o_len, int fd);
size_t m_seek(int fd, int whence, off_t off);
void   readEntry(char *string, int size, int fd);
void   sort_results(int fd, int size);
void   writeEntry(char *string, int size, int fd);

int main(void)  {

   int fd;
   if ( ( fd = open("output", O_RDWR) ) == -1 )  {
      perror("Opening error");
      return OPEN_ERR;
   }

   int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
   int len = 10;

   generate_permutations(len, a, len, fd);
   sort_results(fd, len);

   /*int b[] = { 0, 1, 2};
   int l2 = 3;

   generate_permutations(l2, b, l2, fd);
   sort_results(fd, l2);*/
   return 0;
}

int factorial(int n)  {
   int i;
   int result = 1;
   for ( i = 1; i <= n; i++ )
       result *= i;
   return result;
}

void generate_permutations(int len, int tmp[], int o_len, int fd)  {
    if ( len == 1 )  {
      char buffer[BUF];
      int j;
      for ( j = 0; j < o_len; j++ )  {
         sprintf(buffer, "%d", tmp[j]);
         writeEntry(buffer, 1, fd);
      }
      sprintf(buffer, "\n");
      writeEntry(buffer, 1, fd);
    }

    else {
      int i;
      for ( i = 0; i < len - 1; i++ )  {
         generate_permutations(len - 1, tmp, o_len, fd);
         int tp;
         if ( len % 2 == 0 )  {
            tp = tmp[i];
            tmp[i] = tmp[len-1];
            tmp[len-1] = tp;
         }
         else  {
            tp = tmp[0];
            tmp[0] = tmp[len-1];
            tmp[len-1] = tp;
         }
      }
      generate_permutations(len - 1, tmp, o_len, fd);
   }
}

void sort_results(int fd, int size)  {
   int a;
   int b;
   int i;
   int j;
   int len = factorial(size);

   char buffer1[BUF];
   char buffer2[BUF];

   for ( i = 0 ; i < len; i++ )  {
      for ( j = 0; j < i; j++ )   {
         m_seek(fd, SEEK_SET, j*(size+1));
         readEntry(buffer1, size+1, fd);
         buffer1[size] = '\0';
         a = atoi(buffer1);
         buffer1[size] = '\n';

         m_seek(fd, SEEK_SET, (j*(size+1)) + size+1);
         readEntry(buffer2, size+1, fd);
         buffer2[size] = '\0';
         b = atoi(buffer2);
         buffer2[size] = '\n';

         if ( a > b ) {
             m_seek(fd, SEEK_SET, j*(size+1));
             writeEntry(buffer2, size+1, fd);
             m_seek(fd, SEEK_SET, (j*(size+1)) + size+1);
             writeEntry(buffer1, size+1, fd);
         }
      }
   }
}

void readEntry(char *string, int size, int fd)  {
   size_t nbytes;
   if ( ( nbytes = read(fd, string, size) ) != size )  {
      perror("Read error");
      close(fd);
      exit(READ_ERR);
   }
}

void writeEntry(char *string, int size, int fd)  {
   size_t nbytes;
   if ( ( nbytes = write(fd, string, size) ) != size )  {
      perror("Write error");
      close(fd);
      exit(WRITE_ERR);
   }
}

size_t m_seek(int fd, int whence, off_t off)  {
   size_t nbytes;
   if ( ( nbytes = lseek(fd, off, whence) ) == -1 )  {
      perror("Seeking error");
      close(fd);
      exit(SEEK_ERR);
   }

   return nbytes;
}
