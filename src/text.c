#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"

char *strdupl(char *str) {
    size_t len = strlen(str);
    char *result = malloc(sizeof(char) * (len + 1));
    strcpy(result, str);
    return result;
}

char *avoid_space(char *str) {
    int i = 0;
    for (; str[i]; i++) {
        char ch = str[i];
        if (ch != ' ' && ch != '\n' && ch != '\t') {
            break;
        }
    }
    return str + i;
}

char *resize_capacity(char *ptr, size_t *capacity) {
    size_t new_capacity = *capacity * 2;
    ptr = realloc(ptr, new_capacity);
    if (!ptr) {
        return NULL;
    }
    *capacity = new_capacity;
    return ptr;
}

char *get_text() {
    size_t capacity = 10;
    size_t size = 0;
    char *text = malloc(sizeof(char) * capacity);
    if (!text) {
        return NULL;
    }

    int cnt_end = 0;
    char c;
    while (cnt_end != 2 && (c = getchar()) != EOF) {
        cnt_end = (c == '\n') ? (cnt_end + 1) : 0;
        if (size * 2 < capacity) {
            text[size++] = c;
        } else {
            text = resize_capacity(text, &capacity);
            if (!text) {
                return NULL;
            }
            text[size++] = c;
        }
    }
    text[size] = '\0';

    return text;
}

int get_count_sentences(char *text) {
    int cnt = 0;
    for (int i = 0; text[i]; i++) {
        if (text[i] == '.') {
            cnt++;
        }
    }
    return cnt;
}

char **get_sentences(char *text, int count_sentences) {
    char **sentences = malloc(sizeof(char *) * count_sentences);
    if (!sentences) {
        return NULL;
    }

    char *buf = malloc(sizeof(char) * strlen(text));
    if (!buf) {
        return NULL;
    }

    int i_sent = 0;
    int i_buf = 0;
    for (int i = 0; text[i]; i++) {
        char c = text[i];
        if (c == '.') {
            buf[i_buf++] = c;
            buf[i_buf] = '\0';
            char *sentence = strdupl(avoid_space(buf));
            if (!sentence) {
                return NULL;
            }
            sentences[i_sent++] = sentence;
            i_buf = 0;
        } else {
            buf[i_buf++] = c;
        }
    }
    free(buf);
    return sentences;
}

void print_sentences(char **sentences, int count_sentences) {
    for (int i = 0; i < count_sentences; i++) {
        printf("%s\n", sentences[i]);
    }
}
