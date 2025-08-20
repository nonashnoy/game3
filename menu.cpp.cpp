/*
    This source code is protected by copyright.
    © nohashduck <doebutsu@duck.com>
*/

#include "menu.hpp"

hugaxyu::c_menu::c_menu(void) {
    if (this->f_font.loadFromFile("data.000") == false) {
        return;
    }

    if (this->t_texture.loadFromFile("data.001") == false) {
        return;
    }

    this->s_sprite[0].setTexture(this->t_texture);
    this->s_sprite[1].setTexture(this->t_texture);
    this->s_sprite[2].setTexture(this->t_texture);
    this->s_sprite[3].setTexture(this->t_texture);
    this->s_sprite[4].setTexture(this->t_texture);
    this->s_sprite[5].setTexture(this->t_texture);
    this->s_sprite[6].setTexture(this->t_texture);
    this->s_sprite[7].setTexture(this->t_texture);
    this->s_sprite[8].setTexture(this->t_texture);
    this->s_sprite[9].setTexture(this->t_texture);
    this->s_sprite[10].setTexture(this->t_texture);
    this->s_sprite[11].setTexture(this->t_texture);
    this->s_sprite[12].setTexture(this->t_texture);
    this->s_sprite[13].setTexture(this->t_texture);

    this->s_sprite[0].setTextureRect({ 0, 0, 944, 200 });
    this->s_sprite[1].setTextureRect({ 0, 200, 501, 100 });
    this->s_sprite[2].setTextureRect({ 0, 200, 501, 100 });
    this->s_sprite[3].setTextureRect({ 0, 200, 501, 100 });
    this->s_sprite[4].setTextureRect({ 0, 400, 467, 117 });
    this->s_sprite[5].setTextureRect({ 501, 200, 501, 250 });
    this->s_sprite[6].setTextureRect({ 501, 200, 501, 250 });
    this->s_sprite[7].setTextureRect({ 501, 200, 501, 250 });
    this->s_sprite[8].setTextureRect({ 501, 200, 501, 250 });
    this->s_sprite[9].setTextureRect({ 501, 200, 501, 250 });
    this->s_sprite[10].setTextureRect({ 501, 200, 501, 250 });
    this->s_sprite[11].setTextureRect({ 1002, 0, 1253, 301 });
    this->s_sprite[12].setTextureRect({ 0, 200, 501, 100 });
    this->s_sprite[13].setTextureRect({ 0, 200, 501, 100 });

    this->s_sprite[0].setPosition(488, 440);
    this->s_sprite[1].setPosition(1319, 375);
    this->s_sprite[2].setPosition(1319, 525);
    this->s_sprite[3].setPosition(1319, 675);
    this->s_sprite[4].setPosition(1336, 244);
    this->s_sprite[5].setPosition(100, 115);
    this->s_sprite[6].setPosition(651, 115);
    this->s_sprite[7].setPosition(100, 415);
    this->s_sprite[8].setPosition(651, 415);
    this->s_sprite[9].setPosition(100, 715);
    this->s_sprite[10].setPosition(651, 715);
    this->s_sprite[11].setPosition(333, 390);
    this->s_sprite[12].setPosition(383, 541);
    this->s_sprite[13].setPosition(1035, 541);

    this->t_text[0].setFont(this->f_font);
    this->t_text[1].setFont(this->f_font);
    this->t_text[2].setFont(this->f_font);
    this->t_text[3].setFont(this->f_font);
    this->t_text[4].setFont(this->f_font);
    this->t_text[5].setFont(this->f_font);
    this->t_text[6].setFont(this->f_font);
    this->t_text[7].setFont(this->f_font);
    this->t_text[8].setFont(this->f_font);
    this->t_text[9].setFont(this->f_font);
    this->t_text[10].setFont(this->f_font);
    this->t_text[11].setFont(this->f_font);
    this->t_text[12].setFont(this->f_font);

    this->t_text[0].setString(L"© DevearDev 2024-2024. Build: 1.0.0");
    this->t_text[1].setString(L"Новая игра");
    this->t_text[2].setString(L"Продолжить");
    this->t_text[3].setString(L"Выход");
    this->t_text[4].setString(L"Пустота");
    this->t_text[5].setString(L"Пустота");
    this->t_text[6].setString(L"Пустота");
    this->t_text[7].setString(L"Пустота");
    this->t_text[8].setString(L"Пустота");
    this->t_text[9].setString(L"Пустота");
    this->t_text[10].setString(L"Вы хотите перезаписать эту ячейку?");
    this->t_text[11].setString(L"Да");
    this->t_text[12].setString(L"Нет");

    this->t_text[0].setCharacterSize(20);
    this->t_text[1].setCharacterSize(50);
    this->t_text[2].setCharacterSize(50);
    this->t_text[3].setCharacterSize(50);
    this->t_text[4].setCharacterSize(30);
    this->t_text[5].setCharacterSize(30);
    this->t_text[6].setCharacterSize(30);
    this->t_text[7].setCharacterSize(30);
    this->t_text[8].setCharacterSize(30);
    this->t_text[9].setCharacterSize(30);
    this->t_text[10].setCharacterSize(50);
    this->t_text[11].setCharacterSize(50);
    this->t_text[12].setCharacterSize(50);

    this->t_text[0].setFillColor({ 255, 255, 255, 255 });
    this->t_text[1].setFillColor({ 255, 255, 255, 255 });
    this->t_text[2].setFillColor({ 255, 255, 255, 255 });
    this->t_text[3].setFillColor({ 255, 255, 255, 255 });
    this->t_text[3].setFillColor({ 255, 255, 255, 255 });
    this->t_text[4].setFillColor({ 255, 255, 255, 255 });
    this->t_text[5].setFillColor({ 255, 255, 255, 255 });
    this->t_text[6].setFillColor({ 255, 255, 255, 255 });
    this->t_text[7].setFillColor({ 255, 255, 255, 255 });
    this->t_text[8].setFillColor({ 255, 255, 255, 255 });
    this->t_text[9].setFillColor({ 255, 255, 255, 255 });
    this->t_text[10].setFillColor({ 255, 255, 255, 255 });
    this->t_text[11].setFillColor({ 255, 255, 255, 255 });
    this->t_text[12].setFillColor({ 255, 255, 255, 255 });

    this->t_text[0].setPosition(1389, 815);
    this->t_text[1].setPosition(1419, 395);
    this->t_text[2].setPosition(1402, 545);
    this->t_text[3].setPosition(1485, 695);
    this->t_text[4].setPosition(110, 318);
    this->t_text[5].setPosition(661, 318);
    this->t_text[6].setPosition(110, 618);
    this->t_text[7].setPosition(661, 618);
    this->t_text[8].setPosition(110, 918);
    this->t_text[9].setPosition(661, 918);
    this->t_text[10].setPosition(476, 435);
    this->t_text[11].setPosition(599, 561);
    this->t_text[12].setPosition(1238, 561);

    this->b_is_created = true;
}

auto hugaxyu::c_menu::v_update(void) -> void {
    if (this->s_sprite[0].getColor().a != 0) {
        this->s_sprite[0].setColor(sf::Color(255, 255, 255, this->s_sprite[0].getColor().a - 5));
    }
}

auto hugaxyu::c_menu::v_update_events(sf::RenderWindow &rw_window_, const std::uint8_t ui8t_event_) -> void {
    if (this->s_sprite[0].getColor().a == 0 && b_is_menu == true || b_is_pause == true) {
        if (ui8t_event_ == sf::Event::MouseMoved) {
            if (this->b_is_dialog == false) {
                if (this->b_is_new == false) {
                    this->s_sprite[1].setTextureRect({ 0, 200, 501, 100 });
                }
                
                if (this->b_is_continue == false && this->b_is_save == false) {
                    this->s_sprite[2].setTextureRect({ 0, 200, 501, 100 });
                }
                
                this->s_sprite[3].setTextureRect({ 0, 200, 501, 100 });
                
                if (this->s_sprite[1].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                    this->s_sprite[1].setTextureRect({ 0, 300, 501, 100 });
                } else if (this->s_sprite[2].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                    this->s_sprite[2].setTextureRect({ 0, 300, 501, 100 });
                } else if (this->s_sprite[3].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                    this->s_sprite[3].setTextureRect({ 0, 300, 501, 100 });
                }

                return;
            }

            this->s_sprite[12].setTextureRect({ 0, 200, 501, 100 });
            this->s_sprite[13].setTextureRect({ 0, 200, 501, 100 });

            if (this->s_sprite[12].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                this->s_sprite[12].setTextureRect({ 0, 300, 501, 100 });
            } else if (this->s_sprite[13].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                this->s_sprite[13].setTextureRect({ 0, 300, 501, 100 });
            }
        } else if (ui8t_event_ == sf::Mouse::Left) {
            if (this->b_is_dialog == false) {
                if (this->s_sprite[1].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                    if (this->b_is_menu == true) {
                        this->b_is_new = !this->b_is_new;
                        this->b_is_continue = false;
                        return;
                    }

                    this->b_is_pause = false;
                } else if (this->s_sprite[2].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                    if (this->b_is_menu == true) {
                        this->b_is_new = false;
                        this->b_is_continue = !this->b_is_continue;
                        return;
                    }

                    this->b_is_save = !this->b_is_save;
                } else if (this->s_sprite[3].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                    if (this->b_is_menu == true) {
                        rw_window_.close();
                    }

                    this->t_text[1].setString(L"Новая игра");
                    this->t_text[2].setString(L"Продолжить");
                    this->t_text[3].setString(L"Выход");
                    this->t_text[1].setPosition(1419, 395);
                    this->t_text[2].setPosition(1402, 545);
                    this->t_text[3].setPosition(1485, 695);
                    this->b_is_save = false;
                    this->b_is_menu = true;
                    this->b_is_pause = false;
                } else if (this->b_is_dialog == false && this->b_is_new == true || this->b_is_continue == true || this->b_is_save == true) {
                    if (this->s_sprite[5].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                        if (this->b_is_new == true) {
                            this->b_is_menu = false;
                            this->b_is_new = false;
                            this->b_is_continue = false;
                            std::cout << "Новая игра" << std::endl;
                            return;
                        } else if (this->b_is_continue == true) {
                            std::cout << "Продолжить" << std::endl;
                            return;
                        }

                        std::cout << "SAVE" << std::endl;
                    } else if (this->s_sprite[6].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                    
                    } else if (this->s_sprite[7].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {

                    } else if (this->s_sprite[8].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {

                    } else if (this->s_sprite[9].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {

                    } else if (this->s_sprite[10].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {

                    }
                }

                return;
            }
            
            if (this->s_sprite[12].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                this->b_is_dialog = false;
            } else if (this->s_sprite[13].getGlobalBounds().contains(sf::Mouse::getPosition(rw_window_).x, sf::Mouse::getPosition(rw_window_).y)) {
                this->b_is_dialog = false;
            }
        }
    }
    
    if (this->b_is_menu == false && ui8t_event_ == sf::Keyboard::Scan::Escape) {
        this->b_is_pause = !this->b_is_pause;
        if (this->b_is_pause == true) {
            this->t_text[1].setString(L"Продолжить");
            this->t_text[2].setString(L"Сохранить");
            this->t_text[3].setString(L"Выход");
            this->t_text[1].setPosition(1402, 395);
            this->t_text[2].setPosition(1430, 545);
            this->t_text[3].setPosition(1485, 695);
            return;
        }

        this->t_text[1].setString(L"Новая игра");
        this->t_text[2].setString(L"Продолжить");
        this->t_text[3].setString(L"Выход");
        this->t_text[1].setPosition(1419, 395);
        this->t_text[2].setPosition(1402, 545);
        this->t_text[3].setPosition(1485, 695);
    }
}

auto hugaxyu::c_menu::v_draw(sf::RenderWindow &rw_window_) -> void {
    if (this->s_sprite[0].getColor().a != 0) {
        rw_window_.draw(s_sprite[0]);
        return;
    } else if (b_is_pause == true || b_is_menu == true) {
        if (b_is_menu == true) {
            rw_window_.draw(this->t_text[0]);
        }

        if (this->b_is_new == true || this->b_is_continue == true || this->b_is_save == true) {
            rw_window_.draw(this->s_sprite[5]);
            rw_window_.draw(this->s_sprite[6]);
            rw_window_.draw(this->s_sprite[7]);
            rw_window_.draw(this->s_sprite[8]);
            rw_window_.draw(this->s_sprite[9]);
            rw_window_.draw(this->s_sprite[10]);
            rw_window_.draw(this->t_text[4]);
            rw_window_.draw(this->t_text[5]);
            rw_window_.draw(this->t_text[6]);
            rw_window_.draw(this->t_text[7]);
            rw_window_.draw(this->t_text[8]);
            rw_window_.draw(this->t_text[9]);
        }

        rw_window_.draw(this->s_sprite[0]);
        rw_window_.draw(this->s_sprite[1]);
        rw_window_.draw(this->s_sprite[2]);
        rw_window_.draw(this->s_sprite[3]);
        rw_window_.draw(this->s_sprite[4]);
        rw_window_.draw(this->t_text[1]);
        rw_window_.draw(this->t_text[2]);
        rw_window_.draw(this->t_text[3]);

        if (this->b_is_dialog == true) {
            rw_window_.draw(this->s_sprite[11]);
            rw_window_.draw(this->s_sprite[12]);
            rw_window_.draw(this->s_sprite[13]);
            rw_window_.draw(this->t_text[10]);
            rw_window_.draw(this->t_text[11]);
            rw_window_.draw(this->t_text[12]);
        }
    }
}