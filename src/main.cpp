//
// Created by trochej on 10/15/20.
//

#include <iostream>
#include <boost/asio.hpp>
#include <memory>

using namespace boost;

std::string readFromSocket(asio::ip::tcp::socket &socket){
    asio::streambuf buf;
    asio::read_until(socket, buf, "\n");
    std::string data = asio::buffer_cast<const char*>(buf.data());
    return data;
}

void writeToSocket(asio::ip::tcp::socket& socket, const std::string& message){
    const std::string msg = message + "\n";
    asio::write(socket, asio::buffer(message));
}

int main(int argc, char *argv[]){
    asio::io_service iosrvc;
    asio::ip::tcp::acceptor acceptor(iosrvc, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 2048));
    asio::ip::tcp::socket socket(iosrvc);
    acceptor.accept(socket);
    std::string message = readFromSocket(socket);
    writeToSocket(socket, "ACK");
    return 0;
}