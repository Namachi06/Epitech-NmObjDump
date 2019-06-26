/*
** EPITECH PROJECT, 2019
** objdump.h
** File description:
** objdump header
*/

#ifndef OBJDUMP_H_
	#define OBJDUMP_H_

#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdint.h>
#include <elf.h>

typedef struct s_obj
{
    int fd;
    char const *filename;
    int error;
    void *buff;
    size_t size;
    struct stat st;
} t_obj;

typedef struct s_obj32
{
    Elf32_Ehdr *elf;
    Elf32_Shdr *shdr;
    char *str_tab;
} t_obj32;

typedef struct s_obj64
{
    Elf64_Ehdr *elf;
    Elf64_Shdr *shdr;
    char *str_tab;
} t_obj64;

// initFile.c
int check_elf(t_obj *obj, int argc);
int map_file(t_obj *obj);

// objdump.c
int objdump_program(char const *filename, t_obj *obj);

// utils.c
int check_elf32(t_obj *obj, Elf32_Ehdr *elf);
int check_elf64(t_obj *obj, Elf64_Ehdr *elf);
int is_obj_section64(t_obj64 *obj64, int i);
int is_obj_section32(t_obj32 *obj32, int i);

// Arch32.c
int arch32(t_obj *obj);

// Arch64.c
int arch64(t_obj *obj);

// print64.c
void print_header_name64(t_obj64 *obj64, t_obj *obj);
void print_sections64(t_obj64 *obj64);

// print32.c
void print_header_name32(t_obj32 *obj32, t_obj *obj);
void print_sections32(t_obj32 *obj32);

#endif /* !OBJDUMP_H_ */
