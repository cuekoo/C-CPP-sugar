#include <stdio.h>

void init_1(void) {
    printf("this is init_1\n");
}

void init_2(void) {
    printf("this is init_2\n");
}

/* func_list is an array of pointers to function void f(void) */
void (*func_list[])(void) = {
   init_1,
   init_2
};

int main()
{
    for (int i = 0; func_list[i]; i++) 
        func_list[i]();
}
