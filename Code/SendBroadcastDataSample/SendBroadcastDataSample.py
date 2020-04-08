# SendBroadcastDataSample
# Send data to all devices of the network
# Broadcast transmissions are sent from one source device to all the other devices on the network.
# All the XBee device classes (generic and protocol specific) provide the same method to send broadcast data:
# send_data_broadcast(String or Bytearray, Integer)	Specifies the data to send and optionally the transmit options.

from digi.xbee.devices import XBeeDevice

# TODO: Replace with the serial port where your local module is connected to.
PORT = "COM5"
# TODO: Replace with the baud rate of your local module.
BAUD_RATE = 9600

DATA_TO_SEND = "Hello XBee!"


def main():
    print(" +------------------------------------------------+")
    print(" | XBee Python Library Send Broadcast Data Sample |")
    print(" +------------------------------------------------+\n")

    device = XBeeDevice(PORT, BAUD_RATE)

    try:
        device.open()

        print("Sending broadcast data: %s..." % DATA_TO_SEND)

        device.send_data_broadcast(DATA_TO_SEND)

        print("Success")

    finally:
        if device is not None and device.is_open():
            device.close()


if __name__ == '__main__':
    main()
