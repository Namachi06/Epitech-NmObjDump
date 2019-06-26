/*
** EPITECH PROJECT, 2019
** arch64.c
** File description:
** arch64
*/

#include "../../include/nm.h"

void print_symbols64(t_nm64 *nm64, Elf64_Sym **cpySym,
    long unsigned int size)
{
    for (long unsigned i = 0; i < size; i++) {
        if (cpySym[i]->st_name != 0 && cpySym[i]->st_name != 1) {
            printf("%s\n", &nm64->sym_tab_str[cpySym[i]->st_name]);
        }
    }
}

int get_symbols64(t_nm64 **nm64, t_nm *nm)
{
    for (int i = 0; i < (*nm64)->elf->e_shnum; i++) {
        if ((*nm64)->shdr[i].sh_size != SHT_NOBITS) {
            if (!strcmp(&(*nm64)->str_tab[(*nm64)->shdr[i].sh_name], ".strtab"))
                (*nm64)->sym_str = (Elf64_Shdr *)&(*nm64)->shdr[i];
            if (!strcmp(&(*nm64)->str_tab[(*nm64)->shdr[i].sh_name], ".symtab"))
                (*nm64)->sym_Section = (Elf64_Shdr *)&(*nm64)->shdr[i];
        }
    }
    if ((*nm64)->sym_str == NULL || (*nm64)->sym_Section == NULL) {
        fprintf(stderr, "nm: %s: No symbols\n", nm->filename);
        return (-1);
    }
    (*nm64)->sym_tab = (Elf64_Sym *)((char *)nm->buff +
        (*nm64)->sym_Section->sh_offset);
    (*nm64)->sym_tab_str = (char *)((char *)nm->buff +
        (*nm64)->sym_str->sh_offset);
    return (0);
}

int arch64(t_nm *nm, int argc)
{
    t_nm64 *nm64 = malloc(sizeof(t_nm64));
    Elf64_Sym **cpySym;
    long unsigned size;

    nm64->elf = (Elf64_Ehdr *)nm->buff;
    if (check_elf64(nm, nm64->elf, argc) != 0)
        return (++nm->error);
    nm64->shdr = (Elf64_Shdr *)(nm->buff + nm64->elf->e_shoff);
    nm64->str_tab = (char *)(nm->buff +
        nm64->shdr[nm64->elf->e_shstrndx].sh_offset);
    if (get_symbols64(&nm64, nm) != 0)
        return (++nm->error);
    sort_symbols64(nm64, &cpySym, &size);
    print_symbols64(nm64, cpySym, size);
    free(cpySym);
    return (0);
}
