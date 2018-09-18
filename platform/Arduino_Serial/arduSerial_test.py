from arduSerial import arduSerial

import time

#time1 = 0
#time2 = 0

status = False

port = 'COM4'
baudrate = 9600
s = arduSerial(port, baudrate)


def main():
    cmd = ''
    response = ''
    while cmd != 'QUIT':
        cmd = input('Enter ON, OFF or quit command: ')
        #time1 = time.time()
        status = s.write(cmd)
        if status:
            print('Message has been sent')
            response = s.read(cmd)
            #time2 = time.time()
            #print('exe time: ' + str(time2 - time1))
            if response != 'None':
                
                print('Arduino response: ' + response)
            else:
                print('Incorrect command')
        else:
            print('Failed to send Message')

    s.close()

main()
