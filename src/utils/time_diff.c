#include "philo.h"

float	time_diff(struct timeval *start, struct timeval *end)
{
    return ((end->tv_usec - start->tv_usec));
}