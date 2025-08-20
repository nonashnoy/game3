/*
    This source code is protected by copyright.
    © nohashduck <doebutsu@duck.com>
*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdint>

namespace hugaxyu {
    class c_player {
        private:
            sf::Texture t_texture;
        public:
            sf::Sprite s_sprite;
            bool b_is_created = { false };
            c_player(void);
            auto v_update(void) -> void;
            auto v_update_events(sf::RenderWindow &rw_window_, const std::uint8_t ui8t_event_) -> void;
            auto v_draw(sf::RenderWindow &rw_window_) -> void;
    };
};