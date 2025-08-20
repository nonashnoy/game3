/*
    This source code is protected by copyright.
    © nohashduck <doebutsu@duck.com>
*/

#include "location.hpp"

hugaxyu::c_location::c_location(void) {
    if (this->t_texture.loadFromFile("data.002") == false) {
        return;
    }

    this->s_sprite.setTexture(this->t_texture);
    this->s_sprite.setTextureRect({ 0, 0, 4096, 1410 });

    this->b_is_created = true;
}

auto hugaxyu::c_location::v_update(void) -> void {

}

auto hugaxyu::c_location::v_update_events(sf::RenderWindow &rw_window_, sf::View &v_view_, const std::uint8_t ui8t_event_) -> void {
    if (ui8t_event_ == sf::Keyboard::Scan::W) {
        this->s_sprite.setPosition(this->s_sprite.getPosition().x, this->s_sprite.getPosition().y + 5);
    } else if (ui8t_event_ == sf::Keyboard::Scan::A) {
        this->s_sprite.setPosition(this->s_sprite.getPosition().x - 5, this->s_sprite.getPosition().y);
    } else if (ui8t_event_ == sf::Keyboard::Scan::S) {
        this->s_sprite.setPosition(this->s_sprite.getPosition().x, this->s_sprite.getPosition().y - 5);
    } else if (ui8t_event_ == sf::Keyboard::Scan::D) {
        this->s_sprite.setPosition(this->s_sprite.getPosition().x + 5, this->s_sprite.getPosition().y);
    }

    this->cp_player.v_update_events(rw_window_, ui8t_event_);
}

auto hugaxyu::c_location::v_draw(sf::RenderWindow &rw_window_, sf::View &v_view_) -> void {
    v_view_.setCenter(this->cp_player.s_sprite.getPosition());
    rw_window_.setView(v_view_);
    rw_window_.draw(this->s_sprite);
    this->cp_player.v_draw(rw_window_);
    rw_window_.setView(rw_window_.getDefaultView());
}