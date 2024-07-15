/*Exercise 6-1. Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version.
 *
 * */
/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* MACRO DEFINITIONS */
#define MAX_WORD_LEN 100
#define NR_OF_KEYS (sizeof(keytab) / sizeof(keytab[0]))

// Structure to store keywords and their counts
struct key {
    char *word;  // Keyword
    int count;   // Count of occurrences
};

// Function prototypes
void skip_blanks(void);
void skip_comments(void);
void skip_chars_between(char start, char end);
void skip_char_literal(void);
void skip_string_literal(void);
int get_word(char *word, int max_word_len);
int bin_search(char *word, struct key arr[], int arr_len);

// Array of C keywords
struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"size_t", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

int main(void) {
    int n;
    char word[MAX_WORD_LEN];

    // Read words from input and count keyword occurrences
    while (get_word(word, MAX_WORD_LEN) != EOF) {
        if (isalpha(word[0])) {
            if ((n = bin_search(word, keytab, NR_OF_KEYS)) >= 0) {
                keytab[n].count++;
            }
        }
    }

    // Print the counts of each keyword
    for (size_t i = 0; i < NR_OF_KEYS; ++i) {
        if (keytab[i].count) {
            printf("%4d %s\n", keytab[i].count, keytab[i].word);
        }
    }

    return EXIT_SUCCESS;
}

// Skip blank spaces
void skip_blanks(void) {
    int c;
    while (isblank(c = getc(stdin)))
        ;
    ungetc(c, stdin);
}

// Skip comments
void skip_comments(void) {
    int c = getc(stdin);
    if (c == '/') {
        c = getc(stdin);
        if (c == '/') {
            // Line comment
            while ((c = getc(stdin)) != '\n' && c != EOF)
                ;
        } else if (c == '*') {
            // Block comment
            while ((c = getc(stdin)) != '*' && c != EOF)
                ;
            c = getc(stdin);
            if (c == '/') {
                ungetc('\n', stdin);
                return;
            }
        }
    }
    ungetc(c, stdin);
}

// Skip characters between specified delimiters
void skip_chars_between(char start, char end) {
    int c = getc(stdin);
    if (c == start) {
        while ((c = getc(stdin)) != EOF) {
            if (c == '\\') {
                if ((c = getc(stdin)) == EOF) {
                    break;
                }
            } else if (c == end) {
                return;
            }
        }
    }
    ungetc(c, stdin);
}

// Skip character literals
void skip_char_literal(void) {
    skip_chars_between('\'', '\'');
}

// Skip string literals
void skip_string_literal(void) {
    skip_chars_between('"', '"');
}

// Get the next word or character from the input
int get_word(char *word, int max_word_len) {
    skip_blanks();
    skip_comments();
    skip_char_literal();
    skip_string_literal();

    int c = getc(stdin);
    size_t i = 0;

    if (c != EOF) {
        word[i++] = c;
    }

    if (!isalpha(c) && c != '_') {
        word[i] = '\0';
        return c;
    }

    while ((isalnum(c = getc(stdin)) || c == '_') && i < max_word_len) {
        word[i++] = c;
    }
    ungetc(c, stdin);
    word[i] = '\0';

    return word[0];
}

// Perform binary search on the keyword array
int bin_search(char *word, struct key arr[], int arr_len) {
    int low = 0;
    int high = arr_len - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        int cond = strcmp(word, arr[mid].word);
        if (cond < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

