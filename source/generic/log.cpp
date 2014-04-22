/**
* @file log.cpp
* @author Matthew Dalrymple
**/

#include <fstream>
#include <stdarg.h>
#include <generic/log.hpp>

using namespace tools::generic;

// The name +/- the path of the logging file
std::string	Log::m_fileName;

/**
* Sets the file name +/- the path that will be used to log data
* If no path provided the PWD is used
* MUST BE SET BEFORE USE OF ANY FURTHER METHODS
**/
bool	tools::generic::Log::setFile( std::string fileName )
{
	m_fileName = fileName;
	return erase();
}

/**
* A basic log with no prefix
* uses the standard printf() parameters
**/
bool	tools::generic::Log::log( char* msg, ... )
{
	if(!fileIsSet())
		return false;

	char		formatted[1024];
	va_list	ptr;
	
	va_start(ptr, msg);
	vsprintf(formatted, msg, ptr);
	va_end(ptr);

	if(write(formatted))
		return true;
	else
		return false;
}

/**
* A logging method with a prefix of "Warning: "
* uses the standard printf() parameters
**/
bool	tools::generic::Log::warning( char* msg, ... )
{
	if(!fileIsSet())
		return false;

	char		formatted[1024];
	va_list	ptr;
	
	va_start(ptr, msg);
	vsprintf(formatted, msg, ptr);
	va_end(ptr);

	if(write(formatted, "Warning: "))
		return true;
	else
		return false; 
}

/**
* A logging method with a prefix of "Error: "
* uses the standard printf() parameters
**/
bool	tools::generic::Log::error( char* msg, ... )
{
	if(!fileIsSet())
		return false;

	char		formatted[1024];
	va_list	ptr;
	
	va_start(ptr, msg);
	vsprintf(formatted, msg, ptr);
	va_end(ptr);
	
	if(write(formatted, "Error: "))
		return true;
	else
		return false;
}


/**
* A logging method will only log if the verification is false
* This method tests isTrue and !isTrue will log the message
* uses the standard printf() parameters after the boolean parameter
**/
bool	tools::generic::Log::verify( bool isTrue, char* msg, ... )
{
	if(!fileIsSet())
		return false;
	if(isTrue)
		return true;

	char		formatted[1024];
	va_list	ptr;
	
	va_start(ptr, msg);
	vsprintf(formatted, msg, ptr);
	va_end(ptr);

	if(write(formatted))
		return true;
	else
		return false;
}


/**
* Writes the message to the file set by setFile()
* prelude is set before the message
* Returns false on !fileIsSet() or on an error opening the log file
**/
bool	tools::generic::Log::write( std::string msg, std::string prelude )
{
	if(!fileIsSet())
		return false;
	std::fstream	file;
	// insert the prelude into the beginning of the message
	msg.insert(0, prelude);
	file.open(m_fileName.c_str(), std::ios::out | std::ios::app);
	
	if(file.is_open())
		file << msg.c_str() << '\n';
	else
		return false;
	file.close();
	return true;
}

/**
* Checks to see if the file was set before use
* Returns false on no setFile() call
**/
bool tools::generic::Log::fileIsSet()
{
	return !m_fileName.empty();
}

/**
* Clears the log file of any data currently in it
* Returns false on no setFile() call
**/
bool tools::generic::Log::erase()
{
	if(!fileIsSet())
		return false;
	std::fstream file(m_fileName.c_str(), std::ios::out);
	file.close();
	return true;
}
