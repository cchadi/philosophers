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
