
//      ******************************************************************
//      *                                                                *
//      *                 Header file for SerialDebug.c                  *
//      *                                                                *
//      * This module borrows code and concepts from the Arduino         *
//      * HardwareSerial library that is copyright by Nicholas Zambetti. *
//      * It is subject to the GNU Lesser General Public License policy. *
//      *                                                                *
//      ******************************************************************


#ifndef SerialDebug_h
#define SerialDebug_h

#include <inttypes.h>
#include <Stream.h>



class SerialDebug : public Stream
{
  private:
  
  public:
    SerialDebug();
    void begin();
    
    virtual size_t write(uint8_t c);
    virtual int available(void);
    virtual int peek(void);
    virtual int read(void);
    virtual void flush(void);
    
    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write; // pull in write(str) and write(buf, size) from Print
};

extern SerialDebug Debug;

// ------------------------------------ End ---------------------------------
#endif

