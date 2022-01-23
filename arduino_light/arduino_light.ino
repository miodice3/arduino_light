
// TODO: add an explanation of what this does

void setup() {
    Serial.begin(9600);
    join_wifi_network();
}

void loop() {
  Serial.println("main loop");
  delay(500);
  re_join_network_if_needed();
}
