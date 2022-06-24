#include <utilsBase.h>

#include <devDataSet.h>

#include <fstream>
#include <iostream>

namespace dev
{

void MakeFile_hostname(const std::string& a_hostname)
{
	std::fstream File(GetPath("etc/hostname"), std::ios::out);
	if (File.good())
	{
		File << a_hostname;

		File.close();
	}
}

}
