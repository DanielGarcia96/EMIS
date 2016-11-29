#include "profile.h"

#define DEBUG 0

profilelist *allocateProfile(void)
{
    profilelist *plist;
    plist = (profilelist *) malloc(sizeof(profilelist));
    plist->next = NULL;
    return plist;
}

void loadProfiles(FILE *datafile, profilelist *plist)
{
    if(DEBUG) {
        printf("Loading profiles\n\n");
    }
    int cycle = 0;
    profilelist *start = plist;
    int endfile = feof(datafile);
    char buffer[202];

    while(!endfile) {
        int dsex;
        switch(cycle) {
            case 0:
                fgets(buffer, 202, datafile);
                sscanf(buffer, "%s %s %s", 
                                plist->profile.szFName,
                                plist->profile.szMName,
                                plist->profile.szLName);
                endfile = feof(datafile);
                if(DEBUG) {
                    printf("Cycle: %d\n", cycle);
                    printf("EOF: %d\n\n", endfile);
                }
                cycle++;
                break;
            case 1:
                fgets(buffer, 202, datafile);
                sscanf(buffer, "%d %d %d", 
                               &plist->profile.iAge,
                               &plist->profile.iIQ, 
                               &dsex);
                sex finalsex = (dsex == 0) ? male : female;
                plist->profile.eSex = finalsex;
                endfile = feof(datafile);
                if(DEBUG) {
                    printf("Cycle: %d\n", cycle);
                    printf("EOF: %d\n\n", endfile);
                }
                cycle++;
                break;
            case 2:
                fgets(buffer, 202, datafile);
                strncpy(plist->profile.szCity,
                        buffer,
                        (int)(strchr(buffer, ',') - buffer));
                preccpy(plist->profile.szCountry,
                        buffer,
                        (int)(strchr(buffer, ',') - buffer)+2,
                        strlen(buffer)-1);
                endfile = feof(datafile);
                if(DEBUG) {
                    printf("Cycle: %d\n", cycle);
                    printf("EOF: %d\n\n", endfile);
                }
                cycle++;
                break;
            case 3:
                fgets(plist->profile.szPsy,
                       PSY_SIZE, datafile);
                endfile = feof(datafile);
                if(DEBUG) {
                    printf("Cycle: %d\n", cycle);
                    printf("EOF: %d\n\n", endfile);
                }
                cycle++;
                break;
            default:
                cycle = 0;
                fgets(buffer, 202, datafile);
                endfile = feof(datafile);
                if(endfile)
                    break;

                plist->next= (struct profilelist *) 
                                 allocateProfile();
                plist = (profilelist *) plist->next;
        }
    }

    plist = start;
    fseek(datafile, 0, 0);
}

void printProfile(profilelist *plist, int index)
{
    int i;
    profilelist *start = plist;

    switch(index) {
        case -1:
            while(plist != NULL) {
                printf("First Name: %s\n",
                                    plist->profile.szFName);
                printf("Middle Name: %s\n",
                                    plist->profile.szMName);
                printf("Last Name: %s\n", 
                                    plist->profile.szLName);
                printf("Age: %d\n", plist->profile.iAge);
                printf("IQ: %d\n", plist->profile.iIQ);
                printf("Sex: %s\n", 
                plist->profile.eSex == male ? "male": "female");
                printf("City: %s\n", plist->profile.szCity);
                printf("Country: %s\n", 
                                     plist->profile.szCountry);
                printf("Psyche: %s\n", plist->profile.szPsy);

                plist = (profilelist *)
                              plist->next;
            }
            break;
        default:
            for(i = 0; i<index; i++)
                plist = (profilelist *) plist->next;

            printf("First Name: %s\n", plist->profile.szFName);
            printf("Middle Name: %s\n", plist->profile.szMName);
            printf("Last Name: %s\n", plist->profile.szLName);
            printf("Age: %d\n", plist->profile.iAge);
            printf("IQ: %d\n", plist->profile.iIQ);
            printf("Sex: %s\n", plist->profile.eSex == male ? "male": "female");
            printf("City: %s\n", plist->profile.szCity);
            printf("Country: %s\n", plist->profile.szCountry);
            printf("Psyche: %s\n", plist->profile.szPsy);
    }

    plist = start;
}

void removeProfile(profilelist *plist, int index)
{
    profilelist *start = plist;

    int i;
    for(i=0; i<index-1; i++)
        plist = (profilelist *) plist->next;

    profilelist *tmp = (profilelist *) plist->next;
    plist->next = plist->next->next;

    free(tmp);
    plist = start;
}

void freeProfiles(profilelist *plist)
{
    while(plist != NULL) {
        profilelist *tmp = plist;
        plist = (profilelist *) plist->next;
        free(tmp);
    }
    free(plist);
}

void preccpy(char *dest, char *src, int begin, int end)
{
    int i;
    for(i = begin; i<end; i++)
        dest[i-begin] = src[i];

    dest[i] = '\0';
}

/*int searchProfile(profilelist *plist, void *param, char *type)
{
    if(strcmp(type, "age") == 0) {

    }
    else if(strcmp(type, "sex") == 0) {

    }
    else if(strcmp(type, "IQ") == 0
            strcmp(type, "intelligence quotient") == 0) {
        int *IQ = (int *) param;
    }
    else if(strcmp(type, "first name") == 0) {

    }
    else if(strcmp(type, "second name") == 0) {

    }
    else if(strcmp(type, "last name") == 0) {

    }
    else if(strcmp(type, "city") == 0) {

    }
    else if(strcmp(type, "country") == 0) {

    }
    else if(strcmp(type, "pysche") == 0) {

    }
    else {
        return ERR_SEARCH;
    }
}*/
