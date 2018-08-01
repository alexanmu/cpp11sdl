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

#ifndef GfxHints_hpp
#define GfxHints_hpp

#include <stdexcept>
#include <cstdint>
#include <string>
#include <map>
#include <utility>
#include <vector>

#include "GfxObject.hpp"
#include "GfxSdlHeader.hpp"
#include "GfxBool.hpp"
#include "GfxHintPriority.hpp"
#include "GfxHintCallback.hpp"

namespace gfx
{

namespace hints
{

class GfxHints final : public GfxObject
{
public:
    static const char ClassName[];
    static const bool SdlResource = false;
    static const bool CallsSdl = true;

    enum class ValueType : int32_t
    {
        hintFramebufferAcceleration = 1,
        hintRenderDriver = 2,
        hintRenderOpenGLShaders = 3,
        hintRenderDirect3DThreadSafe = 4,
        hintRenderDirect3D11Debug = 5,
        hintRenderLogicalSizeMode = 6,
        hintRenderScaleQuality = 7,
        hintRenderVSync = 8,
        hintVideoAllowScreensaver = 9,
        hintVideoX11XVidMode = 10,
        hintVideoX11Xinerama = 11,
        hintVideoX11XRandr = 12,
        hintVideoX11NetWmPing = 13,
        hintVideoX11NetWmBypassCompositor = 14,
        hintWindowFrameUsableWhileCursorHidden = 15,
        hintWindowsEnableMessageloop = 16,
        hintGrabKeyboard = 17,
        hintMouseNormalSpeedScale = 18,
        hintMouseRelativeSpeedScale = 19,
        hintMouseRelativeModeWrap = 20,
        hintMouseFocusClickthrough = 21,
        hintVideoMinimizeOnFocusLoss = 22,
        hintIdleTimerDisabled = 23,
        hintOrientations = 24,
        hintAppleTVControllerUIEvents = 25,
        hintAppleTVRemoteAllowRotation = 26,
        hintiOSHideHomeIndicator = 27,
        hintAccelerometerAsJoystick = 28,
        hintTvRemoteAsJoystick = 29,
        hintXInputEnabled = 30,
        hintXInputUseOldJoystickMapping = 31,
        hintGamecontrollerconfig = 32,
        hintJoystickAllowBackgroundEvents = 33,
        hintAllowTopmost = 34,
        hintTimerResolution = 35,
        hintQTWaylandContentOrientation = 36,
        hintQTWaylandWindowFlags = 37,
        hintThreadStackSize = 38,
        hintVideoHighDPIDisabled = 39,
        hintMacCtrlClickEmulateRightClick = 40,
        hintVideoWinD3DCompiler = 41,
        hintVideoWindowSharePixelFormat = 42,
        hintWinRTPrivacyPolicyURL = 43,
        hintWinRTPrivacyPolicyLabel = 44,
        hintWinRTHandleBackButton = 45,
        hintVideoMacFullscreenSpaces = 46,
        hintMacBackgroundApp = 47,
        hintAndroidApkExpansionMainFileVersion = 48,
        hintAndroidApkExpansionPatchFileVersion = 49,
        hintIMEInternalEditing = 50,
        hintAndroidSeparateMouseAndTouch = 51,
        hintReturnKeyHidesIme = 52,
        hintEmScriptenKeyboardElement = 53,
        hintNoSignalHandlers = 54,
        hintWindowsNoCloseOnAltF4 = 55,
        hintBmpSaveLegacyFormat = 56,
        hintWindowsDisableThreadNaming = 57,
        hintRPIVideoLayer = 58,
        hintVideoDoubleBuffer = 59,
        hintOpenGLESVideoDriver = 60,
        hintAudioResamplingMode = 61,
        hintWindowIntResourceIcon = 62,
        hintWindowIntResourceIconSmall = 63,
        hintTouchMouseEvents = 64,
        hintGameControllerIgnoreDevices = 65,
        hintGameControllerIgnoreDevicesExcept = 66
    };

    GfxHints() noexcept;

    GfxHints(const GfxHints&) = delete;
    GfxHints(GfxHints&& other) noexcept;

    GfxHints& operator=(const GfxHints&) = delete;
    GfxHints& operator=(GfxHints&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    const GfxBool setHintWithPriority(const std::string& name, const std::string& value,
                                      const GfxHintPriority& prio) const noexcept;
    const GfxBool setHint(const std::string& name, const std::string& value) const noexcept;
    const std::string getHint(const std::string& name) const noexcept;
    const GfxBool getHintBoolean(const std::string& name, const GfxBool& defvalue) const noexcept;
    void addHintCallback(const std::string& name, const GfxHintCallback& callback) noexcept;
    void delHintCallback(const std::string& name, const GfxHintCallback& callback)
                        throw(std::runtime_error);

    const GfxBool setHintWithPriority(const ValueType hint, const std::string& value,
                                      const GfxHintPriority& prio) const noexcept;
    const GfxBool setHint(const ValueType hint, const std::string& value) const noexcept;
    const std::string getHint(const ValueType hint) const noexcept;
    const GfxBool getHintBoolean(const ValueType hint, const GfxBool& defvalue) const noexcept;
    void addHintCallback(const ValueType hint, const GfxHintCallback& callback) noexcept;
    void delHintCallback(const ValueType hint, const GfxHintCallback& callback)
                        throw(std::runtime_error);

    void clearHints(void) const noexcept;
private:
    const std::string getHintNameByValue(const ValueType value) const noexcept;
    // Will be called from C by SDL
    static void hintCallbackFunction(void * userdata, const char * name, const char * oldv, const char * newv);

    std::map<std::string, GfxHintCallback *> callbackMap_;

    static const std::vector<std::pair<ValueType, const char *>> hintsMap_;
};

}  // namespace hints

}  // namespace gfx

#endif /* GfxHints_hpp */
