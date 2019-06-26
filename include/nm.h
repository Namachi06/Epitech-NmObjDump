/*
** EPITECH PROJECT, 2019
** nm.h
** File description:
** mn header
*/

#ifndef MN_H_
    #define MN_H_

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
#include <strings.h>

typedef struct s_nm
{
    int fd;
    char const *filename;
    int error;
    void *buff;
    size_t size;
    struct stat st;
} t_nm;

typedef struct s_nm32
{
    Elf32_Ehdr *elf;
    Elf32_Shdr *shdr;
    Elf32_Shdr *sym_str;
    Elf32_Shdr *sym_Section;
    Elf32_Sym *sym_tab;
    char *str_tab;
    char *sym_tab_str;
} t_nm32;

typedef struct s_nm64
{
    Elf64_Ehdr *elf;
    Elf64_Shdr *shdr;
    Elf64_Shdr *sym_str;
    Elf64_Shdr *sym_Section;
    Elf64_Sym *sym_tab;
    char *str_tab;
    char *sym_tab_str;
} t_nm64;

// nm.c
int nm_program(char const *filename, int argc, t_nm *nm);

// initFile.c
int map_file(t_nm *nm);

// Arch32.c
int arch32(t_nm *nm, int argc);

// Arch64.c
int arch64(t_nm *nm, int argc);

// sort64.c && sort32.c
void sort_symbols64(t_nm64 *nm64, Elf64_Sym ***cpySym,
    long unsigned *size);
void sort_symbols32(t_nm32 *nm32, Elf32_Sym ***cpySym,
    long unsigned *size);

// utils.c
int check_elf32(t_nm *nm, Elf32_Ehdr *elf,  int argc);
int check_elf64(t_nm *nm, Elf64_Ehdr *elf,  int argc);

#endif /* !MN_H_ */
