# =========== dec/06/2020
## sprite.cpp
### update & draw
	Default string for "none" animation: __NONE to ___NONE
# =========== nov/09/2020
## main.cpp:
### sdlInit:
	Initialize joystick support.
## InputManager:
### finalize:
	New method to free sdl joysticks memory before sdl shutdown.
# =========== oct/16/2020
## ScreenManager:
### unload:
		Free screen content before the object memory.
# =========== sep/24/2020
## Animation:
### draw:
		Destination draw to use the frame's size, insted using object size.
