/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#include <Arduino.h>
#include <string.h>
// the setup function runs once when you press reset or power the board

/**
 * @brief Given plain text, transforms the text to morse code and reflects the morse code blinking the LED on the board.
 *
 * @param inputText
 */
void textToMorse(char *inputText);

/**
 * @brief Given a morse code turns the board LED on and off according to the morse code (.) -> shortBlink, (-) -> longBlink and ( ) -> no blink
 *
 * @param morseLetter
 */
void blink(const char *morseLetter);

void shortBlink();
void longBlink();

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

const char *letterToMorseCodeMap[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

// the loop function runs over and over again forever
void loop()
{
  Serial.println("Start of the loop");

  char plainText[] = "que chucha miras mi causa pedro sanchezzzzz";
  textToMorse(plainText);

  Serial.println("End of the loop");
  return;
}

/**
 * @brief Given plain text, transforms the text to morse code and reflects the morse code blinking the LED on the board.
 *
 * @param inputText
 */
void textToMorse(char *inputText)
{

  // Serial.println("Received input text: " + inputText);

  // get the size of input
  size_t inputLength = strlen(inputText);

  // map letters to morse code
  for (size_t i = 0; i < inputLength; i++)
  {
    Serial.print("Blinking letter: ");
    Serial.println(inputText[i]);
    const char *morseLetter = letterToMorseCodeMap[(unsigned int)inputText[i] - 97];
    blink(morseLetter);
    delay(2000); // delay between letters
  }

  return;
}

/**
 * @brief Given a morse code turns the board LED on and off according to the morse code (.) -> shortBlink, (-) -> longBlink and ( ) -> no blink
 *
 * @param morseLetter
 */
void blink(const char *morseLetter)
{

  size_t length = strlen(morseLetter);

  for (size_t i = 0; i < length; i++)
  {
    if (morseLetter[i] == '.')
    {
      Serial.println(morseLetter[i]);
      shortBlink();
    }
    else if (morseLetter[i] == '-')
    {
      Serial.println(morseLetter[i]);
      longBlink();
    }
  }
}

void shortBlink()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

void longBlink()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
