#include "MenuForm.h"
#include "Game.h"

namespace arkade {
    arkade::MenuForm::MenuForm(Size window_size, Font* ptr_font)
    {
        _window_size = window_size;
        _form = new Form(0, 0, { 0,0 });
        _ptr_button_font = ptr_font;
    }

    arkade::MenuForm::~MenuForm()
    {
        for (Button* ptr_button : _menu_items)
        {            
            delete ptr_button;
        }
    }

    void arkade::MenuForm::add_menu_item(const char* title, std::function<void()> click_action)
    {
        auto text = new Text(title, _ptr_button_font);
        auto button = new Button(text, 0, 0);
        button->border_color({ 255,255,255,255 });
        button->border_margin(make_size(100, 10));
        button->on_click(click_action);   
        _menu_items.push_back(button);
        _form->add_control(button);

        _adjust();
    }

    Form* arkade::MenuForm::form()
    {
        return _form;
    }

    void MenuForm::show()
    {
        _form->show();
    }

    void MenuForm::enable()
    {
        _form->enable();
    }

    void MenuForm::_adjust()
    {      
        uint32_t longest_button_size = 0;
        uint32_t number_of_buttons = _menu_items.size();
        
        for (Button* button : _menu_items)
        {            
            if (button->size().x > longest_button_size)
                longest_button_size = button->size().x;
        }

        uint32_t desired_width = longest_button_size + 80;
                
        for (Button* button : _menu_items)
        {
            auto button_size_x = button->size().x;
            auto desired_button_margin_x = desired_width - button_size_x;
            //auto diff = desired_width - (button_size_x + desired_button_margin_x);
            int new_margin = desired_button_margin_x / 2;
            button->border_margin({ new_margin, button->border_margin().y });
        }

        uint32_t padding_between_buttons = 22; // todo: how can I figure this out?
        uint32_t button_height = _menu_items[0]->size().y + _menu_items[0]->border_margin().y + padding_between_buttons;
        uint32_t total_height = button_height * number_of_buttons;
        
        uint32_t form_height = total_height;
        uint32_t form_screen_y = (_window_size.y / 2) - (form_height / 2);
        uint32_t first_button_y = form_screen_y + 10;

        uint32_t form_width = desired_width + 20; // extra padding on the left and right.
        uint32_t form_screen_x = (_window_size.x /2) - (form_width / 2);

        _form->position(form_screen_x, form_screen_y);
        _form->size(make_size(form_width, form_height));

        uint32_t button_y = first_button_y;

        for (Button* button : _menu_items)
        {
            uint32_t button_x = (_window_size.x / 2) - (button->size().x / 2);
            button->position(button_x, button_y);
            button_y += button_height;
        }
    }

}