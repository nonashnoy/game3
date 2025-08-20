/*
    This source code is protected by copyright.
    © nohashduck <doebutsu@duck.com>
*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdint>

namespace hugaxyu {
    class c_menu {
        private:
            sf::Texture t_texture;
            sf::Sprite s_sprite[14];
            sf::Font f_font;
            sf::Text t_text[13];
        public:
            bool b_is_menu = { true };
            bool b_is_pause = { false };
            bool b_is_dialog = { false };
            bool b_is_new = { false };
            bool b_is_continue = { false };
            bool b_is_save = { false };
            bool b_is_created = { false };
            c_menu(void);
            auto v_update(void) -> void;
            auto v_update_events(sf::RenderWindow &rw_window_, const std::uint8_t ui8t_event_) -> void;
            auto v_draw(sf::RenderWindow &rw_window_) -> void;
    };
};