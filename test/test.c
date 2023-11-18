#include <stdio.h>
#include "../ADT/Wordmachine.h"
#include "../ADT/DynamicList.h"

int main() {
    FILE *file = fopen("test.txt", "r");
    char line[100];
    my_getline(line, 100, file);
    DynamicList result = split_to_ints(line);
    print_dynamic_list(&result);
    // deallocate_dynamic_list(result);
    return 0;
}