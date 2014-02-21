/**
* LOG.HPP
* By Matthew Dalrymple
**/

#include <fstream>
#include <stdarg.h>
#include "../include/log.hpp"

// The name +/- the path of the logging file
std::string	Log::m_fileName;

/**
* Sets the file name +/- the path that will be used to log data
* If no path provided the PWD is used
* MUST BE SET BEFORE USE OF ANY FURTHER METHODS
**/
bool	Log::setFile( std::string fileName )
{
	m_fileName = fileName;
	return erase();
}

/**
* A basic log with no prefix
* uses the standard printf() parameters
**/
bool	Log::log( char* msg, ... )
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
bool	Log::warning( char* msg, ... )
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
bool	Log::error( char* msg, ... )
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
bool	Log::verify( bool isTrue, char* msg, ... )
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
bool	Log::write( std::string msg, std::string prelude )
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
bool Log::fileIsSet()
{
	return !m_fileName.empty();
}

/**
* Clears the log file of any data currently in it
* Returns false on no setFile() call
**/
bool Log::erase()
{
	if(!fileIsSet())
		return false;
	std::fstream file(m_fileName.c_str(), std::ios::out);
	file.close();
	return true;
}
