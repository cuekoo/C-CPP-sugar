#include <stdio.h>

void call_func(void (*func_p)(void)) {
    func_p();
}

void foo(){
    printf("hello from foo()!\n");
}

int main()
{
    call_func(foo);
    return 0;
}
