#ifndef CUSTOM_CLogger_H
#define CUSTOM_CLogger_H
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>
using namespace std;
#define LOGGER CLogger::GetLogger()

class CLogger
{
public:
	template<typename T> void Log(T const & logMessage);                   // logMessage - то что будет логироваться .
	template<typename T>CLogger& operator<<(T const & logMessage);

	void Log(const char * format, ...);


	static CLogger* GetLogger();
private:
	
	CLogger();
	
	CLogger(const CLogger&) {};             
	CLogger& operator=(const CLogger&) { return *this; }; 
	static const std::string m_sFileName;

	static CLogger* m_pThis;
	
	static ofstream m_Logfile;
};
#endif