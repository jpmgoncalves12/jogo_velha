#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *initializeSecretArray(int qtd) {
    static char secret[32];

    for (int cont = 0; cont < qtd; ++cont) {
        secret[cont] = '_';
    }
    secret[qtd+1] = '\0';

    return secret;
}

int isLetterInWord(
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

    if(!isInLetter) {
        return 0;
    }

    return 1;
}

int isFinished(
    char *secret
){
    int totalHits = 0;

    for(int cont = 0; cont <= strlen(secret); cont++) {
        if(secret[cont] != '_') {
            totalHits++;
        }
    }

    if(totalHits-1 == strlen(secret)) {
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
        printf("\n--------------");
        printf("\nErros %i de %i.\n\n", qtdTry, maxTry);
        printf("\n\n");

        printf("\n%s\n", secretWord);
        printf("Letra > ");
        scanf(" %c", &actualLetter);
        printf("\n");

        acertou = isLetterInWord(
            actualLetter,
            word,
            secretWord
        );

        char text[32];
        sprintf(text, "Acertou a letra");
        if (acertou == 0) {
            qtdTry++;
            sprintf(text, "Errou a letra");
        }

        if(isFinished(secretWord)) {
            printf("Parábens, o Jogador ganhou! A palavra era %s\n", secretWord);
            break;
        }
        printf("\n%s", text);
    }

    return 0;
}