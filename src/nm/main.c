/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main programm
*/

#include "../../include/nm.h"

int main(int argc, char const *argv[])
{
    t_nm *nm = malloc(sizeof(t_nm));
    nm->error = 0;

    if (argc == 1) {
        nm->error = nm_program("a.out", argc, nm);
    } else if (argc == 2) {
        nm->error = nm_program(argv[1], argc, nm);
    } else {
        for (int i = 1; i < argc; i++)
            nm_program(argv[i], argc, nm);
    }
    if (nm->error != 0)
        return (84);
    return (0);
}
