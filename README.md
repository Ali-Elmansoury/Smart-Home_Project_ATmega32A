## Smart Home Project using ATmega32A Microcontroller
# Overview

Welcome to the Smart Home project repository! This project was developed as an evaluation for the Embedded Systems Diploma by AMIT Learning, utilizing the ATmega32A microcontroller and various components to create a comprehensive smart home system.
# Project Specifications

    Remote Control: The system can be remotely controlled via Bluetooth using a mobile or laptop.
    User Modes: Emergency and user modes available, accessible via LCD and keypad for offline control.
    Controllable Devices: Includes lamps, door (controlled by a Servo motor), and air conditioner (regulated by a DC motor based on temperature sensor readings).
    User Authentication: Enhanced security with a system breakdown and fire alarm triggered for incorrect logins exceeding three attempts.
    Persistence: Usernames and passwords are stored in EEPROM, ensuring data retention even during power-offs.
    Access Control: Admin and user roles defined, allowing access to all devices except door control for users.

# Project Components

    ATmega32A Microcontroller
        Central component for processing and controlling peripherals.

    Remote Control via Bluetooth Module/TTL
        Enables remote access via Bluetooth-enabled devices.

    LCD and Keypad
        User mode interface for offline device control.

    EEPROM
        Non-volatile memory for persistent storage of user credentials.

    Lamps, Relay, Dimmer
        Control for 5 on/off lamps and 1 dimming lamp.

    Temperature Sensor
        Monitors ambient temperature for air conditioner control.

    DC Motor (for Air Conditioner Control)
        Regulates air conditioner opening and closing based on temperature readings.

    Servo Motor (for Door Control)
        Controls the opening and closing of the door.

# Getting Started

To set up and run this project, refer to the Getting Started Guide.
Contributing

Contributions to this project are welcome! Please follow the Contributing Guidelines for details on how to contribute.

# Other Contributors

    Contributor Name 1
    Contributor Name 2

# License

This project is licensed under the MIT License. See the LICENSE file for details.

# Acknowledgments

This project was developed as part of the Embedded Systems Diploma by AMIT Learning.

For any inquiries or issues, please contact Project Maintainer.
