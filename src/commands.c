#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "commands.h"
#include "text.h"

int strcmp_nocase(char *str1, char *str2) {
    while (*str1 && *str2) {
        char c1 = tolower(*str1);
        char c2 = tolower(*str2);
        if (c1 != c2) {
            return c1 - c2;
        }
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int command_0(char ***ptr_sentences, int *ptr_count_sentences) {
    char **sentences = *ptr_sentences;
    int count_sentences = *ptr_count_sentences;
    for (int i = 0; i < count_sentences; i++) {
        for (int j = i + 1; j < count_sentences; j++) {
            if (!sentences[i] || !sentences[j]) {
                continue;
            }
            if (!strcmp_nocase(sentences[i], sentences[j])) {
                free(sentences[j]);
                sentences[j] = NULL;
            }
        }
    }
    char **new_sentences = NULL;
    int new_count = 0;
    for (int i = 0; i < count_sentences; i++) {
        if (sentences[i]) {
            new_sentences = realloc(new_sentences, sizeof(char *) * (new_count + 1));
            if (!new_sentences) {
                return -12;
            }
            new_sentences[new_count++] = sentences[i];
        }
    }
    free(sentences);
    *ptr_sentences = new_sentences;
    *ptr_count_sentences = new_count;

    return 0;
}

char *word_tolower(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

int command_1(char **sentences, int count_sentences, int text_size) {
    char **words = NULL;
    int count_words = 0;

    char *buf = malloc(sizeof(char) * text_size);
    if (!buf) {
        return -12;
    }
    int i_buf = 0;
    for (int i = 0; i < count_sentences; i++) {
        char *cur_sent = sentences[i];
        int size_sent = strlen(cur_sent);
        for (int j = 0; j < size_sent; j++) {
            char c = cur_sent[j];
            if ((c < '0' || c > '9') && (c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c != '-') && i_buf > 0) {
                buf[i_buf] = '\0';
                words = realloc(words, sizeof(char *) * (count_words + 1));
                if (!words) {
                    return -12;
                }
                char *word = strdupl(buf);
                if (!word) {
                    return -12;
                }
                words[count_words++] = word;
                i_buf = 0;
            } else {
                if (c != ' ') {
                    buf[i_buf++] = c;
                }
            }
        }
    }
    free(buf);

    for (int i = 0; i < count_words; i++) {
        int cur_count = 1;
        for (int j = i + 1; j < count_words; j++) {
            if (!words[i] || !words[j]) {
                continue;
            }
            if (!strcmp_nocase(words[i], words[j])) {
                cur_count++;
                free(words[j]);
                words[j] = NULL;
            }
        }
        if (words[i]) {
            printf("%s : %d\n", word_tolower(words[i]), cur_count);
        }
    }

    free_memory_strings(words, count_words);

    return 0;
}


void reverse_word(char *beg, char *end) {
    while (beg < end) {
        char tmp = *beg;
        *beg = *end;
        *end = tmp;
        beg++;
        end--;
    }
}

void command_2(char **sentences, int count_sentences) {
    for (int i = 0; i < count_sentences; i++) {
        char *cur_sent = sentences[i];
        int size_sent = strlen(cur_sent);
        char *beg = NULL;
        char *end = NULL;
        for (int j = 0; j < size_sent; j++) {
            char c = cur_sent[j];
            if (c == ' ' && beg == NULL) {
                continue;
            }
            beg = (beg == NULL) ? (cur_sent + j) : beg;
            if ((c < '0' || c > '9') && (c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c != '-')) {
                end = cur_sent + j - 1;
                reverse_word(beg, end);
                beg = NULL;
            }
        }
    }
}


int command_3(char ***ptr_sentences, int *ptr_count_sentences) {
    char **sentences = *ptr_sentences;
    int count_sentences = *ptr_count_sentences;
    int count_del = 0;
    for (int i = 0; i < count_sentences; i++) {
        char *cur_sent = sentences[i];
        int size_sent = strlen(cur_sent);
        for (int j = 0; j < size_sent; j++) {
            char c = cur_sent[j];
            if (c == ',') {
                free(sentences[i]);
                sentences[i] = NULL;
                count_del++;
                break;
            }
        }
    }

    int new_count = count_sentences - count_del;
    char **new_sentences = malloc(sizeof(char *) * new_count);
    if (!new_sentences) {
        return -12;
    }

    int new_i = 0;
    for (int i = 0; i < count_sentences; i++) {
        if (sentences[i]) {
            new_sentences[new_i++] = sentences[i];
        }
    }
    free(sentences);
    *ptr_sentences = new_sentences;
    *ptr_count_sentences = new_count;

    return 0;
}

int sort_cmp(const void *s1, const void *s2) {
    const Sentence_idx *sent_idx1 = *(const Sentence_idx **)s1;
    const Sentence_idx *sent_idx2 = *(const Sentence_idx **)s2;
    const char *sent1 = sent_idx1->sentence;
    const char *sent2 = sent_idx2->sentence;
    int idx1 = sent_idx1->idx;
    int idx2 = sent_idx2->idx;
    int size_sent1 = strlen(sent1);
    int size_sent2 = strlen(sent2);
    char c1 = size_sent1 < 5 ? -1 : sent1[4];
    char c2 = size_sent2 < 5 ? -1 : sent2[4];
    int i1 = 0;
    while ((c1 < '0' || c1 > '9') && (c1 < 'A' || c1 > 'Z') && (c1 < 'a' || c1 > 'z') && (c1 != '-')) {
        if (size_sent1 > 5 + i1) {
            c1 = sent1[5 + i1];
        } else {
            c1 = -1;
            break;
        }
        i1++;
    }
    int i2 = 0;
    while ((c2 < '0' || c2 > '9') && (c2 < 'A' || c2 > 'Z') && (c2 < 'a' || c2 > 'z') && (c2 != '-')) {
        if (size_sent2 > 5 + i2) {
            c2 = sent2[5 + i2];
        } else {
            c2 = -1;
            break;
        }
        i2++;
    }

    if (c1 == c2) {
        return idx1 - idx2;
    }

    return c2 - c1;
}

int command_4(char **sentences, int count_sentences) {
    Sentence_idx **sentences_idx = malloc(sizeof(Sentence_idx *) * count_sentences);
    if (!sentences_idx) {
        return -12;
    }
    for (int i = 0; i < count_sentences; i++) {
        Sentence_idx *sent_idx = malloc(sizeof(Sentence_idx) * 1);
        if (!sent_idx) {
            return -12;
        }
        sent_idx->sentence = sentences[i];
        sent_idx->idx = i;
        sentences_idx[i] = sent_idx;
    }

    qsort(sentences_idx, count_sentences, sizeof(Sentence_idx *), sort_cmp);

    for (int i = 0; i < count_sentences; i++) {
        sentences[i] = sentences_idx[i]->sentence;
    }

    free_memory_sentences_idx(sentences_idx, count_sentences);

    return 0;
}

void command_5() {
	puts("Command 0 – text output after the initial mandatory processing\nCommand 1 – function call number 1 from the task list\nCommand 2 – calling function number 2 from the task list\nCommand 3 – calling function number 3 from the task list\nCommand 4 – calling function number 4 from the task list\nCommand 5 – displays information about the functions that the program implements.");
}

void free_memory_sentences_idx(Sentence_idx **sentences_idx, int count_sentence) {
    for (int i = 0; i < count_sentence; i++) {
        free(sentences_idx[i]);
    }
    free(sentences_idx);
}

void free_memory_strings(char **sentences, int count_sentence) {
    for (int i = 0; i < count_sentence; i++) {
        free(sentences[i]);
    }
    free(sentences);
}

void free_memory_all(char *text, char **sentences, int count_sentences) {
    free(text);
    free_memory_strings(sentences, count_sentences);
}
