#include <stdio.h>
#include "../ADT/Wordmachine.h"
#include "../ADT/DynamicList.h"

int main() {
    char *s = "azmi 123";
    size_t length;
    my_strlen(s, &length);

    int l = length - 1;
    while (l-1 >= 0 && '0' <= s[l-1] && s[l-1] <= '9') --l;

    char *name = malloc(l * sizeof(name));
    name[l-1] = '\0';
    for (int i = 0; i < l-1; ++i) {
        name[i] = s[i];
    }


    int num = 0;
    for (int i = l; i < length; ++i) {
        num = 10 * num + (s[i] - '0');
    }
    printf("l is %d\nnum is %d\nname is (%s)\n", l, num, name);

    return 0;
}