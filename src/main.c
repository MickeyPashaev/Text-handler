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

    char *text = NULL;
    int count_sentences = 0;
    char **sentences = NULL;

    switch (mode) {
        case 0: {
            if (get_start_data(&text, &count_sentences, &sentences)) {
                puts("Error: out of memory or wrong text");
                return 0;
            }
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences, count_sentences);
                return 0;
            }
            print_sentences(sentences, count_sentences);
            break;
        }
        case 1: {
            if (get_start_data(&text, &count_sentences, &sentences)) {
                puts("Error: out of memory or wrong text");
                return 0;
            }
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences, count_sentences);
                return 0;
            }
            if (command_1(sentences, count_sentences, strlen(text))) {
                puts("Error: out of memory");
                free_memory_all(text, sentences, count_sentences);
                return 0;
            }
            break;
        }
        case 2: {
            if (get_start_data(&text, &count_sentences, &sentences)) {
                puts("Error: out of memory or wrong text");
                return 0;
            }
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences, count_sentences);
                return 0;
            }
            command_2(sentences, count_sentences);
			print_sentences(sentences, count_sentences);
            break;
        }
        case 3: {
            if (get_start_data(&text, &count_sentences, &sentences)) {
                puts("Error: out of memory or wrong text");
                return 0;
            }
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences, count_sentences);
                return 0;
            }
            if (command_3(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences, count_sentences);
                return 0;
            }
			print_sentences(sentences, count_sentences);
            break;
        }
        case 4: {
            if (get_start_data(&text, &count_sentences, &sentences)) {
                puts("Error: out of memory or wrong text");
                return 0;
            }
            if (command_0(&sentences, &count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences, count_sentences);
                return 0;
            }
            if (command_4(sentences, count_sentences)) {
                puts("Error: out of memory");
                free_memory_all(text, sentences, count_sentences);
                return 0;
            }
			print_sentences(sentences, count_sentences);
            break;
        }
        case 5: {
            command_5();
            return 0;
        }
        default: {
            puts("Error: no command which you write. Write: 0-5");
        }
    }

    free_memory_all(text, sentences, count_sentences);

    return 0;
}
