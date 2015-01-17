#include "rabinkarp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Q 127
#define D 128

int rabin_karp (char* haystack, char* needle) {
    int text_len = strlen (haystack);
    int patt_len = strlen (needle);

    /* return fail if pattern is longer than test text */
    if (patt_len > text_len)
        return -1;
    
    /* h - value of digit "1" in higher-order position of
       a patt_len-digit text region */
    int h = mod_power (D, patt_len - 1, Q);
    /* patter and text region hash */
    int p = 0;
    int t = 0;

    /* number of matches */
    int matches = 0;
    
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
            /* check real matching and increment */
            if (strncmp ((haystack + i), needle, patt_len) == 0) {
                printf ("match found at position: %d \n", i);
                matches++;
            }
        }
        /* shift text region and get its hash */
        t = (D * (t - haystack[i] * h) + haystack[i + patt_len]) % Q;
    }
    
    return matches;
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
