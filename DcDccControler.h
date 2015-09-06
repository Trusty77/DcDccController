//-------------------------------------------------------------------
#ifndef __dcDccControler_H__
#define __dcDccControler_H__
//-------------------------------------------------------------------

////////////////////////////////////////////////////////
// Add a '//' at the beginning of the line to be in 
// release mode.
//#define DEBUG_MODE

///////////////////////////////////////////////////////
// Verbose mode lets you see all actions done by the 
// library, but with a real flood of text to console...
// Has no effect if DEBUG_MODE is not activated.
//#define DEBUG_VERBOSE_MODE

#ifdef __AVR_ATmega328P__
#define NANOCONTROLER
#endif

#define GPIO2_PREFER_SPEED    1

#ifdef VISUALSTUDIO
#define NANOCONTROLER		// for test only
#include "arduino.h"
#include "Serial.hpp"
#include "VStudioLcdUi\arduino2.hpp"
#else
#include "arduino2.hpp"
#endif

#ifndef __LcdUi_H__
#include "../LcdUi/LcdUi.h"
#endif

#ifndef NANOCONTROLER
#ifndef __EEPROMextent_h__
#include "../EEPROMextent/EEPROMextent.h"
#endif
#endif

#ifdef DEBUG_MODE
static void CheckPinNb(GPIO_pin_t inPin, const __FlashStringHelper *inFunc);
static void CheckPinNb(int inPin, const __FlashStringHelper *inFunc);

#define CHECKPIN(val, text)		CheckPinNb(cval, text)
#else
#define CHECKPIN(val, text)
#endif

//extern const char str_special_rst[] PROGMEM;
extern const char * const DDC_config_table[] PROGMEM;
extern const char * const string_table[] PROGMEM;

#if defined(__DDCLanguage_H__)

// Unlocalized special strings
const char str_special_rst[] PROGMEM = "$rst";
#ifdef SHORTLENGTH_MSG
const char str_title[] PROGMEM = "Dc/Dcc Cont V0.5";
const char str_copyright[] PROGMEM = "By Thierry Paris";
#else
const char str_title[] PROGMEM = "Dc/Dcc Controler V0.5";
const char str_copyright[] PROGMEM = "By Thierry Paris";
#endif

const char * const string_table[] PROGMEM
{
	str_title,
	str_copyright,
	str_dc,
	str_dcc,
	str_stop,
	str_stop2,
	str_dcdcc,
	str_dcdcc2,
	str_modemodechoice,
	str_modelococtrl,
	str_modelocoedit,
	str_modeconfig,
	str_locoselect,
	str_resetconfig,
	str_yes,
	str_no,
	str_confirm,
	str_pwmfreqency,
	str_loconew,
	str_locodel,
	str_locoedit,
	str_locochange,
	str_longaddress,
	str_locoId,
	str_locoName,
	str_locoSteps,
	str_locoSteps14,
	str_locoSteps28,
	str_locoSteps128,
	str_handleCfgDigits,
	str_functionId,
	str_saveLoco,
	str_dcslow,
	str_special_rst
};

// List of available main config options

const char * const DDC_config_table[] PROGMEM =
{
	str_special_rst	// option to fully reset the configuration.
};
#endif

#define STR_TITLE		0
#define STR_COPYRIGHT	1
#define STR_DC			2
#define STR_DCC			3
#define STR_STOP		4
#define STR_STOP2		5
#define STR_DCDCC		6
#define STR_DCDCC2		7
#define STR_MODEMODECHOICE	8
#define STR_MODELOCOCTRL	9
#define STR_MODELOCOEDIT	10
#define STR_MODECONFIG		11
#define STR_LOCOSELECT		12
#define STR_RESETCONFIG		13
#define STR_YES				14
#define STR_NO				15
#define STR_CONFIRM			16
#define STR_PWMFREQCFG		17
#define STR_LOCONEW			18
#define STR_LOCOREMOVE		19
#define STR_LOCOEDIT		20
#define STR_MODELOCOCHANGE	21
#define STR_LONGADDRESS		22
#define STR_LOCOID			23
#define STR_LOCONAME		24
#define STR_LOCOSTEPS		25
#define STR_LOCOSTEPS14		26
#define STR_LOCOSTEPS28		27
#define STR_LOCOSTEPS128	28
#define STR_HANDLECFGDIGITS	29
#define STR_FUNCTIONID		30
#define STR_SAVELOCO		31
#define STR_DCSLOW			32

//////////////////////////////////////////
//  Exclusion area
//
// You can exclude some parts of library here, to avoid losing program and data memory
// on parts you don t use.
// For example, if you don t want buttons commander
// just uncomment the line #define NO_BUTTONSCOMMANDER by removing // at the beginning.
//
// Arduino IDE build of list of the files to compile from the content of the library directory
// in a makefile and give it to Gcc. So Gcc compiles all the files of the directory
// even if its content is not used. The result is, if an unused source file contains
// static declarations, these statics will be allocated a this memory will be lost.
// The only solution I have found is to rename the source files to something IDE and Gcc don t know...
//
// So if you want to lose less memory, you can rename the linked files
// from .cpp to .cpp.ori, and from .hpp to .hpp.ori.
// See below the file names related to each exclusion:
//
//NO_BUTTONSCOMMANDER
//	ButtonsCommander.cpp
//	ButtonsCommander.hpp
//	ButtonsCommanderAnalogPushes.cpp
//	ButtonsCommanderAnalogPushes.hpp
//	ButtonsCommanderAnalogPushesItem.cpp
//	ButtonsCommanderAnalogPushesItem.hpp
//	ButtonsCommanderButtons.cpp
//	ButtonsCommanderButtons.hpp
//	ButtonsCommanderEncoder.cpp
//	ButtonsCommanderEncoder.hpp
//	ButtonsCommanderPush.cpp
//	ButtonsCommanderPush.hpp
//	ButtonsCommanderSwitch.cpp
//	ButtonsCommanderSwitch.hpp
//	ButtonsCommanderPotentiometer.cpp
//	ButtonsCommanderPotentiometer.hpp
//
//NO_BUTTONSCOMMANDERPUSH
//	ButtonsCommanderPush.cpp
//	ButtonsCommanderPush.hpp
//
//NO_BUTTONSCOMMANDERENCODER
//	ButtonsCommanderEncoder.cpp
//	ButtonsCommanderEncoder.hpp
//
//NO_BUTTONSCOMMANDERANALOGPUSH
//	ButtonsCommanderAnalogPushes.cpp
//	ButtonsCommanderAnalogPushes.hpp
//	ButtonsCommanderAnalogPushesItem.cpp
//	ButtonsCommanderAnalogPushesItem.hpp
//
//NO_BUTTONSCOMMANDERSWITCH
//	ButtonsCommanderSwitch.cpp
//	ButtonsCommanderSwitch.hpp
//
//NO_BUTTONSCOMMANDERPOTENTIOMETER
//	ButtonsCommanderPotentiometer.cpp
//	ButtonsCommanderPotentiometer.hpp

//#define NO_LOCOMOTIVE
//#define NO_SCREEN

//#define NO_COMMANDER
//#define NO_BUTTONSCOMMANDER
//#define NO_BUTTONSCOMMANDERENCODER
//#define NO_BUTTONSCOMMANDERPUSH
#define NO_BUTTONSCOMMANDERANALOGPUSH
//#define NO_BUTTONSCOMMANDERSWITCH
#define NO_BUTTONSCOMMANDERPOTENTIOMETER

#ifdef NO_COMMANDER
#ifndef NO_BUTTONSCOMMANDER
#define NO_BUTTONSCOMMANDER
#ifndef NO_BUTTONSCOMMANDERENCODER
#define NO_BUTTONSCOMMANDERENCODER
#endif
#ifndef NO_BUTTONSCOMMANDERPUSH
#define NO_BUTTONSCOMMANDERPUSH
#endif
#ifndef NO_BUTTONSCOMMANDERANALOGPUSH
#define NO_BUTTONSCOMMANDERANALOGPUSH
#endif
#ifndef NO_BUTTONSCOMMANDERSWITCH
#define NO_BUTTONSCOMMANDERSWITCH
#endif
#ifndef NO_BUTTONSCOMMANDERPOTENTIOMETER
#define NO_BUTTONSCOMMANDERPOTENTIOMETER
#endif
#endif
#endif

/////////////////////////////////////

enum DcDcc
{
	DcChangeStopped,
	PanicStopped,
	Dc,
	Dcc
};

#include "Handle.hpp"
#ifndef NO_COMMANDER
#include "Commander.hpp"
#endif

#ifndef NO_COMMANDER
#ifndef NO_BUTTONSCOMMANDER
#ifndef NO_BUTTONSCOMMANDERENCODER
#include "ButtonsCommanderEncoder.hpp"
#endif
#ifndef NO_BUTTONSCOMMANDERPUSH
#include "ButtonsCommanderPush.hpp"
#endif
#ifndef NO_BUTTONSCOMMANDERANALOGPUSH
#include "ButtonsCommanderAnalogPushes.hpp"
#endif
#ifndef NO_BUTTONSCOMMANDERSWITCH
#include "ButtonsCommanderSwitch.hpp"
#endif
#ifndef NO_BUTTONSCOMMANDERPOTENTIOMETER
#include "ButtonsCommanderPotentiometer.hpp"
#endif
#endif

#ifndef NO_BUTTONSCOMMANDER
#include "ButtonsCommander.hpp"
#endif
#endif

#include "ControlerDc.hpp"
#include "ControlerDcc.hpp"
#include "DCCItemList.hpp"

// Copy from cmdrarduino ...
#define DCC_SHORT_ADDRESS           0x00
#define DCC_LONG_ADDRESS            0x01

// LcdUi defines
#define EVENT_DCDCC		100
#define EVENT_EMERGENCY	101

#define WINDOWTYPE_INTERRUPT_DCDCC		10
#define WINDOWTYPE_INTERRUPT_EMERGENCY	11
#define EEPROM_DDC_CONFIG_SIZE			64

class DcDccControler
{
protected:
	uint8_t dcPWMpin;	// To be able to change Dc frequency, the pin used must be 9 or 10 !
	uint8_t dcDirPin;

public:
	DcDcc dcType;
	DcDcc dcTypeAtStart;
	Handle **pHandleList;
	int handleAddcounter;
	Controler *pControler;

#ifdef VISUALSTUDIO
	static char LastKeyPressed;
#endif

private:
	ButtonsCommanderButton *pDcDccButton;	// If null, always Dcc...
	ButtonsCommanderButton *pPanicButton;	// If null, no emergency !

public:
	static DcDccControler DDc;

public:
	DcDccControler();

	void StartSetup(uint8_t inDcPWMpin = 0, uint8_t inDcDirPin = 0);
	void EndSetup();
	void AddHandle(Handle *pHandle);
	byte IndexOf(Handle *inpHandle) const;
	inline void SetDcDccButton(ButtonsCommanderButton *inpDcDccButton) { this->pDcDccButton = inpDcDccButton; }
	inline void SetPanicButton(ButtonsCommanderButton *inpPanicButton) { this->pPanicButton = inpPanicButton; }

	void Loop();

	void ConfigLoad();
	int ConfigSave();
	void ConfigReset();

#ifdef DEBUG_MODE
	void CheckIndex(unsigned char inIndex, const __FlashStringHelper *inFunc);
#endif
};

#define DDC DcDccControler::DDc
#endif