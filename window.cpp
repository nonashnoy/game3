/*
    This source code is protected by copyright.
    © nohashduck <dobutsuduck@gmail.com>
*/

#include "window.hpp"

ns_window::c_window::c_window(void) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    this->sdlw_window = SDL_CreateWindow("z", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->i_window_w, this->i_window_h, SDL_WINDOW_SHOWN);
    if (this->sdlw_window == nullptr) {
        this->b_create = false; (b_debug == true) && std::cerr << this << " | Create window->window: FAIL!" << std::endl;
    } else {
        (b_debug == true) && std::cout << this << " | Create window->window: OK!" << std::endl;
    }

    this->sdlr_render = SDL_CreateRenderer(this->sdlw_window, -1, SDL_RENDERER_ACCELERATED);
    if (this->sdlr_render == nullptr) {
        this->b_create = false; (b_debug == true) && std::cerr << this << " | Create window->render: FAIL!" << std::endl;
    } else {
        (b_debug == true) && std::cout << this << " | Create window->render: OK!" << std::endl;
    }
}

ns_window::c_window::~c_window(void) {
    if (this->sdlr_render != nullptr) {
        SDL_DestroyRenderer(this->sdlr_render); (b_debug == true) && std::cout << this << " | Destroy window->render: OK!" << std::endl;
    } else {
        (b_debug == true) && std::cerr << this << " | Destroy window->render: FAIL!" << std::endl;
    }

    if (this->sdlw_window != nullptr) {
        SDL_DestroyWindow(this->sdlw_window); (b_debug == true) && std::cout << this << " | Destroy window->render: OK!" << std::endl;
    } else {
        (b_debug == true) && std::cerr << this << " | Destroy window->window: FAIL!" << std::endl;
    }

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

bool ns_window::c_window::b_is_open(void) {
    this->b_mouse_click_left = false;

    while (SDL_PollEvent(&this->sdle_event) != 0) {
        switch (this->sdle_event.type) {
            case SDL_QUIT: {
                this->b_create = false;
            } break;
            case SDL_MOUSEBUTTONDOWN: {
                SDL_GetMouseState(&this->i_mouse_x, &this->i_mouse_y);
                this->b_mouse_click_left = true;
            } break;
        }
    }

    return this->b_create;
}

bool ns_window::c_window::b_is_event(ns_image::c_image &c_image_, int i_type_) {
    switch (i_type_) {
        case 0: {
            if (
                this->b_mouse_click_left == true &&
                this->i_mouse_x > c_image_.i_get_position_x() &&
                this->i_mouse_x < c_image_.i_get_position_x() + c_image_.i_get_size_w() &&
                this->i_mouse_y > c_image_.i_get_position_y() &&
                this->i_mouse_y < c_image_.i_get_position_y() + c_image_.i_get_size_h() 
            ) {
                return true;
            }
        } break;
    }

    return false;
}

bool ns_window::c_window::b_is_event(ns_text::c_text &c_text_, int i_type_) {
    switch (i_type_) {
        case 0: {
            if (
                this->b_mouse_click_left == true &&
                this->i_mouse_x > c_text_.i_get_position_x() &&
                this->i_mouse_x < c_text_.i_get_position_x() + c_text_.i_get_size_w() &&
                this->i_mouse_y > c_text_.i_get_position_y() &&
                this->i_mouse_y < c_text_.i_get_position_y() + c_text_.i_get_size_h() 
            ) {
                return true;
            }
        } break;
    }

    return false;
}

void ns_window::c_window::v_draw(ns_image::c_image &c_image_) {
    if (c_image_.b_get_surface_change() == true) {
        c_image_.sdls_surface = IMG_Load(c_image_.s_get_image().c_str());
        if (c_image_.sdls_surface == nullptr) {
            this->b_create = false; (b_debug == true) && std::cerr << &c_image_ << " | Change image->surface: FAIL!" << std::endl;
        } else {
            (b_debug == true) && std::cout << &c_image_ << " | Change image->surface: OK!" << std::endl;
        }

        c_image_.v_set_surface_change(false);
    }

    if (c_image_.b_get_texture_change() == true) {
        c_image_.sdlt_texture = SDL_CreateTextureFromSurface(this->sdlr_render, c_image_.sdls_surface);
        if (c_image_.sdlt_texture == nullptr) {
            this->b_create = false; (b_debug == true) && std::cerr << &c_image_ << " | Change image->texture: FAIL!" << std::endl;
        } else {
            (b_debug == true) && std::cout << &c_image_ << " | Change image->texture: OK!" << std::endl;
        }
        
        SDL_SetTextureBlendMode(c_image_.sdlt_texture, SDL_BLENDMODE_BLEND);
        SDL_SetTextureAlphaMod(c_image_.sdlt_texture, c_image_.i_transparency);
        c_image_.v_set_texture_change(false);
    }

    if (c_image_.b_get_visibility() == true) {
        SDL_RenderCopy(this->sdlr_render, c_image_.sdlt_texture, &c_image_.sdlr_surface, &c_image_.sdlr_window);
    }
}

void ns_window::c_window::v_draw(ns_text::c_text &c_text_) {
    if (c_text_.b_get_font_change() == true) {
        c_text_.ttff_font = TTF_OpenFont(c_text_.s_get_font().c_str(), c_text_.i_get_font_size());
        
        if (c_text_.ttff_font == nullptr) {
            this->b_create = false; (b_debug == true) && std::cerr << &c_text_ << " | Change text->font: FAIL!" << std::endl;
        } else {
            (b_debug == true) && std::cout << &c_text_ << " | Change text->font: OK!" << std::endl;
        }

        c_text_.v_set_font_change(false);
    }

    if (c_text_.b_get_surface_change() == true) {
        c_text_.sdls_surface = TTF_RenderUTF8_Solid_Wrapped(c_text_.ttff_font, c_text_.s_get_text().c_str(), c_text_.sdlc_color, c_text_.i_size_w);
        c_text_.sdlr_window.w = c_text_.sdls_surface->w;
        c_text_.sdlr_window.h = c_text_.sdls_surface->h;

        if (c_text_.sdls_surface == nullptr) {
            this->b_create = false; (b_debug == true) && std::cerr << &c_text_ << " | Change text->surface: FAIL!" << std::endl;
        } else {
            (b_debug == true) && std::cout << &c_text_ << " | Change text->surface: OK!" << std::endl;
        }

        c_text_.v_set_surface_change(false);
    }

    if (c_text_.b_get_texture_change() == true) {
        c_text_.sdlt_texture = SDL_CreateTextureFromSurface(this->sdlr_render, c_text_.sdls_surface);
        if (c_text_.sdlt_texture == nullptr) {
            this->b_create = false; (b_debug == true) && std::cerr << &c_text_ << " | Change text->texture: FAIL!" << std::endl;
        } else {
            (b_debug == true) && std::cout << &c_text_ << " | Change text->texture: OK!" << std::endl;
        }

        c_text_.v_set_texture_change(false);
    }

    if (c_text_.b_get_visibility() == true) {
        SDL_RenderCopy(this->sdlr_render, c_text_.sdlt_texture, nullptr, &c_text_.sdlr_window);
    }
}

void ns_window::c_window::v_clear(void) {
    SDL_RenderClear(this->sdlr_render);
}

void ns_window::c_window::v_display(void) {
    SDL_RenderPresent(this->sdlr_render);
    this->i_end_performance_frequency = SDL_GetPerformanceCounter();
	this->f_fps = 1 / ((this->i_end_performance_frequency - this->i_start_performance_frequency) / (float)SDL_GetPerformanceFrequency());
}

float ns_window::c_window::f_get_fps(void) {
    return this->f_fps;
}