#include "../philosophers.h"

long    get_current()
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == 0)
        return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    else
        perror("gettimeofday");
    return (-1);
}


