// Test program for instrument input
#define BSIZE 8000 // DUE has 96K bytes of RAM, use 2*8K of them to give about 1/4 sec max delay
int ringBuff[BSIZE];

#define T1 (BSIZE - (BSIZE/5)) // define tap time points as fraction of buffer size. T1 is shortest delay
#define T2 (BSIZE - 1) // T2 is longest delay possible

void setup() {
  // put your setup code here, to run once:
  
  for(int i = 0; i < BSIZE; i++)
    ringBuff[i] = 0;

  pinMode(A0, INPUT);
  analogReadResolution(12); // override 10 bit default. can go to 12 since board is a due
  analogWriteResolution(10); // overrid default 8 bit since we'll use DAC0 on due board
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int signalIn;
  int signalOut; // value to be output and stored into buffer at currentTap
  int oldValue1; // values read from previous tap points
  int oldValue2;
  int currentTap = 0; // the current tap point - incremented after each sample (modulo BSIZE)
  int tap; // temp used in indexing into older tap points
  long loopCount = 0; // counter for debug writes to serial port
  while(1) {
    signalIn = analogRead(A0) - 2048; // read 10 bit analog signal and convert to bipolar value

    // make delay of approx. 20us so sample rate is 40 Ksamp/sec
    // since without delay is seems to sample >= 100k/sec
    delayMicroseconds(20);

    // get values at delayed tap points in buffer
    tap = currentTap - T1;
    if (tap < 0)
      tap += BSIZE;
    oldValue1 = ringBuff[tap];
    
    tap = currentTap - T2;
    if (tap < 0)
      tap += BSIZE;
    oldValue2 = ringBuff[tap];

    // scale values (uP has 2-cycle integer divide capability, so just use mult/divide)
    oldValue1 /= 3;
    oldValue2 /= 4;

    // create output at this time sample, store it, and increment tap point
    signalOut = signalIn + oldValue1 + oldValue2;
    // limit the outputs to mimic normal overload distortion
    // and avoid digital number wraparound...
    if(signalOut > 2047) signalOut = 2047;
    if(signalOut < -2047) signalOut = -2047;
    // store in buffer
    ringBuff[currentTap] = signalOut;
    // increment circular tap point
    currentTap++;
    if(currentTap >= BSIZE) currentTap -= BSIZE;

    // scale value back to unsigned value in preparation for DAC
    signalOut += 2048;
    // write to DAC0 output on due board
    analogWrite(DAC0, signalOut);

    //**************** For Timing Tests Only *********************
    // ******* comment out for normal use as audio reverb
    // if(++loopCount >= 40000) {
    // Serial.println(signalIn);
    //  loopCount = 0;
    // }

    // repeat
  }
}
