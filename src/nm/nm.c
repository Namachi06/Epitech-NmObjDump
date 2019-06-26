/*
** EPITECH PROJECT, 2019
** nm.c
** File description:
** nm program
*/

#include "../../include/nm.h"

void init_struct_nm(t_nm *nm, char const *filename)
{
    nm->size = 0;
    nm->filename = filename;
    nm->buff = NULL;
    nm->error = 0;
}

int nm_program(char const *filename, int argc, t_nm *nm)
{
    Elf32_Ehdr *elf;

    init_struct_nm(nm, filename);
    if (map_file(nm) != 0)
        return (nm->error);
    elf = nm->buff;
    if (elf->e_ident[EI_CLASS] == ELFCLASS32) {
        if (arch32(nm, argc) != 0)
            return (nm->error);
    } else {
        if (arch64(nm, argc) != 0)
            return (nm->error);
    }
    return (0);
}