#include "Philo.h"

int erreur_case(int erreur_num, int arg_num)
{
    if (erreur_num == 1)
    {
        printf("Le nombre d'argument est invalide\n");
        printf("Veuillez en fournir entre 4 et 5\n");
    }
    else if (erreur_num == 2)
        printf("L'argument suivant contient des caractères invalides : %d\n", arg_num);
    else if (erreur_num == 3)
        printf("L'argument suivant est hors interger : %d\n", arg_num);
    else if (erreur_num == 4)
    {
        if (nul_var(arg_num) == 0)
            return (0);
    }
    else if (erreur_num == 5)
        printf("Une erreur innatendue est survenue\n");
    else if (erreur_num == 6)
        printf("Le nombre de philosophe est invalide\n");
    return (1);
}

int nul_var(int arg_num)
{
    if (arg_num == 1)
        printf("Le spaghet est frette vu que personne est là\n");
    else if (arg_num == 2)
        printf("Quelqu'un veut une mort subite...\n");
    else if (arg_num == 3)
        printf("Simulation infinie par suffisance télépathique\n");
    else if (arg_num == 4)
        return (0);
    else if (arg_num == 5)
        printf("S't'un beau spaghet ça!\n");
    return (1);
}