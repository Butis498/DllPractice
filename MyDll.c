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

double asciiToDouble(char *s){
   
    double answer = 0.0;
    int length = strlen(s);
    int counter= 0;
    int decimalCounter = 0;
    bool decimal = false;
    bool negative = false;
    int exponent = 0;
    while(!decimal && decimalCounter < length){
        if(*s == 46){
            decimal = true;
        }
        else{
            decimalCounter++;
        }
        s++;
    }
    for(int counter = decimalCounter; counter >= 0 ; counter--){
        s--;
    }
    exponent = decimalCounter;
    counter = 0;
    if(length = decimalCounter){
        exponent--;
    }
    if(*s == 43){
        exponent--;
        s++;
        counter++;
    }
    else if(*s == 45){
        s++;
        counter++;
        exponent--;
        negative = true;
    }
    for(counter; counter < decimalCounter; counter++){
        answer += (*s - 48) * pow(10, exponent);
        exponent--;
        s++;
    }
    counter = 0;
    s++;
    exponent = -1;
    for(counter = decimalCounter + 1 ; counter < length; counter++){
        answer += (*s - 48) * pow(10, (exponent));
        exponent--;
        s++;
    }
    if(negative){
        answer *= -1;
    }
    return answer;
}