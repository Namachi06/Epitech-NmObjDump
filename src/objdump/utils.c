/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils
*/

#include "../../include/objdump.h"

int check_elf32(t_obj *obj, Elf32_Ehdr *elf)
{
    elf = obj->buff;
    if (elf->e_ident[EI_MAG0] != ELFMAG0 && elf->e_ident[EI_MAG1] != ELFMAG1
        && elf->e_ident[EI_MAG2] != ELFMAG2 &&
        elf->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "objdump: \'%s\': File format not recognized\n",
            obj->filename);
        return (++obj->error);
    }
    return (0);
}

int check_elf64(t_obj *obj, Elf64_Ehdr *elf)
{
    elf = obj->buff;
    if (elf->e_ident[EI_MAG0] != ELFMAG0 && elf->e_ident[EI_MAG1] != ELFMAG1
        && elf->e_ident[EI_MAG2] != ELFMAG2
        && elf->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "objdump: \'%s\': File format not recognized\n",
            obj->filename);
        return (++obj->error);
    }
    return (0);
}

int is_obj_section64(t_obj64 *obj64, int i)
{
    int result1, result2, result3, result4;

    result1 = strcmp(&obj64->str_tab[obj64->shdr[i].sh_name], ".strtab");
    result2 = strcmp(&obj64->str_tab[obj64->shdr[i].sh_name], ".symtab");
    result3 = strcmp(&obj64->str_tab[obj64->shdr[i].sh_name], ".shstrtab");
    result4 = strcmp(&obj64->str_tab[obj64->shdr[i].sh_name], ".bss");
    if (result1 && result2&& result3 && result4)
        return (0);
    return (-1);
}

int is_obj_section32(t_obj32 *obj32, int i)
{
    int result1, result2, result3, result4;

    result1 = strcmp(&obj32->str_tab[obj32->shdr[i].sh_name], ".strtab");
    result3 = strcmp(&obj32->str_tab[obj32->shdr[i].sh_name], ".symtab");
    result2 = strcmp(&obj32->str_tab[obj32->shdr[i].sh_name], ".shstrtab");
    result4 = strcmp(&obj32->str_tab[obj32->shdr[i].sh_name], ".bss");
    if (result1 && result2&& result3 && result4)
        return (0);
    return (-1);
}