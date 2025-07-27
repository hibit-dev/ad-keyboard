// -------------------------------------------------
// Copyright (c) 2025 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#define AD_KEYBOARD_PIN A0

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int value = analogRead(AD_KEYBOARD_PIN);

  Serial.print("Analog value: ");
  Serial.println(value);

  delay(250);
}
