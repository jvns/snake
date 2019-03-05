snake
=====

Simple snake game written in C using ncurses.

You can run it using

```
make run
```
Then do
```
./snake
```

This was the biggest C program I'd written so far, so I'm pretty happy
with it. There's a separate frontend and backend so theoretically it
could be easily extended to have a graphical frontend instead of a
ncurses frontend, but I'm unlikely to actually do that.

There are also unit tests, which require [checkmk](http://mathias-kettner.de/checkmk.html)
to work.


### Compiling on Linux

To compile on Linux you'll need to have the developer's libraries for ncurses. On a Debian based system installing those libraries might look something like:

    sudo apt install libncurses5-dev

Once you have the ncurses libraries you can run the make command.