/* 
 * This program demonstrates the way to initialize members of a structure. 
 */

#include <stdio.h>

struct student {
    const char *name;
    const char *major;
    int age;
};

struct student anna = {
    .name = "anna",
    .age = 14,
};

int main()
{
    printf("\n========================\n");
    printf  ("    Name: %s\n", anna.name);
    printf  ("     Age: %d\n", anna.age);
    printf  ("========================\n");

    return 0;
}
