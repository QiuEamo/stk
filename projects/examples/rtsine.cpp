// rtsine.cpp STK tutorial program

#include "SineWave.h"
#include "RtWvOut.h"

int main()
{
  // Set the global sample rate before creating class instances.
  Stk::setSampleRate( 44100.0 );
  Stk::showWarnings( true );

  SineWave sine;
  RtWvOut *dac = 0;

  try {
    // Define and open the default realtime output device for one-channel playback
    dac = new RtWvOut( 1 );
  }
  catch ( StkError & ) {
    exit( 1 );
  }

  sine.setFrequency( 441.0 );

  // Play the oscillator for 40000 samples
  for ( int i=0; i<40000; i++ ) {
    try {
      dac->tick( sine.tick() );
     }
    catch ( StkError & ) {
      goto cleanup;
    }
  }

 cleanup:
  delete dac;

  return 0;
}