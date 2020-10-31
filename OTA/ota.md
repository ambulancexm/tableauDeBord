# Explication d'OTA

Pour téléverser (upload) un bin sur la carte, il faut le brancher sur un port usb.
C'est long et fastidieux quand on doit le faire sur plusieurs ESP

la config est assez simple
include les librairies suivantes

```c++
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
```

à mettre à la fin du setup

```c++
void setup() {
      ArduinoOTA.setHostname("name"); // on donne une petit nom a notre module
      ArduinoOTA.begin(); // initialisation de l'OTA
    }
```
À chaque iteration, on verifie si une mise a jour nous est envoyÉe
si tel est cas, la lib ArduinoOTA se charge de gÉrer la suite :)

```c++
void loop() {
      
      ArduinoOTA.handle(); 
    }
```
Voir le site sur lequel je me suis appuyé [www.fais-le-toi-meme.fr](https://www.fais-le-toi-meme.fr/fr/electronique/tutoriel/esp8266-arduinoota-mise-a-jour-logiciel-esp8266-wifi)