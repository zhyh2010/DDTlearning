#ifndef _SOUNDEX_H_
#define _SOUNDEX_H_

#include <string>

class Soundex{
	static const size_t MaxCodeLength{ 4 };
public:
	std::string encode(const std::string & word) const{
		return zeroPad(head(word) + encodedDigits(word));
	}

private:
	std::string head(const std::string & word) const{
		return word.substr(0, 1);
	}

	std::string encodedDigits(const std::string & word) const{
		if (word.length() > 1)
			return encodedDigits();
		return "";
	}

	std::string encodedDigits() const{
		return "1";
	}

	std::string zeroPad(const std::string & word) const{
		auto zerosNeed = MaxCodeLength - word.length();
		return word + std::string(zerosNeed, '0');
	}
};

#endif // _SOUNDEX_H_
