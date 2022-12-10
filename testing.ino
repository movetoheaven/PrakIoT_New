#include <ESP8266WiFi.h>
int IRONE = D7;
int IRTWO = D6;
int IRTRI = D5;

//Konfigurasi WiFi
const char* ssid     = "Rumah";
const char* password = "hayongapain";

//IP Address Server yang terpasang XAMPP
const char *host = "192.168.1.20";

void setup() {
  Serial.begin(9600);
  //declaring pin
  pinMode(IRONE, INPUT);
  pinMode(IRTWO, INPUT);
  pinMode(IRTRI, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  // if connection is working, then the serial monitor will be shown this address
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client;

  // park 1
  int Slot1 = digitalRead(IRONE);

  if(Slot1 == LOW){
    Serial.println("terdeteksi objek");
    Serial.print("Connecting to ");
    Serial.println(host);

     //Mengirimkan ke alamat host dengan port 80 -----------------------------------
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
      Serial.println("Connection failed");
      return;
    }
  
    //Isi Konten yang dikirim adalah alamat ip si esp -----------------------------
    String url = "/parkedlogs/connection.php?Availability=Slot%201%20Filled";
  
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    //Mengirimkan Request ke Server -----------------------------------------------
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                "Host: " + host + "\r\n" +
                "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 1000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
  
    //Read all the lines of the reply from server and print them to Serial
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  
    Serial.println();
    Serial.println("closing connection");

    }else{
      Serial.println("tak terdeteksi objek");
      }
  
  // park 2
  int Slot2 = digitalRead(IRTWO);

  if(Slot2 == LOW){
      Serial.println("terdeteksi objek");
      Serial.print("Connecting to ");
      Serial.println(host);

       //Mengirimkan ke alamat host dengan port 80 -----------------------------------
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
      Serial.println("Connection failed");
      return;
    }
  
    //Isi Konten yang dikirim adalah alamat ip si esp -----------------------------
    String url = "/parkedlogs/connection.php?Availability=Slot%202%20Filled";
  
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    //Mengirimkan Request ke Server -----------------------------------------------
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                "Host: " + host + "\r\n" +
                "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 1000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
  
    //Read all the lines of the reply from server and print them to Serial
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  
    Serial.println();
    Serial.println("closing connection");
        
    }else{
      Serial.println("tak terdeteksi objek");
      }

  // park 3
  int Slot3 = digitalRead(IRTRI);

  if(Slot3 == LOW){
      Serial.println("terdeteksi objek");
      Serial.print("Connecting to ");
      Serial.println(host);

       //Mengirimkan ke alamat host dengan port 80 -----------------------------------
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
      Serial.println("Connection failed");
      return;
    }
  
    //Isi Konten yang dikirim adalah alamat ip si esp -----------------------------
    String url = "/parkedlogs/connection.php?Availability=Slot%203%20Filled";
  
    Serial.print("Requesting URL: ");
    Serial.println(url);
  
    //Mengirimkan Request ke Server -----------------------------------------------
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                "Host: " + host + "\r\n" +
                "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 1000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
  
    //Read all the lines of the reply from server and print them to Serial
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  
    Serial.println();
    Serial.println("closing connection");

    
    }else{
      Serial.println("tak terdeteksi objek");
      }
  delay(200);
}
