/*
    This source code is protected by copyright.
    © nohashduck <doebutsu@duck.com>
*/

#pragma once
#include "menu.hpp"
#include "location.hpp"

namespace hugaxyu {
    class c_game {
        private:
            sf::RenderWindow rw_window;
            sf::Event e_event;
            sf::Font f_font;
            sf::View v_view;
            c_menu cm_menu;
            c_location cl_location;
            bool b_is_frozen = { false };
        public:
            c_game(void);
    };
};