#include "common.h"
#include "editor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void edit_metadata(char* flag, char* buffer, char* filepath) {
    //File handling
    FILE *src = fopen(filepath, "r");
    if (src == NULL) {
        perror("fopen");
        return;
    }

    FILE *dest = fopen("./temp.mp3", "w");
    if (dest == NULL) {
        perror("fopen");
        return;
    }

    //Copy 10 bytes of header from source to destination
    char* buf[10];
    fread(buf, 10, 1, src);
    fwrite(buf, 10, 1, dest);

    //Read 4 bytes of tag from src
    char tag[5];
    fread(tag, 4, 1, src);
    tag[4] = '\0';
    printf("Source Tag: %s\n", tag);

    char tag_list[6][5] = {"TIT2", "TPE1", "TALB", "TYER", "TCON", "COMM"};
    char flag_list[6][3] = {"-t", "-a", "-A", "-y", "-m", "-c"};
    int flag_index = -1;

    for (int i=0; i<6; i++) {
        if(strcmp(flag, flag_list[i]) == 0) {
            flag_index=i;
            break;
        }
    }

    if(strcmp(flag, flag_list[flag_index])==0) {
        //Write 4 bytes of src to dest
        fwrite(tag, 4, 1, dest);

        //Convert size of new data from L.E to B.E
        int le_size = strlen(buffer);
        int be_size = to_be(le_size);
        // printf("%d", be_size);

        //Write B.E size to dest
        fwrite(&be_size, 4, 1, dest);

        //TODO
        //Read 4 bytes of size from src
        //Convert size from B.E -> L.E
        //Read and write 3 flags from (sample->temp)
        //Write new data temp.mp3
    }
}

