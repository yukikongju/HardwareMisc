#include "pitches.h"

#define SPEAKER_PIN 8
#define MAX_GAME_LENGTH 100

const byte ledPins[] = {9,10,11,12};
const byte buttonPins[] = {2,3,4,5};
const int gameTones[] = { NOTE_G3, NOTE_C4, NOTE_E4, NOTE_G5 };

byte gameSequence[MAX_GAME_LENGTH] = {0};
byte gameIndex = 0;


void setup() {
    Serial.begin(9600);

    // Setup led and buttons pins
    for (int i = 0; i < 4; i++) {
	pinMode(ledPins[i], OUTPUT);
	pinMode(buttonPins[i], OUTPUT);
    }

    // Setup Speaker
    pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
    // Add random color to the end of the sequence
    gameSequence[gameIndex] = random(0,4);
    gameIndex++;

    // check if player won
    if(gameIndex >= MAX_GAME_LENGTH) {
	Serial.println("You win!!");
	//reset game
	gameSequence[MAX_GAME_LENGTH] = {0};
	gameIndex = 0;
    }

    // play the sequence
    playSequence();
    if(!checkUserSequence()){
	gameOver();
    }

    delay(300);

    // play level up sound
    if (gameIndex > 0) {
	playLevelUpSound();
	delay(300);
    }

}

byte readPlayerInput() {
    while (true) {
	for (int i = 0; i < 4; i++) {
	    byte buttonPin = buttonPins[i];
	    if(digitalRead(buttonPin) == LOW){
		return i;
	    }
	}
	delay(1);
    }
}


bool checkUserSequence() {
    // check if user input is correct
    for (int i = 0; i < gameIndex; i++) {
	byte expectedButton = gameSequence[i];
	byte actualButton = readPlayerInput();
	if (expectedButton != actualButton) {
	    return false;
	}
    }
    return true;
}

void gameOver() {
    Serial.println("You Lost :( . Your score is:" gameIndex-1);
    gameIndex=0;
    delay(200);

    // Play Loser sound
    tone(SPEAKER_PIN, NOTE_DS5);
    delay(300);
    tone(SPEAKER_PIN, NOTE_D5);
    delay(300);
    tone(SPEAKER_PIN, NOTE_CS5);
    delay(300);
    for (byte i = 0; i < 10; i++) {
	for (int pitch = -10; pitch <= 10; pitch++) {
	    tone(SPEAKER_PIN, NOTE_C5 + pitch);
	    delay(5);
	}

    }
    noTone(SPEAKER_PIN);
    delay(500);
}

void playSequence() {
    // play entire sequence
    for (int i = 0; i < gameIndex; i++) {
	byte currentLed = gameSequence[i];
	playLightLedAndPlayTone(currentLed);
	delay(50);
    }
}

void playLightLedAndPlayTone(byte ledIndex) {
    // play light
    digitalWrite(ledIndex, HIGH);

    // play tone
    tone(SPEAKER_PIN, gameTones[ledIndex])
    delay(300);

    digitalWrite(ledIndex, LOW);
    noTone(SPEAKER_PIN);
}


void playLevelUpSound() {
    tone(SPEAKER_PIN, NOTE_E4);
    delay(150);
    tone(SPEAKER_PIN, NOTE_G4);
    delay(150);
    tone(SPEAKER_PIN, NOTE_E5);
    delay(150);
    tone(SPEAKER_PIN, NOTE_C5);
    delay(150);
    tone(SPEAKER_PIN, NOTE_D5);
    delay(150);
    tone(SPEAKER_PIN, NOTE_G5);
    delay(150);
    noTone(SPEAKER_PIN);
}



