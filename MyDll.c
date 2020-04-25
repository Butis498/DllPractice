#include <stdio.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>
#include "MyDll.h"
#include<stdlib.h>

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

float asciiToDouble(char *s)
{
    float val;
    char str[20];

    strcpy(str, s);
    val = (float)atof(str);
    return val;
}