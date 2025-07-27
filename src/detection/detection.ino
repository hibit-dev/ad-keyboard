// -------------------------------------------------
// Copyright (c) 2025 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#define AD_KEYBOARD_PIN A0

#define SW1_VALUE 0
#define SW2_VALUE 147
#define SW3_VALUE 308
#define SW4_VALUE 495
#define SW5_VALUE 789
#define NONE_VALUE 1023

#define VALUE_MARGIN 10

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int value = analogRead(AD_KEYBOARD_PIN);

  Serial.print("Analog value: ");
  Serial.print(value);
  Serial.print(" - Button: ");
  Serial.println(detectKey(value));

  delay(250);
}

String detectKey(int value)
{
  if (value >= SW1_VALUE - VALUE_MARGIN && value <= SW1_VALUE + VALUE_MARGIN) {
    return "SW1 (Right)";
  }

  if (value >= SW2_VALUE - VALUE_MARGIN && value <= SW2_VALUE + VALUE_MARGIN) {
    return "SW2 (Up)";
  }

  if (value >= SW3_VALUE - VALUE_MARGIN && value <= SW3_VALUE + VALUE_MARGIN) {
    return "SW3 (Down)";
  }

  if (value >= SW4_VALUE - VALUE_MARGIN && value <= SW4_VALUE + VALUE_MARGIN) {
    return "SW4 (Left)";
  }

  if (value >= SW5_VALUE - VALUE_MARGIN && value <= SW5_VALUE + VALUE_MARGIN) {
    return "SW5 (Select)";
  }

  if (value > NONE_VALUE - VALUE_MARGIN) {
    return "No button pressed";
  }

  return "Unknown";
}
