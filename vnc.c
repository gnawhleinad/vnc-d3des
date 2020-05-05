#include <string.h>
#include <stdio.h>

#include "d3des.h"

static unsigned char d3desObfuscationKey[] = {23,82,107,6,35,78,88,7};

int main() {
    char password[256];
    if (! fgets(password, sizeof(password), stdin))
      return -1;

    char obfuscated[8];
    size_t length = strlen(password), i;
    for (i=0; i<8; i++)
      obfuscated[i] = i<length ? password[i] : 0;
    deskey(d3desObfuscationKey, EN0);
    des((unsigned char*)obfuscated, (unsigned char*)obfuscated);
    if (! fwrite(obfuscated, 8, 1, stdout))
      return -1;

    return 0;
}
