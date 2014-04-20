/**
* @file variant.hpp
* @author Matthew Dalrymple
**/
#pragma once

#ifndef __VARIANT_HPP__
#define __VARIANT_HPP__

#include <string>

namespace tools
{
	
	namespace generic
	{
		
		class Variant
		{
		public:
			Variant();
			Variant(const Variant &rhs);
			~Variant();
			
			void Clear();
			
			bool Bool();
			void Bool(bool value);
			
			std::string String();
			void String(const std::string &value);
			
			float Float();
			void Float(float value);
			
			double Double();
			void Double(double value);
			
			int Int();
			void Int(int value);
			
			long Long();
			void Long(long value);
			
		private:
			void Init();
			
		private:
			bool* _boolValue;
			std::string* _stringValue;
			float* _floatValue;
			double* _doubleValue;
			int* _intValue;
			long* _longValue;
		};
		
	}
}

#endif