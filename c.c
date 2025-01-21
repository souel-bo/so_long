#include "so_long.h"

void ft_ft(int *p)
{
    *p = 0;
}
int main()
{
    int a = 5;
    int *p = &a;
    printf("%d\n", a);
    ft_ft(p);
    printf("%d\n", a);
}