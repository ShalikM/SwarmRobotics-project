void sendToServer(String str)
{
    Serial.println(str);
    TKDClient.println(str);
    

    //Read From server
    if(TKDClient.available() != 0)
    {
        String serverResponce = TKDClient.readStringUntil('\r');
        Serial.println(serverResponce);

if(k<2)
{
        if(serverResponce == "stop") 
        {
           digitalWrite(MOT1, LOW);
           digitalWrite(MOT2, LOW);
            digitalWrite(MOT12, HIGH);
            digitalWrite(MOT21, HIGH);
         k++;   
            
            delay(7500);
            digitalWrite(MOT12, LOW);
            digitalWrite(MOT21, LOW);
            
        }           
        
        }
    }
    TKDClient.flush();
    delay(2000);
    
}
