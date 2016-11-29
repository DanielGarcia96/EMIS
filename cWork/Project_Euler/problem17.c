#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    unsigned int sum = 0;
    for(i=1; i<=999; i++)
    {
        char num_str[10];
        int hold_sum = 0;
        sprintf(num_str, "%d", i);
        if(strlen(num_str) == 3)
        {
            hold_sum += 7;
            switch(num_str[0])
            {
                case '1': hold_sum += 3;
                break;
                case '2': hold_sum += 3;
                break;
                case '3': hold_sum += 5;
                break;
                case '4': hold_sum += 4;
                break;
                case '5': hold_sum += 4;
                break;
                case '6': hold_sum += 3;
                break;
                case '7': hold_sum += 5;
                break;
                case '8': hold_sum += 5;
                break;
                case '9': hold_sum += 4;
                break;
            }
        }
        if((strlen(num_str) == 3) &&
           (strcmp(num_str, "100") == 0 ||
            strcmp(num_str, "200") == 0 ||
            strcmp(num_str, "300") == 0 ||
            strcmp(num_str, "400") == 0 ||
            strcmp(num_str, "500") == 0 ||
            strcmp(num_str, "600") == 0 ||
            strcmp(num_str, "700") == 0 ||
            strcmp(num_str, "800") == 0 ||
            strcmp(num_str, "900") == 0)) 
            {
                printf("%d's sum = %d\n", i, hold_sum);
                sum += hold_sum;
                continue;
            }
        else if(strlen(num_str) == 3)
            hold_sum += 3;

        if(strlen(num_str) > 1 && num_str[strlen(num_str)-1] == '0') 
            {
                switch(num_str[strlen(num_str)-2])
                {
                    case '1': hold_sum += 3;
                    break;
                    case '2': hold_sum += 6;
                    break;
                    case '3': hold_sum += 6;
                    break;
                    case '4': hold_sum += 5;
                    break;
                    case '5': hold_sum += 5;
                    break;
                    case '6': hold_sum += 5;
                    break;
                    case '7': hold_sum += 7;
                    break;
                    case '8': hold_sum += 6;
                    break;
                    case '9': hold_sum += 6;
                    break;
                }
                printf("%d's sum = %d\n", i, hold_sum);
                sum += hold_sum;
                continue;
            }
        if(strlen(num_str) > 1)
        {
            if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '1')
                hold_sum += 6;
            else if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '2')
                hold_sum += 6;
            else if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '3')
                hold_sum += 8;
            else if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '4')
                hold_sum += 8;
            else if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '5')
                hold_sum += 7;
            else if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '6')
                hold_sum += 7;
            else if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '7')
                hold_sum += 9;
            else if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '8')
                hold_sum += 9;
            else if(num_str[strlen(num_str)-2] == '1' && num_str[strlen(num_str)-1] == '9')
                hold_sum += 8;
            else
            {
                switch(num_str[strlen(num_str)-1])
                {

                    case '1': hold_sum += 3;
                    break;
                    case '2': hold_sum += 3;
                    break;
                    case '3': hold_sum += 5;
                    break;
                    case '4': hold_sum += 4;
                    break;
                    case '5': hold_sum += 4;
                    break;
                    case '6': hold_sum += 3;
                    break;
                    case '7': hold_sum += 5;
                    break;
                    case '8': hold_sum += 5;
                    break;
                    case '9': hold_sum += 4;
                    break; 
                }
                switch(num_str[strlen(num_str)-2])
                {
                    case '2': hold_sum += 6;
                    break;
                    case '3': hold_sum += 6;
                    break;
                    case '4': hold_sum += 5;
                    break;
                    case '5': hold_sum += 5;
                    break;
                    case '6': hold_sum += 5;
                    break;
                    case '7': hold_sum += 7;
                    break;
                    case '8': hold_sum += 6;
                    break;
                    case '9': hold_sum += 6;
                    break;
                }
            }
        }
        if(strlen(num_str) == 1)
        {
            switch(num_str[0])
            {
                case '1': hold_sum += 3;
                break;
                case '2': hold_sum += 3;
                break;
                case '3': hold_sum += 5;
                break;
                case '4': hold_sum += 4;
                break;
                case '5': hold_sum += 4;
                break;
                case '6': hold_sum += 3;
                break;
                case '7': hold_sum += 5;
                break;
                case '8': hold_sum += 5;
                break;
                case '9': hold_sum += 4;
                break;
            }
        }
        printf("%d's sum = %d\n", i, hold_sum);
        sum += hold_sum;
    }

    printf("1000's sum = %d\n", 11);
    sum += 11;

    printf("%d\n", sum);
    return 0;
}
