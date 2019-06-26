/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main programm
*/

#include "../../include/objdump.h"

int main(int argc, char const *argv[])
{
    t_obj *obj = malloc(sizeof(t_obj));
    obj->error = 0;

    if (argc == 1) {
        obj->error = objdump_program("a.out", obj);
    } else if (argc == 2) {
        obj->error = objdump_program(argv[1], obj);
    } else {
        for (int i = 1; i < argc; i++)
            objdump_program(argv[i], obj);
    }
    if (obj->error != 0)
        return (84);
    return (0);
}
