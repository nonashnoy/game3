/*
    This source code is protected by copyright.
    © nohashduck <dobutsuduck@gmail.com>
*/

#pragma once
#include "includes.hpp"

namespace ns_text {
    class c_text {
        public:
            TTF_Font* ttff_font = nullptr;
            SDL_Surface* sdls_surface = nullptr;
            SDL_Texture* sdlt_texture = nullptr;
            SDL_Rect sdlr_window = { 0, 0, 0, 0 };
            SDL_Color sdlc_color = { 255, 255, 255, 255 };
            int i_size_w = 99999, i_size_h = 0;
        private:
            std::string s_text = " ", s_font = " ";
            int i_font_size = 20;
            bool b_font_change = true, b_surface_change = true, b_texture_change = true, b_visibility = true;
        public:
            void v_set_font_change(bool b_font_change_);
            bool b_get_font_change(void);
            void v_set_surface_change(bool b_surface_change_);
            bool b_get_surface_change(void);
            void v_set_texture_change(bool b_texture_change_);
            bool b_get_texture_change(void);
        public:
            c_text(std::string s_text_, std::string s_font_, int i_font_size_, int i_position_x_, int i_position_y_, int i_size_w_, int i_size_h_);
            ~c_text(void);
            void v_set_text(std::string s_text_);
            std::string s_get_text(void);
            void v_set_font(std::string s_font_);
            std::string s_get_font(void);
            void v_set_font_size(int i_font_size_);
            int i_get_font_size(void);
            void v_set_color(int i_color_r_, int i_color_g_, int i_color_b_, int i_color_a_);
            void v_set_position_x(int i_position_x_);
            int i_get_position_x(void);
            void v_set_position_y(int i_position_y_);
            int i_get_position_y(void);
            void v_set_size_w(int i_size_w_);
            int i_get_size_w(void);
            void v_set_size_h(int i_size_h_);
            int i_get_size_h(void);
            void v_set_visibility(bool b_visibility_);
            bool b_get_visibility(void);
    };
};