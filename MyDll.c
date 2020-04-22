#include <stdio.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>
#include "MyDll.h"

int asciiBinaryToInt(char *s)
{

    int iSize;
    int iAcum = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        iSize = i;
    }
    iSize++;

    for (int i = 0, j = pow(2, iSize - 1); i < iSize; i++, j = j / 2) //check condition
    {

        if (s[i] != 48 && s[i] != 49)
        {
            printf("Error wrong input\n");
            return -1;
        }

        if (s[i] == 49)
        {
            iAcum += j;
        }
    }

    return iAcum;
}

int asciiHEXToInt(char *s)
{

    int iSize;
    for (int i = 0; s[i] != '\0'; i++)
    {
        iSize = i;
    }
    iSize++;

    for (int i = 0; i < iSize; i++)
    {
        if ((s[i] < 48 || s[i] > 57) && (s[i] < 65 || s[i] > 70) && (s[i] < 97 || s[i] > 101))
        {
            printf("Error wrong input\n");
            return -1;
        }
    }

    int number = (int)strtol(s, NULL, 16);

    return number;
}

double asciiToDouble(char *s)
{

    int iSize;
    double dRes;
    int iContP = 0, iContS = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        iSize = i;
    }
    iSize++;

    for (int i = 0; i < iSize; i++)
    {
        if ((s[i] > 57 || s[i] < 48) && (s[i] != '+') && (s[i] != '.') && (s[i] != '-'))
        {
            printf("Error wrong input 1\n");
            return -1;
        }

        if ((s[i] == '+') || (s[i] == '-'))
        {
            if (i != 0)
            {
                printf("Error wrong input 2\n");
                return -1;
            }

            iContS++;
        }

        if (s[i] == '.')
        {

            iContP++;
        }
    }

    if (iContP >= 2 || iContS >= 2)
    {
        printf("Error wrong input 3\n");
        return -1;
    }
    char *ptr;
    dRes = strtod(s, &ptr);

    return dRes;
}

