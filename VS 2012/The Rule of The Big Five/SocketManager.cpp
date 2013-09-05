//-----------------------------------------------------------------------------------
/*
  DISCLAIMER:
  Feabhas is furnishing this item "as is". Feabhas does not provide any warranty 
  of the item whatsoever, whether express, implied, or statutory, including, but 
  not limited to, any warranty of merchantability or fitness for a particular 
  purpose or any warranty that the contents of the item will be error-free.
  In no respect shall Feabhas incur any liability for any damages, including, but 
  limited to, direct, indirect, special, or consequential damages arising out of, 
  resulting from, or any way connected to the use of the item, whether or not 
  based upon warranty, contract, tort, or otherwise; whether or not injury was 
  sustained by persons or property or otherwise; and whether or not loss was 
  sustained from, or arose out of, the results of, the item, or any services that 
  may be provided by Feabhas.
*/
//-----------------------------------------------------------------------------------

#include "SocketManager.h"
#include "Socket.h"
#include <iostream>

using std::cout;
using std::endl;


SocketManager::SocketManager() :
  ip(0),
  pSocket(nullptr)
{
  cout << "SocketManager::SocketManager()" << endl;
}


SocketManager::SocketManager(const IP_address& addr, const Port& p) :
  ip(addr),
  pSocket(new Socket(p))
{
  cout << "SocketManager::SocketManager(const IP_address&, const Port&)" << endl;
  pSocket->open();
}


SocketManager::~SocketManager()
{
  cout << "SocketManager::~SocketManager()" << endl;
  if(pSocket != nullptr)
  {
    pSocket->close();
  }
  delete pSocket;
}


void SocketManager::send(const char* data)
{
  pSocket->write(data);
}

//-----------------------------------------------------------------------------------
//
#ifdef COPY_ENABLED
SocketManager::SocketManager(const SocketManager& src) :
  ip(src.ip),
  pSocket(nullptr)
{
  cout << "SocketManager::SocketManager(const SocketManager&)" << endl;
  if(src.pSocket != nullptr)
  {
    pSocket = new Socket;
    *pSocket = *(src.pSocket);
  }
}


SocketManager& SocketManager::operator=(const SocketManager& rhs)
{
  cout << "SocketManager::operator=(const SocketManager&)" << endl;

  Socket* pTemp = new Socket;
  *pTemp = *(rhs.pSocket);
 
  delete this->pSocket;
  this->pSocket = pTemp;
  this->ip = rhs.ip;
  return *this;
}
#endif // COPY_ENABLED


//-----------------------------------------------------------------------------------
//
#ifdef MOVE_ENABLED
SocketManager::SocketManager(SocketManager&& src) :
  ip(src.ip),
  pSocket(src.pSocket)
{
  cout << "SocketManager::SocketManager(SocketManager&&)" << endl;
  src.pSocket = nullptr;
}


SocketManager& SocketManager::operator=(SocketManager&& rhs)
{
  cout << "SocketManager::operator=(SocketManager&&)" << endl;

  if (this != &rhs)
  {
    delete pSocket;
    pSocket = rhs.pSocket;
    rhs.pSocket = nullptr;
  }

  return *this;
}
#endif // MOVE_ENABLED