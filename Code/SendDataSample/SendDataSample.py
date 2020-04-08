# Send data synchronously
# Synchronous operation
# This type of operation is blocking. This means the method waits until the transmit status response is received or the default timeout is reached.

# The XBeeDevice class of the API provides the following method to perform a synchronous unicast transmission with a remote node of the network:
# send_data(RemoteXBeeDevice, String or Bytearray, Integer)
# Specifies the remote XBee destination object, the data to send and optionally the transmit options.

from digi.xbee.devices import XBeeDevice

# TODO: Replace with the serial port where your local module is connected to.
PORT = "COM5"
# TODO: Replace with the baud rate of your local module.
BAUD_RATE = 9600

DATA_TO_SEND = "Hello XBee!"
REMOTE_NODE_ID = "Test"


NEW_TIMEOUT_FOR_SYNC_OPERATIONS = 1 # 1 seconds



def main():
    print(" +--------------------------------------+")
    print(" | XBee Python Library Send Data Sample |")
    print(" +--------------------------------------+\n")

    device = XBeeDevice(PORT, BAUD_RATE)

    # 这部分可选，传输Timeout
    # Retrieving the configured timeout for synchronous operations.
    print("Current timeout: %d seconds" % device.get_sync_ops_timeout())
    # 默认是4s
    # Configuring the new timeout (in seconds) for synchronous operations.
    device.set_sync_ops_timeout(NEW_TIMEOUT_FOR_SYNC_OPERATIONS)

    try:
        device.open()

        # Obtain the remote XBee device from the XBee network.
        xbee_network = device.get_network()
        remote_device = xbee_network.discover_device(REMOTE_NODE_ID)
        if remote_device is None:
            print("Could not find the remote device")
            exit(1)

        print("Sending data to %s >> %s..." % (remote_device.get_64bit_addr(), DATA_TO_SEND))

        device.send_data(remote_device, DATA_TO_SEND)

        print("Success")

    finally:
        if device is not None and device.is_open():
            device.close()


if __name__ == '__main__':
    main()
