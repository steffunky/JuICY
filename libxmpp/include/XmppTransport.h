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
#include <iostream>
#include <boost/asio.hpp>
#include "tinyxml2.h"
class XmppTransport
{
public:
	XmppTransport();
	bool Connect(const char* host, const char* port);
	~XmppTransport();
private:
	boost::asio::io_service m_ios;
	boost::asio::ip::tcp::endpoint m_endpoint;	
};

#endif // XMPPTRANSPORT_H
