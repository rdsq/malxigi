#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "help.c"

#define MAP_SIZE 13

typedef struct {
    char key;
    char value[2];
} CharStringMap;

bool processChars(char current, char next, const CharStringMap charMap[MAP_SIZE]) {
    if (next == 'x' || next == 'X') {
        for (int i = 0; i < MAP_SIZE; i++) {
            CharStringMap v = charMap[i];
            if (v.key == current) {
                // a little trick
                if (v.value[0] == 'x' && next == 'X') {
                    putchar('X');
                } else {
                    printf("%s", v.value);
                }
                return true;
            }
        }
    }
    putchar(current);
    return false;
}

int main(int argc, char* argv[]) {
    if (argc != 2) { // including the file arg
        helpMessage();
        return 1;
    } else if (strcmp(argv[1], "--help") != 0 || strcmp(argv[1], "-h") != 0) {
        helpMessage();
        return 0;
    }
    const CharStringMap charMap[MAP_SIZE] = {
        {'\\', "x"},
        {'c', "ĉ"},
        {'C', "Ĉ"},
        {'g', "ĝ"},
        {'G', "Ĝ"},
        {'h', "ĥ"},
        {'H', "Ĥ"},
        {'j', "ĵ"},
        {'J', "Ĵ"},
        {'s', "ŝ"},
        {'S', "Ŝ"},
        {'u', "ŭ"},
        {'U', "Ŭ"},
    };

    size_t length = strlen(argv[1]);
    for (size_t i = 0; i < length; i++) {
        char current = argv[1][i];
        char next = '\0'; // any char value, doesn't matter
        if (i < length) {
            next = argv[1][i+1];
        }
        bool res = processChars(current, next, charMap);
        if (res) {
            // skip the x
            i++;
        }
    }
    putchar('\n');

    return 0;
}
