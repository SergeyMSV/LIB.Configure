#include <utilsBase.h>

#include <devDataSet.h>

#include <fstream>
#include <iostream>

namespace dev
{

void MakeFile_hostname(const std::string& a_hostname)
{
	std::string Path = "/etc/hostname";

#if defined(_WIN32)
	Path = SetWinTestPath(Path);
#endif

	std::fstream File(Path, std::ios::out);
	if (File.good())
	{
		File << a_hostname;
		File.close();
	}
}

}
