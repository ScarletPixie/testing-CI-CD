#include "libsay.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

void test_my_stpcpy_basic(void)
{
	const char	*testStr1 = "This is a very nice string\n";
	const char	*testStr2 = "";
	const char	*testStr3 = "a";

	char		buffer1[5000];
	char		buffer2[5000];
	char		buffer3[5000];
	char		*result1 = my_stpcpy(buffer1, testStr1);
	char		*result2 = my_stpcpy(buffer2, testStr2);
	char		*result3 = my_stpcpy(buffer3, testStr3);

	TEST_ASSERT_EQUAL_STRING(testStr1, buffer1);
	TEST_ASSERT_EQUAL_STRING(testStr2, buffer2);
	TEST_ASSERT_EQUAL_STRING(testStr3, buffer3);
	TEST_ASSERT_EQUAL_PTR(buffer1 + strlen(buffer1), result1);
	TEST_ASSERT_EQUAL_PTR(buffer2 + strlen(buffer2), result2);
	TEST_ASSERT_EQUAL_PTR(buffer3 + strlen(buffer3), result3);
}

void test_empty_str(void)
{
	TEST_ASSERT_TRUE(empty_str(""));
	TEST_ASSERT_TRUE(empty_str("     "));
	TEST_ASSERT_TRUE(empty_str("\n\t\v\f\r "));
	TEST_ASSERT_FALSE(empty_str("a"));
	TEST_ASSERT_FALSE(empty_str("      \na\n \t\v\f\r"));
}

void test_wordcpy(void)
{
	char	*testStr1 = "blue green yellow black";
	char	*testStr2 = "     sal";
	char	*testStr3 = "    ";
	char	*result1 = my_wordcpy(testStr1);
	char	*result2 = my_wordcpy(testStr1 + 4);
	char	*result3 = my_wordcpy(testStr2);
	char	*result4 = my_wordcpy(testStr3);

	TEST_ASSERT_EQUAL_STRING("blue", result1);
	TEST_ASSERT_EQUAL_STRING("green", result2);
	TEST_ASSERT_EQUAL_STRING("sal", result3);
	TEST_ASSERT_EQUAL_STRING("", result4);

	free(result1);
	free(result2);
	free(result3);
	free(result4);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_my_stpcpy_basic);
	RUN_TEST(test_empty_str);
	RUN_TEST(test_wordcpy);
	return UNITY_END();
}