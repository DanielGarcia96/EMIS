#include "profile.h"

int main(int argc, char *argv[])
{
    FILE *datafile = fopen("profiles.txt", "r");

    profilelist *plist = allocateProfile();
    loadProfiles(datafile, plist);

    printProfile(plist, -1);

    freeProfiles(plist);
    fclose(datafile);
    return 0;
}
