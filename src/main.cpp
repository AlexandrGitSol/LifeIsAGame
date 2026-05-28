#include "header.h"

int sosx = 1800;
int sosy = 700;

int main()
{
    srand(time(0));
    ContextSettings settings;
    settings.antialiasingLevel = 5;
    sf::RenderWindow window(sf::VideoMode(sosx, sosy), "Life is a game", Style::Default, settings);
    Mouse mouse;

    Desk desk;
    desk.rand_oper();
    window.clear(sf::Color(255, 255, 255));
    desk.draw_desk(window);
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    bool forTime = true;
    chrono::duration<float> d = t2 - t1;
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //if (mouse.isButtonPressed(Mouse::Left)) {
        //    (*desk.get_desk())[mouse.getPosition(window).x / 2 / rb][mouse.getPosition(window).y / 2 / rb].set_alive(true);
        //}

        if (forTime) {
            t1 = chrono::steady_clock::now();
            forTime = false;
        }
        t2 = chrono::steady_clock::now();
        d = t2 - t1;
        if (d >= chrono::milliseconds(3)) {
            forTime = true;
            window.clear(sf::Color(255, 255, 255));
            desk.calculating();
            desk.draw_desk(window);
            window.display();
        }
    }

    return 0;
}