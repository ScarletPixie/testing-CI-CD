#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char	*my_stpcpy(char *dst, const char *src)
{
	for (;*src; src++, dst++)
		*dst = *src;
	*dst = '\0';
	return dst;
}

char	*my_wordcpy(const char *src)
{
	size_t	size = 0;
	char	*buffer = NULL;

	if (isspace(src[size]))
	{
		while (*src && isspace(*src))
			src++;
	}
	while (src[size] && !isspace(src[size]))
		size++;

	buffer = malloc(size + 1);
	if (!buffer)
		abort();

	buffer[size] = '\0';
	for (size_t i = 0; i < size; i++)
		buffer[i] = src[i];

	return buffer;
}

int	empty_str(const char *s)
{
	if (!s || !*s)
		return 1;

	while (*s)
	{
		if (!isspace(*s))
			return 0;
		s++;
	}
	return 1;
}
