#include "monty.h"

/**
 * _strdup - function to duplicate a string
 * @str: the given string
 *
 * Return: the duplicated string
 **/
char *_strdup(char *str)
{
	char *dup;
	int i = 0;
	int strlength = 0;

	if (str == NULL)
		return (NULL);
	strlength = _strlen(str);
	dup = malloc(sizeof(char) * (strlength + 1));
	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/**
 * _strlen - get length of a string
 * @str: a string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str != NULL && str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strconcat - concat two strings
 * @first_string: first string
 * @second_string: second string
 *
 * Return: the concatinated string
 */
char *_strconcat(char *first_string, char *second_string)
{
	int len = 0, ft_index = 0, st_index = 0, ct_index = 0;
	char *concat_str;

	if (first_string == NULL && second_string == NULL)
		return (NULL);

	if (first_string == NULL)
		len = _strlen(second_string);
	else if (second_string == NULL)
		len = _strlen(first_string);
	else
		len = _strlen(first_string) + _strlen(second_string);

	concat_str = malloc((len + 1) * sizeof(char));
	if (!concat_str)
		return (NULL);

	while (first_string != NULL && first_string[ft_index] != '\0')
	{
		concat_str[ct_index] = first_string[ft_index];
		ft_index++;
		ct_index++;
	}
	while (second_string != NULL && second_string[st_index] != '\0')
	{
		concat_str[ct_index] = second_string[st_index];
		st_index++;
		ct_index++;
	}

	concat_str[ct_index] = '\0';

	return (concat_str);
}

/**
 * _strcmp - compares to strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if equal lest than 0 if s2 is greater and
 * greater 0 if s1 is greater
 */
int _strcmp(char *s1, char *s2)
{
	int l = 0;

	while (1)
	{
		if (s1[l] == '\0' && s2[l] == '\0')
			return (0);
		else if (s1[l] == s2[l])
		{
			l++;
			continue;
		}
		else
			return (s1[l] - s2[l]);
		l++;
	}
}
