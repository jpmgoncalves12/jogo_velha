#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *initializeSecretArray(int qtd) {
    static char r[32];
    int i;

    for (i = 0; i < qtd; ++i) {
        r[i] = '_';
    }

    r[qtd+1] = '\0';

    return r;
}

void renderPerson(int numTry) {
    printf("\n");
    printf("o\n");
    printf("|\n");
    printf("A\n");
}

void renderLetters(char *secretWord) {
    printf("\n");
    for (int cont = 0; cont < strlen(secretWord); cont++) {
        printf("%c ", secretWord[cont]);
    }
    printf("\n");
}

void renderScreenElements(int numTry, char *secretWord) {
    renderPerson(numTry);
    renderLetters(secretWord);
}

int main() {
    char word[32];
    sprintf(word, "MELANCIA");

    char *secretWord;
    secretWord = initializeSecretArray(strlen(word));

    int maxTrying = 3;
    int numTry = 0;

    renderScreenElements(
        numTry,
        secretWord
    );

    return 0;
}