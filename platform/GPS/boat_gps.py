import os
import time
try:
	os.system('sudo gpsd /dev/ttyUSB0 -F /var/run/gpsd.sock')
	time.sleep(2)
except:
	pass
import gps

# Listen on port 2947 (gpsd) of localhost
session = gps.gps("localhost", "2947")
session.stream(gps.WATCH_ENABLE | gps.WATCH_NEWSTYLE)

while True:
	try:
		report = session.next()
			# Wait for a 'TPV' report and display the current time 
			# To see all report data, uncomment the line below
			#print(report)
		if report['class'] == 'TPV':
			if hasattr(report, 'lon'):
				print('Longitude: ' + str(report.lon))
			if hasattr(report, 'alt'):
				print('Altitude: ' + str(report.alt))
			if hasattr(report, 'speed'):
				print('Speed (m/s): ' + str(report.speed))
	except KeyError:
		pass
	except KeyboardInterrupt:
		quit()
	except StopIteration:
		sesseion = None
		print('GPSD has terminated')
