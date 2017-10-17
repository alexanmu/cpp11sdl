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
        hintWindowFrameUsableWhileCursorHidden = 14,
        hintWindowsEnableMessageloop = 15,
        hintGrabKeyboard = 16,
        hintMouseNormalSpeedScale = 17,
        hintMouseRelativeSpeedScale = 18,
        hintMouseRelativeModeWrap = 19,
        hintMouseFocusClickthrough = 20,
        hintVideoMinimizeOnFocusLoss = 21,
        hintIdleTimerDisabled = 22,
        hintOrientations = 23,
        hintAppleTVControllerUIEvents = 24,
        hintAppleTVRemoteAllowRotation = 25,
        hintAccelerometerAsJoystick = 26,
        hintXInputEnabled = 27,
        hintXInputUseOldJoystickMapping = 28,
        hintGamecontrollerconfig = 29,
        hintJoystickAllowBackgroundEvents = 30,
        hintAllowTopmost = 31,
        hintTimerResolution = 32,
        hintQTWaylandContentOrientation = 33,
        hintQTWaylandWindowFlags = 34,
        hintThreadStackSize = 35,
        hintVideoHighDPIDisabled = 36,
        hintMacCtrlClickEmulateRightClick = 37,
        hintVideoWinD3DCompiler = 38,
        hintVideoWindowSharePixelFormat = 39,
        hintWinRTPrivacyPolicyURL = 40,
        hintWinRTPrivacyPolicyLabel = 41,
        hintWinRTHandleBackButton = 42,
        hintVideoMacFullscreenSpaces = 43,
        hintMacBackgroundApp = 44,
        hintAndroidApkExpansionMainFileVersion = 45,
        hintAndroidApkExpansionPatchFileVersion = 46,
        hintIMEInternalEditing = 47,
        hintAndroidSeparateMouseAndTouch = 48,
        hintEmScriptenKeyboardElement = 49,
        hintNoSignalHandlers = 50,
        hintWindowsNoCloseOnAltF4 = 51,
        hintBmpSaveLegacyFormat = 52,
        hintWindowsDisableThreadNaming = 53,
        hintRPIVideoLayer = 54,
        hintOpenGLESVideoDriver = 55,
        hintAudioResamplingMode = 56,
        hintWindowIntResourceIcon = 57,
        hintWindowIntResourceIconSmall = 58,
        hintTouchMouseEvents = 59,
        hintGameControllerIgnoreDevices = 60,
        hintGameControllerIgnoreDevicesExcept = 61
    };

    GfxHints() noexcept;

    GfxHints(GfxHints const&) = delete;
    GfxHints(GfxHints&& other) noexcept;

    GfxHints& operator=(GfxHints const&) = delete;
    GfxHints& operator=(GfxHints&& other) noexcept;

    virtual explicit operator bool() const noexcept;
    virtual std::string to_string(void) const noexcept;

    GfxBool setHintWithPriority(std::string const& name, std::string const& value,
                                GfxHintPriority const& prio) const noexcept;
    GfxBool setHint(std::string const& name, std::string const& value) const noexcept;
    std::string getHint(std::string const& name) const noexcept;
    GfxBool getHintBoolean(std::string const& name, GfxBool const& defvalue) const noexcept;
    void addHintCallback(std::string const& name, GfxHintCallback const& callback) noexcept;
    void delHintCallback(std::string const& name, GfxHintCallback const& callback)
                        throw(std::runtime_error);

    GfxBool setHintWithPriority(const ValueType hint, std::string const& value,
                                GfxHintPriority const& prio) const noexcept;
    GfxBool setHint(const ValueType hint, std::string const& value) const noexcept;
    std::string getHint(const ValueType hint) const noexcept;
    GfxBool getHintBoolean(const ValueType hint, GfxBool const& defvalue) const noexcept;
    void addHintCallback(const ValueType hint, GfxHintCallback const& callback) noexcept;
    void delHintCallback(const ValueType hint, GfxHintCallback const& callback)
                        throw(std::runtime_error);

    void clearHints(void) const noexcept;
private:
    std::string getHintNameByValue(const ValueType value) const noexcept;
    // Will be called from C by SDL
    static void hintCallbackFunction(void * userdata, const char * name, const char * oldv, const char * newv);

    std::map<std::string, GfxHintCallback *> callbackMap_;

    static const std::vector<std::pair<ValueType, const char *>> hintsMap_;
};

}  // namespace hints

}  // namespace gfx

#endif /* GfxHints_hpp */
