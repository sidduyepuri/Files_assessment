#include<stdio.h>

#define MAXCOL 50   /* Maximum column width */
#define TABVAL 8    /* Tab value */

char line[MAXCOL];  /* Character array to store input line */

/* Function prototypes */
int expandtab(int pos);
int printline(int pos);
int getblank(int pos);
int newposition(int pos);

int main(void) 
{
	int pos, c;
	pos = 0;

	/* Loop to read characters until EOF */
	while ((c = getchar()) != EOF) {
		line[pos] = c;  /* Store character in the line buffer */

		if (c == '\t')  /* If character is a tab */
			pos = expandtab(pos);   /* Expand tab to spaces */

		if (c == '\n') {    /* If character is a newline */
			printline(pos); /* Print the line */
			pos = 0;        /* Reset position */
		} else if (++pos >= MAXCOL) {  /* If reached maximum column width */
			pos = getblank(pos);    /* Find the last blank position */
			printline(pos);         /* Print the line */
			pos = newposition(pos); /* Update position */
		}
	}
	return 0;
}

/* Function to expand tabs to spaces */
int expandtab(int pos) 
{
	line[pos] = ' ';    /* Replace tab with space */
	for (++pos; (pos < MAXCOL) && ((pos % TABVAL) != 0); ++pos)
		line[pos] = ' ';    /* Fill remaining spaces till next tab stop */
	if (pos >= MAXCOL) {    /* If reached maximum column width */
		printline(pos); /* Print the line */
		return 0;       /* Reset position */
	} else {
		return pos;     /* Return updated position */
	}
}

/* Function to print the line */
int printline(int pos) 
{
	int i;
	for (i = 0; i < pos; ++i)
		putchar(line[i]);   /* Output each character */
	if (pos > 0)
		putchar('\n');  /* Output newline if line is not empty */
}

/* Function to find the last blank position */
int getblank(int pos) {
	if (pos > 0)
		while (line[pos] != ' ')    /* Search for the last blank */
			--pos;  /* Move backward in the line buffer */
	if (pos == 0)
		return MAXCOL;  /* Return MAXCOL if no blanks found */
	else
		return pos + 1; /* Return position after the last blank */
}

/* Function to update position */
int newposition(int pos) {
	int i, j;
	if (pos <= 0 || pos >= MAXCOL)
		return 0;   /* Return 0 if position is out of bounds */
	else {
		i = 0;
		for (j = pos; j < MAXCOL; ++j, ++i)
			line[i] = line[j];  /* Copy characters after last blank to the beginning of line buffer */
	}
	return i;   /* Return new position */
}

