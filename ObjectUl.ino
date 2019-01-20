
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int relay=13;
int buzzer=10;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
float distance=0.0;

int j=1;
int k=0;
void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
// initialize the LCD
pinMode(relay, OUTPUT); 
pinMode(buzzer, OUTPUT);  
digitalWrite(buzzer, LOW); 
}

void loop() {
  delay(60);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
     

  distance = sonar.ping_cm();
  
  // Send results to Serial Monitor
  
  
  
   if (distance <= 50 && distance >= 2)
   {
      if(j==1)
      {
      Serial.println("Reset Relay object came");
      blink();
      digitalWrite(buzzer, HIGH); 
      delay(1000);
      
      j=0;
      k=1;
      }
   
     Serial.print("Object Found at");
     Serial.print(distance);
     Serial.println(" cm");
    }
  else {
    if(k==1)
      {
    Serial.println("Reset Relay object gone");
    blink();
    digitalWrite(buzzer, LOW); 
    delay(1000);
    j=1;
    k=0;
     
      }
     // Serial.println(k); 
      Serial.print("Object NOT Found");
  Serial.print(" Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  }
   
    
    
  } //end loop
 void blink()
 {
 
digitalWrite(relay, HIGH); 
delay(100);
digitalWrite(relay, LOW); 
delay(100);
 
 }
 
 

