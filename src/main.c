#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "text.h"
#include "commands.h"

int main() {
    printf("Course work for option 4.6, created by Mekhman Pashaev.\n");

    int mode;
    if (!scanf("%d", &mode)) {
        puts("Error: wrong mode number. Write number 0-5.");
        return 0;
    }
    if (mode == 5) {
        command_5();
        return 0;
    }

    char *text = get_text();
    if (!text) {
        puts("Error: out of memory");
        return 0;
    }

    int count_sentences = get_count_sentences(text);
    if (count_sentences == 0) {
        puts("Error: text is empty or wrong");
        free(text);
        return 0;
    }
    int count_sentences_original = count_sentences;
    char **sentences_original = get_sentences(text, count_sentences);
    if (!sentences_original) {
        puts("Error: out of memory");
        free(text);
        return 0;
    }
    char **sentences = avoid_space(sentences_original, count_sentences);
    if (!sentences) {
        puts("Error: out of memory");
        free(text);
        return 0;
    }

    switch (mode) {
        case 0: {
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences_original, count_sentences_original, sentences);
                return 0;
            }
            print_sentences(sentences, count_sentences);
            break;
        }
        case 1: {
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences_original, count_sentences_original, sentences);
                return 0;
            }
            if (command_1(sentences, count_sentences, strlen(text))) {
                puts("Error: out of memory");
                free_memory_all(text, sentences_original, count_sentences_original, sentences);
                return 0;
            }
            break;
        }
        case 2: {
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences_original, count_sentences_original, sentences);
                return 0;
            }
            command_2(sentences, count_sentences);
			print_sentences(sentences, count_sentences);
            break;
        }
        case 3: {
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences_original, count_sentences_original, sentences);
                return 0;
            }
            if (command_3(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences_original, count_sentences_original, sentences);
                return 0;
            }
			print_sentences(sentences, count_sentences);
            break;
        }
        case 4: {
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences_original, count_sentences_original, sentences);
                return 0;
            }
            if (command_4(sentences, count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences_original, count_sentences_original, sentences);
                return 0;
            }
			print_sentences(sentences, count_sentences);
            break;
        }
    }

    free_memory_all(text, sentences_original, count_sentences_original, sentences);

    return 0;
}
