# Beandolin

## Physical interaction design for music; building a new physical interface for music with beans, a piezoelectric microphone, a microcontroller, and functional programming

![Beandolin](/beandolin.jpg)

This project was the final project for Stanford MUSIC 250A: Physical Interaction Design for Music. Special thanks to everyone at CCRMA, my classmates, as well as my instructor and TA for their inspiration, motivation, and generous help.

Beandolin is an instrument prototype made with Faust's physical model of a guitar and a Teensy microcontroller. A piezo microphone attached to the lid of a jar picks up on the excitation of garbanzo beans hitting when the jar is shaken. This excitation is routed through the model to play chorsds. Buttons allow for playing chords I, IV, and V, and force-sensitive resistors allow for playing bass notes corresponding to the root and fifth of the chord.

## Why build an instrument? What should we consider?

Designing a physical instrument is a unique task; we are essentially designing an interface for artistic creation. When we design things with straightforward utility (like a chair or a website), there is a strong restriction on the possible use cases.

That isn't to say that nobody will turn a chair into [art by placing it next to the definition of chair and a picture of a chair](https://en.wikipedia.org/wiki/One_and_Three_Chairs) and challenge what a chair is, but a furniture designer doesn't really need to consider how an artist might want to transform a chair.

On the other hand, when designing a musical instrument, the utility is less straightforward. So how do we find our "why?" when we can't pin down utility?

A new musical instrument can:

- Excite an audience
- Engage new modes of physicality from the musician
- Shift and challenge a musician's cognitive mappings of gesture to sound

## Visual gestures as part of an artist's performance

In MUSIC 351: Seminar in Music Cognition and Perception, we discussed how pianists physically move their torsos to signal a cadence in a way that is external to the technical execution (striking keys). Indeed, if you watch professional musicians, there is a lot of physical expression external to the production of sound. Violinists lean, pianists float their hands, guitarists contort their faces.

My idea for this project was to expose the physicality of the music-making itself by encouraging large gestures by the musician as part of the music making, as well as letting the viewer peek into the physical elements producing the sound.
Theorizing about music interfaces aside, I also wanted it to be fun to play, watch, and listen to!

## Placing restrictions to guide the user

If we want the musician to explore the physicality of music-making, we can remove complexity in other areas of sound production. This would lead me to restrain the function of the instrument by envisioning it as a combination of a bass and a mandolin, letting the musician produce acoustic instrumentation, with an emphasis.

The bass noises would be produced by simple button presses, but the gestural magic would be in the mandolin sounds, which would be produced by shaking a jar of beans with a piezoelectric microphone on the lid. I limited the amount of tonal options available to the musician to three chords.

By limiting the tonal options, the musician could focus specifically on the gesture of shaking, simultaneously listening to the timbral quality and adjusting their performance.

## Designing sound

To synthesize the sound, I used Faust, a functional programming language for audio digital signal processing.

The bass sound was built from a single oscillator shaped with an ADSR envelope. These sounds were triggered by button presses.

Due to time constraints, for the "mandolin" sound, I used an existing physical modelling synthesis tool that would process the signal of the beans hitting the bottom of the lid from the piezoelectric microphone and turn it into sound.

## Microcontroller

To carry out the functions needed for sound production, I used a Teensy microcontroller. This means that with a power source, the computation needed to create the digital sounds from physical input can be done without the use of a computer.

## Bringing it together and performing

Our class capped off the class by demonstrating and presenting at the CCRMA stage. A lot of my classmates were mechanical engineering graduate students and had experience using computer-assisted design software, but as a cognitive science student, my prototype was held together with tape, bad soldering, and faith.

My demonstration went well! I stood before John Chowning and Roger Linn, with nothing but beans and a dream. Unfortunately, there's no video, so you'll have to take my word for it. There was a lot of smiles and laughter from the audience, as well as movement as a response to the physicality of my demonstration. Afterwards, I received a lot of great feedback, as well as people who wanted to try out the instrument theirselves.

![Beandolin](/beandolin2.JPG)

Ultimately, I accomplished what I set out to do, which was to create an instrument that exposed the physicality of sound, encouraged the instrumentalist to lean into gesture, and make people smile.
