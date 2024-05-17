from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
import serial

devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = interface.QueryInterface(IAudioEndpointVolume)

port=serial.Serial('COM3',9600)
while True:
    if port.in_waiting>0:
      veri=port.readline().decode('utf-8').rstrip()
      deger= int(veri)
      volume.SetMasterVolumeLevel(deger, None)
      print(deger)
