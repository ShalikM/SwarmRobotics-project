void SetWifi(char* Name, char* Password)
{
    // Stop Any Previous WIFI
    WiFi.disconnect();
  
    // Setting The Wifi Mode
    WiFi.mode(WIFI_AP_STA);
    Serial.println("WIFI Mode : AccessPoint Station");
  
    // Setting The Access Point
    TKDssid      = Name;
    TKDpassword  = Password;
  
    // Starting The Access Point
    WiFi.softAP(TKDssid, TKDpassword);
    Serial.println("WIFI < " + String(TKDssid) + " > ... Started");
  
    // Wait For Few Seconds
    delay(1000);
  
    // Getting Server IP
    IPAddress IP = WiFi.softAPIP();
  
    // Printing The Server IP Address
    Serial.print("AccessPoint IP : ");
    Serial.println(IP);
  
    // Starting Server
    TKDServer.begin();
    Serial.println("Server Started");
}
