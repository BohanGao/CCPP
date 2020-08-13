//
// Created by Bohan Gao on 8/6/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Words.h"

char **GetWords(char *filename, int num_lines) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    char c;
    char **words = malloc(sizeof(filename) * num_lines);
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i, j;
    for (i = 0; i < num_lines; i++) {
        read = getline(&line, &len, fp);
        if (read != EOF) {
            int startIndex = 0;
            int endIndex = strlen(line) - 1;
            while (startIndex < endIndex &&
                   (line[startIndex] == '\r' || line[startIndex] == '\n')) {
                startIndex++;
            }
            while (startIndex < endIndex &&
                   (line[endIndex] == '\r' || line[endIndex] == '\n')) {
                endIndex--;
            }
            words[i] = NULL;
            int word_len = endIndex - startIndex + 1;
            words[i] = malloc(sizeof(c) * word_len + 1);
            for (j = startIndex; j <= endIndex; j++) {
                words[i][j] = line[startIndex + j];
            }
            words[i][j] = '\0';
        }
    }
    fclose(fp);
    if (line) {
        free(line);
        line = NULL;
    }

    return words;
}

void DestroyWords(char **words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        free(words[i]);
        words[i] = NULL;
    }

    free(words);
}
