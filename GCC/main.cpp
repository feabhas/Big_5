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
#include <iostream>

using std::cout;
using std::endl;

// If a move constructor is defined it is
// called on return.
// Otherwise, the copy constructor is called.
//
SocketManager make_SocketManager(const IP_address& addr, const Port& port)
{
  cout << "make_SocketManager(IP_address, Port)" << endl;
  SocketManager temp{addr, port};
  temp.send("Sending data...");
  return temp;
}


// Constructs directly into the client's variable
// (no move or copy constructor)
//
SocketManager create_SocketManager(const IP_address& addr, const Port& port)
{
  cout << "create_SocketManager(IP_address, Port)" << endl;
  return SocketManager{addr, port};
}

// Pass-by-value function (not recommended)
//
void use_SocketManager(SocketManager mgr)
{
  cout << "use_SocketManager(SocketManager)" << endl;
  mgr.send("Sending data...");
}


int main()
{
  IP_address localhost{127};
  Port port1{21};
  Port port2{127};
  Port port3{2222};
  Port port4{56};
  Port port5{1234};

  
  cout << endl << "Explicit construction:" << endl;
  SocketManager  mgr1{localhost, port1};

  cout << endl << "Heap construction:" << endl;
  SocketManager* pMgr2 = new SocketManager{localhost, port2};

  cout << endl << "Initialisation with an existing object:" << endl;
  SocketManager  mgr3 = mgr1;
  
  cout << endl << "NRV optimisation:" << endl;
  SocketManager  mgr4 = create_SocketManager(localhost, port3);
  
  cout << endl << "Make function into existing object:" << endl;
  SocketManager  mgr5;
  mgr5 = make_SocketManager(localhost, port4);

  cout << endl << "Make function into new object:" << endl;
  SocketManager  mgr6 = make_SocketManager(localhost, port5);

  cout << endl << "Pass object by value:" << endl;
  use_SocketManager(mgr1);
  //use_SocketManager(*pMgr2);
  //use_SocketManager(mgr3);
  //use_SocketManager(mgr4);
  //use_SocketManager(mgr5);

  cout << endl << "Deleting heap object:" << endl;
  delete pMgr2;

  cout << endl << "END OF PROGRAM" << endl;
}