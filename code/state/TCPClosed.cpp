#ifndef TCPCLOSED_H
#define TCPCLOSED_H

class TCPState;

class TCPClosed : public TCPState {
public:
  static TCPState* Instance();
  virtual void ActiveOpen(TCPConnection*);
  virtual void PassiveOpen(TCPConnection*);
};

TCPState* TCPClosed::Instance()
{
  
}

void TCPClosed::ActiveOpen (TCPConnection* t) {
  // send SYN, receive SYN, ACK, etc.
  ChangeState(t, TCPEstablished::Instance());
}

void TCPClosed::PassiveOpen (TCPConnection* t) {
  ChangeState(t, TCPListen::Instance());
}

#endif /* TCPCLOSED_H */
