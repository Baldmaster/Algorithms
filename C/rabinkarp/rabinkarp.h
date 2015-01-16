/************************************************************
  Rabin-Karp algorithm.

  Skupoy Sergey. sergey.archlinux@gmail.com, 2015
 ************************************************************/

#ifndef RABINKARP_H
#define RABINKARP_H


/************************************************************
 Looking for a needle in haystack :)
 ************************************************************/
void rabin_karp (char* haystack, char* needle);

/************************************************************
  Exponentation by squaring, result returns by modulo "mod".
 ************************************************************/
int mod_power (int num, int pow, int mod);



#endif
