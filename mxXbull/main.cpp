#include <utilsBase.h>

#include <devDataSet.h>

#include <iostream>

#include <boost/filesystem.hpp>

namespace dev
{

void MakeFile_hostname(const std::string& a_hostname);
void MakeFile_msmtprc(const tEmail& a_email);
void MakeFile_muttrc(const std::string& a_hostname, const tEmail& a_email);

}

std::string GetPath(const std::string& a_dir, bool a_testPath)
{
	if (a_testPath)
		return "/" + a_dir;

	return "testfs/" + a_dir;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
		return static_cast<int>(utils::tExitCode::EX_NOINPUT);

	try
	{
		boost::filesystem::path Path{ argv[1] };
		boost::filesystem::path PathFile = Path.filename();

		dev::tDataSetConfig DsConfig(PathFile.string());

		dev::tEmail Email = DsConfig.GetEmail();

		//dev::MakeFile_hostname(DsConfig.GetHostName());
		dev::MakeFile_msmtprc(Email);
		dev::MakeFile_muttrc(DsConfig.GetHostName(), Email);

		//[TBD] it's possible to make files in one folder and then move them with script into appropriate folders and set them access permissions
		//[TBD] set access permissions to the files and maybe reboot the system - maybe with bash-script
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";

		return static_cast<int>(utils::tExitCode::EX_NOINPUT);
	}

	return static_cast<int>(utils::tExitCode::EX_OK);
}
