/**
 * @file variant.cpp
 * @author Matthew Dalrymple
 */
#include <generic/variant.hpp>
#include <sstream>
#include <climits>
#include <limits>
#include <algorithm>

using namespace tools::generic;

//TODO: Try making this simplier, either refactoring code or always save value as string and parse it back out on demand...
// If go the string route, you can still save values to speed up 2nd get call, but reset all internal vars on any set

Variant::Variant()
{
	this->Init();
}

Variant::Variant(const Variant &rhs)
{
	this->Init();
	
	if (rhs._boolValue) {
		this->_boolValue = new bool;
		(*this->_boolValue) = (*rhs._boolValue);
	}
	
	if (rhs._stringValue) {
		this->_stringValue = new std::string;
		(*this->_stringValue) = (*rhs._stringValue);
	}
	
	if (rhs._floatValue) {
		this->_floatValue = new float;
		(*this->_floatValue) = (*rhs._floatValue);
	}
	
	if (rhs._doubleValue) {
		this->_doubleValue = new double;
		(*this->_doubleValue) = (*rhs._doubleValue);
	}
	
	if (rhs._intValue) {
		this->_intValue = new int;
		(*this->_intValue) = (*rhs._intValue);
	}
	
	if (rhs._longValue) {
		this->_longValue = new long;
		(*this->_longValue) = (*rhs._longValue);
	}
}

Variant::~Variant()
{
	this->Clear();
}

void Variant::Init()
{
	this->_boolValue = nullptr;
	this->_stringValue = nullptr;
	this->_floatValue = nullptr;
	this->_doubleValue = nullptr;
	this->_intValue = nullptr;
	this->_longValue = nullptr;
}

void Variant::Clear()
{
	if (this->_boolValue) {
		delete this->_boolValue;
		this->_boolValue = nullptr;
	}
	
	if (this->_stringValue) {
		delete this->_stringValue;
		this->_stringValue = nullptr;
	}
	
	if (this->_floatValue) {
		delete this->_floatValue;
		this->_floatValue = nullptr;
	}
	
	if (this->_doubleValue) {
		delete this->_doubleValue;
		this->_doubleValue = nullptr;
	}
	
	if (this->_intValue) {
		delete this->_intValue;
		this->_intValue = nullptr;
	}
	
	if (this->_longValue) {
		delete this->_longValue;
		this->_longValue = nullptr;
	}
}





bool Variant::Bool()
{
	if (this->_boolValue) {
		return (*this->_boolValue);
	} else {
		return false;
	}
}

void Variant::Bool(bool value)
{
	this->Clear();
	
	this->_boolValue = new bool;
	if (this->_boolValue) {
		(*this->_boolValue) = value;
	} else {
		//TODO: throw exception
	}
	
	this->_intValue = new int;
	if (this->_intValue) {
		if (value) {
			(*this->_intValue) = 1;
		} else {
			(*this->_intValue) = 0;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_longValue = new long;
	if (this->_longValue) {
		if (value) {
			(*this->_longValue) = 1;
		} else {
			(*this->_longValue) = 0;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_floatValue = new float;
	if (this->_floatValue) {
		if (value) {
			(*this->_floatValue) = 1.0f;
		} else {
			(*this->_floatValue) = 0.0f;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_doubleValue = new double;
	if (this->_doubleValue) {
		if (value) {
			(*this->_doubleValue) = 1.0f;
		} else {
			(*this->_doubleValue) = 0.0f;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_stringValue = new std::string;
	if (this->_stringValue) {
		if (value) {
			(*this->_stringValue) = "true";
		} else {
			(*this->_stringValue) = "false";
		}
	} else {
		//TODO: throw exception
	}
}

std::string Variant::String()
{
	if (this->_stringValue) {
		return (*this->_stringValue);
	} else {
		return "";
	}
}

void Variant::String(const std::string &value)
{
	std::string valueLower;
	long long ll = atoll(value.c_str());
	double d = atof(value.c_str());
	
	std::transform(value.begin(), value.end(), valueLower.begin(), tolower);
	
	this->Clear();
	
	this->_stringValue = new std::string;
	if (this->_stringValue) {
		(*this->_stringValue) = value;
	} else {
		//TODO: throw exception
	}
	
	this->_boolValue = new bool;
	if (this->_boolValue) {
		if (valueLower == "true" || valueLower == "yes" || valueLower == "on" || d != 0 || ll != 0) {
			(*this->_boolValue) = true;
		} else {
			(*this->_boolValue) = false;
		}
		
	} else {
		//TODO: throw exception
	}
	
	this->_intValue = new int;
	if (this->_intValue) {
		if (ll > INT_MAX || ll < INT_MIN) {
			(*this->_intValue) = 0;
		} else {
			(*this->_intValue) = static_cast<int>(ll);
		}
	} else {
		//TODO: throw exception
	}
	
	this->_longValue = new long;
	if (this->_longValue) {
		if (ll > LONG_MAX || ll < LONG_MIN) {
			(*this->_longValue) = 0;
		} else {
			(*this->_longValue) = static_cast<long>(ll);
		}
	} else {
		//TODO: throw exception
	}
	
	this->_floatValue = new float;
	if (this->_floatValue) {
		if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min()) {
			(*this->_floatValue) = 0.0f;
		} else {
			(*this->_floatValue) = static_cast<float>(d);
		}
	} else {
		//TODO: throw exception
	}
	
	this->_doubleValue = new double;
	if (this->_doubleValue) {
		(*this->_doubleValue) = d;
	} else {
		//TODO: throw exception
	}
}

float Variant::Float()
{
	if (this->_floatValue) {
		return (*this->_floatValue);
	} else {
		return 0.0f;
	}
}

void Variant::Float(float value)
{
	this->Clear();
	
	this->_floatValue = new float;
	if (this->_floatValue) {
		(*this->_floatValue) = value;
	} else {
		//TODO: throw exception
	}
	
	this->_boolValue = new bool;
	if (this->_boolValue) {
		if (value != 0) {
			(*this->_boolValue) = true;
		} else {
			(*this->_boolValue) = false;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_intValue = new int;
	if (this->_intValue) {
		(*this->_intValue) = static_cast<int>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_longValue = new long;
	if (this->_longValue) {
		(*this->_longValue) = static_cast<long>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_doubleValue = new double;
	if (this->_doubleValue) {
		(*this->_doubleValue) = static_cast<double>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_stringValue = new std::string;
	if (this->_stringValue) {
		std::stringstream ss;
		ss << value;
		(*this->_stringValue) = ss.str();
	} else {
		//TODO: throw exception
	}
}

double Variant::Double()
{
	if (this->_doubleValue) {
		return (*this->_doubleValue);
	} else {
		return 0.0;
	}
}

void Variant::Double(double value)
{
	this->Clear();
	
	this->_doubleValue = new double;
	if (this->_doubleValue) {
		(*this->_doubleValue) = value;
	} else {
		//TODO: throw exception
	}
	
	this->_boolValue = new bool;
	if (this->_boolValue) {
		if (value != 0) {
			(*this->_boolValue) = true;
		} else {
			(*this->_boolValue) = false;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_intValue = new int;
	if (this->_intValue) {
		if (value > INT_MAX || value < INT_MIN) {
			(*this->_intValue) = 0;
		} else {
			(*this->_intValue) = static_cast<int>(value);
		}
	} else {
		//TODO: throw exception
	}
	
	this->_longValue = new long;
	if (this->_longValue) {
		(*this->_longValue) = static_cast<long>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_floatValue = new float;
	if (this->_floatValue) {
		if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min()) {
			(*this->_floatValue) = 0;
		} else {
			(*this->_floatValue) = static_cast<float>(value);
		}
	} else {
		//TODO: throw exception
	}
	
	this->_stringValue = new std::string;
	if (this->_stringValue) {
		std::stringstream ss;
		ss << value;
		(*this->_stringValue) = ss.str();
	} else {
		//TODO: throw exception
	}
}

int Variant::Int()
{
	if (this->_intValue) {
		return (*this->_intValue);
	} else {
		return 0;
	}
}

void Variant::Int(int value)
{
	this->Clear();
	
	this->_intValue = new int;
	if (this->_intValue) {
		(*this->_intValue) = value;
	} else {
		//TODO: throw exception
	}
	
	this->_boolValue = new bool;
	if (this->_boolValue) {
		if (value != 0) {
			(*this->_boolValue) = true;
		} else {
			(*this->_boolValue) = false;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_longValue = new long;
	if (this->_longValue) {
		(*this->_longValue) = static_cast<long>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_floatValue = new float;
	if (this->_floatValue) {
		(*this->_floatValue) = static_cast<float>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_doubleValue = new double;
	if (this->_doubleValue) {
		(*this->_doubleValue) = static_cast<double>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_stringValue = new std::string;
	if (this->_stringValue) {
		std::stringstream ss;
		ss << value;
		(*this->_stringValue) = ss.str();
	} else {
		//TODO: throw exception
	}
}

long Variant::Long()
{
	if (this->_longValue) {
		return (*this->_longValue);
	} else {
		return 0L;
	}
}

void Variant::Long(long value)
{
	this->Clear();
	
	this->_longValue = new long;
	if (this->_longValue) {
		(*this->_longValue) = value;
	} else {
		//TODO: throw exception
	}
	
	this->_boolValue = new bool;
	if (this->_boolValue) {
		if (value != 0) {
			(*this->_boolValue) = true;
		} else {
			(*this->_boolValue) = false;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_intValue = new int;
	if (this->_intValue) {
		if (value > INT_MAX || value < INT_MIN) {
			(*this->_intValue) = 0;
		} else {
			(*this->_intValue) = value;
		}
	} else {
		//TODO: throw exception
	}
	
	this->_floatValue = new float;
	if (this->_floatValue) {
		/*if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min()) {
			(*this->_floatValue) = 0.0f;
		} else {
			(*this->_floatValue) = static_cast<float>(value);
		}*/
		(*this->_floatValue) = static_cast<float>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_doubleValue = new double;
	if (this->_doubleValue) {
		/*if (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min()) {
			(*this->_doubleValue) = 0;
		} else {
			(*this->_doubleValue) = static_cast<double>(value);
		}*/
		(*this->_doubleValue) = static_cast<double>(value);
	} else {
		//TODO: throw exception
	}
	
	this->_stringValue = new std::string;
	if (this->_stringValue) {
		std::stringstream ss;
		ss << value;
		(*this->_stringValue) = ss.str();
	} else {
		//TODO: throw exception
	}
}