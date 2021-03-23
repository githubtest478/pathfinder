#include "libmx.h"

//  int mx_memcmp(const void *s1, const void *s2, size_t n);

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
   if(big_len < little_len 
      || little_len == 0 
      || big_len == 0) {
      return NULL;
   }
   int compe = 0;

    for(size_t i = 0; i < big_len - little_len + 1; ++i) {
      compe = mx_memcmp(little, (char*)big + i, little_len);
     
      if(compe == 0) {
         return ((char*)big + i);
      }
    }
    return NULL;
}

