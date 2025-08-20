/*
    This source code is protected by copyright.
    © nohashduck <doebutsu@duck.com>
*/

#include "game.hpp"
#include <SFML/Window/Event.hpp>

hugaxyu::c_game::c_game(void) {
    this->rw_window.create({ 1920, 1080 }, "hugaxyu", sf::Style::Default);
    this->rw_window.setFramerateLimit(60);
    this->v_view.setSize({ 1920, 1080 });
    
    if (this->cm_menu.b_is_created == false) {
        return;
    }

    if (this->cl_location.b_is_created == false) {
        return;
    }

    if (this->cl_location.cp_player.b_is_created == false) {
        return;
    }

    while (this->rw_window.isOpen() == true) {
        if (this->b_is_frozen == false && this->cm_menu.b_is_pause == false) {
            this->cl_location.v_update();
            this->cm_menu.v_update();
        }

        while (this->rw_window.pollEvent(this->e_event) == true) {
            if (this->e_event.type == sf::Event::Closed) {
                this->rw_window.close();
            } else if (this->e_event.type == sf::Event::LostFocus) {
                this->b_is_frozen = true;
            } else if (this->e_event.type == sf::Event::GainedFocus) {
                this->b_is_frozen = false;
            } else if (this->e_event.type == sf::Event::MouseMoved) {
                this->cm_menu.v_update_events(this->rw_window, sf::Event::MouseMoved);
            } else if (this->e_event.type == sf::Event::MouseButtonPressed) {
                if (this->e_event.mouseButton.button == sf::Mouse::Left) {
                    this->cm_menu.v_update_events(this->rw_window, sf::Mouse::Left);
                    break;
                }

                this->cm_menu.v_update_events(this->rw_window, sf::Mouse::Right);
            } else if (this->e_event.type == sf::Event::KeyPressed) {
                if (this->e_event.key.scancode == sf::Keyboard::Scan::Escape) {
                    this->cm_menu.v_update_events(this->rw_window, sf::Keyboard::Scan::Escape);
                } else if (this->e_event.key.scancode == sf::Keyboard::Scan::W) {
                    this->cm_menu.v_update_events(this->rw_window, sf::Keyboard::Scan::W);
                } else if (this->e_event.key.scancode == sf::Keyboard::Scan::A) {
                    this->cm_menu.v_update_events(this->rw_window, sf::Keyboard::Scan::A);
                } else if (this->e_event.key.scancode == sf::Keyboard::Scan::S) {
                    this->cm_menu.v_update_events(this->rw_window, sf::Keyboard::Scan::S);
                } else if (this->e_event.key.scancode == sf::Keyboard::Scan::D) {
                    this->cm_menu.v_update_events(this->rw_window, sf::Keyboard::Scan::D);
                }
            }
        }

        this->rw_window.clear({ 0, 0, 0 });

        if (this->cm_menu.b_is_menu == false) {
            this->cl_location.v_draw(this->rw_window, this->v_view);
        }

        this->cm_menu.v_draw(this->rw_window);
        this->rw_window.display();
    }
}