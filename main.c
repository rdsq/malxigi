#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAP_SIZE 13

typedef struct {
    char key;
    char value[2];
} CharStringMap;

bool processChars(char current, char next, CharStringMap charMap[MAP_SIZE]) {
    if (next == 'x' || next == 'X') {
        for (int i = 0; i < MAP_SIZE; i++) {
            CharStringMap v = charMap[i];
            if (v.key == current) {
                // a little trick
                if (v.value[0] == 'x' && next == 'X') {
                    putchar('X');
                } else {
                    printf(v.value);
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
        printf("help msg wip\n");
        return 1;
    }
    CharStringMap charMap[MAP_SIZE] = {
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
        char next = ' '; // something, not really good code...
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
