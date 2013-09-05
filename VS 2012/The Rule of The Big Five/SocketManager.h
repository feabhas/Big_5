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

#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include "defs.h"

class Socket;

// Select your copy/move policy here by un-commenting
// the appropriate macro definition:
//
#define COPY_ENABLED
#define MOVE_ENABLED


class SocketManager
{
public:
  explicit SocketManager(const IP_address& addr, const Port& p);
  SocketManager();
  ~SocketManager();
  void send(const char* data);

#ifdef COPY_ENABLED
  SocketManager(const SocketManager& src);
  SocketManager& operator=(const SocketManager& rhs);
#else
  SocketManager(const SocketManager& src)            = delete;
  SocketManager& operator=(const SocketManager& rhs) = delete;
#endif

#ifdef MOVE_ENABLED
  SocketManager(SocketManager&& src);
  SocketManager& operator=(SocketManager&& rhs);
#else
  SocketManager(SocketManager&& src)                 = delete;
  SocketManager& operator=(SocketManager&& rhs)      = delete;
#endif

private:
  IP_address ip;
  Socket* pSocket;
};

#endif // SOCKETMANAGER_H