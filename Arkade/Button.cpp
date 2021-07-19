#include "Button.h"

namespace arkade {
    Button::Button(Image* ptr_image, uint32_t screen_x, uint32_t screen_y)
        : FormControl(ptr_image->x(), ptr_image->y(), make_size(ptr_image->source_rect()->w, ptr_image->source_rect()->h))
    {
        _ptr_image = ptr_image;
        _is_managing_image = false;
        _is_being_clicked = false;
    }

    Button::Button(Text* ptr_text, uint32_t screen_x, uint32_t screen_y)
        : FormControl(screen_x, screen_y, make_size(ptr_text->source_rect()->w, ptr_text->source_rect()->h))
    {
        _ptr_image = ptr_text->to_image();
        _is_managing_image = true;
        _is_being_clicked = false;
    }

    Button::~Button()
    {
        if (_is_managing_image && _ptr_image)
        {
            SDL_DestroyTexture(_ptr_image->texture());
            delete _ptr_image;
        }
    }

    Image* Button::image()
    {
        _ptr_image->x(x());
        _ptr_image->y(y());
        return _ptr_image;
    }

    void Button::image(Image* ptr_image)
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

    void Button::on_render(Graphics* ptr_graphics)
    {
        Image* image = this->image();
        Rect* button_rect = image->destination_rect();
        Size button_margin = border_margin();
        Rect border_rect = copy_rect(button_rect);
        expand_rect(&border_rect, button_margin);

        ptr_graphics->render(&border_rect, border_color(), _is_being_clicked);
        ptr_graphics->render(image);
    }

    void Button::on_mouse_down(uint32_t mouse_x, uint32_t mouse_y)
    {
        _is_being_clicked = true;
    }

    void Button::on_mouse_up()
    {
        _is_being_clicked = false;
    }

    void Button::on_mouse_over(uint32_t mouse_x, uint32_t mouse_y)
    {
    }
}