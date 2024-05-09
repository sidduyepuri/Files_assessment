#include <stdio.h>
/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is 
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.	*/
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
#define BUFFER 100

int main(void) {
    int Ihistogram[BUFFER];
    int Ihistogram_length = 0;
    int Imax_word_count = 0;

    // Initialize the histogram array with 0
    int Ii;
    for (Ii = 0; Ii < BUFFER; ++Ii)
        Ihistogram[Ii] = 0;

    // Count the words length and store in Ihistogram array at the specific index
    char c;
    int Iword_count_index = 0;
    while ((c = getchar())) {
        if (c == ' ' || c == '\t' || c == '\n' || c == EOF) {
            if (Iword_count_index > 0) {
                ++Ihistogram[Iword_count_index - 1];

                if (Ihistogram[Iword_count_index - 1] > Imax_word_count)
                    Imax_word_count = Ihistogram[Iword_count_index - 1];
                if (Ihistogram_length < Iword_count_index - 1)
                    Ihistogram_length = Iword_count_index - 1;
                Iword_count_index = 0;
            }
            if (c == EOF)
                break;
        } else
            ++Iword_count_index;
    }

    // Add in the histogram array a end of useful data char
    Ihistogram[Ihistogram_length + 1] = '$';

    putchar('\n');
    int Icolumn_index = 0;
    int Iline_index = 0;

    // Print horizontal Ihistogram
    printf("Horizontal Histogram\n--------------------\n");
    while (Ihistogram[Icolumn_index] != '$') {
        printf("%3d: \t", Icolumn_index + 1);
        for (Iline_index = 0; Iline_index < Ihistogram[Icolumn_index]; ++Iline_index)
            putchar('#');
        putchar('\n');
        ++Icolumn_index;
    }
    putchar('\n');

    // Print a vertical Ihistogram
    printf("Vertical Histogram\n------------------\n");
    for (Iline_index = Imax_word_count; Iline_index >= 0; --Iline_index) {
        Icolumn_index = 0;
        while (Ihistogram[Icolumn_index] != '$') {
            if (Iline_index == 0)
                printf("%2d ", Icolumn_index + 1);
            else if (Ihistogram[Icolumn_index] >= Iline_index)
                printf("## ");
            else
                printf("   ");
            ++Icolumn_index;
        }
        putchar('\n');
    }

    return 0;
}

