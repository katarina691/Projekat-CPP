#include <string>
#include <iostream>

class IzuzetakFile
{
private:
	std::string m_strError;
	IzuzetakFile() {};
public:
	IzuzetakFile(std::string strError)
		: m_strError(strError) { }
	std::string GetError() { return m_strError; }
};

