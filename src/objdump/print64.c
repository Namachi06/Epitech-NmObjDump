/*
** EPITECH PROJECT, 2019
** print64.c
** File description:
** print sections
*/

#include "../../include/objdump.h"

void print_section64(t_obj64 *obj64, int index)
{
    int address = obj64->shdr[index].sh_addr;
    for (unsigned int j = 0; j < obj64->shdr[index].sh_size; j++) {
        if (j % 16 == 0)
            printf(" %04x \n", address);
        address += 16;
    }
}

void print_sections64(t_obj64 *obj64)
{
    for (int i = 0; i < obj64->elf->e_shnum; i++) {
        if (obj64->shdr[i].sh_size && !is_obj_section64(obj64, i)) {
            printf("Contents of section %s:\n",
                &obj64->str_tab[obj64->shdr[i].sh_name]);
            print_section64(obj64, i);
        }
    }
}

void print_header_name64(t_obj64 *obj64, t_obj *obj)
{
    const char *getMachineName = obj64->elf->e_machine == EM_386
        ? "i386" : "i386:x86-64";
    printf("\n%s:%5cfile format elf64-x86-64\n", obj->filename, ' ');
    printf("architecture: %s, flags 0x%08x:\n\n",
        getMachineName, obj64->elf->e_flags);
    printf("start address 0x%016x\n\n", (unsigned int)obj64->elf->e_entry);
}