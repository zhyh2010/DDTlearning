#include "gtest/gtest.h"
#include "Soundex.h"

class SoundexEncoding :public testing::Test{
public:
	Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord){
	auto encoded = soundex.encode("A");
	ASSERT_EQ(encoded, std::string("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits){
	auto encoded = soundex.encode("I");
	ASSERT_EQ(encoded, std::string("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits){
	EXPECT_EQ(soundex.encode("Ab"), std::string("A100"));
	EXPECT_EQ(soundex.encode("Ac"), std::string("A200"));
	EXPECT_EQ(soundex.encode("Ad"), std::string("A300"));
	EXPECT_EQ(soundex.encode("Ax"), std::string("A200"));
	EXPECT_EQ(soundex.encode("A@"), std::string("A000"));
	EXPECT_EQ(soundex.encode("AB"), std::string("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits){
	ASSERT_EQ(soundex.encode("Acdl"), std::string("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters){
	ASSERT_EQ(soundex.encode("Dcdlb").length(), 4u);
}

int main(int argc, char ** argv){
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}

