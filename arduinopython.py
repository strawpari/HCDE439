import serial
portName = '/dev/cu.usbmodem145201'

ser = serial.Serial(portName, 9600)

f = open('log.csv', 'a')

while True:
	f.write(ser.readline())
	f.close()
	f = open('log.csv', 'a')
