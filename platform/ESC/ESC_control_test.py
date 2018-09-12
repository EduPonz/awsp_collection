from ESC_control import ESC_control

PWM_pin = 18
esc = ESC_control(PWM_pin)

a = ""
count = 1000
print('Enter (u) to increase speed')
print('Enter (d) to decrease speed')
print('Enter (q) to quit')
while True:
    a = raw_input('Enter command: ')

    if a == "u":
        count = count + 50
    elif a == "d":
        count = count - 50
    elif a == "q":
        break
    else:
	print('Invalid key pressed')
    print(count)
    esc.motor_speed(count)

esc.motor_stop()
esc.end()
