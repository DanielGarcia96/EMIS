#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE    30
#define LOC_SIZE     40
#define PSY_SIZE     200

#define ERR_SEARCH   808

/* Easily referenced enum for sexes */
enum sex {male, female};
typedef enum sex sex;


/* Profile structure */
struct profile {
    int  iAge;
    int  iIQ;
    sex  eSex;
    char szFName[NAME_SIZE];
    char szMName[NAME_SIZE];
    char szLName[NAME_SIZE];
    char szCity[LOC_SIZE];
    char szCountry[LOC_SIZE];
    char szPsy[PSY_SIZE];
};
typedef struct profile profile;


/* Linked list structure for profiles */
struct profilelist {
    int iIndex;
    profile profile;
    struct profilelist *next;
};
typedef struct profilelist profilelist;


void loadProfiles(FILE *datafile, profilelist *plist);
profilelist *allocateProfile(void);
void removeProfile(profilelist *plist, int index);
void freeProfiles(profilelist *plist);
void printProfile(profilelist *plist, int index);
void preccpy(char *dest, char *src, int begin, int end);
//int  searchProfile(profilelist *profilelist, void *param, char *type);
