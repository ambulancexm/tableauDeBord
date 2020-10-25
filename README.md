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