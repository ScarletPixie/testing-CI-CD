#include "libsay.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char buffer[50] = "this is a testing string";
	char *firstWord = my_wordcpy(buffer);
	char *secondWord = my_wordcpy(buffer + strlen(firstWord));

	printf("%s\n", firstWord);
	printf("%s\n", secondWord);
	printf("%d\n", empty_str(firstWord));

	free(firstWord);
	free(secondWord);
	return 0;
}