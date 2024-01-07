#ifndef DIRERCTORY_OPS_H
#define DIRERCTORY_OPS_H

int directory_exists(const char *dir_path, char **resolved_path_p);

int list_dir_contents(char *dir_path);

#endif /* DIRERCTORY_OPS_H */

/* end of file */
