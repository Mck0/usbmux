
#pragma once

#include <Arduino.h>
#include "ts3usb221-arduino.h"

class UsbMuxDriver
{

public:

    typedef enum
    {
        USB_ID_HIGH = HIGH,
        USB_ID_LOW  = LOW,
    } UsbIdState;

public:

    /**
     * @brief Ctor
     *
     * @param usbIdPin - USB_ID pin
     */
    explicit UsbMuxDriver(int usbIdPin);

    /**
     * @brief Enables a given channel, setting proper state on usb_id pin
     *
     * @param chNumber - channel number to be enabled on the output
     * @param id       - usb id pin state enbaled on given channel
     */
    void enableChannel(uint8_t chNumber, UsbIdState idState);

    /**
     * @brief Disbles all channels, not forwarding any on the output
     *
     * @note USB ID pin state is set to LOW
     */
    void disableAll();

private:

    /**
     * @brief Returns if channel number is available (valid)
     *
     * @param chNumber - channel number to be checked
     * @return Is channel number valid (true) or not (false)
     */
    bool isChannelValid(uint8_t chNumber);

private:

    /**
     * @brief Number of physically available multiplexer channels
     */
    static const int k_usbInputChannelsNumber = 2;

    /**
     * @brief USB multiplexer dev objects
     */
    ts3usb221 m_usbMuxDev;
    ts3usb221_arduino m_usbMuxArduinoDev;

    /**
     * @brief USB_ID pin
     */
    int m_usbIdPin;
};
