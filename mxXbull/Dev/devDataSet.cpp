#include "devDataSet.h"

#include <boost/property_tree/json_parser.hpp>

namespace dev
{

tEmail::tEmail(boost::property_tree::ptree a_PTree)
{
	User = a_PTree.get<std::string>("email.user");
	Password = a_PTree.get<std::string>("email.password");
	Host = a_PTree.get<std::string>("email.host");
	Port = a_PTree.get<uint16_t>("email.port");
	From = a_PTree.get<std::string>("email.from");
	TLS = a_PTree.get<bool>("email.tls");
	Auth = a_PTree.get<bool>("email.auth");
}

tEmailSender::tEmailSender(boost::property_tree::ptree a_PTree)
{
	MailTo = a_PTree.get<std::string>("emailsender.mail_to");
	Period = a_PTree.get<uint32_t>("emailsender.period");
}

tConfigFiles::tConfigFiles(boost::property_tree::ptree a_PTree)
{
	msmtprc = a_PTree.get<std::string>("config_files.msmtprc");
	muttrc = a_PTree.get<std::string>("config_files.muttrc");

#if defined(_WIN32)
	msmtprc = SetWinTestPath(msmtprc);
	muttrc = SetWinTestPath(muttrc);
#endif
}

tDataSetConfig::tDataSetConfig(const std::string& a_fileName)
{
	boost::property_tree::json_parser::read_json(a_fileName, m_PTree);
	m_HostName = m_PTree.get<std::string>("hostname");
	m_Email = tEmail(m_PTree);
	m_EmailSender = tEmailSender(m_PTree);

	m_ConfigFiles = tConfigFiles(m_PTree);
}

#if defined(_WIN32)
std::string SetWinTestPath(const std::string& a_dir)
{
	std::string Path = "test_root_fs";
	if (a_dir.size() > 0 && a_dir[0] != '/')
		Path += "/";
	Path += a_dir;
	return Path;
}
#endif

}
