/**
 * @file os.hpp
 * @author Matthew Dalrymple
 */
#pragma once

#ifndef _OS_HPP_
#define _OS_HPP_

#if defined(_WIN32)
#define OS_ENV_WINDOWS
#elif defined(__linux__)
#define OS_ENV_LINUX
#elif defined(__unix__)
#define OS_ENV_UNIX
#elif defined(__APPLE__)
#define OS_ENV_APPLE
#elif defined(__ANDROID__)
#define OS_ENV_ANDROID
#endif

#if defined(OS_ENV_LINUX) || defined(OS_ENV_APPLE) || defined(OS_ENV_UNIX) || defined(OS_ENV_ANDROID)
#define OS_ENV_UNIX_ANY
#endif

#endif