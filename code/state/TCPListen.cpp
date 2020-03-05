#ifndef TCPLISTEN_H
#define TCPLISTEN_H

class TCPState;

class TCPListen : public TCPState {
public:
  static TCPState* Instance();
  virtual void Send(TCPConnection*);
  // ...
};

void TCPListen::Send (TCPConnection* t) {
  // send SYN, receive SYN, ACK, etc.
  ChangeState(t, TCPEstablished::Instance());
}

#endif /* TCPLISTEN_H */
