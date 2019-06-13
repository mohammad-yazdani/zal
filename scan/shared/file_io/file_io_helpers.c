//
// Created by yazda on 6/12/2019.
//

#include <file_io/file_io_helpers.h>

char *
read_file(char * file_name, int *sz)
{
    char *out_buff = NULL;
    FILE *in_file = fopen(file_name, "r");
    if (in_file == NULL)
    {
        perror("FILE IO HELPER");
        exit(EXIT_FAILURE);
    }

    char cc;
    int idx = 0, buff_sz = 0;
    while ((cc = (char) fgetc(in_file)) != EOF)
    {
        idx += 1;
        if (buff_sz < idx)
        {
            buff_sz = idx * 2;
            out_buff = realloc(out_buff, buff_sz * sizeof(char));
        }
        out_buff[idx - 1] = cc;
    }

    *sz = idx;
    return out_buff;
}
