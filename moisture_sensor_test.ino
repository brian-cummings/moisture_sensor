int upperValue = 700;
int lowerValue = 300;
int maxResistance, minResistance, moistPct, totalRange,dryValue, normalValue, wetValue;
String soilStatus;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  if (minResistance == 0) minResistance = sensorValue;
  maxResistance = max(sensorValue, maxResistance);
  minResistance = min(sensorValue, minResistance);
  if (maxResistance > upperValue) upperValue = maxResistance;
  if (minResistance < lowerValue) lowerValue = minResistance;
  moistPct = map(sensorValue, lowerValue, upperValue, 100, 0);
  totalRange = upperValue - lowerValue;
  wetValue = totalRange / 10 + lowerValue;
  normalValue = totalRange / 2 + lowerValue;
  dryValue = upperValue - totalRange / 10;
  if (sensorValue > dryValue) {
    soilStatus = "Dry";
    } else if (sensorValue < wetValue) {
      soilStatus = "Wet";
    } else {
      soilStatus = "Normal";
    }
  
  Serial.print("Moisture%: ");
  Serial.print(moistPct);
  Serial.print("    | Lower: ");
  Serial.print(lowerValue);
  Serial.print("    | Upper: ");
  Serial.print(upperValue);
  Serial.print("    | Dry: ");
  Serial.print(dryValue);
  Serial.print("    | Normal: ");
  Serial.print(normalValue);
  Serial.print("    | Wet: ");
  Serial.println(wetValue);
  Serial.println();
  delay(200);
  Serial.print("Resistance:");
  Serial.print(sensorValue);
  Serial.print("  | MinResistance:");
  Serial.print(minResistance);
  Serial.print("  | MaxResistance:");
  Serial.println(maxResistance);
  Serial.println();
  delay(200);
  Serial.print("Soil status is ");
  Serial.println(soilStatus);
  Serial.println();
  delay(200);
}



