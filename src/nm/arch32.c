/*
** EPITECH PROJECT, 2019
** arch32.c
** File description:
** Handle nm for 32 bits architecture
*/

#include "../../include/nm.h"

void print_symbols32(t_nm32 *nm32, Elf32_Sym **cpySym,
    long unsigned int size)
{
    for (long unsigned i = 0; i < size; i++) {
        if (cpySym[i]->st_name != 0 && cpySym[i]->st_name != 1) {
            printf("%s\n", &nm32->sym_tab_str[cpySym[i]->st_name]);
        }
    }
}

int get_symbols32(t_nm32 **nm32, t_nm *nm)
{
    for (int i = 0; i < (*nm32)->elf->e_shnum; i++) {
        if ((*nm32)->shdr[i].sh_size != SHT_NOBITS) {
            if (!strcmp(&(*nm32)->str_tab[(*nm32)->shdr[i].sh_name], ".strtab"))
                (*nm32)->sym_str = (Elf32_Shdr *)&(*nm32)->shdr[i];
            if (!strcmp(&(*nm32)->str_tab[(*nm32)->shdr[i].sh_name], ".symtab"))
                (*nm32)->sym_Section = (Elf32_Shdr *)&(*nm32)->shdr[i];
        }
    }
    if ((*nm32)->sym_Section == NULL || (*nm32)->sym_str == NULL) {
        fprintf(stderr, "nm: %s: No symbols\n", nm->filename);
        return (-1);
    }
    (*nm32)->sym_tab = (Elf32_Sym *)((char *)nm->buff +
        (*nm32)->sym_Section->sh_offset);
    (*nm32)->sym_tab_str = (char *)((char *)nm->buff +
        (*nm32)->sym_str->sh_offset);
    return (0);
}

int arch32(t_nm *nm, int argc)
{
    t_nm32 *nm32 = malloc(sizeof(t_nm32));
    Elf32_Sym **cpySym;
    long unsigned size;

    nm32->elf = (Elf32_Ehdr *)nm->buff;
    if (check_elf32(nm, nm32->elf, argc) != 0)
        return (++nm->error);
    nm32->shdr = (Elf32_Shdr *)(nm->buff + nm32->elf->e_shoff);
    nm32->str_tab = (char *)(nm->buff +
        nm32->shdr[nm32->elf->e_shstrndx].sh_offset);
    if (get_symbols32(&nm32, nm) != 0)
        return (++nm->error);
    sort_symbols32(nm32, &cpySym, &size);
    print_symbols32(nm32, cpySym, size);
    free(cpySym);
    return (0);
}