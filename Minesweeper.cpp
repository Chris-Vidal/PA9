#include "Minesweeper.h"
#include "Board.h"
#include "Menu.h""

void Minesweeper::menu()
{
    sf::RenderWindow mainWindow(sf::VideoMode(1000, 1000), "Minesweeper", sf::Style::Default);
    Menu mainMenu(mainWindow.getSize().x, mainWindow.getSize().y);

    //Background
    sf::RectangleShape background;
    background.setSize(Vector2f(1000, 1000));
    Texture bkgdTexture;
    bkgdTexture.loadFromFile("test.png");
    background.setFillColor(Color::Black);
    //background.setTexture(&bkgdTexture);


    while (mainWindow.isOpen())
    {
        Event event;
        while (mainWindow.pollEvent(event))
        {
            sf::RectangleShape info;
            info.setSize(Vector2f(1000, 1000));
            Texture bkgdTexture;
            bkgdTexture.loadFromFile("test.png");
            info.setTexture(&bkgdTexture);

            if (event.type == Event::Closed)
            {
                mainWindow.close();
            }

            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                {
                    mainMenu.moveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down)
                {
                    mainMenu.moveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return)
                {
                    RenderWindow HTP(VideoMode(1000, 1000), "How To Play");

                    int x = mainMenu.mainMenuPressed();
                    if (x == 0)
                    {
                        //break;
                        HTP.close();
                        initialize();
                    }
                    if (x == 1)
                    {
                        while (HTP.isOpen())
                        {
                            Event intEvent;
                            while (HTP.pollEvent(intEvent))
                            {
                                if (intEvent.type == Event::Closed)
                                {
                                    HTP.close();
                                }
                                if (intEvent.type == Event::KeyPressed)
                                {
                                    //this->info.loadFromFile
                                    if (intEvent.key.code == Keyboard::Escape)
                                    {
                                        HTP.close();
                                    }
                                }
                            }



                            HTP.clear();

                            HTP.draw(info);

                            HTP.display();
                        }
                    }
                    if (x == 2)
                    {
                        exit(1);
                    }
                }

            }
        }
        mainWindow.clear();
        mainWindow.draw(background);
        mainMenu.draw(mainWindow);
        mainWindow.display();
    }


}

Minesweeper::Minesweeper()
{
}

Minesweeper::~Minesweeper()
{
}

void Minesweeper::initialize()
{
	Board start(12);
	start.setup();
}

void Minesweeper::run()
{
	menu();
}