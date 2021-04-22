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
        0 - Default Animation
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
    const char SETUP_CHAR_STREAM[] PROGMEM = "rSVI2C,64,1,1800,2670,1000,2409\nrSVI2C,64,0,1520,2400,1000,1960\n";
    const char STREAM_DEFAULTANIMATION_CHAR_STREAM[] PROGMEM = "sC,641,0,667,700,175,0,300,-255,159\nsC,640,0,667,500,175,0,300,-255,128\nsC,641,667,1333,300,473,-296,300,-325,0\nsC,640,667,1333,300,473,-237,300,-325,0\nsC,641,2000,2000,300,500,0,500,-500,0\nsC,640,2000,2000,300,500,0,500,-500,0\nsC,641,4000,1333,500,333,0,300,-333,0\nsC,640,4000,1333,500,333,0,700,-333,0\nsC,641,5333,1334,300,333,0,700,-333,0\nsC,640,5333,1334,700,333,0,300,-333,0\n";
    const char STREAM_DEFAULTANIMATION_CHAR_STREAM_LOOP[] PROGMEM = "sC,640,10000,352,300,176,0,500,-176,0\n";

    CommandStream setupStream = CommandStream(SETUP_CHAR_STREAM, 0);
    CommandStream stream_DefaultAnimation = CommandStream(STREAM_DEFAULTANIMATION_CHAR_STREAM, 10000, STREAM_DEFAULTANIMATION_CHAR_STREAM_LOOP, 352);    

    CommandStream *getCommandStream(byte streamID)
    {
        switch (streamID)
        {
        case 0:
            return &stream_DefaultAnimation;
        default:
            return NULL;
        }
    }

    CommandStream *getSetupCommandStream()
    {
        return &setupStream;
    }
} // namespace GeneratedCommandStreams
