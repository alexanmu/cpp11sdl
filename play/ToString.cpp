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

#include "ToString.hpp"

/******************************************************* Meta *******************************************************/
#include <iostream>
#include <type_traits>
#include <string>

#include "GfxBits.hpp"
#include "GfxBlendMode.hpp"
#include "GfxBool.hpp"
#include "GfxClipboard.hpp"
#include "GfxColor.hpp"
#include "GfxCpuInfo.hpp"
#include "GfxDisplayMode.hpp"
#include "GfxEndian.hpp"
#include "GfxGetError.hpp"
#include "GfxFileSystem.hpp"
#include "GfxGetRendererInfo.hpp"
#include "GfxGetVersion.hpp"
#include "GfxInitQuit.hpp"
#include "GfxLoadSo.hpp"
#include "GfxMessageBox.hpp"
#include "GfxMessageBoxButtonData.hpp"
#include "GfxMessageBoxButtonFlags.hpp"
#include "GfxMessageBoxColor.hpp"
#include "GfxMessageBoxColorScheme.hpp"
#include "GfxMessageBoxData.hpp"
#include "GfxMessageBoxFlags.hpp"
#include "GfxPalette.hpp"
#include "GfxPixelFormat.hpp"
#include "GfxPlatform.hpp"
#include "GfxPoint.hpp"
#include "GfxPowerInfo.hpp"
#include "GfxPowerState.hpp"
#include "GfxRect.hpp"
#include "GfxRenderer.hpp"
#include "GfxRendererFlags.hpp"
#include "GfxRendererFlip.hpp"
#include "GfxRendererInfo.hpp"
#include "GfxScreenSaver.hpp"
#include "GfxSurface.hpp"
#include "GfxSurfaceFlags.hpp"
#include "GfxTexture.hpp"
#include "GfxTextureAccess.hpp"
#include "GfxTextureModulate.hpp"
#include "GfxVersion.hpp"
#include "GfxVideo.hpp"
#include "GfxWindow.hpp"
#include "GfxWindowEventID.hpp"
#include "GfxWindowFlags.hpp"
#include "GfxWindowPosition.hpp"
#include "GfxAngle.hpp"
#include "GfxBitmapFont.hpp"
#include "GfxCanvas.hpp"
#include "GfxCanvasBgi.hpp"
#include "GfxRadius.hpp"
#include "GfxText.hpp"
#include "GfxInitFlags.hpp"  // 2017.05.17
#include "GfxTtfFont.hpp"  // 2017.05.17
#include "GfxTtfInitQuit.hpp"  // 2017.05.17
#include "GfxTtfGetVersion.hpp"  // 2017.05.18
#include "GfxTtfFontStyle.hpp"  // 2017.05.18
#include "GfxTtfFontHinting.hpp"  // 2017.05.18
#include "GfxTtfFontRenderer.hpp"  // 2017.05.19
#include "GfxFontInfo.hpp"  // 2017.05.19
#include "GfxPixelType.hpp"  // 2017.05.30
#include "GfxBitmapOrder.hpp"  // 2017.05.30
#include "GfxPackedOrder.hpp"  // 2017.05.30
#include "GfxArrayOrder.hpp"  // 2017.05.30
#include "GfxPackedLayout.hpp"  // 2017.05.30
#include "GfxPixelFormatEnum.hpp"  // 2017.05.30
#include "GfxHitTestResult.hpp"  // 2017.05.31
#include "GfxGammaRamp.hpp"  // 2017.06.01
#include "GfxHitTest.hpp"  // 2017.06.02
#include "GfxTextureFormats.hpp"  // 2017.06.02
#include "GfxError.hpp"  // 2017.06.03
#include "GfxLogPriority.hpp"  // 2017.06.07
#include "GfxLogCategory.hpp"  // 2017.06.07
#include "GfxLog.hpp"  // 2017.06.07
#include "GfxLogOutputFunction.hpp"  // 2017.06.09
#include "GfxHintPriority.hpp"  // 2017.06.16
#include "GfxHints.hpp"  // 2017.06.16
#include "GfxHintCallback.hpp"  // 2017.06.16
#include "GfxEventType.hpp"  // 2017.06.18
#include "GfxCommonEvent.hpp"  // 2017.06.19
#include "GfxWindowEvent.hpp"  // 2017.06.19
#include "GfxScancode.hpp"  // 2017.06.21
#include "GfxKeycode.hpp"  // 2017.06.21
#include "GfxKeymod.hpp"  // 2017.06.21
#include "GfxKeysym.hpp"  // 2017.06.21
#include "GfxKeyboard.hpp"  // 2017.06.21
#include "GfxKeyboardEvent.hpp"  // 2017.06.21
#include "GfxTextEditingEvent.hpp"  // 2017.06.22
#include "GfxTextInputEvent.hpp"  // 2017.06.22
#include "GfxDrawingMode.hpp"  // 2017.06.22
#include "GfxArcCoordsType.hpp"  // 2017.06.23
#include "GfxPaletteType.hpp"  // 2017.06.23
#include "GfxFillSettingsType.hpp"  // 2017.06.23
#include "GfxLineSettingsType.hpp"  // 2017.06.23
#include "GfxTextSettingsType.hpp"  // 2017.06.23
#include "GfxViewPortType.hpp"  // 2017.06.23
#include "GfxLineStyle.hpp"  // 2017.06.23
#include "GfxFillStyles.hpp"  // 2017.06.23
#include "GfxLineThickness.hpp"  // 2017.06.23
#include "GfxTextJustification.hpp"  // 2017.06.23
#include "GfxDirection.hpp"  // 2017.06.23
#include "GfxFonts.hpp"  // 2017.06.23
#include "GfxColors2.hpp"  // 2017.06.23
#include "GfxJoystickGUID.hpp"  // 2017.07.04
#include "GfxJoystickID.hpp"  // 2017.07.05
#include "GfxJoystickType.hpp"  // 2017.07.06
#include "GfxJoystickPowerLevel.hpp"  // 2017.07.06
#include "GfxHatPosition.hpp"  // 2017.07.07
#include "GfxJoystick.hpp"  // 2017.07.07
#include "GfxEventAction.hpp"  // 2017.07.08
#include "GfxMouseMotionEvent.hpp"  // 2017.07.08
#include "GfxMouseButtonEvent.hpp"  // 2017.07.09
#include "GfxMouseWheelEvent.hpp"  // 2017.07.09
#include "GfxJoyAxisEvent.hpp"  // 2017.07.10
#include "GfxJoyBallEvent.hpp"  // 2017.07.10
#include "GfxJoyHatEvent.hpp"  // 2017.07.10
#include "GfxJoyButtonEvent.hpp"  // 2017.07.10
#include "GfxJoyDeviceEvent.hpp"  // 2017.07.10
#include "GfxSystemCursor.hpp"  // 2017.07.14
#include "GfxMouseWheelDirection.hpp"  // 2017.07.17
#include "GfxButton.hpp"  // 2017.07.17
#include "GfxMouse.hpp"  // 2017.07.17
#include "GfxCursor.hpp"  // 2017.07.17
#include "GfxEvent.hpp"  // 2017.07.25
#include "GfxEventFilter.hpp"  // 2017.07.27
#include "GfxControllerAxisEvent.hpp"  // 2017.08.03
#include "GfxControllerButtonEvent.hpp"  // 2017.08.03
#include "GfxControllerDeviceEvent.hpp"  // 2017.08.03
#include "GfxQuitEvent.hpp"  // 2017.08.04
#include "GfxUserEvent.hpp"  // 2017.08.04
#include "GfxAudioDeviceEvent.hpp"  // 2017.08.08
#include "GfxDropEvent.hpp"  // 2017.08.22
#include "GfxSysWmEvent.hpp"  // 2017.08.22
#include "GfxTouchFingerEvent.hpp"  // 2017.08.22
#include "GfxDollarGestureEvent.hpp"  // 2017.08.22
#include "GfxMultiGestureEvent.hpp"  // 2017.08.22
#include "GfxTimerID.hpp"  // 2017.09.06
#include "GfxTimerCallback.hpp"  // 2017.09.06

struct ToStringStruct
{
    const char * className_;
};

namespace prv
{
    // https://stackoverflow.com/questions/12015195/how-to-call-member-function-only-if-object-happens-to-have-it

    /*! The template `has_void_foo_no_args_const<T>` exports a
     boolean constant `value` that is true iff `T` provides
     `void foo() const`

     It also provides `static void eval(T const & t)`, which
     invokes void `T::foo() const` upon `t` if such a public member
     function exists and is a no-op if there is no such member.
     */
template< typename T>
struct has_void_to_string_no_args_const
{
    /* SFINAE foo-has-correct-sig :) */
    template<typename A>
    static std::true_type test(std::string (A::*)() const)
    {
        return std::true_type();
    }

    /* SFINAE foo-exists :) */
    template <typename A>
    static decltype(test(&A::to_string)) test(decltype(&A::to_string), void *)
    {
        /* foo exists. What about sig? */
        typedef decltype(test(&A::to_string)) return_type;

        return return_type();
    }

    /* SFINAE game over :( */
    template<typename A>
    static std::false_type test(...)
    {
        return std::false_type();
    }

    /* This will be either `std::true_type` or `std::false_type` */
    typedef decltype(test<T>(0, 0)) type;

    static const bool value = type::value; /* Which is it? */

    /*  `eval(T const &,std::true_type)`
     delegates to `T::foo()` when `type` == `std::true_type`
     */
    static void eval(T const & t, std::true_type)
    {
        std::cout << t.to_string() << std::endl;
    }

    /* `eval(...)` is a no-op for otherwise unmatched arguments */
    static void eval(...)
    {
        // This output for demo purposes. Delete
        std::cout << "T::foo() not called" << std::endl;
    }

    /* `eval(T const & t)` delegates to :-
     - `eval(t,type()` when `type` == `std::true_type`
     - `eval(...)` otherwise
     */
    static void eval(T const & t)
    {
        eval(t, type());
    }
};

// This is the desired implementation of `void f(T const& val)`
template<class T>
void f(T const& val)
{
    has_void_to_string_no_args_const<T>::eval(val);
}

template <typename T>
constexpr ToStringStruct makeStringStruct(void)
{
    return {
        T::ClassName
    };
}
}  // namespace prv

static void Other(void)
{
    std::cout << "--> ::to_string()" << std::endl;

    gfx::GfxBool b;
    prv::f(b);
}

const struct ToStringStruct infoArray_[] =
{
    // gfx::bits
    {   prv::makeStringStruct<gfx::bits::GfxBits>()                 },
    // gfx::blendmode
    {   prv::makeStringStruct<gfx::blendmode::GfxBlendMode>()       },
    // gfx
    {   prv::makeStringStruct<gfx::GfxBool>()                       },
    // gfx::clipboard
    {   prv::makeStringStruct<gfx::clipboard::GfxClipboard>()       },
    // gfx::pixels
    {   prv::makeStringStruct<gfx::pixels::GfxColor>()              },
    {   prv::makeStringStruct<gfx::pixels::GfxPalette>()            },
    {   prv::makeStringStruct<gfx::pixels::GfxPixelFormat>()        },
    {   prv::makeStringStruct<gfx::pixels::GfxPixelType>()          },  // 2017.05.30
    {   prv::makeStringStruct<gfx::pixels::GfxBitmapOrder>()        },  // 2017.05.30
    {   prv::makeStringStruct<gfx::pixels::GfxPackedOrder>()        },  // 2017.05.30
    {   prv::makeStringStruct<gfx::pixels::GfxArrayOrder>()         },  // 2017.05.30
    {   prv::makeStringStruct<gfx::pixels::GfxPackedLayout>()       },  // 2017.05.30
    {   prv::makeStringStruct<gfx::pixels::GfxPixelFormatEnum>()    },  // 2017.05.30
    // gfx::cpuinfo
    {   prv::makeStringStruct<gfx::cpuinfo::GfxCpuInfo>()           },
    // gfx::video
    {   prv::makeStringStruct<gfx::video::GfxDisplayMode>()         },
    {   prv::makeStringStruct<gfx::video::GfxScreenSaver>()         },
    {   prv::makeStringStruct<gfx::video::GfxVideo>()               },
    {   prv::makeStringStruct<gfx::video::GfxWindow>()              },
    {   prv::makeStringStruct<gfx::video::GfxWindowEventID>()       },
    {   prv::makeStringStruct<gfx::video::GfxWindowFlags>()         },
    {   prv::makeStringStruct<gfx::video::GfxWindowPosition>()      },
    {   prv::makeStringStruct<gfx::video::GfxHitTestResult>()       },  // 2017.05.31
    {   prv::makeStringStruct<gfx::video::GfxHitTest>()             },  // 2017.06.02
    // gfx::endian
    {   prv::makeStringStruct<gfx::endian::GfxEndian>()             },
    // gfx::error
    {   prv::makeStringStruct<gfx::error::GfxGetError>()            },
    {   prv::makeStringStruct<gfx::error::GfxError>()               },  // 2017.06.03
    // gfx::filesystem
    {   prv::makeStringStruct<gfx::filesystem::GfxFileSystem>()     },
    // gfx::version
    {   prv::makeStringStruct<gfx::version::GfxGetVersion>()        },
    {   prv::makeStringStruct<gfx::version::GfxVersion>()           },
    // gfx::initquit
    {   prv::makeStringStruct<gfx::initquit::GfxInitQuit>()         },
    {   prv::makeStringStruct<gfx::initquit::GfxInitFlags>()        },  // 2017.05.17
    // gfx::loadso
    {   prv::makeStringStruct<gfx::loadso::GfxLoadSo>()             },
    // gfx::msgbox
    {   prv::makeStringStruct<gfx::msgbox::GfxMessageBox>()         },
    {   prv::makeStringStruct<gfx::msgbox::GfxMessageBoxButtonData>()  },
    {   prv::makeStringStruct<gfx::msgbox::GfxMessageBoxButtonFlags>() },
    {   prv::makeStringStruct<gfx::msgbox::GfxMessageBoxColor>()       },
    {   prv::makeStringStruct<gfx::msgbox::GfxMessageBoxColorScheme>() },
    {   prv::makeStringStruct<gfx::msgbox::GfxMessageBoxData>()     },
    {   prv::makeStringStruct<gfx::msgbox::GfxMessageBoxFlags>()    },
    // gfx::platform
    {   prv::makeStringStruct<gfx::platform::GfxPlatform>()         },
    // gfx::rect
    {   prv::makeStringStruct<gfx::rect::GfxPoint>()                },
    {   prv::makeStringStruct<gfx::rect::GfxRect>()                 },
    // gfx::power
    {   prv::makeStringStruct<gfx::power::GfxPowerInfo>()           },
    {   prv::makeStringStruct<gfx::power::GfxPowerState>()          },
    // gfx::surface
    {   prv::makeStringStruct<gfx::surface::GfxSurface>()           },
    {   prv::makeStringStruct<gfx::surface::GfxSurfaceFlags>()      },
    // gfx::bgi
    {   prv::makeStringStruct<gfx::bgi::GfxAngle>()                 },
    {   prv::makeStringStruct<gfx::bgi::GfxCanvas>()                },
    {   prv::makeStringStruct<gfx::bgi::GfxRadius>()                },
    {   prv::makeStringStruct<gfx::bgi::GfxText>()                  },
    {   prv::makeStringStruct<gfx::bgi::GfxDrawingMode>()           },  // 2017.06.22
    {   prv::makeStringStruct<gfx::bgi::GfxArcCoordsType>()         },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxPaletteType>()           },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxFillSettingsType>()      },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxLineSettingsType>()      },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxTextSettingsType>()      },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxViewPortType>()          },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxLineStyle>()             },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxFillStyles>()            },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxLineThickness>()         },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxTextJustification>()     },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxDirection>()             },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxFonts>()                 },  // 2017.06.23
    {   prv::makeStringStruct<gfx::bgi::GfxColors2>()               },  // 2017.06.23
    // gfx::bgi::prv
    {   prv::makeStringStruct<gfx::bgi::prv::GfxCanvasBgi>()        },
    // gfx::bgi::fnt
    {   prv::makeStringStruct<gfx::bgi::fnt::GfxBitmapFont>()       },
    // gfx::ttf
    {   prv::makeStringStruct<gfx::ttf::GfxTtfFont>()               },  // 2017.05.17
    {   prv::makeStringStruct<gfx::ttf::GfxTtfInitQuit>()           },  // 2017.05.17
    {   prv::makeStringStruct<gfx::ttf::GfxTtfGetVersion>()         },  // 2017.05.18
    {   prv::makeStringStruct<gfx::ttf::GfxTtfFontStyle>()          },  // 2017.05.18
    {   prv::makeStringStruct<gfx::ttf::GfxTtfFontHinting>()        },  // 2017.05.18
    {   prv::makeStringStruct<gfx::ttf::GfxTtfFontRenderer>()       },  // 2017.05.19
    // gfx::xtra
    {   prv::makeStringStruct<gfx::xtra::GfxFontInfo>()             },  // 2017.05.19
    {   prv::makeStringStruct<gfx::xtra::GfxGammaRamp>()            },  // 2017.06.01
    // gfx::log
    {   prv::makeStringStruct<gfx::log::GfxLogPriority>()           },  // 2017.06.07
    {   prv::makeStringStruct<gfx::log::GfxLogCategory>()           },  // 2017.06.07
    {   prv::makeStringStruct<gfx::log::GfxLog>()                   },  // 2017.06.07
    {   prv::makeStringStruct<gfx::log::GfxLogOutputFunction>()     },  // 2017.06.09
    // gfx::render
    {   prv::makeStringStruct<gfx::render::GfxGetRendererInfo>()    },
    {   prv::makeStringStruct<gfx::render::GfxRenderer>()           },
    {   prv::makeStringStruct<gfx::render::GfxRendererFlags>()      },
    {   prv::makeStringStruct<gfx::render::GfxRendererFlip>()       },
    {   prv::makeStringStruct<gfx::render::GfxRendererInfo>()       },
    {   prv::makeStringStruct<gfx::render::GfxTexture>()            },
    {   prv::makeStringStruct<gfx::render::GfxTextureAccess>()      },
    {   prv::makeStringStruct<gfx::render::GfxTextureModulate>()    },
    {   prv::makeStringStruct<gfx::render::GfxTextureFormats>()     },  // 2017.06.02
    //  gfx::hints
    {   prv::makeStringStruct<gfx::hints::GfxHintPriority>()        },  // 2017.06.16
    {   prv::makeStringStruct<gfx::hints::GfxHints>()               },  // 2017.06.16
    {   prv::makeStringStruct<gfx::hints::GfxHintCallback>()        },  // 2017.06.16
    //  gfx::events
    {   prv::makeStringStruct<gfx::events::GfxEventType>()          },  // 2017.06.18
    {   prv::makeStringStruct<gfx::events::GfxCommonEvent>()        },  // 2017.06.19
    {   prv::makeStringStruct<gfx::events::GfxWindowEvent>()        },  // 2017.06.19
    {   prv::makeStringStruct<gfx::events::GfxKeyboardEvent>()      },  // 2017.06.21
    {   prv::makeStringStruct<gfx::events::GfxTextEditingEvent>()   },  // 2017.06.22
    {   prv::makeStringStruct<gfx::events::GfxTextInputEvent>()     },  // 2017.06.22
    {   prv::makeStringStruct<gfx::events::GfxEventAction>()        },  // 2017.07.08
    {   prv::makeStringStruct<gfx::events::GfxMouseMotionEvent>()   },  // 2017.07.08
    {   prv::makeStringStruct<gfx::events::GfxMouseButtonEvent>()   },  // 2017.07.09
    {   prv::makeStringStruct<gfx::events::GfxMouseWheelEvent>()    },  // 2017.07.09
    {   prv::makeStringStruct<gfx::events::GfxJoyAxisEvent>()       },  // 2017.07.10
    {   prv::makeStringStruct<gfx::events::GfxJoyBallEvent>()       },  // 2017.07.10
    {   prv::makeStringStruct<gfx::events::GfxJoyHatEvent>()        },  // 2017.07.10
    {   prv::makeStringStruct<gfx::events::GfxJoyButtonEvent>()     },  // 2017.07.10
    {   prv::makeStringStruct<gfx::events::GfxJoyDeviceEvent>()     },  // 2017.07.10
    {   prv::makeStringStruct<gfx::events::GfxEvent>()              },  // 2017.07.25
    {   prv::makeStringStruct<gfx::events::GfxEventFilter>()        },  // 2017.07.27
    {   prv::makeStringStruct<gfx::events::GfxControllerAxisEvent>()    },  // 2017.08.03
    {   prv::makeStringStruct<gfx::events::GfxControllerButtonEvent>()  },  // 2017.08.03
    {   prv::makeStringStruct<gfx::events::GfxControllerDeviceEvent>()  },  // 2017.08.03
    {   prv::makeStringStruct<gfx::events::GfxQuitEvent>()          },  // 2017.08.04
    {   prv::makeStringStruct<gfx::events::GfxUserEvent>()          },  // 2017.08.04
    {   prv::makeStringStruct<gfx::events::GfxAudioDeviceEvent>()   },  // 2017.08.08
    {   prv::makeStringStruct<gfx::events::GfxDropEvent>()          },  // 2017.08.22
    {   prv::makeStringStruct<gfx::events::GfxSysWmEvent>()         },  // 2017.08.22
    {   prv::makeStringStruct<gfx::events::GfxMultiGestureEvent>()  },  // 2017.08.22
    {   prv::makeStringStruct<gfx::events::GfxDollarGestureEvent>() },  // 2017.08.22
    {   prv::makeStringStruct<gfx::events::GfxTouchFingerEvent>()   },  // 2017.08.22
    //  gfx::scancode
    {   prv::makeStringStruct<gfx::scancode::GfxScancode>()         },  // 2017.06.21
    //  gfx::keycode
    {   prv::makeStringStruct<gfx::keycode::GfxKeycode>()           },  // 2017.06.21
    {   prv::makeStringStruct<gfx::keycode::GfxKeymod>()            },  // 2017.06.21
    //  gfx::keyboard
    {   prv::makeStringStruct<gfx::keyboard::GfxKeysym>()           },  // 2017.06.21
    {   prv::makeStringStruct<gfx::keyboard::GfxKeyboard>()         },  // 2017.06.21
    //  gfx::joystick
    {   prv::makeStringStruct<gfx::joystick::GfxJoystickGUID>()     },  // 2017.07.04
    {   prv::makeStringStruct<gfx::joystick::GfxJoystickID>()       },  // 2017.07.05
    {   prv::makeStringStruct<gfx::joystick::GfxJoystickType>()     },  // 2017.07.06
    {   prv::makeStringStruct<gfx::joystick::GfxJoystickPowerLevel>()   },  // 2017.07.06
    {   prv::makeStringStruct<gfx::joystick::GfxHatPosition>()      },  // 2017.07.07
    {   prv::makeStringStruct<gfx::joystick::GfxJoystick>()         },  // 2017.07.07
    //  gfx::mouse
    {   prv::makeStringStruct<gfx::mouse::GfxSystemCursor>()        },  // 2017.07.14
    {   prv::makeStringStruct<gfx::mouse::GfxMouseWheelDirection>() },  // 2017.07.17
    {   prv::makeStringStruct<gfx::mouse::GfxButton>()              },  // 2017.07.17
    {   prv::makeStringStruct<gfx::mouse::GfxMouse>()               },  // 2017.07.17
    {   prv::makeStringStruct<gfx::mouse::GfxCursor>()              },  // 2017.07.17
    // gfx::timer
    {   prv::makeStringStruct<gfx::timer::GfxTimerID>()             },  // 2017.09.06
    {   prv::makeStringStruct<gfx::timer::GfxTimerCallback>()       }  // 2017.09.06
};

void _doToString(void)
{
    std::cout << "ToString" << std::endl;

    std::size_t size = sizeof(infoArray_) / sizeof(infoArray_[0]);
    std::cout << "size=" << size << std::endl;

    for (std::size_t index = 0; index < size; index++)
    {
        std::cout << infoArray_[index].className_ << std::endl;
    }
    Other();
}
