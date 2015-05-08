/**
 *******************************************************************************
 *  @file   Bsp.h
 *  @brief  Defines a set of board specific functions.
 *  @author Chad Bartlett   <cbartlet@uw.com>
 *******************************************************************************
 */
#ifndef BSP_H
#define BSP_H

#include <stdint.h>

extern "C" {
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
}

// Forward declarations
class DUart;

#define TIME_MS_TO_TICK(ms)     ((ms)*SYSTICK_PER_MS)

namespace App {
/**
 * @defgroup APP_CONSTANTS App Constants
 * @brief Global constants used within this application.
 * @{
 */
//

//!< The number of clock cycles between calls to SysTick_Handler
static const uint32_t TICKS_BETWEEN_SYSTICK_IRQ = SystemCoreClock/1000;  //!< Hz
static const uint32_t SYSTICK_PER_MS = (SystemCoreClock/TICKS_BETWEEN_SYSTICK_IRQ/1000);

typedef enum {
    PIN_LED_BLUE  = GPIO_Pin_8,
    PIN_LED_GREEN = GPIO_Pin_9,
    PIN_BTN_USER  = GPIO_Pin_0,
} PinConfiguration_t;

typedef enum {
    BTN_PRESSED  = Bit_SET,
    BTN_RELEASED = Bit_RESET,
} ButtonState_t;

/** @} */

/**
 * Configures the base peripherals used in this application.
 */
void InitHardware(DUart& uart);

/**
 * Reads the state of the user button.
 * @return Returns the state of the user button (i.e. BTN_PRESSED | BTN_RELEASED)
 */
ButtonState_t ReadUserBtn();

/**
 * Turn on an LED.
 * @param led The LED to operate.
 */
void SetLed(PinConfiguration_t led);

/**
 * Turn off an LED.
 * @param led The LED to operate.
 */
void ClrLed(PinConfiguration_t led);

/**
 * Toggle an LED.
 * @param led The LED to operate.
 */
void TglLed(PinConfiguration_t led);

/**
 * Gets the current system tick value.
 *
 * @return Returns the system tick value.
 */
uint32_t GetSysTick();

/**
 * Resets the value of the system tick counter to zero.
 */
void ResetSysTick();

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

/**
 * Blocking delay function in milliseconds.
 *
 * @param nTime The number of milliseconds to delay.
 */
void DelayMs(uint32_t nTime);

} // namespace App
#endif // #ifndef BSP_H