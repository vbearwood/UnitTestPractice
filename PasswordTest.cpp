/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, MultipleLeadingCharacters) {
    Password my_password;
    int actual = my_password.count_leading_characters("aaabc123");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, NoLeadingCharacters) {
    Password my_password;
    int actual = my_password.count_leading_characters("abc123");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, HasMixedCase) {
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("MixedCase"));
    ASSERT_FALSE(my_password.has_mixed_case("ALLUPPERCASE"));
    ASSERT_FALSE(my_password.has_mixed_case("alllowercase"));
}
