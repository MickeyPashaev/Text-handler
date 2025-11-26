#pragma once

char *get_text();
int get_count_sentences(char *text);
char **get_sentences(char *text, int count_sentences);
char *avoid_space(char *str);
void print_sentences(char **sentencens, int count_sentences);
char *strdupl(char *str);
int get_start_data(char **text, int *count_sentences, char ***sentences);
