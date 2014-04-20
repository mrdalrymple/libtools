#include <gtest/gtest.h>
#include <generic/variant.hpp>
#include <climits>
#include <sstream>

using namespace tools::generic;

TEST(Variant, defaults) {
	Variant v;
	
	EXPECT_FALSE(v.Bool());
	EXPECT_EQ(0, v.Int());
	EXPECT_EQ(0, v.Long());
	EXPECT_EQ(0, v.Float());
	EXPECT_EQ(0, v.Double());
	EXPECT_EQ("", v.String());
}

TEST(Variant, setters) {
	Variant v;

	// Boolean
	v.Bool(true);
	EXPECT_TRUE(v.Bool());
	v.Bool(false);
	EXPECT_FALSE(v.Bool());
	
	// Int
	v.Int(99);
	EXPECT_EQ(99, v.Int());
	v.Int(-1287);
	EXPECT_EQ(-1287, v.Int());
	
	// Long
	v.Long(99);
	EXPECT_EQ(99, v.Long());
	v.Long(-1287);
	EXPECT_EQ(-1287, v.Long());
	
	// Float
	v.Float(59.25f);
	EXPECT_EQ(59.25, v.Float());
	v.Float(-3412.50f);
	EXPECT_EQ(-3412.50f, v.Float());
	
	// Double
	v.Double(59.25f);
	EXPECT_EQ(59.25f, v.Double());
	v.Double(-3412.50f);
	EXPECT_EQ(-3412.50f, v.Double());
	
	// Double
	v.String("hello world");
	EXPECT_EQ("hello world", v.String());
	v.String("foo bar");
	EXPECT_EQ("foo bar", v.String());
}

TEST(Variant, operators) {
	Variant v;
	
	//v = 1;
}

TEST(Variant, conversion) {
	Variant v;
	std::stringstream ss;
	
	// Boolean
	v.Bool(true);
	EXPECT_GE(1, v.Int());
	EXPECT_GE(1, v.Long());
	EXPECT_GE(1.0f, v.Float());
	EXPECT_GE(1.0f, v.Double());
	EXPECT_EQ("true", v.String());
	
	v.Bool(false);
	EXPECT_EQ(0, v.Int());
	EXPECT_EQ(0, v.Long());
	EXPECT_EQ(0.0f, v.Float());
	EXPECT_EQ(0.0f, v.Double());
	EXPECT_EQ("false", v.String());
	
	// Int
	v.Int(0);
	EXPECT_FALSE(v.Bool());
	v.Int(450);
	EXPECT_TRUE(v.Bool());
	EXPECT_EQ(450, v.Long());
	EXPECT_EQ(450.0f, v.Float());
	EXPECT_EQ(450.0f, v.Double());
	EXPECT_EQ("450", v.String());
	v.Int(-1283);
	EXPECT_TRUE(v.Bool());
	EXPECT_EQ(-1283, v.Long());
	EXPECT_EQ(-1283.0f, v.Float());
	EXPECT_EQ(-1283.0f, v.Double());
	EXPECT_EQ("-1283", v.String());
	
	// Long
	v.Long(0);
	EXPECT_FALSE(v.Bool());
	v.Long(98);
	EXPECT_TRUE(v.Bool());
	EXPECT_EQ(98, v.Int());
	EXPECT_EQ(98.0f, v.Float());
	EXPECT_EQ(98.0f, v.Double());
	EXPECT_EQ("98", v.String());
	v.Long(-530);
	EXPECT_TRUE(v.Bool());
	EXPECT_EQ(-530, v.Int());
	EXPECT_EQ(-530.0f, v.Float());
	EXPECT_EQ(-530.0f, v.Double());
	EXPECT_EQ("-530", v.String());
	v.Long(LONG_MAX);
	EXPECT_TRUE(v.Bool());
	EXPECT_EQ(0, v.Int());
	EXPECT_EQ(LONG_MAX, v.Float());
	EXPECT_EQ(LONG_MAX, v.Double());
	ss.str(std::string());
	ss << LONG_MAX;
	std::string a = ss.str();
	EXPECT_EQ(a, v.String());
	v.Long(LONG_MIN);
	EXPECT_TRUE(v.Bool());
	EXPECT_EQ(0, v.Int());
	EXPECT_EQ(LONG_MIN, v.Float());
	EXPECT_EQ(LONG_MIN, v.Double());
	ss.str(std::string());
	ss << LONG_MIN;
	std::string b = ss.str();
	EXPECT_EQ(b, v.String());
	
	// Float
	
	// Double
	
	// String
	
}