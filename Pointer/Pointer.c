#include <stdio.h>

int main()
{
    int a = 10;
    int *ptr = &a;

    printf("Dia chi cua ptr _ &ptr = %p\n", &ptr);
    printf("Gia tri cua ptr _ ptr = %p\n", ptr);
    printf("Gia tri ma con tro ptr tro toi _ *ptr = %d\n", *ptr);
    printf("Dia chi cua bien a _ &a = %p\n", &a);
    printf("Gia tri cua bien a _ a = %d\n", a);

    return 0;
}