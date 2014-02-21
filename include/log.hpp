/**
* LOG.HPP
* By Matthew Dalrymple
**/

#ifndef __LOG_HPP__
#define __LOG_HPP__

#include <string>

/**
* A method of "logging" data to a file
**/
class Log
{
public:
	/**
	* Sets the file name +/- the path that will be used to log data
	* If no path provided the PWD is used
	* MUST BE SET BEFORE USE OF ANY FURTHER METHODS
	**/
	static bool		setFile	( std::string fileName );
	
	/**
	* A basic log with no prefix
	* uses the standard printf() parameters
	**/
	static bool		log		( char* msg, ... );
	
	/**
	* A logging method with a prefix of "Warning: "
	* uses the standard printf() parameters
	**/
	static bool		warning	( char* msg, ... );
	
	/**
	* A logging method with a prefix of "Error: "
	* uses the standard printf() parameters
	**/
	static bool		error	( char* msg, ... );
	
	/**
	* A logging method will only log if the verification is false
	* This method tests isTrue and !isTrue will log the message
	* uses the standard printf() parameters after the boolean parameter
	**/
	static bool		verify	( bool isTrue, char* msg, ... );
	
	/**
	* Checks to see if the file was set before use
	* Returns false on no setFile() call
	**/
	static bool		fileIsSet	();
	
	/**
	* Clears the log file of any data currently in it
	* Returns false on no setFile() call
	**/
	static bool		erase	();
private:
	
	/**
	* Writes the message to the file set by setFile()
	* prelude is set before the message
	* Returns false on !fileIsSet() or on an error opening the log file
	**/
	static bool		write	( std::string msg, std::string prelude = "" );
	static std::string	m_fileName;  // The name +/- the path of the logging file
};

/**

[EXAMPLE USE]

#include "../include/log.hpp"

int errorFunction()
{
	return 0;
}

int main()
{
	int error = errorFunction();
	bool truth = false;
	
	Log::setFile("Errors.log");
	Log::log("Program started successfully");
	Log::error("An error value of %i was returned", error);
	Log::verify(truth, "The truth is a lie!");
	Log::verify(!truth, "The truth is NOT a lie!");
	Log::warning("The program has come to an end without doing anything useful"):
	
	return 0;
}

[/EXAMPLE USE]

[EXAMPLE OUTPUT: Errors.log]
Program started successfully
Error: An error value of 0 was returned
The truth is a lie!
Warning: The program has come to an end without doing anything useful
[/EXAMPLE OUTPUT]

**/
#endif
