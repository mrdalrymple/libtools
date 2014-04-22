/**
 * @file string.cpp
 * @author Matthew Dalrymple
 */

#include <string/string.hpp>

#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <string.h>

using namespace tools::string;

std::string tools::string::StringToLower(const std::string &str)
{
	std::string ret;
	std::transform(str.begin(), str.end(), ret.begin(), tolower);
	return ret;
}

std::string tools::string::StringToUpper(const std::string &str)
{
	std::string ret;
	std::transform(str.begin(), str.end(), ret.begin(), toupper);
	return ret;
}

std::string tools::string::Trim(const std::string &str)
{
	return "";
}

std::string tools::string::GetTimestamp()
{
	std::string timestamp = "";
	
	time_t t = 0;
	tm* ptm = nullptr;
	
	time(&t);
	ptm = localtime(&t);
	
	if (ptm) {
		const int BUFF_SIZE = 15;
		char buff[BUFF_SIZE];
		memset(buff, '\0', 15);
		
		snprintf(buff, BUFF_SIZE, "%04d%02d%02d%02d%02d%02d",
			ptm->tm_year + 1900,
			ptm->tm_mon + 1,
			ptm->tm_mday,
			ptm->tm_hour,
			ptm->tm_min,
			ptm->tm_sec);
			
		timestamp = buff;
	} else {
	  //TODO: throw exception
	}
	
	return timestamp;
}

std::string tools::string::GenerateUniqueString(const char* prefix, const char* suffix)
{
	std::string uniqueString = "";
	
	if (prefix) {
		uniqueString += prefix;
	}
	
	uniqueString += tools::string::GetTimestampz();
	
	if (suffix) {
		uniqueString += suffix;
	}
	
	return uniqueString;
}

void tools::string::EmptyStringStream(std::stringstream &ss)
{
	ss.str(std::string());
}