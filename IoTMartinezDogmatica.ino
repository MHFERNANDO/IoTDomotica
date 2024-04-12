#include <Arduino.h>

#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

const char* WIFI_SSID = "Cresendo";
const char* WIFI_PASSWORD= "12345678";


const char* API_KEY= "AIzaSyBzeYOwYRfz8o4qiH9adFKmNlk6jgqqGgc";

const char* DATABASE_URL= "https://domotica-24511-default-rtdb.firebaseio.com"; //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app;

const char* USER_EMAIL= "esp32@test.com";
const char* USER_PASSWORD= "12345678";


FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;


int buttonState = 0;


void setup_WIFI(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  unsigned long ms = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  config.signer.tokens.legacy_token = "<database secret>";
  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096, 1024);
  fbdo.setResponseSize(2048);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  config.timeout.serverResponse = 10 * 1000;
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

}
BUTTON1 = 23 ;
BUTTON2 = 22;
BUTTON3 = 21;
BUTTON4 = 19;
BUTTON5 = 18;
BUTTON6 = 5;

void setup() {
    Serial.begin(115200);
    setup_WIFI();
    setupFirebase();
    pinMode(BUTTON1,INPUT_PULLUP);
    pinMode(BUTTON2,INPUT_PULLUP);
    pinMode(BUTTON3,INPUT_PULLUP);
    pinMode(BUTTON4,INPUT_PULLUP);
    pinMode(BUTTON5,INPUT_PULLUP);
    pinMode(BUTTON6,INPUT_PULLUP);
}

void loop() {
  // Verifica si Firebase está listo y si ha pasado cierto tiempo desde el último envío de datos
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))//*********************************************** DORMITORIO1
  {
      // Lee el estado del botón
      buttonState = digitalRead(BUTTON);
      
      // Envía el estado del botón a la base de datos en tiempo real de Firebase
      if (Firebase.RTDB.setBool(&fbdo, F("/Casita/Dormitorio1"), buttonState == HIGH)) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }

  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))//********************************************** DORMITORIO2
  {
      // Lee el estado del botón
      buttonState = digitalRead(BUTTON2);
      
      // Envía el estado del botón a la base de datos en tiempo real de Firebase
      if (Firebase.RTDB.setBool(&fbdo, F("/Casita/Dormitorio1"), buttonState == HIGH)) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }

  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))//********************************************* BANIOCOMUN
  {
      // Lee el estado del botón
      buttonState = digitalRead(BUTTON3);
      
      // Envía el estado del botón a la base de datos en tiempo real de Firebase
      if (Firebase.RTDB.setBool(&fbdo, F("/Casita/BanioComun"), buttonState == HIGH)) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }

  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))//************************************************ SALA
  {
      // Lee el estado del botón
      buttonState = digitalRead(BUTTON4);
      
      // Envía el estado del botón a la base de datos en tiempo real de Firebase
      if (Firebase.RTDB.setBool(&fbdo, F("/Casita/Sala"), buttonState ==  HIGH)) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }

  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))//************************************************** BANIOPADRES
  {
      // Lee el estado del botón
      buttonState = digitalRead(BUTTON5);
      
      // Envía el estado del botón a la base de datos en tiempo real de Firebase
      if (Firebase.RTDB.setBool(&fbdo, F("/Casita/BanioPadres"), buttonState == HIGH)) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }

  }

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))//**************************************************** COCINA
  {
      // Lee el estado del botón
      buttonState = digitalRead(BUTTON6);
      
      // Envía el estado del botón a la base de datos en tiempo real de Firebase
      if (Firebase.RTDB.setBool(&fbdo, F("/Casita/Cocina"), buttonState= HIGH)) {
          Serial.println("Data sent successfully.");
      } else {
          Serial.print("Failed to send data: ");
          Serial.println(fbdo.errorReason().c_str());
      }

  }

}