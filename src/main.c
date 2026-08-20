#include <stdio.h>
#include <string.h>
#include "reader.h"
#include "editor.h"


int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: ./a.out <mp3_file_path>");
        return 0;
    }

    // printf("%s", argv[1]);
    if (strcmp(argv[1], "-r")==0) {
        read_metadata(argv[2]);
    } else if(strcmp(argv[1], "-e")==0) {
        edit_metadata(argv[2], argv[3], argv[4]);
    }
    return 0;
}
