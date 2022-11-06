#pragma once

#include <gd.h>

#include "ModPlayLayer.hpp"

#include "mods.hpp"
#include "switcher.hpp"

using namespace gd;
using namespace cocos2d;

class ModUILayer final : UILayer {
    public:
        void _keyDown(enumKeyCodes key) {
            auto pModPlayLayer = reinterpret_cast<ModPlayLayer*>(PlayLayer::get());

            matdash::orig<&ModUILayer::_keyDown>(this, key);
            
            if ((key == switcher::keyBinds[0] || key == switcher::keyBinds[1]) && mods::toogle) {
                if (!mods::switchOnDeath) {
                    pModPlayLayer->updateIndex(key == switcher::keyBinds[1]);
                }
                else {
                    switcher::direction = (key == switcher::keyBinds[1]);
                    switcher::toSwitch = true;
                }
            }
        }
};