//
// Created by trochej on 10/15/20.
//

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int serve_agent(tcp::socket &socket)
{
	boost::system::error_code ignored_error;
	boost::asio::write(socket, boost::asio::buffer("Helo, agent"), ignored_error);

	return 0;
}

int main()
{
    boost::asio::io_context io_context;

    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 5003));

    for (;;)
    {
      tcp::socket socket(io_context);
      acceptor.accept(socket);

      serve_agent(socket);
    }

  return 0;
}
