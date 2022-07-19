#pragma once

#include <string>

#include <boost/property_tree/ptree.hpp>

namespace dev
{

struct tEmail
{
	std::string User;
	std::string Password;
	std::string Host;
	uint16_t Port = 0;
	std::string From;
	bool TLS = false;
	bool Auth = false;

	tEmail() = default;
	explicit tEmail(boost::property_tree::ptree a_PTree);
};

struct tEmailSender
{
	std::string MailTo;
	uint32_t Period = 0; //in seconds

	tEmailSender() = default;
	explicit tEmailSender(boost::property_tree::ptree a_PTree);
};

struct tConfigFiles
{
	std::string msmtprc;
	std::string muttrc;

	tConfigFiles() = default;
	explicit tConfigFiles(boost::property_tree::ptree a_PTree);
};

class tDataSetConfig
{
	std::string m_HostName;
	tEmail m_Email;
	tEmailSender m_EmailSender;

	tConfigFiles m_ConfigFiles;

	boost::property_tree::ptree m_PTree;

public:
	explicit tDataSetConfig(const std::string& a_fileName);

	std::string GetHostName() { return m_HostName; }
	tEmail GetEmail() const { return m_Email; }
	tEmailSender GetEmailSender() const { return m_EmailSender; }
	tConfigFiles GetConfigFiles() const { return m_ConfigFiles; }
};

#if defined(_WIN32)
std::string SetWinTestPath(const std::string& a_dir);
#endif

}