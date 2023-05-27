#include "simple_shell.h"
/**
 *cmp_char_str - This will look for a char in a string
 *@_char: This is the char to look for
 *@_str: string
 *Return: 1 if finding char is successful or 0 on failure
 */
int cmp_char_str(char _char, char *_str)
{
	int j = 0;

	while (_str[j])
	{
		if (_str[j] == _char)
			return (1);
		j++;
	}

	return (0);
}
/**
 *count_words - this will count the amount of words in a string
 *@str: string
 *@delimiter: this is the delimiter of the strings
 *Return: the amount of the words
 */
int count_words(char *str, char *delimiter)
{
	int j = 0, words = 0;

	while (str[j])
	{
		if (cmp_char_str(str[j], delimiter))
		{
			while (cmp_char_str(str[j], delimiter) && str[j])
				j++;
		}
		else
		{
			while (!cmp_char_str(str[j], delimiter) && str[j])
				j++;
			words++;
		}
	}

	return (words);
}
/**
 *length_word - this will find the length of a  word inside a string
 *@str: string
 *@delimiter: this is the delimiter of the words
 *@flag: initial position of the word
 *Return: the length of the word
 */
int length_word(char *str, char *delimiter, int flag)
{
	int j = 0, leng = 0;

	while (str[j] && flag >= 0)
	{
		if (cmp_char_str(str[j], delimiter))
		{
			while (cmp_char_str(str[j], delimiter) && str[j])
				j++;
		}
		else
		{
			while (!cmp_char_str(str[j], delimiter) && str[j])
			{
				if (flag == 0)
					leng++;
				j++;
			}
			flag--;
		}
	}

	return (leng);
}
/**
 *copy_word - This will copy a specified word into a new string
 *@str: this is the string with the word
 *@str_tok: this is the new string to save the word
 *@flag: initial position of the word
 *@delimiter: delimiter of the word
 *Return: void
 */
void copy_word(char *str, char *str_tok, int flag, char *delimiter)
{
	int x = 0, y = 0;

	while (str[x] && flag >= 0)
	{
		if (cmp_char_str(str[x], delimiter))
		{
			while (cmp_char_str(str[x], delimiter) && str[x])
				x++;
		}
		else
		{
			while (!cmp_char_str(str[x], delimiter) && str[x])
			{
				if (flag == 0)
					str_tok[y] = str[x], y++;
				x++;
			}
			flag--;
		}
	}
	str_tok[y] = '\0';
}
/**
 *str_tok - split a string into words in an array of string
 *@str: string
 *@delimiter: delimiters of the words
 *Return: An array of string
 */
char **str_tok(char *str, char *delimiter)
{
	int words = 0, j = 0, leng = 0, flag = 0;
	char **str_tok = NULL;
	/* 1. count words */
	words = count_words(str, delimiter);
	/* 2. allocate memory for array of strings */
	str_tok = malloc(sizeof(char *) * (words + 1));
	/* 2.1. Check for malloc */
	if (!str_tok)
		return (NULL);
	/* 3. find the specified word */
	while (j < words)
	{
		/*STEP3.1. find length of the word */
		leng = length_word(str, delimiter, flag);
		/* STEP3.2 Allocate memory for the word */
		str_tok[j] = malloc(sizeof(char) * (leng + 1));
		/* STEP3.3 Check for malloc */
		if (!str_tok[j])
			return (NULL);
		/* STEP3.4 Copy specific word in the allocate memory */
		copy_word(str, str_tok[j], flag, delimiter);
		/* STEP3.5 Save  position which the new word begins */
		flag++;
		j++;
	}
	str_tok[j] = NULL;

	return (str_tok);
}

