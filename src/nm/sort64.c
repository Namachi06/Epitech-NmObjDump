/*
** EPITECH PROJECT, 2019
** sort64.c
** File description:
** Sort symbols
*/

#include "../../include/nm.h"

Elf64_Sym **cpy_symbols64(t_nm64 *nm64, Elf64_Sym **cpySym,
    long unsigned size)
{
    cpySym = malloc(sizeof(*cpySym) * size + 1);
    for (long unsigned i = 0; i < size; i++)
        cpySym[i] = &nm64->sym_tab[i];
    return (cpySym);
}

void swap64(long unsigned i, long unsigned j,
    t_nm64 *nm64, Elf64_Sym ***cpySym)
{
    Elf64_Sym *temp;
    if (strcmp(&nm64->sym_tab_str[(*cpySym)[i]->st_name],
        &nm64->sym_tab_str[(*cpySym)[j]->st_name]) > 0) {
        temp = (*cpySym)[i];
        (*cpySym)[i] = (*cpySym)[j];
        (*cpySym)[j] = temp;
    }
}

void sort_symbols64(t_nm64 *nm64, Elf64_Sym ***cpySym,
    long unsigned *size)
{
    *size = nm64->sym_Section->sh_size / sizeof(*nm64->sym_tab);

    *cpySym = cpy_symbols64(nm64, *cpySym, *size);
    for (long unsigned i = 0; i < *size - 1; i++) {
        for (long unsigned j = i + 1; j < *size; j++) {
            swap64(i, j, nm64, &(*cpySym));
        }
    }
}