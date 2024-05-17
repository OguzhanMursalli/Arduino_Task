import serial

port = serial.Serial('COM3', 9600)

while True:
    if port.in_waiting > 0:
        veri = port.readline().decode('utf-8').rstrip()
        print(veri)

