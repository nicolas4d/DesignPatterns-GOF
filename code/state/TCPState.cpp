#ifndef TCPSTATE_H
#define TCPSTATE_H

class TCPConnection;
class TCPOctetStream;

class TCPState {
public:
  virtual void Transmit(TCPConnection*, TCPOctetStream*);
  virtual void ActiveOpen(TCPConnection*);
  virtual void PassiveOpen(TCPConnection*);
  virtual void Close(TCPConnection*);
  virtual void Synchronize(TCPConnection*);
  virtual void Acknowledge(TCPConnection*);
  virtual void Send(TCPConnection*);

protected:
  void ChangeState(TCPConnection*, TCPState*);
};

void TCPState::Transmit (TCPConnection*, TCPOctetStream*) { }

void TCPState::ActiveOpen (TCPConnection*) { }

void TCPState::PassiveOpen (TCPConnection*) { }

void TCPState::Close (TCPConnection*) { }

void TCPState::Synchronize (TCPConnection*) { }

void TCPState::ChangeState (TCPConnection* t, TCPState* s) {
  t->ChangeState(s);
}

#endif /* TCPSTATE_H */
