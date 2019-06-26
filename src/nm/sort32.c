/*
** EPITECH PROJECT, 2019
** sort32.c
** File description:
** Sort symbols
*/

#include "../../include/nm.h"

Elf32_Sym **cpy_symbols32(t_nm32 *nm32, Elf32_Sym **cpySym,
    long unsigned size)
{
    cpySym = malloc(sizeof(*cpySym) * size + 1);
    for (long unsigned i = 0; i < size; i++)
        cpySym[i] = &nm32->sym_tab[i];
    return (cpySym);
}

void swap32(long unsigned i, long unsigned j, t_nm32 *nm32,
    Elf32_Sym ***cpySym)
{
    Elf32_Sym *temp;
    if (strcmp(&nm32->sym_tab_str[(*cpySym)[i]->st_name],
        &nm32->sym_tab_str[(*cpySym)[j]->st_name]) > 0) {
        temp = (*cpySym)[i];
        (*cpySym)[i] = (*cpySym)[j];
        (*cpySym)[j] = temp;
    }
}

void sort_symbols32(t_nm32 *nm32, Elf32_Sym ***cpySym,
    long unsigned *size)
{
    *size = nm32->sym_Section->sh_size / sizeof(*nm32->sym_tab);

    *cpySym = cpy_symbols32(nm32, *cpySym, *size);
    for (long unsigned i = 0; i < *size - 1; i++) {
        for (long unsigned j = i + 1; j < *size; j++) {
            swap32(i, j, nm32, &(*cpySym));
        }
    }
}