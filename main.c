#include <windows.h>
#include <stdio.h>

typedef double (*MyFunc)(char *);
typedef int (*MyFunc2)(char *);

int main(int argc, char const *argv[])
{
    HINSTANCE hinst;
    MyFunc asciiToDouble;
    MyFunc2 asciiHEXToInt, asciiBinaryToInt;

    hinst = LoadLibrary("MyDll.dll");
    if (!hinst)
    {
        printf("Error  dll not found\n");
        return 0;
    }

    asciiBinaryToInt = (MyFunc2)GetProcAddress(hinst, "asciiBinaryToInt");
    asciiHEXToInt = (MyFunc2)GetProcAddress(hinst, "asciiHEXToInt");
    asciiToDouble = (MyFunc)GetProcAddress(hinst, "asciiToDouble");

    int res = asciiBinaryToInt("1001101");
    int res2 = asciiHEXToInt("23F");
    double resDouble = asciiToDouble("+3.6");


    printf("Numero binario a decimal res = %i\n", res);
    printf("Numero hexadecimal a decimal res = %i\n", res2);
    printf("String a decimal res = %lf\n", resDouble);

    FreeLibrary(hinst);

    return 0;
}
