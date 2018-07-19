void sendToServer(String str)
{
    
    
    TKDClient.println(str);
    
    //Read From server
    if(TKDClient.available() != 0)
    {
        String serverResponce = TKDClient.readStringUntil('\r');
      int ult =serverResponce.toInt();
        
       Serial.println(k);
       Serial.println(serverResponce); 
        if(ult>20)
        {
                     k++; 
        }
              if(ult > 20 && k == 15)
          {
          
         
Serial.println("done");
          digitalWrite(MOT1, HIGH);
      digitalWrite(MOT2, HIGH);
           
          } 
        
       


    if(j>1)    
{

        if(serverResponce=="stop") 
        {
          digitalWrite(MOT1, LOW);
           digitalWrite(MOT2, LOW);
            digitalWrite(MOT12, HIGH);
            digitalWrite(MOT21, HIGH);
                  j=1;    
            delay(7500);
            digitalWrite(MOT12, LOW);
            digitalWrite(MOT21, LOW);
            
        }       
        }
    }
    
    TKDClient.flush();
    delay(2000);
}
