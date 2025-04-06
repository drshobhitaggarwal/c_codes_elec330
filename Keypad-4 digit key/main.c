/* DriverLib Includes */
#include <ti/devices/msp432e4/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
#include "uartstdio.h"
#include <string.h>

uint32_t g_ui32SysClock;
// Define keypad connections (adjust these to your specific wiring)
#define ROW_1 GPIO_PORTP_BASE, GPIO_PIN_0
#define ROW_2 GPIO_PORTP_BASE, GPIO_PIN_1
#define ROW_3 GPIO_PORTP_BASE, GPIO_PIN_2
#define ROW_4 GPIO_PORTP_BASE, GPIO_PIN_3
#define COL_1 GPIO_PORTP_BASE, GPIO_PIN_4
#define COL_2 GPIO_PORTP_BASE, GPIO_PIN_5
#define COL_3 GPIO_PORTP_BASE, GPIO_PIN_6

// Keypad matrix
const char keypad[4][4] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

// UART Initialization
void
ConfigureUART(void)
{
    //
    // Enable the GPIO Peripheral used by the UART.
    //
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //
    // Enable UART0.
    //
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    //
    // Configure GPIO Pins for UART mode.
    //
    MAP_GPIOPinConfigure(GPIO_PA0_U0RX);
    MAP_GPIOPinConfigure(GPIO_PA1_U0TX);
    MAP_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    //
    // Initialize the UART for console I/O.
    //
    UARTStdioConfig(0, 115200, g_ui32SysClock);
}

// Function to initialize the keypad GPIO pins
void keypadInit(void) {
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
    while (!MAP_SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOP));

    // Configure rows as outputs, columns as inputs
    MAP_GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    MAP_GPIOPinTypeGPIOInput(GPIO_PORTP_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7);

    // Enable pull-up resistors on columns
    MAP_GPIOPadConfigSet(GPIO_PORTP_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    // Set all rows high initially
    MAP_GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0xFF);
}

// Function to read a key press from the keypad
char getKey(void) {
    uint8_t row, col;
    uint32_t rowPins[4] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3};
    uint32_t colPins[3] = {GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6};

    for (row = 0; row < 4; row++) {
        // Drive the current row low
        MAP_GPIOPinWrite(GPIO_PORTP_BASE, rowPins[row], 0x00);

        for (col = 0; col < 3; col++) {
            // Check if the current column is low
            if (MAP_GPIOPinRead(GPIO_PORTP_BASE, colPins[col]) == 0x00) {
                // Debounce delay (adjust as needed)
                MAP_SysCtlDelay(g_ui32SysClock/30); // ~1ms delay

                // Confirm key press after delay
                if (MAP_GPIOPinRead(GPIO_PORTP_BASE, colPins[col]) == 0x00) {
                    // Restore row to high
                    MAP_GPIOPinWrite(GPIO_PORTP_BASE, rowPins[row], rowPins[row]);
                    // Wait for key release
                    while (MAP_GPIOPinRead(GPIO_PORTP_BASE, colPins[col]) == 0x00);

                    // Debounce delay after release
                    MAP_SysCtlDelay(g_ui32SysClock/300);

                    // return the pressed key.
                    return keypad[row][col];
                }
            }
        }
        MAP_GPIOPinWrite(GPIO_PORTP_BASE, rowPins[row], rowPins[row]);
    }
    return '\0'; // No key pressed
}

// Function to read a 4-digit PIN from the keypad
void readPin(char pin[5]) {
    uint8_t i = 0;
    char key;

    while (i < 4) {
        key = getKey();
//        UARTprintf("Waiting for user\n");
        if (key != '\0') {
            pin[i] = key;
//            UARTprintf("Key: %c", key);
            i++;
            // Optionally add some visual feedback (e.g., print '*')
        }
    }
    pin[4] = '\0'; // Null-terminate the string
}

int main(void) {
    // Initialize system clock
    g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                             SYSCTL_OSC_MAIN |
                                             SYSCTL_USE_PLL |
                                             SYSCTL_CFG_VCO_480), 120000000);

    //Initialize UART
    ConfigureUART();

    UARTprintf("App: Starting App\n");
    UARTprintf("Enter 4 digit pin on keypad\n");

    // Initialize keypad
    keypadInit();

    char pin[5];
    readPin(pin);

    //     Use the read PIN (e.g., compare it with a stored PIN)
        UARTprintf("PIN entered: %s\n", pin);

    while (1) {

    }
}
