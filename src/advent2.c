/*
 ============================================================================
 Name        : advent2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

char strs[1000][27];

int main(void)
{
    uint32_t letters[26];
//    uint32_t twos = 0, threes = 0;
    uint32_t index1 = 0,index2;

    FILE * input;

    memset(strs, 0, sizeof(strs));
    input = fopen("input.txt", "r");
    if (input)
    {
        int c;
        do
        {
            index2 = 0;
//            memset(letters, 0, sizeof(letters));
            do
            {
                c = fgetc(input);
                if (c < 0)
                {
                    break;
                }
                if ( c == '\n' )
                {
                    break;
                }
                strs[index1][index2++] = c;
//                letters[c-'a']++;
            } while (1);
            index1++;
            if (c < 0)
            {
                break;
            }
//            bool twofind = true, threefind = true;
//            for (int i = 0; i < 26; i++)
//            {
//                if (twofind && (letters[i] == 2))
//                {
//                    twos++;
//                    twofind = false;
//                }
//                if (threefind && (letters[i] == 3))
//                {
//                    threes++;
//                    threefind = false;
//                }
//            }
        } while (1);

        fclose(input);

        for (int i = 0; i < index1; i++)
        {
            for (int j = 0; j < index1; j++)
            {
                int diff = 0;
                for (int k = 0; k < 26; k++)
                {
                    if (strs[i][k] != strs[j][k])
                    {
                        diff++;
                    }
                }
                if (diff == 1)
                {
                    printf("%s\n%s\n", strs[i], strs[j]);
                    return 0;
                }
            }
        }


//        printf("%i * %i = %i\n", twos, threes, twos*threes);


        return 0;
    }
    return 1;
}
