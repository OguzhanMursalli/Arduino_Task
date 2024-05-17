import serial
port=serial.Serial("com3",9600)

while True:
    veri = input("durum değişimi için (<) ya da (>) basınız:")
    if(veri=='<'):
        port.write(b'<')
    if(veri == '>'):
        port.write(b'>')