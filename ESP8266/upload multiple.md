# uploader un groupe d'esp 
## création d'un script
    detecter chaque esp sur le port usb et le donner à la commande de flash de epstool

    voici le modele

     #bin/bash
```
for i in $(ls /dev/tty* |grep USB)
 do 
 sudo /home/bulleux/.arduino15/packages/esp8266/tools/python3/3.7.2-post1/python3 /home/bulleux/.arduino15/packages/esp8266/hardware/esp8266/2.7.4/tools/upload.py --chip esp8266 --port $i --baud 115200 --before default_reset --after hard_reset write_flash 0x0 /tmp/arduino_build_875157/sondeJardin.ino.bin
 done
```