#include <stdio.h>
#include <io_utils.h>

typedef enum FileFormat {
    PNG, JPEG=10, BMP, UNKNOWN
} FileFormat;

FileFormat GuessFormat(char *file_path) {
    FILE *file = fopen(file_path, "rb");
    FileFormat file_format = UNKNOWN;
    if (file) {
        char buffer[8] = {0};
        size_t bytes_count = fread(buffer, 1, 8, file);
        if (bytes_count == 8) {
            // bmp: 42 4D
            // png: 89 50 4E 47 0D 0A 1A 0A
            // jpeg: FF D8 FF E0
            if ((*(short *) buffer) == 0x4D42) {
                file_format = DMP;
            } else if ((*(long long *) buffer) == 0x0A1A0A0D474E5089) {
                file_format = PNG;
            } else if ((*(int *) buffer) == 0xE0FFD8FF) {
                file_format = JPEG;
            }
        }
        fclose(file);
    }
    return file_format;
}

int main() {
    FileFormat file_format = JPEG;
//    FileFormat file_format = 1;
    return 0;
}