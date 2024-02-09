
  Rain_Detector_Alert_System.ino
1. #include <LiquidCrystal.h> //Libraries
2. LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Arduino pins to 1cd
3. #define sensor_pin A0
4. int adc value;
5. int percent_value;
6. #define bt silent A5
7. int silent=0;
8. #define G_led 8 
9. #define R_led 9
10.#define buzzer 13.
11. void setup() { // put your setup code here, to run once
12. pinMode(sensor pin, INPUT);
13. pinMode(bt_silent, INPUT_PULLUP);
14. pinMode(R_led, OUTPUT); // declare Red LED as output
15. pinMode(G_led, OUTPUT); // declare Green LED as output
16. pinMode (buzzer, OUTPUT); // declare Buzzer as output
17. lcd.begin(16, 2); // Configura lcd numero columnas y filas
18.lcd.clear();
19.lcd.setCursor (0,0);
20.lcd.print(" Welcome To ");
21.lcd.setCursor (0,1);
22.lcd.print(" Rain Detector ");
23. delay(2000);
24. lcd.clear();
25.}
26. void loop() {
27. adc_value= analogRead(sensor_pin);
28. percent_value = map(adc_value, 0, 1023,100,0);
29. if(digitalRead (bt_silent) == 0){
30. silent = 1;
31. delay(100);
32.}
33.lcd.setCursor(0, 0);
34.lcd.print("Rain Level: "); 35.lcd.print(percent_value);
36.lcd.print("%");
37.lcd.setCursor(0, 1);
38. if(percent_value>30){
39. if(silent==0){digitalWrite(buzzer, HIGH);}
40.lcd.print("Rain Alert...!!!");
41. digitalWrite(G_led, LOW); // Turn LED off.
42. digitalWrite(R_led, HIGH); // Turn LED on.
43. delay(300);
44. }else{ silent=0;
45.lcd.print(".....Normal.....");
46. digitalWrite(G_led, HIGH); // Turn LED on.
47.digitalWrite(R_led, LOW); // Turn LED off.
48.}
49. digitalWrite(buzzer, LOW);
50. delay(100);
51.}