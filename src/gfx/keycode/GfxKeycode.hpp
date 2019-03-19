/*
  Giotto
  Copyright (C) 2019 George Oros

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
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

#ifndef GfxKeycode_hpp
#define GfxKeycode_hpp

#include <cstdint>
#include <string>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxScancode.hpp"

namespace gfx
{

namespace keycode
{

class GfxKeycode final : public GfxObject
{
public:
    typedef int32_t SdlType;

    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = false;

    enum class ValueType : int32_t
    {
        kUnknown = SDLK_UNKNOWN,
        kReturn = SDLK_RETURN,
        kEscape = SDLK_ESCAPE,
        kBackSpace = SDLK_BACKSPACE,
        kTab = SDLK_TAB,
        kSpace = SDLK_SPACE,
        kExclaim = SDLK_EXCLAIM,
        kQuoteDbl = SDLK_QUOTEDBL,
        kHash = SDLK_HASH,
        kPercent = SDLK_PERCENT,
        kDollar = SDLK_DOLLAR,
        kAmpersand = SDLK_AMPERSAND ,
        kQuote = SDLK_QUOTE,
        kLeftParen = SDLK_LEFTPAREN,
        kRightParen = SDLK_RIGHTPAREN,
        kAsterisk = SDLK_ASTERISK,
        kPlus = SDLK_PLUS,
        kComma = SDLK_COMMA,
        kMinus = SDLK_MINUS,
        kPeriod = SDLK_PERIOD,
        kSlash = SDLK_SLASH,
        kKey0 = SDLK_0,
        kKey1 = SDLK_1,
        kKey2 = SDLK_2,
        kKey3 = SDLK_3,
        kKey4 = SDLK_4,
        kKey5 = SDLK_5,
        kKey6 = SDLK_6,
        kKey7 = SDLK_7,
        kKey8 = SDLK_8,
        kKey9 = SDLK_9,
        kColon = SDLK_COLON,
        kSemiColon = SDLK_SEMICOLON,
        kLess = SDLK_LESS,
        kEquals = SDLK_EQUALS,
        kGreater = SDLK_GREATER,
        kQuestion = SDLK_QUESTION,
        kAt = SDLK_AT,
        kLeftbracket = SDLK_LEFTBRACKET,
        kBackslash = SDLK_BACKSLASH,
        kRightBracket = SDLK_RIGHTBRACKET,
        kCaret = SDLK_CARET,
        kUnderscore = SDLK_UNDERSCORE,
        kBackQuote = SDLK_BACKQUOTE,
        kKeyA = SDLK_a,
        kKeyB = SDLK_b,
        kKeyC = SDLK_c,
        kKeyD = SDLK_d,
        kKeyE = SDLK_e,
        kKeyF = SDLK_f,
        kKeyG = SDLK_g,
        kKeyH = SDLK_h,
        kKeyI = SDLK_i,
        kKeyJ = SDLK_j,
        kKeyK = SDLK_k,
        kKeyL = SDLK_l,
        kKeyM = SDLK_m,
        kKeyN = SDLK_n,
        kKeyO = SDLK_o,
        kKeyP = SDLK_p,
        kKeyQ = SDLK_q,
        kKeyR = SDLK_r,
        kKeyS = SDLK_s,
        kKeyT = SDLK_t,
        kKeyU = SDLK_u,
        kKeyV = SDLK_v,
        kKeyW = SDLK_w,
        kKeyX = SDLK_x,
        kKeyY = SDLK_y,
        kKeyZ = SDLK_z,
        kCapsLock = SDLK_CAPSLOCK,
        kKeyF1 = SDLK_F1,
        kKeyF2 = SDLK_F2,
        kKeyF3 = SDLK_F3,
        kKeyF4 = SDLK_F4,
        kKeyF5 = SDLK_F5,
        kKeyF6 = SDLK_F6,
        kKeyF7 = SDLK_F7,
        kKeyF8 = SDLK_F8,
        kKeyF9 = SDLK_F9,
        kKeyF10 = SDLK_F10,
        kKeyF11 = SDLK_F11,
        kKeyF12 = SDLK_F12,
        kPrintScreen = SDLK_PRINTSCREEN,
        kScrollLock = SDLK_SCROLLLOCK,
        kPause = SDLK_PAUSE,
        kInsert = SDLK_INSERT,
        kHome = SDLK_HOME,
        kPageUp = SDLK_PAGEUP,
        kDelete = SDLK_DELETE,
        kEnd = SDLK_END,
        kPageDown = SDLK_PAGEDOWN,
        kRightArrow = SDLK_RIGHT,
        kLeftArrow = SDLK_LEFT,
        kDownArrow = SDLK_DOWN,
        kUpArrow = SDLK_UP,
        kNumLockClear = SDLK_NUMLOCKCLEAR,
        kKeyPadDivide = SDLK_KP_DIVIDE,
        kKeyPadMultiply = SDLK_KP_MULTIPLY,
        kKeyPadMinus = SDLK_KP_MINUS,
        kKeyPadPlus = SDLK_KP_PLUS,
        kKeyPadEnter = SDLK_KP_ENTER,
        kKeyPad1 = SDLK_KP_1,
        kKeyPad2 = SDLK_KP_2,
        kKeyPad3 = SDLK_KP_3,
        kKeyPad4 = SDLK_KP_4,
        kKeyPad5 = SDLK_KP_5,
        kKeyPad6 = SDLK_KP_6,
        kKeyPad7 = SDLK_KP_7,
        kKeyPad8 = SDLK_KP_8,
        kKeyPad9 = SDLK_KP_9,
        kKeyPad0 = SDLK_KP_0,
        kKeyPadPeriod = SDLK_KP_PERIOD,
        kKeyPadApplication = SDLK_APPLICATION,
        kPower = SDLK_POWER,
        kKeyPadEquals = SDLK_KP_EQUALS,
        kKeyF13 = SDLK_F13,
        kKeyF14 = SDLK_F14,
        kKeyF15 = SDLK_F15,
        kKeyF16 = SDLK_F16,
        kKeyF17 = SDLK_F17,
        kKeyF18 = SDLK_F18,
        kKeyF19 = SDLK_F19,
        kKeyF20 = SDLK_F20,
        kKeyF21 = SDLK_F21,
        kKeyF22 = SDLK_F22,
        kKeyF23 = SDLK_F23,
        kKeyF24 = SDLK_F24,
        kExecute = SDLK_EXECUTE,
        kHelp = SDLK_HELP,
        kMenu = SDLK_MENU,
        kSelect = SDLK_SELECT,
        kStop = SDLK_STOP,
        kAgain = SDLK_AGAIN,
        kUndo = SDLK_UNDO,
        kCut = SDLK_CUT,
        kCopy = SDLK_COPY,
        kPaste = SDLK_PASTE,
        kFind = SDLK_FIND,
        kMute = SDLK_MUTE,
        kVolumeUp = SDLK_VOLUMEUP,
        kVolumeDown = SDLK_VOLUMEDOWN,
        kKeyPadComma = SDLK_KP_COMMA,
        kKeyPadEqualAs400 = SDLK_KP_EQUALSAS400,
        kAltErase = SDLK_ALTERASE,
        kSysReq = SDLK_SYSREQ,
        kCancel = SDLK_CANCEL,
        kClear = SDLK_CLEAR,
        kPrior = SDLK_PRIOR,
        kReturn2 = SDLK_RETURN2,
        kSeparator = SDLK_SEPARATOR,
        kOut = SDLK_OUT,
        kOper = SDLK_OPER,
        kClearAgain = SDLK_CLEARAGAIN,
        kCRSel = SDLK_CRSEL,
        kEXSel = SDLK_EXSEL,
        kKeyPad00 = SDLK_KP_00,
        kKeyPad000 = SDLK_KP_000,
        kThousansSeparator = SDLK_THOUSANDSSEPARATOR,
        kDecimalSeparator = SDLK_DECIMALSEPARATOR,
        kCurrencyUnit = SDLK_CURRENCYUNIT,
        kCurrecnySubunit = SDLK_CURRENCYSUBUNIT,
        kKeyPadLeftParen = SDLK_KP_LEFTPAREN,
        kKeyPadRightParen = SDLK_KP_RIGHTPAREN,
        kKeyPadLeftBrace = SDLK_KP_LEFTBRACE,
        kKeyPadRightBrace = SDLK_KP_RIGHTBRACE,
        kKeyPadTab = SDLK_KP_TAB,
        kKeyPadBackSpace = SDLK_KP_BACKSPACE,
        kKeyPadA = SDLK_KP_A,
        kKeyPadB = SDLK_KP_B,
        kKeyPadC = SDLK_KP_C,
        kKeyPadD = SDLK_KP_D,
        kKeyPadE = SDLK_KP_E,
        kKeyPadF = SDLK_KP_F,
        kKeyPadXor = SDLK_KP_XOR,
        kKeyPadPower = SDLK_KP_POWER,
        kKeyPadPercent = SDLK_KP_PERCENT,
        kKeyPadLess = SDLK_KP_LESS,
        kKeyPadGreater = SDLK_KP_GREATER,
        kKeyPadAmpersand = SDLK_KP_AMPERSAND,
        kKeyPadDblAmpersand = SDLK_KP_DBLAMPERSAND,
        kKeyPadVerticalBar = SDLK_KP_VERTICALBAR,
        kKeypadDblverticalBar = SDLK_KP_DBLVERTICALBAR,
        kKeyPadColon = SDLK_KP_COLON,
        kKeyPadHash = SDLK_KP_HASH,
        kKeyPadSpace = SDLK_KP_SPACE,
        kKeyPadAt = SDLK_KP_AT,
        kKeyPadExclam = SDLK_KP_EXCLAM,
        kKeyPadMemStore = SDLK_KP_MEMSTORE,
        kKeypadMemRecall = SDLK_KP_MEMRECALL,
        kKeyPadMemClear = SDLK_KP_MEMCLEAR,
        kKeyPadMemAdd = SDLK_KP_MEMADD,
        kKeyPadMemSubstract = SDLK_KP_MEMSUBTRACT,
        kKeyPadMemMultiply = SDLK_KP_MEMMULTIPLY,
        kKeyPadMemDivide = SDLK_KP_MEMDIVIDE,
        kKeyPadPlusMinus = SDLK_KP_PLUSMINUS,
        kKeyPadClear = SDLK_KP_CLEAR,
        kKeyPadClearEntry = SDLK_KP_CLEARENTRY,
        kKeyPadBinary = SDLK_KP_BINARY,
        kKeyPadOctal = SDLK_KP_OCTAL,
        kKeyPadDecimal = SDLK_KP_DECIMAL,
        kKeyPadHexaDeciaml = SDLK_KP_HEXADECIMAL,
        kLCtrl = SDLK_LCTRL,
        kLShift = SDLK_LSHIFT,
        kLAlt = SDLK_LALT,
        kLGui = SDLK_LGUI,
        kRCtrl = SDLK_RCTRL,
        kRShift = SDLK_RSHIFT,
        kRAlt = SDLK_RALT,
        kRGui = SDLK_RGUI,
        kMode = SDLK_MODE,
        kAudioNext = SDLK_AUDIONEXT,
        kAudioPrev = SDLK_AUDIOPREV,
        kAudioStop = SDLK_AUDIOSTOP,
        kAudioPlay = SDLK_AUDIOPLAY,
        kAudioMute = SDLK_AUDIOMUTE,
        kMediaSelect = SDLK_MEDIASELECT,
        kWWW = SDLK_WWW,
        kMail = SDLK_MAIL,
        kCalculator = SDLK_CALCULATOR,
        kComputer = SDLK_COMPUTER,
        kACSearch = SDLK_AC_SEARCH,
        kACHome = SDLK_AC_HOME,
        kACBack = SDLK_AC_BACK,
        kACForward = SDLK_AC_FORWARD,
        kACStop = SDLK_AC_STOP,
        kACRefresh = SDLK_AC_REFRESH,
        kACBookmarks = SDLK_AC_BOOKMARKS,
        kBrightnessDown = SDLK_BRIGHTNESSDOWN,
        kBrightnessUp = SDLK_BRIGHTNESSUP,
        kDisplaySwitch = SDLK_DISPLAYSWITCH,
        kKbdIllumToggle = SDLK_KBDILLUMTOGGLE,
        kKbdIllumDown = SDLK_KBDILLUMDOWN,
        kKbdIllumUp = SDLK_KBDILLUMUP,
        kEject = SDLK_EJECT,
        kSleep = SDLK_SLEEP,
        kApp1 = SDLK_APP1,
        kApp2 = SDLK_APP2,
        kAudioRewind = SDLK_AUDIOREWIND,
        kAudioFastForward = SDLK_AUDIOFASTFORWARD
    };

    const int32_t kScandCodeMask = SDLK_SCANCODE_MASK;

    GfxKeycode() noexcept;

    explicit GfxKeycode(const int32_t code) noexcept;
    explicit GfxKeycode(const ValueType code) noexcept;

    GfxKeycode(const GfxKeycode& other) noexcept;
    GfxKeycode(GfxKeycode&& other) noexcept;

    GfxKeycode& operator=(const GfxKeycode& other) noexcept;
    GfxKeycode& operator=(GfxKeycode&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;
    ValueType scancodeToKeycode(const scancode::GfxScancode& scancode) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType code_;
};

}  // namespace keycode

}  // namespace gfx

#endif /* GfxKeycode_hpp */
