/*
** EPITECH PROJECT, 2019
** initFile.c
** File description:
** Open file and handle errors
*/

#include "../../include/nm.h"

int open_and_check_file(t_nm *nm)
{
    nm->fd = open(nm->filename, O_RDONLY);
    if (nm->fd < 0) {
        fprintf(stderr, "nm: \'%s\': No such file\n", nm->filename);
        return (++nm->error);
    }
    return (nm->error);
}

int map_file(t_nm *nm)
{
    if (open_and_check_file(nm) != 0)
        return (nm->error);
    fstat(nm->fd, &nm->st);
    if ((nm->buff = mmap(NULL, nm->st.st_size,
        PROT_READ, MAP_SHARED, nm->fd, 0)) == MAP_FAILED) {
        perror("mmap");
        close(nm->fd);
        return (++nm->error);
    }
    nm->size = nm->st.st_size;
    return (0);
}