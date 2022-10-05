#pragma once
#include "Black/Input.h"

namespace Black
{
    class WindowsWindowInput : public Input
    {
    protected:
        

        // Inherited via Input
        virtual bool IskeyPressedImpl(int keycode) override;

        virtual bool IsMouseButtonPressedImpl(int button) override;

        virtual std::pair<float, float> GetMousePositionImpl() override;

        virtual float GetMouseXImpl() override;

        virtual float GetMouseYImpl() override;

    };

}