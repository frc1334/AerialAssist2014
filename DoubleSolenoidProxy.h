#ifndef DOUBLESOLENOIDPROXY_H
#define DOUBLESOLENOIDPROXY_H

class DoubleSolenoidProxy
{
private:
  Solenoid* doubleSolenoidAChannel;
  Solenoid* doubleSolenoidBChannel;
public:
  DoubleSolenoidProxy(uint32_t symChannel)
  {
    doubleSolenoidAChannel = new Solenoid(1, symChannel);
    doubleSolenoidBChannel = new Solenoid(2, symChannel);
    Set(false);
  }
  
  void Set(bool on)
  {
    doubleSolenoidAChannel->Set(on);
    doubleSolenoidBChannel->Set(!on);
  }
};

#endif
