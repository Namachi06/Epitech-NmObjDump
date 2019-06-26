/*
** EPITECH PROJECT, 2019
** initFile.c
** File description:
** Open file and handle errors
*/

#include "../../include/objdump.h"

int open_and_check_file(t_obj *obj)
{
    obj->fd = open(obj->filename, O_RDONLY);
    if (obj->fd < 0) {
        fprintf(stderr, "objdump: \'%s\': No such file\n", obj->filename);
        return (++obj->error);
    }
    return (obj->error);
}

int map_file(t_obj *obj)
{
    if (open_and_check_file(obj) != 0)
        return (obj->error);
    fstat(obj->fd, &obj->st);
    obj->buff = mmap(NULL, obj->st.st_size, PROT_READ, MAP_PRIVATE, obj->fd, 0);
    obj->size = obj->st.st_size;
    if (obj->buff == (void *)-1) {
        perror("mmap");
        close(obj->fd);
        return (obj->error);
    }
    return (0);
}