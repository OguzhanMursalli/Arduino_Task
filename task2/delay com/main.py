import serial
port=serial.Serial("com3",9600)
while True:
    veri = input("durum değişimi için (a) basınız:")
    if(veri=='a'):
        port.write(b'a')
