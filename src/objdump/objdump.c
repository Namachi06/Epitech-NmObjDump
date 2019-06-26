/*
** EPITECH PROJECT, 2019
** objdump.c
** File description:
** objdump program
*/

#include "../../include/objdump.h"

void init_struct_obj(t_obj *obj, char const *filename)
{
    obj->size = 0;
    obj->filename = filename;
    obj->buff = NULL;
    obj->error = 0;
}

int objdump_program(char const *filename, t_obj *obj)
{
    Elf32_Ehdr *elf;

    init_struct_obj(obj, filename);
    if (map_file(obj) != 0)
        return (obj->error);
    elf = obj->buff;
    if (elf->e_ident[EI_CLASS] == ELFCLASS32) {
        if (arch32(obj) != 0)
            return (obj->error);
    } else {
        if (arch64(obj) != 0)
            return (obj->error);
    }
    munmap(obj->buff, obj->size);
    close(obj->fd);
    return (0);
}