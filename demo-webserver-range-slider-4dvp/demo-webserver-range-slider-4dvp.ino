#include <WiFiS3.h>
#include <SafeString.h>   // https://www.arduino.cc/reference/en/libraries/safestring/

#include "connectWifi.h"
#include "index.h"        // code HTML
#include "css.h"          // code CSS
#include "javascript.h"   // code JavaScript
#include "entete_http.h"
#include "ledmatrix_frames.h" 

WiFiServer server(80);  // instanciation serveur Web port 80 http
bool htmlRequired = false;
bool cssRequired = false;
bool rangeUpdate = false;
bool javascriptRequired = false;
bool majOnloadRequired = false;

createSafeString(currentLine, 100);
createSafeString(json, 50);
createSafeString(getRequest, 30);
int rangeValue; // position du slider entre 0 et 100

ArduinoLEDMatrix matrix;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(115200);
  delay(10);

  connectWifi();  // connexion au wifi (voir arduino_secrets.h pour ssid/mot de passe)

  server.begin();  // démarrage du serveur web
  Serial.print(F("Web server connected, IP address: "));
  Serial.println(WiFi.localIP());

  matrix.begin();
  print_rangeSlider(0);
}

void loop() {
  // En attente d'un client http
  WiFiClient client = server.available();

  if (client) {  // si un client se connecte au serveur Web
    //Serial.println(F("-------------------"));
    //Serial.println(F("new client"));

    // an HTTP request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        currentLine += c;

        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the HTTP request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {

          if (htmlRequired) {
            entete_http_200(&client, F("text/html"));
            client.println(HTML_CONTENT);  // envoi du html au client
            htmlRequired = false;
          }

          else if (cssRequired) {
            entete_http_200(&client, F("text/css"));
            client.println(CSS_CONTENT);  // envoi du css au client
            cssRequired = false;
          }

          else if (javascriptRequired) {
            entete_http_200(&client, F("application/javascript"));
            client.println(JAVASCRIPT_CONTENT);  // envoi du javascript au client
            javascriptRequired = false;
          }

          else if (rangeUpdate) {
            // rangeUpdate à exploiter
            //Serial.println(rangeValue);
            print_rangeSlider(rangeValue);
            entete_http_204(&client);  // 204 No Content
            client.println();
            rangeUpdate = false;
          }

          else if (majOnloadRequired) {
            /*  Renvoi d'un json  */            
            json = "{\"value\" : \"";
            json += rangeValue;
            json += "\"}";
            entete_http_200(&client, F("application/json"));
            client.println(json);
            client.println();
            majOnloadRequired = false;
          }

          else {
            ;
          }

          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
          currentLine.trim();
          //Serial.println(currentLine);

          if (currentLine.startsWith("GET")) {  // traitement des requêtes GET
            //Serial.println(F("--> GET détecté !"));
            int i = currentLine.indexOf("/");

            if (i > 0) {
              currentLine.substring(getRequest, i);

              if (getRequest == "/ HTTP/1.1") {
                Serial.println(F("--> Requête page d'accueil"));
                htmlRequired = true;
              }
              else if (getRequest.startsWith("/style.css")) {
                Serial.println(F("--> Requête feuille de style CSS"));
                cssRequired = true;
              }
              else if (getRequest.startsWith("/javascript.js")) {
                Serial.println(F("--> Requête javascript"));
                javascriptRequired = true;
              }

              else if (getRequest.startsWith("/range")) { // requête sous la forme /range?v=xx HTTP/1.1
                //Serial.println(F("--> range update"));
                int i = getRequest.indexOf('?');  // indice de position du '?'
                if (i > 0) {
                  createSafeString(v, 5);
                  getRequest.stoken(v, i+3, ' ');  // recherche de la valeur xx jusqu'au prochain espace ' '
                  if (v.toInt(rangeValue)) { // conversion en entier réussie
                    rangeUpdate = true;
                  }
                }            
                else { ; }
              }
              
              else if (getRequest.startsWith("/maj_onload")) {
                Serial.println("MaJ de la page");
                majOnloadRequired = true;
              }

              else {
                entete_http_204(&client);  // 204 No Content
                client.println();
              }
            }
          }
          currentLine.clear();
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }

    // give the web browser time to receive the data
    delay(5);

    // clore la connexion
    client.stop();
    //Serial.println(F("client disconnected"));
    //Serial.println(F("-------------------"));
    Serial.println();
  }
}

void print_rangeSlider(int value) {
  value = map(value, 0, 100, 0, 11);
  matrix.loadFrame(frame_slider[value]);
  //delay(1);
}
