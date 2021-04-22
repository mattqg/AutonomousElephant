#include "GeneratedCommandStreams.h"

namespace GeneratedCommandStreams
{

    //// !!! Insert/edit your animation triggering and playback logic here !!! ////
    /* Some helpful methods:

        BottangoCore::commandStreamProvider.streamIsInProgress()                                        //returns if any animation is currently playing
        BottangoCore::commandStreamProvider.startCommandStream(byte animationID, bool looping)          //starts playing an animation (and stops the current if any)
        BottangoCore::commandStreamProvider.stop()                                                      //stops the current playing animation, if any
    */

    /* Animations key:
        0 - Test Animation
    */

    bool playBegan = false;
    bool playOnStart = true;
    bool loop = true;
    byte startingAnimation = 0;

    // called once per update loop, your logic probably goes here.
    void updatePlayStatus()
    {
        // if haven't started any animations, or if should loop and nothing is playing (IE the last loop ended)
        if (playOnStart && (!playBegan || (loop && !BottangoCore::commandStreamProvider.streamIsInProgress())))
        {
            BottangoCore::commandStreamProvider.startCommandStream(startingAnimation, loop);
            playBegan = true;
        }
    }

    //// ----------------------------------------- /////

    //// GENERATED CODE. You probably don't need to change any of the below ////
    const char SETUP_CHAR_STREAM[] PROGMEM = "rSVI2C,64,0,600,2400,2400,1500\nrSVI2C,64,1,800,2400,2400,1600\nrSVI2C,64,2,600,2400,2400,1500\nrSVI2C,64,3,1000,2000,2500,1500\n";
    const char STREAM_TESTANIMATION_CHAR_STREAM[] PROGMEM = "sC,640,-77298,1967,500,492,0,145,-481,99\nsC,641,-77298,1000,500,250,0,500,-250,0\nsC,643,-77298,2000,500,500,0,162,-500,0\nsC,642,-77265,2967,500,742,0,829,-742,0\nsC,641,-76298,3900,500,975,0,808,-975,0\nsC,640,-75331,2000,145,735,-151,510,-1337,-2\nsC,643,-75298,2933,162,733,0,803,-733,0\nsC,642,-74298,3100,829,775,0,534,-775,0\nsC,640,-73331,3066,510,1114,2,83,-752,0\nsC,641,-72398,3167,808,792,0,470,-792,0\nsC,643,-72365,5067,803,1267,0,531,-1267,0\nsC,642,-71198,2100,534,525,0,912,-525,0\nsC,640,-70265,2967,83,742,0,83,-742,0\nsC,641,-69231,1933,470,483,0,863,-483,0\nsC,642,-69098,1800,912,450,0,260,-450,0\n";
    const char STREAM_TESTANIMATION_CHAR_STREAM_LOOP[] PROGMEM = "sC,640,-67298,625,83,313,0,500,-313,0\nsC,641,-67298,484,863,242,0,500,-242,0\nsC,642,-67298,361,260,180,0,500,-180,0\nsC,643,-67298,25,531,13,0,500,-13,0\n";

    CommandStream setupStream = CommandStream(SETUP_CHAR_STREAM, 0);
    CommandStream stream_TestAnimation = CommandStream(STREAM_TESTANIMATION_CHAR_STREAM, 10000, STREAM_TESTANIMATION_CHAR_STREAM_LOOP, 625);    

    CommandStream *getCommandStream(byte streamID)
    {
        switch (streamID)
        {
        case 0:
            return &stream_TestAnimation;
        default:
            return NULL;
        }
    }

    CommandStream *getSetupCommandStream()
    {
        return &setupStream;
    }
} // namespace GeneratedCommandStreams
