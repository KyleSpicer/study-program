#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "../include/directory_ops.h"

#define SUCCESS  0
#define ERROR    1
#define MAX_PATH 1024

static int is_regular_file(const char *path);

int
directory_exists(const char *dir_path, char **resolved_path_p)
{
    int ret_val = ERROR;

    if (NULL == dir_path)
    {
        goto EXIT_DIR_EXISTS;
    }

    char *resolved_path = NULL;
    resolved_path       = realpath(dir_path, NULL);

    if (NULL == resolved_path)
    {
        perror("Error resolving path.");
        errno         = 0;
        resolved_path = NULL;
        goto EXIT_DIR_EXISTS;
    }

    *resolved_path_p = resolved_path;
    ret_val          = SUCCESS;

EXIT_DIR_EXISTS:
    return ret_val;
}

int
list_dir_contents(char *dir_path)
{
    int ret_val = ERROR;
    if (NULL == dir_path)
    {
        goto EXIT_LS_DIR;
    }

    DIR *dir_p = NULL;
    dir_p      = opendir(dir_path);

    if (NULL == dir_p)
    {
        perror("Error opening directory.");
        errno = 0;
        goto EXIT_LS_DIR;
    }

    struct dirent *entry_p = NULL;

    while ((entry_p = readdir(dir_p)) != NULL)
    {
        char file_path[MAX_PATH] = { 0 };
        snprintf(
            file_path, sizeof(file_path), "%s/%s", dir_path, entry_p->d_name);

        if (is_regular_file(file_path))
        {
            printf("File name: %s\n", entry_p->d_name);
        }
    }

    closedir(dir_p);

EXIT_LS_DIR:
    return ret_val;
}

static int
is_regular_file(const char *path)
{
    struct stat path_stat = { '\0' };
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

/* end of file */
