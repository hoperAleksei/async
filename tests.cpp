#include "gtest/gtest.h"
#include "lib.h"

TEST(encode, test) {
	char* message = "Hello, World!";
	char expected[100] = "SGVsbG8sIFdvcmxkIQ==";
	char res[100];
	encode(res, message);
	
	int i = 0;
	while ((expected[i] != '\0') && (res[i] != '\0'))
	{
		if (expected[i] != res[i])
		{
			FAIL();
		}
		++i;
	}
	if ((expected[i] == '\0') && (res[i] == '\0'))
	{
		SUCCEED();
	}
	else
	{
		FAIL();
	}
}


TEST(decode, test) {
	char* inp = "SGVsbG8sIFdvcmxkIQ==";
	char out[100] = "Hello, World!";
	char res[100];
	decode(res, inp);
	
	int i = 0;
	while ((out[i] != '\0') && (res[i] != '\0'))
	{
		if (out[i] != res[i])
		{
			FAIL();
		}
		++i;
	}
	if ((out[i] == '\0') && (res[i] == '\0'))
	{
		SUCCEED();
	}
	else
	{
		FAIL();
	}
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
