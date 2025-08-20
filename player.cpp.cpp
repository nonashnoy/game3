/*
    This source code is protected by copyright.
    © nohashduck <doebutsu@duck.com>
*/

#include "player.hpp"

hugaxyu::c_player::c_player(void) {
    if (this->t_texture.loadFromFile("data.003") == false) {
        return;
    }

    this->s_sprite.setTexture(this->t_texture);
    this->s_sprite.setTextureRect({ 125, 455, 115, 215 });
    this->s_sprite.setPosition({ 2180, 953 });

    this->b_is_created = true;
}

auto hugaxyu::c_player::v_update(void) -> void {

}

auto hugaxyu::c_player::v_update_events(sf::RenderWindow &rw_window_, const std::uint8_t ui8t_event_) -> void {
    if (ui8t_event_ == sf::Keyboard::Scan::W) {
        
    } else if (ui8t_event_ == sf::Keyboard::Scan::A) {

    } else if (ui8t_event_ == sf::Keyboard::Scan::S) {
        
    } else if (ui8t_event_ == sf::Keyboard::Scan::D) {
        
    }
}

auto hugaxyu::c_player::v_draw(sf::RenderWindow &rw_window_) -> void {
    rw_window_.draw(this->s_sprite);
}