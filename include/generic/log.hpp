/**
* @file log.hpp
* @author Matthew Dalrymple
**/
#pragma once

#ifndef __LOG_HPP__
#define __LOG_HPP__

#include <string>

namespace tools
{
	
	namespace generic
	{
		
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
			static bool		setFile( std::string fileName );
			
			/**
			* A basic log with no prefix
			* uses the standard printf() parameters
			**/
			static bool		log	( char* msg, ... );
			
			/**
			* A logging method with a prefix of "Warning: "
			* uses the standard printf() parameters
			**/
			static bool		warning( char* msg, ... );
			
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
			static bool		verify( bool isTrue, char* msg, ... );
			
			/**
			* Checks to see if the file was set before use
			* Returns false on no setFile() call
			**/
			static bool		fileIsSet();
			
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

	}

}

#endif
