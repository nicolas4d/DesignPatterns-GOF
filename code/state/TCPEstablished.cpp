#ifndef TCPESTABLISHED_H
#define TCPESTABLISHED_H

class TCPState;

class TCPEstablished : public TCPState {
public:
  static TCPState* Instance();
  virtual void Transmit(TCPConnection*, TCPOctetStream*);
  virtual void Close(TCPConnection*);
};

void TCPEstablished::Close (TCPConnection* t) {
  // send FIN, receive ACK of FIN
  ChangeState(t, TCPListen::Instance());
}

void TCPEstablished::Transmit ( TCPConnection* t, TCPOctetStream* o ) {
  t->ProcessOctet(o);
}

#endif /* TCPESTABLISHED_H */
