#include "Text.h"

namespace arkade
{
    Text::Text(const char* psz_text, Font* font, SDL_Color color)
    {
        _psz_text = psz_text;
        _ptr_font = font;
        _color = color;
        _make_texture();
    }

    Text::~Text()
    {
        if (_ptr_texture)
            SDL_DestroyTexture(_ptr_texture);
    }

    Texture* Text::texture()
    {
        return _ptr_texture;
    }

    const char* Text::text() const
    {
        return _psz_text;
    }

    void Text::text(const char* psz_text)
    {
        if (_ptr_texture)
            SDL_DestroyTexture(_ptr_texture);
        _psz_text = psz_text;
        _make_texture();
    }

    void Text::color(SDL_Color color)
    {
        if (_ptr_texture)
            SDL_DestroyTexture(_ptr_texture);
        _color = color;
        _make_texture();
    }

    Rect* Text::source_rect()
    {
        return &_source_rect;
    }

    void Text::_make_texture()
    {
        _ptr_texture = _ptr_font->make_text_texture(_psz_text, _color);
        _make_source_rect();
    }

    void Text::_make_source_rect()
    {
        SDL_QueryTexture(_ptr_texture, nullptr, nullptr, &_source_rect.w, &_source_rect.h);
        _source_rect.x = 0;
        _source_rect.y = 0;
    }
}