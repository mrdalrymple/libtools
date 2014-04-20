/**
 * @file string.hpp
 * @author Matthew Dalrymple
 */
#pragma once

#ifndef _STRING_HPP_
#define _STRING_HPP_

#include <string>
#include <sstream>

namespace tools {
	
	namespace string {
		
		inline std::string StringToLower(const std::string &str);
		
		inline std::string StringToUpper(const std::string &str);
		
		std::string GetTimestamp();
		
		std::string GenerateUniqueString(const char* prefix = nullptr, const char* suffix = nullptr);
		
		inline void EmptyStringStream(std::stringstream &ss);
		
	}
	
}

#endif