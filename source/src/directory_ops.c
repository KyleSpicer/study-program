#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "../include/directory_ops.h"

#define SUCCESS 0
#define ERROR   1

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

int list_dir_contents(char *dir_path);
