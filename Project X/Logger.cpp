#include "Logger.h"
#include "Logger.h"
#include"Utilities.h"
const string CLogger::m_sFileName = "Log.txt";
CLogger* CLogger::m_pThis = NULL;
ofstream CLogger::m_Logfile;
CLogger::CLogger()
{

}
CLogger* CLogger::GetLogger() {
	if (m_pThis == NULL) {
		m_pThis = new CLogger();
		m_Logfile.open(m_sFileName.c_str(), ios::out | ios::app);
	}
	return m_pThis;
}

void CLogger::Log(const char * format, ...)
{
	char* sMessage = NULL;
	int nLength = 0;
	va_list args;
	va_start(args, format);
	
	nLength = _vscprintf(format, args) + 1;
	sMessage = new char[nLength];
	vsprintf_s(sMessage, nLength, format, args);
	
	m_Logfile << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
	va_end(args);

	delete[] sMessage;
}


template<typename T> void CLogger::Log(T const & logMessage)

{
	(const string&)logMessage;
	logfile << Util::CurrentDateTime() << ":\t";
	logfile << logMessage << "\n";

}

template<typename T>CLogger& CLogger::operator<<(T const & logMessage)
{
	(const string&)logMessage;
	logfile << "\n" << Util::CurrentDateTime() << ":\t";
	logfile << logMessage << "\n";
	return *this;
}


