/*
    This source code is protected by copyright.
    © nohashduck <dobutsuduck@gmail.com>
*/

#include "image.hpp"

bool ns_image::c_image::b_get_surface_change(void) {
    return this->b_surface_change;
}

void ns_image::c_image::v_set_surface_change(bool b_surface_change_) {
    this->b_surface_change = b_surface_change_;
}

bool ns_image::c_image::b_get_texture_change(void) {
    return this->b_texture_change;
}

void ns_image::c_image::v_set_texture_change(bool b_texture_change_) {
    this->b_texture_change = b_texture_change_;
}

ns_image::c_image::c_image(std::string s_image_, int i_position_x_, int i_position_y_, int i_size_w_, int i_size_h_, int i_position_x__, int i_position_y__) {
    v_set_image(s_image_, i_position_x_, i_position_y_, i_size_w_, i_size_h_);
    v_set_position_x(i_position_x__);
    v_set_position_y(i_position_y__);
    (b_debug == true) && std::cout << this << " | Create image->surface: OK!" << std::endl;
    (b_debug == true) && std::cout << this << " | Create image->texture: OK!" << std::endl;
}

ns_image::c_image::~c_image(void) {
    if (this->sdls_surface != nullptr) {
        SDL_FreeSurface(this->sdls_surface); (b_debug == true) && std::cout << this << " | Destroy image->surface: OK!" << std::endl;
    } else {
        (b_debug == true) && std::cerr << this << " | Destroy image->surface: FAIL!" << std::endl;
    }

    if (this->sdlt_texture != nullptr) {
        SDL_DestroyTexture(this->sdlt_texture); (b_debug == true) && std::cout << this << " | Destroy image->texture: OK!" << std::endl;
    } else {
        (b_debug == true) && std::cerr << this << " | Destroy image->texture: FAIL!" << std::endl;
    }
}

void ns_image::c_image::v_set_image(std::string s_image_, int i_position_x_, int i_position_y_, int i_size_w_, int i_size_h_) {
    this->b_surface_change = true;
    this->b_texture_change = true;
    this->s_image = s_image_;
    v_set_image(i_position_x_, i_position_y_, i_size_w_, i_size_h_);
}

void ns_image::c_image::v_set_image(int i_position_x_, int i_position_y_, int i_size_w_, int i_size_h_) {
    this->sdlr_surface.x = i_position_x_;
    this->sdlr_surface.y = i_position_y_;
    this->sdlr_surface.w = i_size_w_;
    this->sdlr_surface.h = i_size_h_;
    this->sdlr_window.w = this->sdlr_surface.w;
    this->sdlr_window.h = this->sdlr_surface.h;
}

std::string ns_image::c_image::s_get_image(void) {
    return this->s_image.c_str();
}

void ns_image::c_image::v_set_position_x(int i_position_x_) {
    this->sdlr_window.x = i_position_x_;
}

int ns_image::c_image::i_get_position_x(void) {
    return this->sdlr_window.x;
}

void ns_image::c_image::v_set_position_y(int i_position_y_) {
    this->sdlr_window.y = i_position_y_;
}

int ns_image::c_image::i_get_position_y(void) {
    return this->sdlr_window.y;
}

int ns_image::c_image::i_get_size_w(void) {
    return this->sdlr_window.w;
}

int ns_image::c_image::i_get_size_h(void) {
    return this->sdlr_window.h;
}

void ns_image::c_image::v_set_transparency(int i_transparency_) {
    this->b_texture_change = true;
    this->i_transparency = i_transparency_;
}

int ns_image::c_image::i_get_transparency(void) {
    return this->i_transparency;
}

bool ns_image::c_image::b_get_visibility(void) {
    return this->b_visibility;
}

void ns_image::c_image::v_set_visibility(bool b_visibility_) {
    this->b_visibility = b_visibility_;
}