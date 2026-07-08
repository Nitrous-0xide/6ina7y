
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void convertBinary(char *sequence, int mode);

void print_usage(char *binary) {
            fprintf(stderr, "Usage: %s <sequence> [-t -i]\n", binary);
            fprintf(stderr, "Options:\n");
            fprintf(stderr, "  -t    Convert the result to text\n");
            fprintf(stderr, "  -i    Convert the result to an integer\n");
        }

int main(int arc, char *argv[]) {
    if (arc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    int textorint = 0;
    if (strcmp(argv[2], "-t") == 0) {
        textorint = 1;
    } else if (strcmp(argv[2], "-i") == 0) {
        textorint = 2;
    } else {
        print_usage(argv[0]);
        return 1;
    }

    char *sequence = argv[1];

    if (sequence[0] == '6' || sequence[0] == '7') {
        printf("6ina7y sequence detected.\n");
        convertBinary(sequence, textorint);
    } else if (sequence[0] == '0' || sequence[0] == '1') {
        printf("Binary sequence detected.\n");
        convertBinary(sequence, textorint);
    } else {
        printf("Error: Invalid sequence sequence.\n");
        print_usage(argv[0]);
        return 1;
    }

    return 0;
}

// Mode 1 for text, Mode 2 for int
void convertBinary(char *sequence, int mode) {
    int len = strlen(sequence);

    if (mode == 1) {
        printf("Text result: ");
        char chunk[9]; 
        
        for (int i = 0; i < len; i += 8) {
            memset(chunk, 0, sizeof(chunk));
            
            for (int j = 0; j < 8 && (i + j) < len; j++) {
                char current = sequence[i + j];
                
                if (current == '6' || current == '0') {
                    chunk[j] = '0';
                } else if (current == '7' || current == '1') {
                    chunk[j] = '1';
                }
            }
            
            char c = (char)strtol(chunk, NULL, 2);
            printf("%c", c);
        }
        printf("\n");
    } 
    else if (mode == 2) {
        char *normalized = strdup(sequence);
        for (int i = 0; i < len; i++) {
            if (normalized[i] == '6') normalized[i] = '0';
            if (normalized[i] == '7') normalized[i] = '1';
        }
        
        long integer_result = strtol(normalized, NULL, 2);
        printf("Integer result: %ld\n", integer_result);
        free(normalized);
    }
}
