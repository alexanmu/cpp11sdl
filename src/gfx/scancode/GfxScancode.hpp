/*
  Giotto
  Copyright (C) 2017 George Oros

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose),
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  See copyright notice at http://lidsdl.org/license.php
*/

#ifndef GfxScancode_hpp
#define GfxScancode_hpp

#include <cstdint>
#include <string>
#include <type_traits>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"

namespace gfx
{

namespace scancode
{

class GfxScancode final : public GfxObject
{
public:
    typedef SDL_Scancode SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        kScanCodeUnknown = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_UNKNOWN),
        kScanCodeA = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_A),
        kScanCodeB = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_B),
        kScanCodeC = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_C),
        kScanCodeD = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_D),
        kScanCodeE = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_E),
        kScanCodeF = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F),
        kScanCodeG = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_G),
        kScanCodeH = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_H),
        kScanCodeI = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_I),
        kScanCodeJ = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_J),
        kScanCodeK = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_K),
        kScanCodeL = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_L),
        kScanCodeM = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_M),
        kScanCodeN = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_N),
        kScanCodeO = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_O),
        kScanCodeP = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_P),
        kScanCodeQ = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_Q),
        kScanCodeR = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_R),
        kScanCodeS = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_S),
        kScanCodeT = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_T),
        kScanCodeU = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_U),
        kScanCodeV = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_V),
        kScanCodeW = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_W),
        kScanCodeX = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_X),
        kScanCodeY = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_Y),
        kScanCodeZ = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_Z),
        kScanCode1 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_1),
        kScanCode2 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_2),
        kScanCode3 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_3),
        kScanCode4 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_4),
        kScanCode5 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_5),
        kScanCode6 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_6),
        kScanCode7 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_7),
        kScanCode8 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_8),
        kScanCode9 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_9),
        kScanCode0 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_0),
        kScanCodeReturn = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_RETURN),
        kScanCodeEscape = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_ESCAPE),
        kScanCodeBackSpace = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_BACKSPACE),
        kScanCodeTab = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_TAB),
        kScanCodeSpace = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_SPACE),
        kScanCodeMinus = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_MINUS),
        kScanCodeEquals = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_EQUALS),
        kScanCodeLeftBracket = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LEFTBRACKET),
        kScanCodeRightBracket = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_RIGHTBRACKET),
        kScanCodeBackSlash = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_BACKSLASH),
        kScanCodeNonUSHash = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_NONUSHASH),
        kScanCodeSemiColon = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_SEMICOLON),
        kScanCodeApostophe = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_APOSTROPHE),
        kScanCodeGrave = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_GRAVE),
        kScanCodeComma = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_COMMA),
        kScanCodePeriod = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_PERIOD),
        kScanCodeSlash = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_SLASH),
        kScanCodeCapsLock = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CAPSLOCK),
        kScanCodeF1 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F1),
        kScanCodeF2 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F2),
        kScanCodeF3 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F3),
        kScanCodeF4 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F4),
        kScanCodeF5 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F5),
        kScanCodeF6 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F6),
        kScanCodeF7 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F7),
        kScanCodeF8 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F8),
        kScanCodeF9 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F9),
        kScanCodeF10 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F10),
        kScanCodeF11 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F11),
        kScanCodeF12 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F12),
        kScanCodePrintScreen = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_PRINTSCREEN),
        kScanCodeScrollLock = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_SCROLLLOCK),
        kScanCodePause = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_PAUSE),
        kScanCodeInsert = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INSERT),
        kScanCodeHome = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_HOME),
        kScanCodePageUp = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_PAGEUP),
        kScanCodeDelete = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_DELETE),
        kScanCodeEnd = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_END),
        kScanCodePageDown = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_PAGEDOWN),
        kScanCodeRight = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_RIGHT),
        kScanCodeLeft = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LEFT),
        kScanCodeDown = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_DOWN),
        kScanCodeUp = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_UP),
        kScanCodeNumLockClear = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_NUMLOCKCLEAR),
        kScanCodeKPDivide = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_DIVIDE),
        kScanCodeKPMultiply = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MULTIPLY),
        kScanCodeKPMinus = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MINUS),
        kScanCodeKPPlus = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_PLUS),
        kScanCodeKPEnter = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_ENTER),
        kScanCodeKP1 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_1),
        kScanCodeKP2 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_2),
        kScanCodeKP3 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_3),
        kScanCodeKP4 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_4),
        kScanCodeKP5 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_5),
        kScanCodeKP6 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_6),
        kScanCodeKP7 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_7),
        kScanCodeKP8 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_8),
        kScanCodeKP9 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_9),
        kScanCodeKP0 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_0),
        kScanCodeKPPeriod = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_PERIOD),
        kScanCodeNonUSBackslash = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_NONUSBACKSLASH),
        kScanCodeApplication = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_APPLICATION),
        kScanCodePower = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_POWER),
        kScanCodeKPEquals = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_EQUALS),
        kScanCodeF13 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F13),
        kScanCodeF14 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F14),
        kScanCodeF15 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F15),
        kScanCodeF16 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F16),
        kScanCodeF17 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F17),
        kScanCodeF18 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F18),
        kScanCodeF19 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F19),
        kScanCodeF20 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F20),
        kScanCodeF21 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F21),
        kScanCodeF22 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F22),
        kScanCodeF23 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F23),
        kScanCodeF24 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_F24),
        kScanCodeExecute = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_EXECUTE),
        kScanCodeHelp = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_HELP),
        kScanCodeMenu = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_MENU),
        kScanCodeSelect = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_SELECT),
        kScanCodeStop = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_STOP),
        kScanCodeAgain = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AGAIN),
        kScanCodeUndo = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_UNDO),
        kScanCodeCut = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CUT),
        kScanCodeCopy = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_COPY),
        kScanCodePaste = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_PASTE),
        kScanCodeFind = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_FIND),
        kScanCodeMute = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_MUTE),
        kScanCodeVolumeUp = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_VOLUMEUP),
        kScanCodeVolumeDown = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_VOLUMEDOWN),
        kScanCodeKPComma = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_COMMA),
        kScanCodeKPEqualsAs400 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_EQUALSAS400),
        kScanCodeInternationl1 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL1),
        kScanCodeInternationl2 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL2),
        kScanCodeInternationl3 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL3),
        kScanCodeInternationl4 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL4),
        kScanCodeInternationl5 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL5),
        kScanCodeInternationl6 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL6),
        kScanCodeInternationl7 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL7),
        kScanCodeInternationl8 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL8),
        kScanCodeInternationl9 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_INTERNATIONAL9),
        kScanCodeLang1 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG1),
        kScanCodeLang2 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG2),
        kScanCodeLang3 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG3),
        kScanCodeLang4 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG4),
        kScanCodeLang5 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG5),
        kScanCodeLang6 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG6),
        kScanCodeLang7 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG7),
        kScanCodeLang8 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG8),
        kScanCodeLang9 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LANG9),
        kScanCodeAltErase = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_ALTERASE),
        kScanCodeSysReq = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_SYSREQ),
        kScanCodeCancel = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CANCEL),
        kScanCodeClear = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CLEAR),
        kScanCodePrior = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_PRIOR),
        kScanCodeReturn2 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_RETURN2),
        kScanCodeSeparator = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_SEPARATOR),
        kScanCodeOut = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_OUT),
        kScanCodeOper = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_OPER),
        kScanCodeClearAgain = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CLEARAGAIN),
        kScanCodeCRSel = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CRSEL),
        kScanCodeEXSel = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_EXSEL),
        kScanCodeKP00 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_00),
        kScanCodeKP000 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_000),
        kScanCodeThousandsSeparator = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_THOUSANDSSEPARATOR),  // NOLINT
        kScanCodeDeciamalSeparator = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_DECIMALSEPARATOR),  // NOLINT
        kScanCodeCurrencyUnit = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CURRENCYUNIT),
        kScanCodeCurrencySubunit = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CURRENCYSUBUNIT),  // NOLINT
        kScanCodeKPLeftparen = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_LEFTPAREN),
        kScanCodeKPRightParen = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_RIGHTPAREN),
        kScanCodeKPLeftBrace = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_LEFTBRACE),
        kScanCodeKPRightBrace = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_RIGHTBRACE),
        kScanCodeKPTab = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_TAB),
        kScanCodeKPBackspace = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_BACKSPACE),
        kScanCodeKPA = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_A),
        kScanCodeKPB = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_B),
        kScanCodeKPC = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_C),
        kScanCodeKPD = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_D),
        kScanCodeKPE = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_E),
        kScanCodeKPF = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_F),
        kScanCodeKPXor = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_XOR),
        kScanCodeKPPower = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_POWER),
        kScanCodeKPPercent = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_PERCENT),
        kScanCodeKPLess = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_LESS),
        kScanCodeKPGreater = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_GREATER),
        kScanCodeKPAmpersand = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_AMPERSAND),
        kScanCodeKPDblAmpersand = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_DBLAMPERSAND),  // NOLINT
        kScanCodeKPVeritcalBar = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_VERTICALBAR),
        kScanCodeKPDblVerticalBar = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_DBLVERTICALBAR),  // NOLINT
        kScanCodeKPColon = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_COLON),
        kScanCodeKPHash = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_HASH),
        kScanCodeKPSpace = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_SPACE),
        kScanCodeKPAt = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_AT),
        kScanCodeKPExclam = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_EXCLAM),
        kScanCodeKPMemStore = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MEMSTORE),
        kScanCodeKPMemRecall = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MEMRECALL),
        kScanCodeKPMemClear = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MEMCLEAR),
        kScanCodeKPMemAdd = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MEMADD),
        kScanCodeKPMemSubsrtact = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MEMSUBTRACT),
        kScanCodeKPMemMultiply = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MEMMULTIPLY),
        kScanCodeKPMemDivide = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_MEMDIVIDE),
        kScanCodeKPPlusMinus = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_PLUSMINUS),
        kScanCodeKPClear = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_CLEAR),
        kScanCodeCKPlearEntry = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_CLEARENTRY),
        kScanCodeKPBinary = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_BINARY),
        kScanCodeKPOctal = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_OCTAL),
        kScanCodeKPDecimal = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_DECIMAL),
        kScanCodeKPHexaDeciaml = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KP_HEXADECIMAL),
        kScanCodeLCtrl = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LCTRL),
        kScanCodeLShift = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LSHIFT),
        kScanCodeLAlt = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LALT),
        kScanCodeLGui = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_LGUI),
        kScanCodeRCtrl = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_RCTRL),
        kScanCodeRShift = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_RSHIFT),
        kScanCodeRAlt = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_RALT),
        kScanCodeRGui = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_RGUI),
        kScanCodeMode = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_MODE),
        kScanCodeAudioNext = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AUDIONEXT),
        kScanCodeAudioPrev = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AUDIOPREV),
        kScanCodeAudioStop = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AUDIOSTOP),
        kScanCodeAudioPlay = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AUDIOPLAY),
        kScanCodeAudioMute = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AUDIOMUTE),
        kScanCodeMediaSelect = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_MEDIASELECT),
        kScanCodeWWW = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_WWW),
        kScanCodeMail = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_MAIL),
        kScanCodeCalculator = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_CALCULATOR),
        kScanCodeComputer = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_COMPUTER),
        kScanCodeACSearch = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AC_SEARCH),
        kScanCodeACHome = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AC_HOME),
        kScanCodeACBack = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AC_BACK),
        kScanCodeACForward = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AC_FORWARD),
        kScanCodeACStop = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AC_STOP),
        kScanCodeACRefresh = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AC_REFRESH),
        kScanCodeACBookmarks = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AC_BOOKMARKS),
        kScanCodeBrightnessDown = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_BRIGHTNESSDOWN),
        kScanCodeBrightnessUp = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_BRIGHTNESSUP),
        kScanCodeDisplaySwitch = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_DISPLAYSWITCH),
        kScanCodeKbdIllumToggle = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KBDILLUMTOGGLE),
        kScanCodeKbdIllumDown = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KBDILLUMDOWN),
        kScanCodeKbdIllumUp = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_KBDILLUMUP),
        kScanCodeEject = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_EJECT),
        kScanCodeSleep = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_SLEEP),
        kScanCodeApp1 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_APP1),
        kScanCodeApp2 = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_APP2),
        kScanCodeAudioRewind = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AUDIOREWIND),
        kScanCodeAudioFastForward = static_cast<std::underlying_type<ValueType>::type>(SDL_SCANCODE_AUDIOFASTFORWARD),  // NOLINT
        kScanCodeNumScanCodes = static_cast<std::underlying_type<ValueType>::type>(SDL_NUM_SCANCODES)
    };

    GfxScancode() noexcept;

    explicit GfxScancode(const std::underlying_type<ValueType>::type code) noexcept;
    explicit GfxScancode(const ValueType code) noexcept;

    GfxScancode(GfxScancode const& other) noexcept;
    GfxScancode(GfxScancode&& other) noexcept;

    GfxScancode& operator=(GfxScancode const& other) noexcept;
    GfxScancode& operator=(GfxScancode&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType code_;
};

}  // namespace scancode

}  // namespace gfx

#endif /* GfxScancode_hpp */
