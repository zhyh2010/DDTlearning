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

int main(int argc, char ** argv){
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}

