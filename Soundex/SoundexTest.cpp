class Soundex{

};

#include "gtest/gtest.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord){
	Soundex soundex;
}

int main(int argc, char ** argv){
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}

