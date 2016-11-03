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
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits){
	ASSERT_EQ(soundex.encode("Acdl"), std::string("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters){
	ASSERT_EQ(soundex.encode("Dcdlb").length(), 4u);
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters){
	ASSERT_EQ(soundex.encode("Baeiouhycdl"), std::string("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings){
	ASSERT_EQ(soundex.encodedDigits('b'), soundex.encodedDigits('f'));
	ASSERT_EQ(soundex.encodedDigits('c'), soundex.encodedDigits('g'));
	ASSERT_EQ(soundex.encodedDigits('d'), soundex.encodedDigits('t'));

	ASSERT_EQ(soundex.encode("Abfcgdt"), std::string("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter){
	ASSERT_EQ(soundex.encode("abcd").substr(0, 1), std::string("A"));
}

TEST_F(SoundexEncoding, IgnoreVowelLikeLetters){
	ASSERT_EQ(soundex.encode("BaAeEiIoOuUhHyYcdl"), std::string("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicateslst){
	ASSERT_EQ(soundex.encode("Bbcd"), std::string("B230"));
}

TEST_F(SoundexEncoding, DoesNotCombineDuplicateEncodingsSeparatedByVowels){
	ASSERT_EQ(soundex.encode("Jbob"), std::string("J110"));
}

int main(int argc, char ** argv){
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}

