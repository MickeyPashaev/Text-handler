#pragma once

typedef struct {
    char *sentence;
    int idx;
} Sentence_idx;

int command_0(char ***ptr_sentences, int *ptr_count_sentences);
int command_1(char **sentences, int count_sentences, int text_size);
void command_2(char **sentences, int count_sentences);
int command_3(char ***ptr_sentences, int *ptr_count_sentences);
int command_4(char **sentences, int count_sentences);
void command_5();
void free_memory_sentences_idx(Sentence_idx **sentences_idx, int count_sentence);
void free_memory_strings(char **sentences, int count_sentences);
void free_memory_all(char *text, char **sentences, int count_sentences);
