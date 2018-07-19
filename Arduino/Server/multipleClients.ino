void IsClients(int dist,int sj)
{
    if (TKDServer.hasClient())
    {
        for (int i = 0; i < MAXSC; i++)
        {
          //find free/disconnected spot
          if (!TKDClient[i] || !TKDClient[i].connected())
          {
              if (TKDClient[i]) TKDClient[i].stop();
              TKDClient[i] = TKDServer.available();
              Serial.print("New Client : "); Serial.print(String(i + 1) + " - ");
              continue;
          }
        }
        // no free / disconnected spot so reject
        digitalWrite(LED1, HIGH);
        WiFiClient TKDClient = TKDServer.available();
        TKDClient.stop();
    }
  
    //check clients for data -------------------------------------------------------
  
    for (int i = 0; i < MAXSC; i++)
    {
        if (TKDClient[i] && TKDClient[i].connected())
        {
            if (TKDClient[i].available())
            {
                 // If Any Data Was Available, Read It
                 // Read From Client
                  String clientRead = TKDClient[i].readStringUntil('\r');
                  Serial.println(clientRead);
                  Serial.println(i);

                  
                  
                  if(dist < 40 || k==2) 
                  {
                    k=2;
                    TKDClient[i].println("stop");
                    Serial.print("stop");
                     
                    TKDClient[i].flush();

                      }
                  
                  
                  
                 if(clientRead=="on"&& k==1)
                  {
                    j++;
                    
                    }
                    if(j>1 && k==1)
                    {
                   
TKDClient[i].println(String(sj));
TKDClient[i].flush();
                                 
                  
                  
                    }
                    if(j==1)
                  {
                    TKDClient[i].println("start");
                    TKDClient[i].flush();
                  }           
            }
        }
    
    }
    
}
