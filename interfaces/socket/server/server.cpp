

//// server.cc
//#include "server.h"
//#include <iostream>
//using namespace std;

//Server::Server(QObject* parent): QObject(parent)
//{
//}

//void Server::Bind(int Addr){

//    connect(&server, SIGNAL(newConnection()),
//      this, SLOT(acceptConnection()));

//    server.listen(QHostAddress::Any, Addr);

//}

//Server::~Server()
//{
//    puts("noo");
//  server.close();
//}

//void Server::acceptConnection()
//{
//  client = server.nextPendingConnection();

//  connect(client, SIGNAL(readyRead()),
//    this, SLOT(startRead()));
//}

//void Server::startRead()
//{
//  char buffer[1024] = {0};
//  client->read(buffer, client->bytesAvailable());
//  client->write("ohhi");
//  cout << buffer << endl;
//  client->close();
//}
