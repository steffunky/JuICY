/**
*
* @File : XmppTransport.cpp
*
* @Authors : Grokafar
*
* @Date : 04/04/2015
*
* @Version : V0.1
*
* @Synopsis : Implémentation de XmppTransport
**/
#include "../include/XmppTransport.h"

XmppTransport::XmppTransport()
{
}
bool XmppTransport::Connect(const char* host,const char* port)
{
	boost::asio::ip::tcp::resolver resolver(m_ios);
	
	boost::asio::ip::tcp::resolver::query query(host,port);
	boost::asio::ip::tcp::resolver::iterator endpoint_it=resolver.resolve(query);
	m_endpoint=*endpoint_it;
	
	boost::asio::ip::tcp::socket socket(m_ios);
	socket.connect(m_endpoint);
	std::string stream="<?xml version='1.0'?>\
						   <stream:stream\
							   from='juliet@im.example.com'\
							   to='im.example.com'\
							   version='1.0'\
							   xml:lang='en'\
							   xmlns='jabber:client'\
							   xmlns:stream='http://etherx.jabber.org/streams'>";
	socket.send(boost::asio::buffer(stream));
	stream="";
	boost::system::error_code error;
	boost::array<char, 128> buf;
	while(error!=boost::asio::error::eof)
	{	
		socket.read_some(boost::asio::buffer(buf), error);
		stream+=buf.data();
	}
	m_log=stream;
}
std::string XmppTransport::GetLog()
{
	return m_log;
}
XmppTransport::~XmppTransport()
{
}

