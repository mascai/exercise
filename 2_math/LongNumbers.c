#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add(int *num1, int *num2, int len1, int len2)
{
    int *rezult, over = 0, i;
    rezult = (int*)malloc((len1 + 1) * sizeof(int));
    for(i = 0; i < len1; i++)
    {
        if (i >= len1) rezult[i] = num2[i] + over;
        else if (i >= len2) rezult[i] = num1[i] + over;
        else rezult[i] = num1[i] + num2[i] + over;
        over = 0;
        if (rezult[i] > 9)
        {
            rezult[i] -= 10;
            over++;
        }
    }
    if (over) printf("%d", over);
    for(i = len1 - 1; i >= 0; i--) printf("%d", rezult[i]);
    free(rezult);
    return;
}

void subtract(int *num1, int *num2, int len1, int len2, int flag)
{
    int *rezult, under = 0, i, t = 0;
    rezult = (int*)malloc(len1 * sizeof(int));
    for(i = 0; i < len1; i++)
    {
        if (i >= len2) rezult[i] = num1[i] - under;
        else rezult[i] = num1[i] - num2[i] - under;
        under = 0;
        if (rezult[i] < 0)
        {
            rezult[i] += 10;
            under++;
        }
    }
    if (flag) putchar('-');
    for(i = len1 - 1; i >= 0; i--)
        if(!rezult[i]) t++;
        else break;
    for(i = len1 - 1 - t; i >= 0; i--) printf("%d", rezult[i]);
    free(rezult);
    return;
}

void multiply(int *num1, int *num2, int len1, int len2)
{
    int *rezult, over = 0, i, t = 0, k;
    rezult = (int*)malloc((len1 + len2) * sizeof(int));
    for (k = 0; k < len1 + len2; k++) rezult[k] = 0;
    for (i = 0; i < len2; i++)
    {
        for (k = 0; k < len1; k++)
        {
            rezult[k + t] += (num1[k] * num2[i] + over);
            over = rezult[k + t] / 10;
            rezult[k + t] %= 10;
        }
        if (over) rezult[k + t] += over;
        over = 0;
        t++;
    }
    for(i = len1 + len2 - 1; i >= 0; i--)
        if ((i != len1 + len2 - 1) || rezult[i])printf("%d", rezult[i]);
    free(rezult);
    return;
}

int main(void)
{
    char s1[10001], s2[10001];
    int *num1, *num2, operation, len1, len2, i, index1 = -1, index2 = -1, flag = 0;
    scanf ("%[^+*-]", s1);
    operation = getchar();
    scanf ("%s", s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    if (strcmp(s1, s2) < 0)
    {
        char tmp[10001];
        strcpy(tmp, s2);
        strcpy(s2, s1);
        strcpy(s1, tmp);
        len1 ^= len2;
        len2 ^= len1;
        len1 ^= len2;
        flag = 1;
    }

    num1 = (int*)malloc(len1 * sizeof(int));
    num2 = (int*)malloc(len2 * sizeof(int));
    for(i = len1 - 1; i >= 0; i--)
    {
        index1++;
        num1[index1] = s1[i] - '0';
    }
    for(i = len2 - 1; i >= 0; i--)
    {
        index2++;
        num2[index2] = s2[i] - '0';
    }
    if (operation == '+') add(num1, num2, len1, len2);
    if (operation == '-')
    {
        if(!strcmp(s1, s2)) printf("0");
        else subtract(num1, num2, len1, len2, flag);
    }
    if (operation == '*')
    {
        if (s2[0] == '0') printf("0");
        else multiply(num1, num2, len1, len2);
    }
    free(num1);
    free(num2);
    return 0;
}

