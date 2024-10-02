#include <WiFiNINA.h>      // Include the Wi-Fi library

// Wi-Fi credentials
char ssid[] = "Naman";         // Replace with your Wi-Fi SSID
char pass[] = "naman1234";     // Replace with your Wi-Fi password

int status = WL_IDLE_STATUS;       // To check Wi-Fi status
const int buttonPin = 2;           // Push button pin

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);    // Setting built-in LED as output
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with pull-up resistor
  
  Serial.begin(9600);              // Start the serial communication
  
  // Attempt to connect to Wi-Fi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);   // Connect to Wi-Fi network
    delay(10000);
  }
  
  Serial.println("Connected to Wi-Fi!");
}

// Function to blink a dot in Morse code
void dot() 
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(900);
}

// Function to blink a dash in Morse code
void dash() 
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(600);
  digitalWrite(LED_BUILTIN, LOW);
  delay(900);
}

void loop() 
{
  if (digitalRead(buttonPin) == LOW) // If the button is pressed
  {
    // Morse Code for the name "NAMAN"
    
    // Letter 'N'
    dash();
    dot();
    delay(1500);

    // Letter 'A'
    dot();
    dash();
    delay(1500);

    // Letter 'M'
    dash();
    dash();
    delay(1500);

    // Letter 'A'
    dot();
    dash();
    delay(1500);

    // Letter 'N'
    dash();
    dot();
    delay(200000); // Long delay to end the code
    
  } else {
    // If the button is not pressed, do nothing
    delay(100);   // Small delay to avoid unnecessary processing
  }
}
