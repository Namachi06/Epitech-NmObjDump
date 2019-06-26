/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils
*/

#include "../../include/nm.h"

int check_elf32(t_nm *nm, Elf32_Ehdr *elf,  int argc)
{
    elf = nm->buff;
    if (elf->e_ident[EI_MAG0] != ELFMAG0 && elf->e_ident[EI_MAG1] != ELFMAG1
        && elf->e_ident[EI_MAG2] != ELFMAG2 &&
        elf->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "nm: \'%s\': File format not recognized\n",
            nm->filename);
        return (++nm->error);
    }
    if (argc > 2)
        printf("\n%s:\n", nm->filename);
    return (0);
}

int check_elf64(t_nm *nm, Elf64_Ehdr *elf,  int argc)
{
    elf = nm->buff;
    if (elf->e_ident[EI_MAG0] != ELFMAG0 && elf->e_ident[EI_MAG1] != ELFMAG1
        && elf->e_ident[EI_MAG2] != ELFMAG2 &&
            elf->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "nm: \'%s\': File format not recognized\n",
            nm->filename);
        return (++nm->error);
    }
    if (argc > 2)
        printf("\n%s:\n", nm->filename);
    return (0);
}