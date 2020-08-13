//
// Created by Bohan Gao on 8/6/20.
//
#include <stdlib.h>

#include "Words.h"
#include "TestUtils.h"

int main() {
    char **words = GetWords("words.txt", 432334);
    PrintAllAnagramGroups(words, 432334);
    DestroyWords(words, 432334);
    return EXIT_SUCCESS;
}

