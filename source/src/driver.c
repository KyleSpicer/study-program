#include <stdbool.h>
#include <stdio.h>

#include "../include/directory_ops.h"
#include "../include/driver.h"

int
main(int argc, char *argv[])
{

    int exit_value = SUCCESS;

    char *study_docs_dir = NULL;
    char *resolved_path  = NULL; // path if directory is found.
    bool  path_provided  = false;

    if (1 == argc)
    {
        study_docs_dir = (char *)DEFAULT_FILE_DIR;
    }

    else if (2 == argc)
    {
        study_docs_dir = argv[1];
        path_provided  = true;
    }

    else
    {
        printf("Too many arguments.\n");
        exit_value = ERROR;
        goto EXIT_MAIN;
    }

    // TODO: Ensure security of chosen directories.
    // EXAMPLE: Do not allow targeted traversal to unwanted folders.
    int dir_ret = directory_exists(study_docs_dir, &resolved_path);
    if (SUCCESS != dir_ret)
    {
        exit_value = ERROR;
        goto EXIT_MAIN;
    }

    // TODO: List contents of study directory.

    printf("Study docs dir: %s\n", resolved_path);

EXIT_MAIN:
    return exit_value;
}
