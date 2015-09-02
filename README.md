# README #

This project is a replacement for the WaterRower A1 monitor. It runs on a Arduino Yun with an LCD Shield on top.

![IMG_6143.jpg](https://bitbucket.org/repo/XdXBrG/images/1518004658-IMG_6143.jpg)

![IMG_6146.jpg](https://bitbucket.org/repo/XdXBrG/images/3418155426-IMG_6146.jpg)

It reads the speed of the wheel via a sensor located on top of a disk with 6 magnets

![8Gwne9W.jpg](https://bitbucket.org/repo/XdXBrG/images/2013458362-8Gwne9W.jpg)  

Every time the magnet goes under the sensor arduino generates an interrupt.

Right now it can keep track of the duration of the exercise, distance, intensity (meters x seconds), 500 meters splits and can save the data on an SD card. It also has it's own web server that reads the saved data and creates a simple graph with the stats.

![192_168_145_103_sd_.png](https://bitbucket.org/repo/XdXBrG/images/2373117926-192_168_145_103_sd_.png)

if you are interested please send me an email: giordy_at_giordy.it