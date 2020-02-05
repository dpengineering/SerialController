
//      ******************************************************************
//      *                                                                *
//      *                          SerialDebug                           *
//      *                                                                *
//      *        Serial port for Arduino debugging - Write only          *
//      *                                                                *
//      *       Configured for at ATMega 2560 using the USART port 0     *
//      *                                                                *
//      * This module borrows code and concepts from the Arduino         *
//      * HardwareSerial library that is copyright by Nicholas Zambetti. *
//      * It is subject to the GNU Lesser General Public License policy. *
//      *                                                                *
//      *            Stan Reifel                     2/16/2015           *
//      *                                                                *
//      ******************************************************************

//
// This module provides debugging support for the Arduino Mega using Print statements. 
// Normally one can do this using the Arduino functions Serial.begin() and Serial.print(). 
// Unfortunately these two functions are not compatible with the RS-485 and Bluetooth 
// serial slave and master modules.  As a result, it has been necessary to implement  
// these new functions that are compatible.
//
// Usage:
//    Debug.begin();                     // This must be added in setup()
//
//    Debug.print("Fred");               // print "Fred" stored in RAM
//    Debug.print(F("Fred"));            // print "Fred" stored in Flash ROM
//
//    Debug.print("Fred\n");             // prints a string with a new line
//    Debug.println("Fred");             // prints a string with a new line
//
//    Debug.print(charValue);            // prints the character
//    Debug.print(charValue, DEC);       // prints the ASCII number for a character
//
//    Debug.print(byteValue);            // prints a number from a variable of type byte
//    Debug.print(integerValue);         // prints signed integer
//
//    Debug.print(floatValue);           // prints a float with 2 digits right of decimal
//    Debug.print(floatValue, 0);        // prints a float with no fractional part
//    Debug.print(floatValue, 4);        // prints a float with 4 digits right of decimal
//
//    Debug.print(i, DEC);               // prints an integer in base 10
//    Debug.print(i, HEX);               // prints an integer in base 16
//    Debug.print(i, BIN);               // prints an integer in base 2
//
//    Debug.write(byteValue);            // write binary data
//    Debug.write(stringValue);          // write string
//    Debug.write(buffer, len);          // write array of bytes
//

#include "wiring_private.h"
#include "SerialDebug.h"


//
// ring buffer for transmitting characters to the Arduino's USB serial port
//
#define SERIAL_BUFFER_SIZE 64

struct ring_buffer
{
  byte buffer[SERIAL_BUFFER_SIZE];
  volatile byte head;
  volatile byte tail;
};

ring_buffer tx_buffer = { { 0 }, 0, 0};



// ---------------------------------------------------------------------------------
//                                  Public functions 
// ---------------------------------------------------------------------------------

//
// constructor 
//
SerialDebug::SerialDebug()
{
  tx_buffer.head = 0;      // mark the ring buffer as empty
  tx_buffer.tail = 0;
  
  cbi(UCSR0B, TXEN0);      // disable transmitting interrupts
  cbi(UCSR0B, UDRIE0);
 }



//
// open the Mega's slave port that is connected to the USB port at 9600 baud for debugging
//
void SerialDebug::begin()
{
  uint16_t clockRate;
  const long baudRate = 9600;
  
  //
  // set the baud rate assuming a 16Mhz clock and double speed operation
  //
  clockRate = (uint16_t) ((16000000 / 8L / baudRate) - 1L);
  UCSR0A = 1 << U2X2;
  UBRR0H = clockRate >> 8;
  UBRR0L = clockRate & 0xff;
 
  //
  // set 8 bit, no parity, 1 stop
  //
  UCSR0C = 0x06;

  //
  // enable transmitting
  //
  sbi(UCSR0B, TXEN0);
}



//
// write one character to the transmit ring buffer, if the buffer is full wait 
// for it to have space
//    Enter:  c = character to write to serial port
//    Exit:   number of characters written
//
size_t SerialDebug::write(byte c)
{
  byte newHead;
  
  //
  // determine the location for the new byte in the ring buffer
  //
  newHead = (tx_buffer.head + 1) % SERIAL_BUFFER_SIZE;
  
  //
  // wait if the buffer is full
  //
  while (newHead == tx_buffer.tail)
    ;

  //
  // add the byte to the buffer
  //
  tx_buffer.buffer[tx_buffer.head] = c;
  tx_buffer.head = newHead;

  //
  // make sure transmit interrupts are enabled
  //
  sbi(UCSR0B, UDRIE0);

  //
  // return the number of characters written
  //
  return(1);
}



//
// interrupt service routine indicating the USART is ready to transmit the next byte
//
ISR(USART0_UDRE_vect)
{
  //
  // check if there is any more data ring buffer to send
  //
  if (tx_buffer.head == tx_buffer.tail)
  {
    //
    // nothing left to transmit, disable the interrupt
    //
    cbi(UCSR0B, UDRIE0);
    return;
  }
  
  //
  // transmit the next byte in the ring buffer
  //
  UDR0 = tx_buffer.buffer[tx_buffer.tail];
  tx_buffer.tail = (tx_buffer.tail + 1) % SERIAL_BUFFER_SIZE;
}



//
// stub function to support the IOStream class
//
int SerialDebug::available(void)
{ return(0);
}


//
// stub function to support the IOStream class
//
int SerialDebug::peek(void)
{ return(0);
}


int SerialDebug::read(void)
//
// stub function to support the IOStream class
//

{ return(0);
}


//
// stub function to support the IOStream class
//
void SerialDebug::flush()
{
}


//
// declare the Debug serial port and make it externally available
//
SerialDebug Debug;


// -------------------------------------- End --------------------------------------

