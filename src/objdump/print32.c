/*
** EPITECH PROJECT, 2019
** print32.c
** File description:
** print sections
*/

#include "../../include/objdump.h"

void print_section32(t_obj32 *obj32, int index)
{
    int address = obj32->shdr[index].sh_addr;
    for (unsigned int j = 0; j < obj32->shdr[index].sh_size; j++) {
        if (j % 16 == 0)
            printf(" %04x \n", address);
        address += 16;
    }
}

void print_sections32(t_obj32 *obj32)
{
    for (int i = 0; i < obj32->elf->e_shnum; i++) {
        if (obj32->shdr[i].sh_size && !is_obj_section32(obj32, i)) {
            printf("Contents of section %s:\n",
                &obj32->str_tab[obj32->shdr[i].sh_name]);
            print_section32(obj32, i);
        }
    }
}

void print_header_name32(t_obj32 *obj32, t_obj *obj)
{
    const char *getMachineName = obj32->elf->e_machine == EM_386
        ? "i386" : "i386:x86-64";
    printf("\n%s:%5cfile format elf32-i386\n", obj->filename, ' ');
    printf("architecture: %s, flags 0x%08x:\n\n",
        getMachineName, obj32->elf->e_flags);
    printf("start address 0x%016x\n\n", (int)obj32->elf->e_entry);
}