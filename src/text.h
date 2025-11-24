#pragma once

char *get_text();
int get_count_sentences(char *text);
char **get_sentences();
char **avoid_space(char **sentences_original, int count_sentences);
void print_sentences(char **sentencens, int count_sentences);
char *strdupl(char *str);
