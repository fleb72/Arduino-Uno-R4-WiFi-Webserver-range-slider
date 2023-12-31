# [Arduino Uno R4 WiFi] Webserver range slider

[![Arduino Uno R4 WiFi Webserver range slider](https://img.youtube.com/vi/NDlexsN1Tzc/0.jpg)](https://www.youtube.com/watch?v=NDlexsN1Tzc)

[Arduino R4 WiFi] Démo serveur Web HTTP : range slider pour animer un curseur sur la matrice de Leds 

Dans cette démonstration, le programme transforme votre Arduino R4 WiFi en serveur Web (HTTP) embarqué.
La page Web depuis votre navigateur comprend un widget HTML de type "range" (ou range slider). Le déplacement du slider est reproduit par un curseur dessiné sur la matrice de Leds.

Notes :
- ouvrir le fichier .ino dans l'EDI Arduino (version 2.2.1 pour ma part) ;
- renseignez l'identifiant SSID/mot de passe de votre box/routeur dans l'onglet du fichier arduino_secrets.h ;
- l'adresse IP prise par le serveur s'affiche dans le Terminal Série (115200 bauds), faire éventuellement un Reset de la carte après téléversement ;
- CSS du widget html "range" (fichier css.h) d'après How to Create a Range Slider in HTML + CSS, par Danielle Ellis (juillet 2023)
https://blog.hubspot.com/website/html-slider
- pour cette démo, je suis simplement parti sur les bases de l'exemple fourni par Arduino : https://github.com/arduino/ArduinoCore-renesas/tree/main/libraries/WiFiS3/examples/WiFiWebServer ;
- bibliothèque supplémentaire à installer : SafeString (https://www.arduino.cc/reference/en/libraries/safestring/) ;
- sans système de fichiers, les codes statiques HTML/CSS/JavaScript sont stockés dans des const char*, voir index.h, css.h et javascript.h ;
