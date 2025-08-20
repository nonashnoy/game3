/*
    This source code is protected by copyright.
    © nohashduck <dobutsuduck@gmail.com>
*/

#pragma once
#include "includes.hpp"

namespace ns_window {
    class c_window {
        public:
            SDL_Window* sdlw_window = nullptr;
            SDL_Renderer* sdlr_render = nullptr;
            SDL_Event sdle_event = { 0 };
            bool b_create = true, b_mouse_click_left = false;
            int i_window_w = 1920, i_window_h = 1080, i_mouse_x = 0, i_mouse_y = 0;
            int i_start_performance_frequency = 0, i_end_performance_frequency = 0;
            float f_fps = 0;
        public:
            c_window(void);
            ~c_window(void);
            bool b_is_open(void);
            bool b_is_event(ns_image::c_image &c_image_, int i_type_);
            bool b_is_event(ns_text::c_text &c_text_, int i_type_);
            void v_draw(ns_image::c_image &c_image_);
            void v_draw(ns_text::c_text &c_text_);
            void v_clear(void);
            void v_display(void);
            float f_get_fps(void);
    };
};