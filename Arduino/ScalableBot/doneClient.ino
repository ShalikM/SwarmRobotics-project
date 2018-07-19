//------------------------------------------------------------------------------------
#include <ESP8266WiFi.h>
//------------------------------------------------------------------------------------
// Defining I/O Pins
//------------------------------------------------------------------------------------
#define       LED0      2         // WIFI Module LED
//#define       LED1      D5        // Connectivity With Client #1
#define       LED2      D8        // Connectivity With Client #2
#define       BUTTON    D2        // Connectivity ReInitiate Button

#define       MOT1      D0
#define       MOT12     D1
#define       MOT2      D3
#define       MOT21     D5

      //------------------------------------------------------------------------------------
// BUTTON Variables
//------------------------------------------------------------------------------------

const String  nodeIdentifier = "node2";



//------------------------------------------------------------------------------------
// Authentication Variables
//------------------------------------------------------------------------------------
char*         TKDssid;
char*         TKDpassword;
IPAddress     TKDServer(192, 168, 4, 1);
WiFiClient    TKDClient;
//====================================================================================

// defines pins numbers
#define       trigPin   D6         // WIFI Module LED
#define       echoPin   D7   
// defines variables
long duration;
int distance;
int j=3;
int k=1;

void setup()
{
    // Setting The Serial Port ----------------------------------------------
    Serial.begin(9600);           // Computer Communication

digitalWrite(MOT1, LOW);
digitalWrite(MOT12, LOW);
digitalWrite(MOT2, LOW);
digitalWrite(MOT21, LOW);

    pinMode(MOT1, OUTPUT);
 pinMode(MOT12, OUTPUT);
 pinMode(MOT2, OUTPUT);
 pinMode(MOT21, OUTPUT);


pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 // Setting The Mode Of Pins ---------------------------------------------


  
  pinMode(LED0, OUTPUT);          // WIFI OnBoard LED Light
//    pinMode(LED1, OUTPUT);          // Indicator For Client #1 Connectivity
    pinMode(LED2, OUTPUT);          // Indicator For Client #2 Connectivity
    pinMode(BUTTON, INPUT_PULLUP);  // Initiate Connectivity
    digitalWrite(LED0, !LOW);       // Turn WiFi LED Off

    // Print Message Of I/O Setting Progress --------------------------------
    Serial.println("\nI/O Pins Modes Set .... Done");

// Starting To Connect --------------------------------------------------
    WiFi.mode(WIFI_STA);            // To Avoid Broadcasting An SSID
    WiFi.begin("TAKEONE");          // The SSID That We Want To Connect To

    // Printing Message For User That Connetion Is On Process ---------------
    Serial.println("!--- Connecting To " + WiFi.SSID() + " ---!");

    // WiFi Connectivity ----------------------------------------------------
                // Checking For Connection    


      CheckConnectivity();

    

}

//====================================================================================

void loop()
{
    
    sendToServer("bot 3");
   
}



