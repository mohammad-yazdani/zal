//
// Created by yazda on 6/12/2019.
//

#ifndef SCAN_FILE_IO_HELPERS_H
#define SCAN_FILE_IO_HELPERS_H

#include <stdlib.h>
#include <stdio.h>

char *
read_file(char *file_name, int *sz);

int
write_file(const char *path, const char *buffer);

#endif //SCAN_FILE_IO_HELPERS_H
