#include "../../include/input/gamepad.h"




Gamepad::Gamepad() {
	this->initializeJoys();
	m_bOnce = true;
}
Gamepad::~Gamepad() {
	this->finalizeJoys();
}
void Gamepad::clearFrame() {
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		for (unsigned int j = 0; j < m_joyButtonsPressed[i].size(); j++)
		{
			m_joyButtonsPressed[i][j] = false;
			m_joyButtonsReleased[i][j] = false;
		}
	}
}
void Gamepad::updateInput(SDL_Event &ev) {
	if (ev.type == SDL_JOYBUTTONDOWN)
	{
		if (m_bOnce)
		{
			m_joyButtonsPressed[ev.jbutton.which][ev.jbutton.button] = true;
			m_joyButtonsReleased[ev.jbutton.which][ev.jbutton.button] = false;
			m_joyButtonsHold[ev.jbutton.which][ev.jbutton.button] = true;
			
			m_bOnce = false;
		}
	}
	else if (ev.type == SDL_JOYBUTTONUP)
	{
		m_joyButtonsPressed[ev.jbutton.which][ev.jbutton.button] = false;
		m_joyButtonsReleased[ev.jbutton.which][ev.jbutton.button] = true;
		m_joyButtonsHold[ev.jbutton.which][ev.jbutton.button] = false;
		
		m_bOnce = true;
	}
	
	if (ev.type == SDL_JOYAXISMOTION)
	{
		m_joyAxis[ev.jaxis.which][ev.jaxis.axis] = ev.jaxis.value;
	}
	
	
	if (ev.type == SDL_JOYDEVICEREMOVED || ev.type == SDL_JOYDEVICEADDED)
	{
		this->finalizeJoys();
		this->initializeJoys();
	}
}
bool Gamepad::getJoyPressed(int joyID, Uint8 buttonID) {
	if (joyID >= 0 && joyID < SDL_NumJoysticks())
	{
		return m_joyButtonsPressed[joyID][buttonID];
	}
	return false;
}
bool Gamepad::getJoyReleased(int joyID, Uint8 buttonID) {
	if (joyID >= 0 && joyID < SDL_NumJoysticks())
	{
		return m_joyButtonsReleased[joyID][buttonID];
	}
	return false;
}
bool Gamepad::getJoyHold(int joyID, Uint8 buttonID) {
	if (joyID >= 0 && joyID < SDL_NumJoysticks())
	{
		return m_joyButtonsHold[joyID][buttonID];
	}
	return false;
}
Sint16 Gamepad::getAxisMove(int joyID, Uint8 axis) {
    if (joyID >= 0 && joyID < SDL_NumJoysticks() &&
        axis >= 0)//não previne de por um valor axis muito mais alto.
    {
        return m_joyAxis[joyID][axis];
    }
	return 0;
}
void Gamepad::initializeJoys() {
	int numJoys = SDL_NumJoysticks();//tempo real o num de joys plugados.
	
	if (numJoys > 0)
	{
        //Expande a primeira dimensão da matrix de botão baseado no número de joys.
        //[aqui][] -> tendo 1 joy -> [0][..n] -> '..n' será alocado depois.
		m_joyButtonsPressed.resize(numJoys);
		m_joyButtonsReleased.resize(numJoys);
		m_joyButtonsHold.resize(numJoys);
		
		m_joyAxis.resize(numJoys);
	}
	
	for (int i = 0; i < numJoys; i++)
	{
		SDL_Joystick *joy = SDL_JoystickOpen(i);
		
		m_joysticks.push_back(joy);
		
		int numButtons = SDL_JoystickNumButtons( joy );
		int numAxes = SDL_JoystickNumAxes( joy );
		
		m_joyButtonsPressed[i].resize(numButtons);
		m_joyButtonsReleased[i].resize(numButtons);
		m_joyButtonsHold[i].resize(numButtons);
		
		m_joyAxis[i].resize(numAxes);
		for (unsigned int j = 0; j < m_joyAxis[i].size(); j++)
		{
			m_joyAxis[i][j] = 0;
		}
	}
}
void Gamepad::finalizeJoys() {
	for (unsigned int i = 0; i < m_joysticks.size(); i++)
	{
		SDL_JoystickClose(m_joysticks[i]);
	}
}
