# tableauDeBord
toutes les notes que j'ai dans la têtes

## sychronisation des publish mqtt

je vais envoyer un timer pour synchroniser au mieux chaque node
à chaque step pub node reçoit un long qui correspond au prochain 
faisceau de reception de donnée pour faire correspondre les graphiques

le deepSleep recois un long en microSecondes

## gestion du deepSleep

j'ai eu un soucis avec deepSleep.
à chaque loop, le callback de client.publish("");
met trop de temps et le node s'eteint avant la fin de l'envoi
j'ai mis un `delay(500)` ; mais c'est moche

```c++
boolean publish(const char* topic, const char* payload);
boolean publish(const char* topic, const char* payload, boolean retained);
```

publish a un retour je vais faire une boucle qui attend le retour pour passer à la suite
--à tester--

## À la recherche d'un repeteur wifi pas cher

en cherchant ce matin repeteur wifi esp8266 j'ai trouvé sur git à cette adresse
- [wifi repeteur](https://github.com/martin-ger/esp_wifi_repeater)
quelqu'un qui flash se carte esp 8266 et qui configure un répeteur
c'est interessant pour augmenter la porté des sondes sur le jardin. 
je dois trouver de quoi flasher un esp8266

## Flash esp8266 pour repeteur wifi

[esptool](https://github.com/espressif/esptool)
### commande utilisée :

```sh
esptool.py --port /dev/ttyUSB0  --baud 115200 write_flash -fs detect -fm qio --flash_freq 80m 0x00000 firmware/0x00000.bin 0x02000 firmware/0x02000.bin 0x82000 firmware/0x82000.bin
```

le dossier firmware fait partie du depot git vu plus haut
j'ai eu des soucis jusqu'a changer `-fs detect` qui trouve tout seul la bonne valeur.

une fois le nodeMcu flashé 
il faut se rendre sur 
    - se connecté sur le wifi `myAP`
    - l'interface à l'IP `192.168.4.1`
    - configurer l'interface avec le wifi hote 

## Installation des caméras esp32

[CHAPITRE ESP32](https://github.com/ambulancexm/tableauDeBord/tree/main/ESP32)

## Gestion du téléchargement par wifi

J'ai découvert OTA sur une revue et le test a été concluant 
directement.
Chaque ESP est repertorié sur le réseau et attend une mise à jour.
[OTA](https://github.com/ambulancexm/tableauDeBord/tree/main/OTA)

## Gestion des websocket avec mosquitto et reactJs

je ferais un post plus tard
mais l'essentiel est dans le lancement de mosquitto
avec la commande 
```sh
mosquitto -c /etc/mosquitto/conf.d/<le_fichier_de_conf>
```

ensuite avec  
```sh
$ /etc/mosquitto# lsof -i tcp |grep mosquitto
mosquitto 1244156 mosquitto    5u  IPv4 131221983      0t0  TCP *:1883 (LISTEN)
mosquitto 1244156 mosquitto    6u  IPv6 131221984      0t0  TCP *:1883 (LISTEN)
mosquitto 1244156 mosquitto   10u  IPv4 131221986      0t0  TCP *:9001 (LISTEN)

```

