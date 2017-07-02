/*
  Giotto
  Copyright (C) 2017 George Oros

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
        kUnknown = sdl2::SDLK_UNKNOWN,
        kReturn = sdl2::SDLK_RETURN,
        kEscape = sdl2::SDLK_ESCAPE,
        kBackSpace = sdl2::SDLK_BACKSPACE,
        kTab = sdl2::SDLK_TAB,
        kSpace = sdl2::SDLK_SPACE,
        kExclaim = sdl2::SDLK_EXCLAIM,
        kQuoteDbl = sdl2::SDLK_QUOTEDBL,
        kHash = sdl2::SDLK_HASH,
        kPercent = sdl2::SDLK_PERCENT,
        kDollar = sdl2::SDLK_DOLLAR,
        kAmpersand = sdl2::SDLK_AMPERSAND ,
        kQuote = sdl2::SDLK_QUOTE,
        kLeftParen = sdl2::SDLK_LEFTPAREN,
        kRightParen = sdl2::SDLK_RIGHTPAREN,
        kAsterisk = sdl2::SDLK_ASTERISK,
        kPlus = sdl2::SDLK_PLUS,
        kComma = sdl2::SDLK_COMMA,
        kMinus = sdl2::SDLK_MINUS,
        kPeriod = sdl2::SDLK_PERIOD,
        kSlash = sdl2::SDLK_SLASH,
        kKey0 = sdl2::SDLK_0,
        kKey1 = sdl2::SDLK_1,
        kKey2 = sdl2::SDLK_2,
        kKey3 = sdl2::SDLK_3,
        kKey4 = sdl2::SDLK_4,
        kKey5 = sdl2::SDLK_5,
        kKey6 = sdl2::SDLK_6,
        kKey7 = sdl2::SDLK_7,
        kKey8 = sdl2::SDLK_8,
        kKey9 = sdl2::SDLK_9,
        kColon = sdl2::SDLK_COLON,
        kSemiColon = sdl2::SDLK_SEMICOLON,
        kLess = sdl2::SDLK_LESS,
        kEquals = sdl2::SDLK_EQUALS,
        kGreater = sdl2::SDLK_GREATER,
        kQuestion = sdl2::SDLK_QUESTION,
        kAt = sdl2::SDLK_AT,
        kLeftbracket = sdl2::SDLK_LEFTBRACKET,
        kBackslash = sdl2::SDLK_BACKSLASH,
        kRightBracket = sdl2::SDLK_RIGHTBRACKET,
        kCaret = sdl2::SDLK_CARET,
        kUnderscore = sdl2::SDLK_UNDERSCORE,
        kBackQuote = sdl2::SDLK_BACKQUOTE,
        kKeyA = sdl2::SDLK_a,
        kKeyB = sdl2::SDLK_b,
        kKeyC = sdl2::SDLK_c,
        kKeyD = sdl2::SDLK_d,
        kKeyE = sdl2::SDLK_e,
        kKeyF = sdl2::SDLK_f,
        kKeyG = sdl2::SDLK_g,
        kKeyH = sdl2::SDLK_h,
        kKeyI = sdl2::SDLK_i,
        kKeyJ = sdl2::SDLK_j,
        kKeyK = sdl2::SDLK_k,
        kKeyL = sdl2::SDLK_l,
        kKeyM = sdl2::SDLK_m,
        kKeyN = sdl2::SDLK_n,
        kKeyO = sdl2::SDLK_o,
        kKeyP = sdl2::SDLK_p,
        kKeyQ = sdl2::SDLK_q,
        kKeyR = sdl2::SDLK_r,
        kKeyS = sdl2::SDLK_s,
        kKeyT = sdl2::SDLK_t,
        kKeyU = sdl2::SDLK_u,
        kKeyV = sdl2::SDLK_v,
        kKeyW = sdl2::SDLK_w,
        kKeyX = sdl2::SDLK_x,
        kKeyY = sdl2::SDLK_y,
        kKeyZ = sdl2::SDLK_z,
        kCapsLock = sdl2::SDLK_CAPSLOCK,
        kKeyF1 = sdl2::SDLK_F1,
        kKeyF2 = sdl2::SDLK_F2,
        kKeyF3 = sdl2::SDLK_F3,
        kKeyF4 = sdl2::SDLK_F4,
        kKeyF5 = sdl2::SDLK_F5,
        kKeyF6 = sdl2::SDLK_F6,
        kKeyF7 = sdl2::SDLK_F7,
        kKeyF8 = sdl2::SDLK_F8,
        kKeyF9 = sdl2::SDLK_F9,
        kKeyF10 = sdl2::SDLK_F10,
        kKeyF11 = sdl2::SDLK_F11,
        kKeyF12 = sdl2::SDLK_F12,
        kPrintScreen = sdl2::SDLK_PRINTSCREEN,
        kScrollLock = sdl2::SDLK_SCROLLLOCK,
        kPause = sdl2::SDLK_PAUSE,
        kInsert = sdl2::SDLK_INSERT,
        kHome = sdl2::SDLK_HOME,
        kPageUp = sdl2::SDLK_PAGEUP,
        kDelete = sdl2::SDLK_DELETE,
        kEnd = sdl2::SDLK_END,
        kPageDown = sdl2::SDLK_PAGEDOWN,
        kRightArrow = sdl2::SDLK_RIGHT,
        kLeftArrow = sdl2::SDLK_LEFT,
        kDownArrow = sdl2::SDLK_DOWN,
        kUpArrow = sdl2::SDLK_UP,
        kNumLockClear = sdl2::SDLK_NUMLOCKCLEAR,
        kKeyPadDivide = sdl2::SDLK_KP_DIVIDE,
        kKeyPadMultiply = sdl2::SDLK_KP_MULTIPLY,
        kKeyPadMinus = sdl2::SDLK_KP_MINUS,
        kKeyPadPlus = sdl2::SDLK_KP_PLUS,
        kKeyPadEnter = sdl2::SDLK_KP_ENTER,
        kKeyPad1 = sdl2::SDLK_KP_1,
        kKeyPad2 = sdl2::SDLK_KP_2,
        kKeyPad3 = sdl2::SDLK_KP_3,
        kKeyPad4 = sdl2::SDLK_KP_4,
        kKeyPad5 = sdl2::SDLK_KP_5,
        kKeyPad6 = sdl2::SDLK_KP_6,
        kKeyPad7 = sdl2::SDLK_KP_7,
        kKeyPad8 = sdl2::SDLK_KP_8,
        kKeyPad9 = sdl2::SDLK_KP_9,
        kKeyPad0 = sdl2::SDLK_KP_0,
        kKeyPadPeriod = sdl2::SDLK_KP_PERIOD,
        kKeyPadApplication = sdl2::SDLK_APPLICATION,
        kPower = sdl2::SDLK_POWER,
        kKeyPadEquals = sdl2::SDLK_KP_EQUALS,
        kKeyF13 = sdl2::SDLK_F13,
        kKeyF14 = sdl2::SDLK_F14,
        kKeyF15 = sdl2::SDLK_F15,
        kKeyF16 = sdl2::SDLK_F16,
        kKeyF17 = sdl2::SDLK_F17,
        kKeyF18 = sdl2::SDLK_F18,
        kKeyF19 = sdl2::SDLK_F19,
        kKeyF20 = sdl2::SDLK_F20,
        kKeyF21 = sdl2::SDLK_F21,
        kKeyF22 = sdl2::SDLK_F22,
        kKeyF23 = sdl2::SDLK_F23,
        kKeyF24 = sdl2::SDLK_F24,
        kExecute = sdl2::SDLK_EXECUTE,
        kHelp = sdl2::SDLK_HELP,
        kMenu = sdl2::SDLK_MENU,
        kSelect = sdl2::SDLK_SELECT,
        kStop = sdl2::SDLK_STOP,
        kAgain = sdl2::SDLK_AGAIN,
        kUndo = sdl2::SDLK_UNDO,
        kCut = sdl2::SDLK_CUT,
        kCopy = sdl2::SDLK_COPY,
        kPaste = sdl2::SDLK_PASTE,
        kFind = sdl2::SDLK_FIND,
        kMute = sdl2::SDLK_MUTE,
        kVolumeUp = sdl2::SDLK_VOLUMEUP,
        kVolumeDown = sdl2::SDLK_VOLUMEDOWN,
        kKeyPadComma = sdl2::SDLK_KP_COMMA,
        kKeyPadEqualAs400 = sdl2::SDLK_KP_EQUALSAS400,
        kAltErase = sdl2::SDLK_ALTERASE,
        kSysReq = sdl2::SDLK_SYSREQ,
        kCancel = sdl2::SDLK_CANCEL,
        kClear = sdl2::SDLK_CLEAR,
        kPrior = sdl2::SDLK_PRIOR,
        kReturn2 = sdl2::SDLK_RETURN2,
        kSeparator = sdl2::SDLK_SEPARATOR,
        kOut = sdl2::SDLK_OUT,
        kOper = sdl2::SDLK_OPER,
        kClearAgain = sdl2::SDLK_CLEARAGAIN,
        kCRSel = sdl2::SDLK_CRSEL,
        kEXSel = sdl2::SDLK_EXSEL,
        kKeyPad00 = sdl2::SDLK_KP_00,
        kKeyPad000 = sdl2::SDLK_KP_000,
        kThousansSeparator = sdl2::SDLK_THOUSANDSSEPARATOR,
        kDecimalSeparator = sdl2::SDLK_DECIMALSEPARATOR,
        kCurrencyUnit = sdl2::SDLK_CURRENCYUNIT,
        kCurrecnySubunit = sdl2::SDLK_CURRENCYSUBUNIT,
        kKeyPadLeftParen = sdl2::SDLK_KP_LEFTPAREN,
        kKeyPadRightParen = sdl2::SDLK_KP_RIGHTPAREN,
        kKeyPadLeftBrace = sdl2::SDLK_KP_LEFTBRACE,
        kKeyPadRightBrace = sdl2::SDLK_KP_RIGHTBRACE,
        kKeyPadTab = sdl2::SDLK_KP_TAB,
        kKeyPadBackSpace = sdl2::SDLK_KP_BACKSPACE,
        kKeyPadA = sdl2::SDLK_KP_A,
        kKeyPadB = sdl2::SDLK_KP_B,
        kKeyPadC = sdl2::SDLK_KP_C,
        kKeyPadD = sdl2::SDLK_KP_D,
        kKeyPadE = sdl2::SDLK_KP_E,
        kKeyPadF = sdl2::SDLK_KP_F,
        kKeyPadXor = sdl2::SDLK_KP_XOR,
        kKeyPadPower = sdl2::SDLK_KP_POWER,
        kKeyPadPercent = sdl2::SDLK_KP_PERCENT,
        kKeyPadLess = sdl2::SDLK_KP_LESS,
        kKeyPadGreater = sdl2::SDLK_KP_GREATER,
        kKeyPadAmpersand = sdl2::SDLK_KP_AMPERSAND,
        kKeyPadDblAmpersand = sdl2::SDLK_KP_DBLAMPERSAND,
        kKeyPadVerticalBar = sdl2::SDLK_KP_VERTICALBAR,
        kKeypadDblverticalBar = sdl2::SDLK_KP_DBLVERTICALBAR,
        kKeyPadColon = sdl2::SDLK_KP_COLON,
        kKeyPadHash = sdl2::SDLK_KP_HASH,
        kKeyPadSpace = sdl2::SDLK_KP_SPACE,
        kKeyPadAt = sdl2::SDLK_KP_AT,
        kKeyPadExclam = sdl2::SDLK_KP_EXCLAM,
        kKeyPadMemStore = sdl2::SDLK_KP_MEMSTORE,
        kKeypadMemRecall = sdl2::SDLK_KP_MEMRECALL,
        kKeyPadMemClear = sdl2::SDLK_KP_MEMCLEAR,
        kKeyPadMemAdd = sdl2::SDLK_KP_MEMADD,
        kKeyPadMemSubstract = sdl2::SDLK_KP_MEMSUBTRACT,
        kKeyPadMemMultiply = sdl2::SDLK_KP_MEMMULTIPLY,
        kKeyPadMemDivide = sdl2::SDLK_KP_MEMDIVIDE,
        kKeyPadPlusMinus = sdl2::SDLK_KP_PLUSMINUS,
        kKeyPadClear = sdl2::SDLK_KP_CLEAR,
        kKeyPadClearEntry = sdl2::SDLK_KP_CLEARENTRY,
        kKeyPadBinary = sdl2::SDLK_KP_BINARY,
        kKeyPadOctal = sdl2::SDLK_KP_OCTAL,
        kKeyPadDecimal = sdl2::SDLK_KP_DECIMAL,
        kKeyPadHexaDeciaml = sdl2::SDLK_KP_HEXADECIMAL,
        kLCtrl = sdl2::SDLK_LCTRL,
        kLShift = sdl2::SDLK_LSHIFT,
        kLAlt = sdl2::SDLK_LALT,
        kLGui = sdl2::SDLK_LGUI,
        kRCtrl = sdl2::SDLK_RCTRL,
        kRShift = sdl2::SDLK_RSHIFT,
        kRAlt = sdl2::SDLK_RALT,
        kRGui = sdl2::SDLK_RGUI,
        kMode = sdl2::SDLK_MODE,
        kAudioNext = sdl2::SDLK_AUDIONEXT,
        kAudioPrev = sdl2::SDLK_AUDIOPREV,
        kAudioStop = sdl2::SDLK_AUDIOSTOP,
        kAudioPlay = sdl2::SDLK_AUDIOPLAY,
        kAudioMute = sdl2::SDLK_AUDIOMUTE,
        kMediaSelect = sdl2::SDLK_MEDIASELECT,
        kWWW = sdl2::SDLK_WWW,
        kMail = sdl2::SDLK_MAIL,
        kCalculator = sdl2::SDLK_CALCULATOR,
        kComputer = sdl2::SDLK_COMPUTER,
        kACSearch = sdl2::SDLK_AC_SEARCH,
        kACHome = sdl2::SDLK_AC_HOME,
        kACBack = sdl2::SDLK_AC_BACK,
        kACForward = sdl2::SDLK_AC_FORWARD,
        kACStop = sdl2::SDLK_AC_STOP,
        kACRefresh = sdl2::SDLK_AC_REFRESH,
        kACBookmarks = sdl2::SDLK_AC_BOOKMARKS,
        kBrightnessDown = sdl2::SDLK_BRIGHTNESSDOWN,
        kBrightnessUp = sdl2::SDLK_BRIGHTNESSUP,
        kDisplaySwitch = sdl2::SDLK_DISPLAYSWITCH,
        kKbdIllumToggle = sdl2::SDLK_KBDILLUMTOGGLE,
        kKbdIllumDown = sdl2::SDLK_KBDILLUMDOWN,
        kKbdIllumUp = sdl2::SDLK_KBDILLUMUP,
        kEject = sdl2::SDLK_EJECT,
        kSleep = sdl2::SDLK_SLEEP
    };

    const int32_t kScandCodeMask = SDLK_SCANCODE_MASK;

    GfxKeycode() noexcept;

    explicit GfxKeycode(const int32_t code) noexcept;
    explicit GfxKeycode(const ValueType code) noexcept;

    GfxKeycode(GfxKeycode const& other) noexcept;
    GfxKeycode(GfxKeycode&& other) noexcept;

    GfxKeycode& operator=(GfxKeycode const& other) noexcept;
    GfxKeycode& operator=(GfxKeycode&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    ValueType getValue(void) const noexcept;
    ValueType scancodeToKeycode(scancode::GfxScancode const& scancode) const noexcept;

    void clear(void) noexcept;

    SdlType getAsSdlType(void) const noexcept;
private:
    SdlType code_;
};

}  // namespace keycode

}  // namespace gfx

#endif /* GfxKeycode_hpp */
