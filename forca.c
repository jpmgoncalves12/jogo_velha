#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *initializeSecretArray(int qtd) {
    static char r[32];
    int i;

    for (i = 0; i < qtd; ++i) {
        r[i] = '_';
    }

    r[qtd+1] = '\0';

    return r;
}

int verifyLetterInWord(
    char actualLetter,
    char *word,
    char *secretWord
) {
    int isInLetter = 0;

    for (int cont = 0; cont <= strlen(word); cont++) {
        if (actualLetter == word[cont]) {
            secretWord[cont] = actualLetter;
            isInLetter++;
        }
    }

    if(isInLetter) {
        return 1;
    }

    return 0;
}

int main() {
    char word[32];
    sprintf(word, "MELANCIA");

    char *secretWord;
    secretWord = initializeSecretArray(strlen(word));

    char actualLetter;

    int qtdTry = 0;
    int maxTry = 3;

    int acertou;

    while (qtdTry <= maxTry) {
        printf("Erros %i de %i.\n", qtdTry, maxTry);

        printf(" Letra > ");
        scanf("%c", &actualLetter);
        printf("\n");

        acertou = verifyLetterInWord(
            actualLetter,
            word,
            secretWord
        );
        printf("Acertou: %i\n", acertou);

        if (acertou == 0) {
            qtdTry++;
        }

        printf("%s", secretWord);
    }

    return 0;
}