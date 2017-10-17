#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void sprintf_test()
{
    char *ch1 = "abcd\0efg";
    char *ch2 = "hijk  lmn";
    char ch3[100] = {'\0'};

    sprintf(ch3, "%s%s", ch1, ch2);

    printf("%s\n", ch3);
}

void strcat_test()
{
    char ch1[100] = "abcde\0fg";
    char *ch2 = "hijk  lmn";

    strcat(ch1,ch2);

    printf("%s\n", ch1);
}

int main()
{
    //sprintf_test();

    strcat_test();

    return 0;
}
