// This acts as an econet clock.  There is a mark time and a space time.
//
// D3 is 5V during the Mark time
// D4 is 5V during the Space time
//
// Because of the loop, there is the following timings:
//  Mark starts
//    72ns + 60*nop_count
//  Space starts
//    188ns + 60*nop_count
//  (the difference is because the loop takes around 120ns to execute).

// Comparing to a Beebmaster clock:
//    Mark: 0.125us -> 1 nop
//          0.25us  -> 3
//          0.5us   -> 7
//          1.0us   -> 15
//          2.0us   -> 32
//          4.0us   -> 65

//   Space: 0.25us  -> 1 nop
//          0.5us   -> 5
//          1.0us   -> 14
//          2.0us   -> 30
//          4.0us   -> 64
//          8.0us   -> 130

#define STAGE1 8
#define STAGE2 16

void setup()
{
  // Set all GPIO "port D" pins to output mode
  DDRD=B11111111;

  Serial.begin(115200);
  Serial.println("Clock started");
}

void loop()
{
  sei();
  while(1)
  {
    // Mark time.  72ns + 60*nop_count.  So 1 "nop" is 132ns.
    PORTD=STAGE1;
    asm("nop");

    // Space time.  188ns + 60*nop_count.  So 1 "nop" is 248ns.
    PORTD=STAGE2;
    asm("nop");
  }
}
