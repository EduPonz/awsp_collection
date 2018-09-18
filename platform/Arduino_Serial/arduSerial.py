import serial
import time


class arduSerial:

    def __init__(self, port, baudrate):
        self.ser = serial.Serial(port, baudrate, timeout=1)
        self.ser.flush()

        print('Waiting for Arduino to connect to the COM-port')
        fromArdu = ""
        while fromArdu != "Ready\n":
            fromArdu = self.ser.readline().decode('Latin_1')

        print('Arduino is now connected to COM-port')


    def write(self, cmd):
        try:
            self.ser.write(str(cmd + '\n').encode('UTF-8'))
            return True
        except:
            return False


    def read(self, cmd):
        break_timer = time.time()
        try:
            rec = ''
            cmd += '\n'
            while cmd != rec and break_timer + 1 > time.time(): 
                rec = str(self.ser.readline().decode('UTF-8'))
            if cmd != rec:
                rec = 'None'
            return rec
        except:
            return False


    def open(self):
        self.ser.open()


    def close(self):
        self.ser.close()
