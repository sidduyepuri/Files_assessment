#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define NR_OF_TYPES sizeof(data_types) / sizeof(data_types[0])

// Tree node structure
struct tree_node
{
	char *word;
	struct tree_node *left;
	struct tree_node *right;
};

// List node structure
struct list_node
{
	struct tree_node *var_group;
	struct list_node *next;
};

// Function prototypes
struct tree_node *add_to_tree(struct tree_node *node_p, char *word);
void print_tree(struct tree_node *node_p);
struct list_node *add_to_list(struct list_node *list_node_p, char *word);
void print_list(struct list_node *node_p);
int parse_arg_list(int argc, char *argv[]);
char *str_dup(char *src);
void skip_blanks();
void skip_comments();
void skip_chars_between(char start, char end);
void skip_char_literal(void);
void skip_string_literal(void);
int get_word(char *word, int max_word_len);
int bin_search(char *word, char *arr[], int arr_len);

// List of data types
char *data_types[] = {
	"char",
	"double",
	"float",
	"int",
	"long",
	"short",
	"void",
};

int var_name_str_cmp_len = 6; // Default comparison length for variable names

int main(int argc, char *argv[])
{
	// Parse command line arguments
	if (!parse_arg_list(argc, argv))
	{
		puts("Error: invalid arguments.");
		return EXIT_FAILURE;
	}

	int n;
	struct list_node *list_root = NULL; // Initialize list root to NULL
	char word[MAX_WORD_LEN];

	// Read words from input until EOF
	while (get_word(word, MAX_WORD_LEN) != EOF)
	{
		// Check if word is a data type
		if ((n = bin_search(word, data_types, NR_OF_TYPES)) >= 0)
		{
			do
			{
				// Read and add variable/function names associated with the data type to the list
				if (get_word(word, MAX_WORD_LEN) != EOF && (isalpha(word[0]) || word[0] == '_'))
				{
					list_root = add_to_list(list_root, word);
				}
			} while (get_word(word, MAX_WORD_LEN) == ','); // Continue until no more words or comma-separated list ends
		}
	}

	// Print the list of variable/function names
	print_list(list_root);

	return EXIT_SUCCESS;
}

// Parse command line arguments
int parse_arg_list(int argc, char *argv[])
{
	if (argc > 2) // Only accept zero or one argument
	{
		return 0; // Invalid arguments
	}

	if (argc == 2)
	{
		if (!isdigit(argv[1][0])) // Argument should be a digit
		{
			return 0; // Invalid argument
		}

		var_name_str_cmp_len = atoi(argv[1]); // Set comparison length for variable names

		if (var_name_str_cmp_len < 0)
		{
			return 0; // Invalid argument
		}
	}

	return 1; // Arguments parsed successfully
}

// Duplicate a string
char *str_dup(char *src)
{
	char *dest = (char *)malloc(strlen(src) + 1); // Allocate memory for duplicated string
	if (dest != NULL)
	{
		strcpy(dest, src); // Copy source string to destination
	}
	return dest; // Return pointer to duplicated string
}

// Skip blank characters
void skip_blanks()
{
	int c;
	while (isblank(c = getc(stdin)))
		;
	ungetc(c, stdin);
}

// Skip comments in input
void skip_comments()
{
	int c = getc(stdin);
	if (c == '/')
	{
		c = getc(stdin);
		if (c == '/')
		{
			while ((c = getc(stdin)) != '\n' && c != EOF)
				;
		}
		else if (c == '*')
		{
			while ((c = getc(stdin)) != '*' && c != EOF)
				;
			c = getc(stdin);
			if (c == '/')
			{
				ungetc('\n', stdin);
				return;
			}
		}
	}
	ungetc(c, stdin);
}

// Skip characters between specified start and end characters
void skip_chars_between(char start, char end)
{
	int c = getc(stdin);
	if (c == start)
	{
		while ((c = getc(stdin)) != EOF)
		{
			if (c == '\\')
			{
				if ((c = getc(stdin)) == EOF)
				{
					break;
				}
			}
			else if (c == end)
			{
				return;
			}
		}
	}
	ungetc(c, stdin);
}

// Skip character literals in input
void skip_char_literal(void)
{
	skip_chars_between('\'', '\'');
}

// Skip string literals in input
void skip_string_literal(void)
{
	skip_chars_between('"', '"');
}

// Get the next word from input
int get_word(char *word, int max_word_len)
{
	skip_blanks();
	skip_comments();
	skip_char_literal();
	skip_string_literal();

	int c = getc(stdin);
	size_t i = 0;

	if (c != EOF)
	{
		word[i++];
		word[i++] = c;
	}

	if (!isalpha(c) && c != '_') // Word cannot start with a digit
	{
		word[i] = '\0';
		return c;
	}

	while ((isalnum(c = getc(stdin)) || c == '_') && i < max_word_len)
	{
		word[i++] = c;
	}
	ungetc(c, stdin);
	word[i] = '\0';

	return word[0];
}

// Binary search for a word in a sorted array of strings
int bin_search(char *word, char *arr[], int arr_len)
{
	int low = 0;
	int high = arr_len - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		int cond = strcmp(word, arr[mid]);
		if (cond < 0)
		{
			high = mid - 1;
		}
		else if (cond > 0)
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1; // Word not found
}

// Add a word to the binary search tree
struct tree_node *add_to_tree(struct tree_node *node_p, char *word)
{
	int cond;

	if (node_p == NULL) // If tree is empty, create a new node
	{
		node_p = (struct tree_node *)malloc(sizeof(struct tree_node));
		node_p->word = str_dup(word);
		node_p->left = node_p->right = NULL;
	}
	else if ((cond = strcmp(word, node_p->word)) != 0) // If word is not already in the tree
	{
		if (cond < 0)
		{
			node_p->left = add_to_tree(node_p->left, word); // Recursively insert into left subtree
		}
		else if (cond > 0)
		{
			node_p->right = add_to_tree(node_p->right, word); // Recursively insert into right subtree
		}
	}

	return node_p;
}

// Print the tree in-order
void print_tree(struct tree_node *node_p)
{
	if (node_p != NULL)
	{
		print_tree(node_p->left); // Traverse left subtree
		puts(node_p->word); // Print current node
		print_tree(node_p->right); // Traverse right subtree
	}
}

// Add a word to the linked list of trees
struct list_node *add_to_list(struct list_node *list_node_p, char *word)
{
	if (list_node_p == NULL) // If list is empty, create a new node
	{
		list_node_p = (struct list_node *)malloc(sizeof(struct list_node));
		list_node_p->var_group = add_to_tree(list_node_p->var_group, word); // Add word to tree in the node
	}
	else if (strncmp(list_node_p->var_group->word, word, var_name_str_cmp_len) == 0) // If word matches the current tree node
	{
		list_node_p->var_group = add_to_tree(list_node_p->var_group, word); // Add word to the tree
	}
	else
	{
		list_node_p->next = add_to_list(list_node_p->next, word); // Recursively insert into next node
	}

	return list_node_p;
}

// Print the list of trees
void print_list(struct list_node *node_p)
{
	if (node_p != NULL)
	{
		print_tree(node_p->var_group); // Print the tree in the node
		putchar('\n'); // Add a new line
		print_list(node_p->next); // Recursively print the next node
	}
}

