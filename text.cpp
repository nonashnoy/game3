/*
    This source code is protected by copyright.
    © nohashduck <dobutsuduck@gmail.com>
*/

#include "text.hpp"

void ns_text::c_text::v_set_font_change(bool b_font_change_) {
    this->b_font_change = b_font_change_;
}

bool ns_text::c_text::b_get_font_change(void) {
    return this->b_font_change;
}

void ns_text::c_text::v_set_surface_change(bool b_surface_change_) {
    this->b_surface_change = b_surface_change_;
}

bool ns_text::c_text::b_get_surface_change(void) {
    return this->b_surface_change;
}

void ns_text::c_text::v_set_texture_change(bool b_texture_change_) {
    this->b_texture_change = b_texture_change_;
}

bool ns_text::c_text::b_get_texture_change(void) {
    return this->b_texture_change;
}

ns_text::c_text::c_text(std::string s_text_, std::string s_font_, int i_font_size_, int i_position_x_, int i_position_y_, int i_size_w_, int i_size_h_) {
    v_set_text(s_text_);
    v_set_font(s_font_);
    v_set_font_size(i_font_size_);
    v_set_position_x(i_position_x_);
    v_set_position_y(i_position_y_);
    v_set_size_w(i_size_w_);
    v_set_size_h(i_size_h_);
    (b_debug == true) && std::cout << this << " | Create text->surface: OK!" << std::endl;
    (b_debug == true) && std::cout << this << " | Create text->texture: OK!" << std::endl;
}

ns_text::c_text::~c_text(void) {
    if (ttff_font != nullptr) {
        TTF_CloseFont(this->ttff_font); (b_debug == true) && std::cout << this << " | Destroy text->font: OK!" << std::endl;
    } else {
        (b_debug == true) && std::cerr << this << " | Destroy text->font: FAIL!" << std::endl;
    }

    if (this->sdls_surface != nullptr) {
        SDL_FreeSurface(this->sdls_surface); (b_debug == true) && std::cout << this << " | Destroy text->surface: OK!" << std::endl;
    } else {
        (b_debug == true) && std::cerr << this << " | Destroy text->surface: FAIL!" << std::endl;
    }

    if (this->sdlt_texture != nullptr) {
        SDL_DestroyTexture(this->sdlt_texture); (b_debug == true) && std::cout << this << " | Destroy text->texture: OK!" << std::endl;
    } else {
        (b_debug == true) && std::cerr << this << " | Destroy text->texture: FAIL!" << std::endl;
    }
}

void ns_text::c_text::v_set_text(std::string s_text_) {
    this->s_text = s_text_;
    v_set_surface_change(true);
    v_set_texture_change(true);
}

std::string ns_text::c_text::s_get_text(void) {
    return this->s_text;
}

void ns_text::c_text::v_set_font(std::string s_font_) {
    this->s_font = s_font_;
    v_set_font_change(true);
    v_set_surface_change(true);
    v_set_texture_change(true);
}

std::string ns_text::c_text::s_get_font(void) {
    return this->s_font;
}

void ns_text::c_text::v_set_font_size(int i_font_size_) {
    this->i_font_size = i_font_size_;
    v_set_font_change(true);
    v_set_surface_change(true);
    v_set_texture_change(true);
}

int ns_text::c_text::i_get_font_size(void) {
    return this->i_font_size;
}

void ns_text::c_text::v_set_color(int i_color_r_, int i_color_g_, int i_color_b_, int i_color_a_) {
    sdlc_color.r = i_color_r_;
    sdlc_color.g = i_color_g_;
    sdlc_color.b = i_color_b_;
    sdlc_color.a = i_color_a_;
}

void ns_text::c_text::v_set_position_x(int i_position_x_) {
    this->sdlr_window.x = i_position_x_;
}

int ns_text::c_text::i_get_position_x(void) {
    return this->sdlr_window.y;
}

void ns_text::c_text::v_set_position_y(int i_position_y_) {
    this->sdlr_window.y = i_position_y_;
}

int ns_text::c_text::i_get_position_y(void) {
    return this->sdlr_window.y;
}

void ns_text::c_text::v_set_size_w(int i_size_w_) {
    this->i_size_w = i_size_w_;
    v_set_surface_change(true);
    v_set_texture_change(true);
}

int ns_text::c_text::i_get_size_w(void) {
    return i_size_w;
}

void ns_text::c_text::v_set_size_h(int i_size_h_) {
    this->i_size_h = i_size_h_;
    v_set_surface_change(true);
    v_set_texture_change(true);
}

int ns_text::c_text::i_get_size_h(void) {
    return i_size_h;
}

void ns_text::c_text::v_set_visibility(bool b_visibility_) {
    this->b_visibility = b_visibility_;
}

bool ns_text::c_text::b_get_visibility(void) {
    return this->b_visibility;
}