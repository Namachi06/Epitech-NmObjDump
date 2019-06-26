/*
** EPITECH PROJECT, 2019
** arch64.c
** File description:
** Architeture 64
*/

#include "../../include/objdump.h"

int arch64(t_obj *obj)
{
    t_obj64 *obj64 = malloc(sizeof(t_obj64));

    obj64->elf = (Elf64_Ehdr *)obj->buff;
    if (check_elf64(obj, obj64->elf) != 0)
        return (++obj->error);
    obj64->shdr = (Elf64_Shdr *)(obj->buff + obj64->elf->e_shoff);
    obj64->str_tab = (char *)(obj->buff +
        obj64->shdr[obj64->elf->e_shstrndx].sh_offset);
    print_header_name64(obj64, obj);
    print_sections64(obj64);
    return (0);
}
