#include <stdio.h>
#define TABINC 8    /* Define tab increment size */
int main(void) 
{
	int nb, nt, pos, c;
	nb = 0;         /* Number of blanks */
	nt = 0;         /* Number of tabs */

	/* Loop to read characters */
	for (pos = 1; (c = getchar()) != EOF; ++pos) 
	{
		if (c == ' ') 
		{
			if ((pos % TABINC) != 0)   /* If not at a tab stop */
				++nb;                   /* Increment number of blanks */
			else
		       	{                      /* If at a tab stop */
				nb = 0;                 /* Reset number of blanks */
				++nt;                   /* Increment number of tabs */
			}
		} 
		else
		{                        /* If character is not a space */
			/* Output appropriate number of tabs */
			for (; nt > 0; --nt)
				putchar('\t');

			if (c == '\t')              /* If character is a tab */
				nb = 0;                 /* Reset number of blanks */
			else                        /* If character is not a tab */
				/* Output appropriate number of blanks */
				for (; nb > 0; --nb)
					putchar(' ');

			putchar(c);                 /* Output the character */

			if (c == '\n')              /* If character is a newline */
				pos = 0;                /* Reset position counter */
			else if (c == '\t')         /* If character is a tab */
				pos = pos + (TABINC - (pos - 1) % TABINC) - 1; /* Calculate position */
		}
	}
	return 0;
}

