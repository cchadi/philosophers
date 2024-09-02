#include "philosophers.h"

int main(int ac, char **av)
{
    if (ac >= 5 && ac <= 6)
    {
        ft_start(parsing(av));
    }
    else
        write(2, "invalid arguments!\n", 20);
    return (0);
}


void test()
{
    // data d1; //(mutex m1)
    // data d2; //(mutex m1)
    
    // thread
    // lock(d1->m1)
    // d2->v1 = 1
    // unlock(d1->m1)
}