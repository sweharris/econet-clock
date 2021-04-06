# econet-clock

This is an attempt to use an Arduino Nano as a clock for an Acorn Econet
system.

Briefly, [Econet](https://en.wikipedia.org/wiki/Econet) is a differential
serial network created by Acorn Computers.  It became popular in schools
because of the BBC Micro.

In order for this to work there needs to be a clock source.  Dedicated
clock devices exist.

A thread on [Stardot](https://www.stardot.org.uk/forums/viewtopic.php?p=315974)
proposed using a Raspberry Pi as the clock source.  I wondered if an
Arduino could do it.

This is my result.
