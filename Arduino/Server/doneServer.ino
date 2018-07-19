//-- Libraries Included --------------------------------------------------------------
#include <ESP8266WiFi.h>
//------------------------------------------------------------------------------------
// Define I/O Pins
#define       LED0      2         // WIFI Module LED
#define       LED1      D5        // Connectivity With Client #1
#define       LED2      D8        // Connectivity With Client #2
#define       BUTTON    D2        // Connectivity ReInitiate Button
//------------------------------------------------------------------------------------
// Authentication Variables
char*       TKDssid;              // SERVER WIFI NAME
char*       TKDpassword;          // SERVER PASSWORD
//------------------------------------------------------------------------------------
#define     MAXSC     4        // MAXIMUM NUMBER OF CLIENTS
WiFiServer  TKDServer(9001);      // THE SERVER AND THE PORT NUMBER
WiFiClient  TKDClient[MAXSC];     // THE SERVER CLIENTS
//====================================================================================

String Message;
// boolean led1State = LOW;

 // defines pins numbers
#define       trigPin   D6         // WIFI Module LED
#define       echoPin   D7


#define       trigPin1   D0         // WIFI Module LED
#define       echoPin1   D1   

// defines variables
long duration;
int distance;
long duration1;
int dist1;
int j=1;
int k=1;
int e=1;
void setup()
{

  
    // Setting The Serial Port
    Serial.begin(9600);           // Computer Communication
SetWifi("TAKEONE", "");
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

   pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
    // Setting The Mode Of Pins
    pinMode(LED0, OUTPUT);          // WIFI OnBoard LED Light
    pinMode(LED1, OUTPUT);          // Indicator For Client #1 Connectivity
    pinMode(LED2, OUTPUT);          // Indicator For Client #2 Connectivity
    pinMode(BUTTON, INPUT_PULLUP);  // Initiate Connectivity

    // Print Message Of I/O Setting Progress
    Serial.println();
    Serial.println("I/O Pins Modes Set .... Done");

    // Setting Up A Wifi Access Point
 
}


void loop()
{
   // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;


// Clears the trigPin
                   
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance
dist1= duration1*0.034/2;

    IsClients(distance,dist1);
}
