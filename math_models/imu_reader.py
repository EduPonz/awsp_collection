#!/usr/bin/python
"""."""
import smbus
import math
import time
import sys


def read_byte(reg):
    """."""
    return bus.read_byte_data(address, reg)


def read_word(reg):
    """."""
    h = bus.read_byte_data(address, reg)
    l = bus.read_byte_data(address, reg + 1)
    value = (h << 8) + l
    return value


def read_word_2c(reg):
    """."""
    val = read_word(reg)
    if (val >= 0x8000):
        return -((65535 - val) + 1)
    else:
        return val


def dist(a, b):
    """."""
    return math.sqrt((a * a) + (b * b))


def get_y_rotation(x, y, z):
    """."""
    radians = math.atan2(x, dist(y, z))
    return -math.degrees(radians)


def get_x_rotation(x, y, z):
    """."""
    radians = math.atan2(y, dist(x, z))
    return math.degrees(radians)


if __name__ == '__main__':
    try:
        # Registers
        power_mgmt_1 = 0x6b
        power_mgmt_2 = 0x6c

        bus = smbus.SMBus(1)
        address = 0x68       # via i2cdetect

        # Enables communication with the IMU
        bus.write_byte_data(address, power_mgmt_1, 0)

        while(1):
            print("Gyroscope")
            print("--------")

            gyro_x = read_word_2c(0x43)
            gyro_y = read_word_2c(0x45)
            gyro_z = read_word_2c(0x47)

            print("gyro_x: {} scaled {}".format(("%5d" % gyro_x), (gyro_x / 131)))
            print("gyro_y: {} scaled {}".format(("%5d" % gyro_y), (gyro_y / 131)))
            print("gyro_z: {} scaled {}".format(("%5d" % gyro_z), (gyro_z / 131)))

            print("")
            print("Acceleration sensor")
            print("---------------------")

            accel_x = read_word_2c(0x3b)
            accel_y = read_word_2c(0x3d)
            accel_z = read_word_2c(0x3f)

            accel_x_scaled = accel_x / 16384.0
            accel_y_scaled = accel_y / 16384.0
            accel_z_scaled = accel_z / 16384.0

            print("accel_x: {} scaled {}".format(("%6d" % accel_x), accel_x_scaled))
            print("accel_x: {} scaled {}".format(("%6d" % accel_y), accel_y_scaled))
            print("accel_x: {} scaled {}".format(("%6d" % accel_z), accel_z_scaled))

            print("X Rotation: {}".format(get_x_rotation(accel_x_scaled, accel_y_scaled, accel_z_scaled)))
            print("Y Rotation: {}".format(get_y_rotation(accel_x_scaled, accel_y_scaled, accel_z_scaled)))
            print('\n')
            time.sleep(1)
    except Exception as e:
        print(e)
    except KeyboardInterrupt:
        print('\nUser shutdown!')
        sys.exit(0)
