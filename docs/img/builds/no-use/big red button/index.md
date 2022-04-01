# Boulder Dash, or, How I Made a Big Concrete Button and Lived to Post About It

We've previously shown how to make a battery-operated, Internet-connected Big Red Button (http://www.thingsquare.com/blog/articles/wireless-battery-driven-big-red-button/). I've always been a fan of concrete so I felt I need to do this in concrete. But first! The final result.

![IMG_20171019_130812](C:\Dropbox\sloth\marketing\betong-button\IMG_20171019_130812.jpg)


## Step 0: Necessary Components

For this project, I used

* 1 Texas Instruments Sensortag
* 1 Adafruit Big Red Button
* 1 RGB LED
* Prototyping cables
* Concrete
* Various things for concrete mold


## Step 1: Get Concrete

It's easy to make something in concrete. To start with, we need to gather some things. Of course, we need the concrete itself. Just head to one of the large warehouses for construction material and buy a large bag of fine-grained concrete. Where I live, I went to www.bauhaus.se.

![IMG_20171008_121039](C:\Dropbox\sloth\marketing\betong-button\touse\IMG_20171008_121039.jpg)



## Step 2: Take Apart the Big Red

The button can be disassembled into a base socket, top button, and switch assembly. We will use the base socket (upper right in the picture) and mold the concrete around it. Thus, the button will be firmly fixed in concrete.

![IMG_20171019_134741_1](C:\Dropbox\sloth\marketing\betong-button\IMG_20171019_134741_1.jpg)


## Step 3: Make a Mold

Making a mold is rather easy, but you need to think in negative terms and think ahead of where you need to have empty space (ie no concrete). You need to think about the outer shape, and any holes and openings. Here, I used an old bowl and a plastic bottle.

The bottle is used for the negative space which will be under the button and house the electronics, so it has to be large enough. I cut off the top of the bottle and hot-glued it to the button underside.

![IMG_20171009_091053](C:\Dropbox\sloth\marketing\betong-button\touse\IMG_20171009_091053.jpg)


Using ordinary house-hold food oil, I lube the bowl so the concrete won't stick. The button socket should stick, so no oil on that one. Same for the bottle.


## Step 4: Mix the Concrete

For this step, you should keep in mind that eyes or lungs does not combine very well with concrete, and concrete is very dusty. It is also corrosive and not cool to have on your body. Use suitable protection and clean yourself up as soon as possible afterwards.

Pour some concrete into a large container of some kind. Add a little water and start mixing carefully - dust will fly! It's done when it's thouroghly mixed and has a consistency like thick porridge.

![IMG_20171010_091903](C:\Dropbox\sloth\marketing\betong-button\touse\IMG_20171010_091903.jpg)

## Step 5: Pour Concrete into Mold

Now, we can pour the mixed concrete into the mold. Since the button-bottle insert is not glued into the bowl, hold it down with one hand while pouring the concrete with a small spade. It might also float up so keep it pressed down.

A problem, depending on your viewpoint on aesthetics, is that concrete has a lot of trapped air. Tap the outside of the bowl from time to time to help air float to the top and escape. Otherwise, there will be bubbles which will result in small holes on the surface as you can see in the first picture. Myself, I kind of like the lunar-like surface; it makes for an interesting texture when feeling it.

![IMG_20171010_091846](C:\Dropbox\sloth\marketing\betong-button\touse\IMG_20171010_091846.jpg)


## Step 6: Wait

Concrete needs to harden through an exotermic process called "burning". Don't worry, there are no flames, not even noticeably higher temperatures. The concrete needs moisture for this process or it will risk cracking and being generally structurally unsound. So, once a day I sprinkled a little water on the surface.

The burn time depends on how thick the concrete is, but I waited three days in total. I kept a small weight on the bottle to keep it down.



![IMG_20171010_092201](C:\Dropbox\sloth\marketing\betong-button\touse\IMG_20171010_092201.jpg)

I did this on our balcony, and used a TI Sensortag running Thingsquare to keep track of the temperature. The concrete needs special attention if used in lower than +5 degrees Celsius.

![tag-temperature](C:\Dropbox\sloth\marketing\betong-button\touse\tag-temperature.png)

Good. Never below 8 degrees, we're fine. (the Sensortag was moved from inside the apartment to the balcony on October 5th.)

## Step 7: Remove from Mold

After a couple of days, it was done. I removed the mold and cleaned up hard edges with a bit of 200 grit sandpaper. Using a knife I cut off the parts of the bottle that were sticking out. I also added a couple of pads to the bottom so it wouldn't scratch the surface of what it stands on.

![IMG_20171011_204321](C:\Dropbox\sloth\marketing\betong-button\tag-switch.png)

Turns out, it weighs about 2.8 kg. That's a nice and heavy feel.

## Step 8: Add Electronics

Now we have a large button concrete. Time to add some smarts. The interior space is quite large, but not large enough for a TI Launchpad, so I used a TI Sensortag for this purpose.

There are two signals we want to route to the Sensortag: the button of course, but it also has an integrated LED.

First, remove the stock button LED (which has a current limiting resistor for 12V) and add our own LED with resistor for 3.3V. I soldered wires to the button terminals for normally-opened, and to the LED. These should then go to the Sensortag, but where?

## Step 9: Tweak the Sensortag

The Sensortag comes in a couple of flavors, one is sub-GHz with a CC1350, and another is on the 2.4 GHz band with a CC2650. Thingsquare has support for them both, but I picked the 2.4 GHz more or less since it was closer to me on my desk, I'm kind of reluctant to say :). I flashed the Sensortag with the latest firmware binary from www.thingsquare.com/download.

Ok, so the Sensortag is a reference design and as such the full schematics and diagrams are published by Texas Instruments here http://www.ti.com/tool/TIDC-CC2650STK-SENSORTAG.

From the schematic, I see that LEDs are active high, and buttons are active low. This tells me how to connect the button and LED.

![stag schematics leds buttons](C:\Dropbox\sloth\marketing\betong-button\touse\stag schematics leds buttons.png)

Now I need to find _where_ on the Sensortag I should solder the wires. I see on the assembly diagram how to do this.

![button led](C:\Dropbox\sloth\marketing\betong-button\touse\button led.png)

![button switch](C:\Dropbox\sloth\marketing\betong-button\touse\button switch.png)

First, I clip away the switch from the Sensortag and clean up the pads. Then, to save power, the LED on the Sensortag is removed too. The ground terminal is the oval slot next to the battery clip.



![tag-switch](C:\Dropbox\sloth\marketing\betong-button\tag-switch.png)

Now, I can solder the cables to the button to these pads. Et voila, button and LED is connected to the Sensortag and no software modification is necessary.



## Step 10: Full-on Glory

Now, I assemble it all, and insert a coin cell battery. The Sensortag boots up and I connect it to the gateway, then in the Thingsquare app (http://www.thingsquare.com/app/), enable remote access and set notifications. Next up, I configure it to send data less often since I primarily want to use this as a button and has sensor data from other Sensortags already. This will give me longer lifetime on a battery and is described in more detail here http://www.thingsquare.com/blog/articles/sensortag-power/

Finally, I share the button with the office account so that we all can control it and get notifications.