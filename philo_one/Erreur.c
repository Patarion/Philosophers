#include "Philo.h"

int erreur_case(int erreur_num)
{
    if (erreur_num == 1)
    {
        write_error(1);
        return(1);
    }
    else if (erreur_num == 2)
    {
        write_error(2);
        return(1);
    }
    return(0);
}

void write_error(int erreur_num)
{
    write(2, "Error: ", 7);
    if (erreur_num == 1)
        write(2, "At least one wrong argument\n", 28);
    else if (erreur_num == 2)
        write(2, "Fatal error when initializing mutex\n", 36);
}