/**
*
* @File : XmppTransport.h
*
* @Authors : Grokafar
*
* @Date : 04/04/2015
*
* @Version : V0.1
*
* @Synopsis : Classe de communication avec un serveur XMPP
**/
#ifndef XMPPTRANSPORT_H
#define XMPPTRANSPORT_H
#include <boost/asio.hpp>
class XmppTransport
{
public:
	XmppTransport();
	bool Connect(const char* host, const char* port);
	std::string GetLog(); // just for debugging
	~XmppTransport();
private:
	boost::asio::io_service m_ios;
	boost::asio::ip::tcp::endpoint m_endpoint;
	std::string m_log; //just for debugging
	
};

#endif // XMPPTRANSPORT_H
