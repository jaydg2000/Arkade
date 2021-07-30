#include "Form.h"

namespace arkade {

    arkade::Form::Form(uint32_t screen_x, uint32_t screen_y, Size size)
    {
        _x = screen_x;
        _y = screen_y;
        _size = size;
        _enabled = false;
        _visible = false;
        _next_control_id = 1000;
        
        _should_render_border = false;
    }

    arkade::Form::~Form()
    {
    }

    void Form::size(Size size)
    {
        _size.x = size.x;
        _size.y = size.y;        
    }

    void Form::position(uint32_t screen_x, uint32_t screen_y)
    {
        _x = screen_x;
        _y = screen_y;
    }

    void arkade::Form::add_control(FormControl* control)
    {
        control->set_id(++_next_control_id);
        _controls.push_back(control);
    }

    FormControl* arkade::Form::find_control(uint32_t id)
    {
        for (FormControl* control : _controls)
        {
            if (control->id() == id)
                return control;
        }
        return nullptr;
    }

    bool Form::enabled()
    {
        return _enabled;
    }

    void Form::enable()
    {
        _enabled = true;
        setup_controls();
    }

    void Form::disable()
    {
        _enabled = false;
    }

    bool Form::visible()
    {
        return _visible;
    }

    void Form::show()
    {
        _visible = true;
    }

    void Form::hide()
    {
        _visible = false;
    }

    void Form::show_border(bool should_render_border)
    {
        _should_render_border = should_render_border;
    }

    void arkade::Form::setup_controls()
    {
        for (FormControl* control : _controls)
        {
            control->on_setup();
        }
    }

    void arkade::Form::on_check_input(InputManager* ptr_input_manager)
    {
        for (FormControl* control : _controls)
        {
            control->on_check_input(ptr_input_manager);
        }
    }

    void arkade::Form::on_update()
    {
        for (FormControl* control : _controls)
        {
            control->on_update();
        }
    }

    void arkade::Form::on_render(Graphics* ptr_graphics)
    {
        Rect rect = make_rect(_x, _y, _size.x, _size.y);
        if (_should_render_border)
            ptr_graphics->render(&rect);
        for (FormControl* control : _controls)
        {
            control->on_render(ptr_graphics);
        }
    }

    void arkade::Form::on_deactivate()
    {
        for (FormControl* control : _controls)
        {
            control->on_cleanup();
        }
    }

    void arkade::Form::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data)
    {
    }

}