/*
    This source code is protected by copyright.
    © nohashduck <doebutsu@duck.com>
*/

#pragma once
#include "player.hpp"

namespace hugaxyu {
    class c_location {
        private:
            sf::Texture t_texture;
            sf::Sprite s_sprite;
        public:
            std::uint32_t ui32t_location = { 0 };
            c_player cp_player;
            bool b_is_created = { false };
            c_location(void);
            auto v_update(void) -> void;
            auto v_update_events(sf::RenderWindow &rw_window_, sf::View &v_view_, const std::uint8_t ui8t_event_) -> void;
            auto v_draw(sf::RenderWindow &rw_window_, sf::View &v_view_) -> void;
    };
};