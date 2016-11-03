#ifndef _SOUNDEX_H_
#define _SOUNDEX_H_

#include <string>
#include <unordered_map>

class Soundex{
	static const size_t MaxCodeLength{ 4 };
public:
	std::string encode(const std::string & word) const{
		return zeroPad(head(word) + encodedDigits(tail(word)));
	}

	std::string encodedDigits(char letter) const{
		const std::unordered_map<char, std::string> encodings{
			{ 'b', "1" }, { 'f', "1" }, { 'p', "1" }, { 'v', "1" },
			{ 'c', "2" }, { 'g', "2" }, { 'j', "2" }, { 'k', "2" },
			{ 'q', "2" }, { 's', "2" }, { 'x', "2" }, { 'z', "2" },
			{ 'd', "3" }, { 't', "3" },
			{ 'l', "4" },
			{ 'm', "5" }, { 'n', "5" },
			{ 'r', "6" }
		};
		auto it = encodings.find(letter);
		return it == encodings.end() ? "" : it->second;
	}

private:
	std::string head(const std::string & word) const{
		return word.substr(0, 1);
	}

	std::string tail(const std::string & word) const{
		return word.substr(1);
	}

	std::string encodedDigits(const std::string & word) const{
		std::string encoding;
		for (auto letter : word){
			if (isComplete(encoding)) break;
			if (encodedDigits(letter) != lastDigit(encoding))
				encoding += encodedDigits(letter);
		}			
		return encoding;
	}

	std::string lastDigit(const std::string & encoding) const{
		if (encoding.empty()) return "";
		return std::string(1, encoding.back());
	}

	bool isComplete(const std::string & encoding) const{
		return encoding.length() == MaxCodeLength - 1;
	}

	std::string zeroPad(const std::string & word) const{
		auto zerosNeed = MaxCodeLength - word.length();
		return word + std::string(zerosNeed, '0');
	}
};

#endif // _SOUNDEX_H_
