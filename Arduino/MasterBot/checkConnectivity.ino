void CheckConnectivity()
{
    while (WiFi.status() != WL_CONNECTED)
    {
        for (int i = 0; i < 10; i++)
        {
            digitalWrite(LED0, !HIGH);
            delay(250);
            digitalWrite(LED0, !LOW);
            delay(250);
            Serial.print(".");
        }
        Serial.println("");
    }

    // Stop Blinking To Indicate Connected ----------------------------------
    digitalWrite(LED0, !HIGH);
    Serial.println("!-- Client Device Connected --!");
     
  
    // Printing IP Address --------------------------------------------------
    Serial.println("Connected To      : " + String(WiFi.SSID()));
    Serial.println("Signal Strenght   : " + String(WiFi.RSSI()) + " dBm");
    Serial.print  ("Server IP Address : ");
    Serial.println(TKDServer);
    Serial.print  ("Device IP Address : ");
    Serial.println(WiFi.localIP());
  
    // Conecting The Device As A Client -------------------------------------
    TKDRequest();
}

void TKDRequest()
{
    // First Make Sure You Got Disconnected
    TKDClient.stop();
  
    // If Sucessfully Connected Send Connection Message
    if (TKDClient.connect(TKDServer, 9001))
    {
        Serial.println    ("<" + nodeIdentifier + "-CONNECTED>");
        TKDClient.println ("<" + nodeIdentifier + "-CONNECTED>");
    }
}
