#include <gtest/gtest.h>
#include <string/string.hpp>

using namespace tools::string;

TEST(Stringz, transforms) {
	EXPECT_EQ("hello world", StringToLower("hello world"));
	EXPECT_EQ("hello world", StringToLower("HELLO WORLD"));
	
	EXPECT_EQ("HELLO WORLD", StringToUpper("HELLO WORLD"));
	EXPECT_EQ("HELLO WORLD", StringToUpper("hello world"));
	
	EXPECT_EQ("", Trim(" "));
	EXPECT_EQ("hello world", Trim("  hello world    "));
}