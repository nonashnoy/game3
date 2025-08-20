/*
    This source code is protected by copyright.
    © nohashduck <dobutsuduck@gmail.com>
*/

#pragma once
#include "includes.hpp"

namespace ns_image {
    class c_image {
        public:
            SDL_Surface* sdls_surface = nullptr;
            SDL_Texture* sdlt_texture = nullptr;
            SDL_Rect sdlr_window = { 0, 0, 0, 0 }, sdlr_surface = { 0, 0, 0, 0 };
            std::string s_image = "";
            int i_transparency = 255;
        private:
            bool b_surface_change = true, b_texture_change = true, b_visibility = true;
        public:
            bool b_get_surface_change(void);
            void v_set_surface_change(bool b_surface_change_);
            bool b_get_texture_change(void);
            void v_set_texture_change(bool b_texture_change_);
            c_image(std::string s_image_, int i_position_x_, int i_position_y_, int i_size_w_, int i_size_h_, int i_position_x__, int i_position_y__);
            ~c_image(void);
            void v_set_image(std::string s_image_, int i_position_x_, int i_position_y_, int i_size_w_, int i_size_h_);
            void v_set_image(int i_position_x_, int i_position_y_, int i_size_w_, int i_size_h_);
            std::string s_get_image(void);
            void v_set_position_x(int i_position_x_);
            int i_get_position_x(void);
            void v_set_position_y(int i_position_y_);
            int i_get_position_y(void);
            int i_get_size_w(void);
            int i_get_size_h(void);
            void v_set_transparency(int i_transparency_);
            int i_get_transparency(void);
            bool b_get_visibility(void);
            void v_set_visibility(bool b_visibility_);
    };
};