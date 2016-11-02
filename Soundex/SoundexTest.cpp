#include <string>

class Soundex{
public:
	std::string encode(const std::string & word) const{
		return zeroPad(word);
	}

private:
	std::string zeroPad(const std::string & word) const{
		return word + "000";
	}
};

#include "gtest/gtest.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord){
	Soundex soundex;

	auto encoded = soundex.encode("A");
	ASSERT_EQ(encoded, std::string("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits){
	Soundex soundex;
	auto encoded = soundex.encode("I");
	ASSERT_EQ(encoded, std::string("I000"));
}

int main(int argc, char ** argv){
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}

