# MCP23008_ESP
A modified Adafruit_MCP23008 library, this enables one to use any pins for the mcp which support I2C. This is important for anyone using the ESP32 with
Arduino IDE.
Basically the only change made was an overload to the MCP23008::begin function.
It adds parameters to specify the SDA/SCL pins in order to call Wire.begin(SDA, SCL) with those pins as params.


Original Source: https://github.com/adafruit/Adafruit-MCP23008-library

MCP23008 Datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21919b.pdf