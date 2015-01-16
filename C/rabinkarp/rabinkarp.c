#include "rabinkarp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Q 127
#define D 127

void rabin_karp (char* haystack, char* needle) {
    int text_len = strlen (haystack);
    int patt_len = strlen (needle);
    /* h - value of digit "1" in higher-order position of
       an patt_len-digit text region */
    int h = mod_power (D, patt_len - 1, Q);
    /* patter and text region hash */
    int p = 0;
    int t = 0;
    
    int i;

    /* calculating initial hashes */
    for (i = 0; i < patt_len; i++) {
        p = (D * p + needle[i]) % Q;
        t = (D * t + haystack[i]) % Q;
    }

    /* processing all haystack */
    for (i = 0; i <= text_len - patt_len; i++) {
        /* if pattern hash matches current text region hash */
        if (p == t) {
            /* check for matching and show a position of current match */
            if (strncmp ((haystack + i), needle, patt_len) == 0)
                printf ("match found at position: %d \n", i);
        }
        /* shift text region and get its hash */
        t = (D * (t - haystack[i] * h) + haystack[i + patt_len]) % Q;
    }
}

/* Exponentation by squaring */
int mod_power (int num, int pow, int mod) {
    int res = 1;
    while (pow) {
        if (pow % 2) {
            res = res * num % mod;
            pow--;
        }
        num = num * num % mod;
        pow /= 2;
    }

    return res;
}
