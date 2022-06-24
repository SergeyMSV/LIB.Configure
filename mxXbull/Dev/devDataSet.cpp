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
	Period = a_PTree.get<uint32_t>("emailsender.period");
}

tDataSetConfig::tDataSetConfig(const std::string& a_fileName)
{
	boost::property_tree::json_parser::read_json(a_fileName, m_PTree);
	m_HostName = m_PTree.get<std::string>("hostname");
	m_Email = tEmail(m_PTree);
	m_EmailSender = tEmailSender(m_PTree);
}

std::string GetPath(const std::string& a_dir)
{
	//#ifdef OS_WINDOWS
		//return "/" + a_dir;
	//#else
	return "testfs/" + a_dir;
	//#endif
}

}
