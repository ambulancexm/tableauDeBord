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
    j'ai mis un delay(500); mais c'est moche
        `boolean publish(const char* topic, const char* payload);`
        `boolean publish(const char* topic, const char* payload, boolean retained);`

    publish a un retour je vais faire une boucle qui attend le retour pour passer à la suite
    --à tester--

## à la recherche d'un repeteur wifi pas cher

    en cherchant ce matin repeteur wifi esp8266 j'ai trouvé sur git à cette adresse
    - https://github.com/martin-ger/esp_wifi_repeater
    quelqu'un qui flash se carte esp 8266 et qui configure un répeteur
    c'est interessant pour augmenter la porté des sondes sur le jardin. 
    je dois trouver de quoi flasher un esp8266

## flash esp8266 pour repeteur wifi

    https://github.com/espressif/esptool
    commande utilisée :
    `esptool.py --port /dev/ttyUSB0  --baud 115200 write_flash -fs detect -fm qio --flash_freq 80m 0x00000 firmware/0x00000.bin 0x02000 firmware/0x02000.bin 0x82000 firmware/0x82000.bin`
    le dossier firmware fait partie du depot git vu plus haut
    j'ai eu des soucis jusqu'a changer `-fs detect` qui trouve tout seul la bonne valeur.

    une fois le nodeMcu flashé 
    il faut se rendre sur 
        - se connecté sur le wifi `myAP`
        - l'interface à l'IP `192.168.4.1`
        - configurer l'interface avec le wifi hote 