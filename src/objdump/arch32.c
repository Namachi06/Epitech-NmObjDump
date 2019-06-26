/*
** EPITECH PROJECT, 2019
** arch32.c
** File description:
** Architecture 32
*/

#include "../../include/objdump.h"

int arch32(t_obj *obj)
{
    t_obj32 *obj32 = malloc(sizeof(t_obj32));

    obj32->elf = (Elf32_Ehdr *)obj->buff;
    if (check_elf32(obj, obj32->elf) != 0)
        return (++obj->error);
    obj32->shdr = (Elf32_Shdr *)(obj->buff + obj32->elf->e_shoff);
    obj32->str_tab = (char *)(obj->buff +
        obj32->shdr[obj32->elf->e_shstrndx].sh_offset);
    print_header_name32(obj32, obj);
    print_sections32(obj32);
    return (0);
}