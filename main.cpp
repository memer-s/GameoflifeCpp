#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    const int pxsize = 1;
    const int height = 800;
    const int width = 1080;

    sf::RenderWindow window(sf::VideoMode(width*pxsize, height*pxsize), "Game of Life.");
    sf::RectangleShape shape(sf::Vector2f(pxsize,pxsize));
    shape.setFillColor(sf::Color::White);

    window.setFramerateLimit(10);




    int8_t pg[width][height] = {0};
    int8_t pgf[width][height] = {0};

    /*
    int pat[10][50] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

    };

    */
    
    
    
    srand(1337);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            pg[i][j] = rand()%2;
        }
    }
    
    /*
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            pg[i+50][j+50] = pat[i][j];
        }
        
    }
    */

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            pgf[i][j]=pg[i][j];
        }
    }
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();







        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++) {
                if(pg[i][j]==1) {
                    shape.setPosition(sf::Vector2f(i*pxsize, j*pxsize));
                    window.draw(shape);
                }

                int n = 0;

                if (pg[i-1][j-1]==1){n++;}
                if (pg[i-1][j]==1) {n++;}
                if(pg[i-1][j+1]==1) {n++;}
                if (pg[i][j-1]==1) {n++;} 
                if (pg[i][j+1]==1) {n++;} 
                if(pg[i+1][j-1]==1) {n++;}
                if (pg[i+1][j]==1) {n++;} 
                if(pg[i+1][j+1]==1) {n++;}

                if (pg[i][j] == 1 && n<2) {
                    pgf[i][j] = 0;
                }

                else if (pg[i][j] == 1 && n>3) {
                    pgf[i][j] = 0;
                }

                else if (pg[i][j] == 0 && n==3) {
                    pgf[i][j] = 1;
                }

                else {

                } 
            }
        }

        window.display();

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                pg[i][j] = pgf[i][j];
            }
        }
    }

    return 0;
}

// g++ -c main.cpp
// g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system