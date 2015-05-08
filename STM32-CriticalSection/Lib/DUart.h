/**
 *******************************************************************************
 *  @file   DUart.h
 *  @brief  Declares an interface for a UART peripheral.
 *  @author Chad Bartlett   <cbartlet@uw.com>
 *******************************************************************************
 */
#ifndef DUART_H
#define DUART_H

#include <stdint.h>

/**
 * @class DUart
 * @brief An interface for a UART peripheral.
 */
class DUart
{
  public:
    /**
     * Constructor
     */
    DUart();

    /**
     * Destructor
     */
    ~DUart();

    /**
     * Initialize the Uart peripheral.
     */
    void Init();

    /**
     * Prints a string.
     * @param string The string to be printed
     */
    void PrintStr(char const * const string);

    /**
     * Print a hex number.
     * @param hex The number to be printed.
     */
    void PrintHex(uint32_t hex);

  private:
    DUart(const DUart&);            //!< Intentionally not implemented
    DUart& operator=(const DUart&); //!< Intentionally not implemented

    /**
     * Uart put char function
     * @param  c Character to be printed.
     */
    void PutC(uint8_t c);

    /**
     * Reads a character from the Uart RX line.
     * @return Character read.
     */
    uint8_t GetC();

    /**
     * Convert number to ascii character.
     * @param  byte  The number to be converted.
     * @return       Returns the number as an ascii character.
     */
    uint8_t ConvertHexToAscii(uint8_t byte);
};

#endif // #ifndef DUART_H
