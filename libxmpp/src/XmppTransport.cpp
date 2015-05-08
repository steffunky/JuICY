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
#include "XmppTransport.h"

XmppTransport::XmppTransport()
{
}
bool XmppTransport::Connect(const char* host,const char* port)
{
	/**/
	boost::asio::ip::tcp::resolver resolver(m_ios);
	
	boost::asio::ip::tcp::resolver::query query(host,port);
	boost::asio::ip::tcp::resolver::iterator endpoint_it=resolver.resolve(query);
	m_endpoint=*endpoint_it;
	boost::asio::ip::tcp::socket socket(m_ios);
	socket.connect(m_endpoint);
	 /**/
	std::string log;
	log+="Client : \n";
	tinyxml2::XMLPrinter stream;
	stream.PushHeader(false,true);
	stream.OpenElement("stream:stream");
	stream.PushAttribute("to",host);
	stream.PushAttribute("xmlns","jabber:client");
	stream.PushAttribute("xmlns:stream","http://etherx.jabber.org/streams");
	stream.PushAttribute("version","1.0");
	stream.PushText("");
	
	log=stream.CStr();
	log+="\n Serveur : \n";
	std::cout<<log<<std::endl;
	socket.send(boost::asio::buffer(std::string(stream.CStr())));
	boost::array<char, 2048> buf;
	int len=1;
	boost::system::error_code error;
	//Waiting for stream...
	while(socket.available()==0);
	socket.read_some(boost::asio::buffer(buf),error);
	std::cout<<buf.data()<<std::endl;
	//Wainting for features
	while(socket.available()==0);
	socket.read_some(boost::asio::buffer(buf),error);
	std::cout<<buf.data()<<std::endl;
	}
XmppTransport::~XmppTransport()
{
}

