String inWord;
char inByte;
String data;

void setup() {
    Particle.variable("STU", data);
    // GPS Serial
    Serial1.begin(9600);
}

void loop() {
	// get data from GPS unit
    while (Serial1.available() > 0) {
        inByte = Serial1.read();
        if (inByte == '\n') {
            // get RMC data
            if (inWord.startsWith("$GPRMC")) {
                data = inWord;
                inWord = "";
            } else {
                inWord = "";
            }
        } else {
            inWord += inByte;   
        }
    }
}