#include <Adafruit_NeoPixel.h>

#define PHOTO    A0
#define LED      11
#define SWITCH   13
#define NUM_LEDS 32

long randR;
long randG;
long randB;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(SWITCH, INPUT);
  pinMode(PHOTO, INPUT);
  strip.begin();
  strip.show();
}

void loop() {
  	// If switch is high and light is low
	while (digitalRead(SWITCH) == HIGH && analogRead(PHOTO) < 225) {
      	for(int i=0; i<40; i++) {
          	// If switch is low or light is high
          	if (digitalRead(SWITCH) == LOW || analogRead(PHOTO) > 225) {
          		i -= 1;
          	}
         	
          	else {
                // Random colors in the whole spectrum
                randR = random(0, 255);   //Random RED value
                randG = random(0, 255);   //Random GREEN value
                randB = random(0, 255);	  //Random BLUE value

                // Random colors only in green-blue hues
                // randR = random(0, 64);
                // randG = random(0, 255);
                // randB = random(0, 255);

                // Random colors only in red-blue hues
                // randR = random(0, 255);
                // randG = random(0, 64);
                // randB = random(0, 255);

                // Random colors only in green-red hues
                // randR = random(0, 255);
                // randG = random(0, 255);
                // randB = random(0, 64);

                uint32_t color = strip.Color(randR, randG, randB); // Set color
                strip.setPixelColor(i, color); // Draw new pixel
                strip.setPixelColor(i-8, 0); // Erase pixels
                strip.show();

                delay(70);
            }
      	}
	}
}