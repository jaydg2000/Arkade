#include "Button.h"

namespace arkade {
    arkade::Button::Button(Image* ptr_image, uint32_t screen_x, uint32_t screen_y)
    {
        _ptr_image = ptr_image;
        _click_message_id = click_message_id;
        _is_managing_image = false;
        _x = screen_x;
        _y = screen_y;
    }

    Button::Button(Text* ptr_text, uint32_t screen_x, uint32_t screen_y)
    {
        _ptr_image = ptr_text->to_image();
        _is_managing_image = true;
        _x = screen_x;
        _y = screen_y;
    }

    arkade::Button::~Button()
    {
        if (_is_managing_image && _ptr_image)
        {
            SDL_DestroyTexture(_ptr_image->texture());
            delete _ptr_image;
        }
    }

    Image* arkade::Button::image()
    {
        _ptr_image->x(_x);
        _ptr_image->y(_y);
        return _ptr_image;
    }

    void arkade::Button::image(Image* ptr_image)
    {
        _ptr_image = ptr_image;
    }
    RGB Button::border_color()
    {
        return _border_color;
    }
    void Button::border_color(RGB border_color)
    {
        _border_color = border_color;
    }
    Size Button::border_margin()
    {
        return _border_size;
    }
    void Button::border_margin(Size border_margin)
    {
        _border_size = border_margin;
    }
    void Button::on_click(std::function<void()> click_action)
    {
        _click_action = click_action;
    }
}