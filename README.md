# SCarter Egnine

Author: Sandy Carter

## Contents
```
    GLConfigUtil.hpp  
    Gui.cpp  
    Gui.hpp  
    IKArm.cpp  
    IKArm.hpp  
    IKLine.cpp  
    IKLine.hpp  
    Makefile  
    README  
	Scenes/
        SceneBase.cpp  
        SceneBase.hpp  
        SceneIK.cpp     /* Part 2 */
        SceneIK.hpp  
        SceneMorph.cpp  /* Part 1 */
        SceneMorph.hpp
        SceneParticleBase.cpp  /* Part 3 */
        SceneParticleBase.hpp
        SceneParticleFountain.cpp
        SceneParticleFountain.hpp
        SceneParticleRepelant.cpp
        SceneParticleRepelant.hpp
    main.cpp  
    math3d.hpp  
    nbproject/
        ** Netbeans project files **
    scarter_engine.glade
```

The source files compile into a single executable.


## Unpacking and Compiling instructions
### Prerequisites
- Linux
- GTK
- gtkmm 2.4 
- glibmm 2.4 
- gtkglextmm 1.2
- glew
- GL
- GLU
- a c++11 compatible compiler
- OpenGL 4.3.0 compatible Video Card

## Compiling
- `$ make`
- or build in Netbeans


## Running instructions 
- File should be in dist/Debug/GNU-Linux-x86
- The `*.glade` file should be in the current directory
```
$ ./dist/Debug/GNU-Linux-x86/scarter_engine
```

## Controls
- Changing tabs will change between parts (Scenes)
- Morph (Part 1)
    - Slider
        - 0.00: cube
        - 1.00: Normalized into sphere

    - IK (Part 2)
        - Target location is randomly changed every 5 seconds.
    - Particle systems (Part 3)
        - Mouse movement interacts with the particle system.
