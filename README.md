stigame
=======

[![Build Status](https://travis-ci.org/jordsti/stigame.svg?branch=master)](https://travis-ci.org/jordsti/stigame)

StiGame is a C++ 2D game library using SDL2.
You can fork this repository if you want to bootstrap your new game with this library and modify the library for the need of your game
or you can use the pre-compiled binary and use this library for your project.

### What is included ?
At the moment, these features are already implemented into StiGame.

- Basic State
  - BaseGameState
  - GuiState
- Viewport
  - Window Size
  - Window Mode
  - FPS Handling
- Action Binding
  - Key Action
  - Mouse Action
  - Binding Configuration File
- User Interface
  - Gui Elements
    - Button
	- Label
	- Combo Box
	- Check Box and Radio Button
	- Selection List
	- Tab Panel
	- Layout *on the way...*
		- Vertical Box Layout **vertical align todo**
		- Horizontal Box Layout **test and horizontal align todo**
		- Form Layout **todo**
		- Spacer Item for Layout **to test**
- Game Sprite
  - Directional Sprite
  - General Sprite
  - Sprite Library for texture management
  
- Tool(s)
  - [Sprite Editor](tools/sprite-editor)
  - [Gui Editor](tools/gui-editor)

### Purpose
This library will be used for StiCode game development and this library will be development for the need of StiCode Games.
But we will try to keep the library "general", so no game specific thing will be implemented in this library.

### Compile and Test

#### Windows

At the moment the only test is to run the Sample coming with the library. This sample only show gui elements at the moment.

We currently compile StiGame using mingw32-TDM-GCC-4.8.1 (Coming with Code::Blocks).

Windows 7 and Linux are the only tested Operating System at the moment.

You need to first retrieve the extern files like SDL2 header and libraries.

A Python script is included for this. (Windows Only)

After you can compile using Code::Blocks IDE.

__Windows build is broken at the moment because of SDL_Thread (need a windows pc to fix this)__

#### Linux

Tested on Linux (Ubuntu 14.04-64bit) with g++ and SDL2, SDL2-image, SDL2-ttf and SDL2-gfx

You just need to fetch the depencies
- SDL2
- SDL2-image
- SDL2-ttf
- SDL2-net
- SDL2-gfx

### TO DO


- Gui Test Project, to test all Gui Element
	- Table -> to be tested and finished
	- Decorated Button *Python wrapper w/ (M)Style*
		- Highlight button, graphics are there
	- Progress Bar test
	- TextBox working, but need to handle unicode or transfert char into ascii.
	- Need to add a BaseClass for Font Rendering Gui Item, to generalize setCaption and getCaption method.
	- Layout Item
		- Form Layout
		- ~~Item Minimum Size and MaxSize ?~~
	- Normalize all *.setCaption method ; std::string text or const char* , to be determined! __High Priority__
	- Gui Item Appereance effect and dispearring effects __Working at the moment__
- Viewport
  - Save resolution information, to persist configuration
  - Viewport Settings ?
 
- Controller Support
  - Map Controller and handle event
  - Persitant configuration of the default controller
  
- SPhysic *recode*
 
- GameUnit review *will be deleted*

- Sprite tick rework, not static anymore

- float matrix for point transformation

- Network Code
    - Udp Socket -> Working with UdpPacket and PacketStream to read content of a packet, still need to implement more data type (Only Int32 and UInt32 are handled)
    - Need to test between two different environment (Big Endian vs Little Endian)
    - Tcp Socket seems to work, but still need to do many things, still need to encapsulate all the data into a packet to use PacketStream class
    - MessageQueue System Base Class with multi-thread (one sending, one receiving)
    
- FrameFile ( equation evaluation (+, -) with vars (state_width, state_height,etc... )

and things that don't come to my mind at the moment...


### Nigthly Builds

Nightly builds are currently available at : http://ci.sticode.org/

Current API documention can be found at : http://ci.sticode.org/stigamedoc/
