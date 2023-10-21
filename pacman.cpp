#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
#include<windows.h>
using namespace sf;
using namespace std;

strings(double n);

const int h=40;
const int w=40;
float x=100;
float y=100;

int main()
{
  
  a:
  
  string gamemap[h]={
    "0000000000000000000000000000000000000000",
    "0000000000000000000000000000000000000000",
    "00xccccccccccccccc    cccccccccccccccx00",
    "00c000c000000c0000    0000c000000c000c00",
    "00c000c000000c0000    0000c000000c000c00",
    "00cccccccccccccccc    cccccccccccccccc00",
    "00c0000000c00c000000000000c00c0000000c00",
    "00c0000000c00c000000000000c00c0000000c00",
    "00c00cccccx        00      00xccccc00c00",
    "00c00cc000c0000000 00 0000000c000cc00c00",
    "00c00cc000c0000000 00 0000000c000cc00c00",
    "00c00cc000c00              00c000cc00c00",
    "00ccccc000c00 00000  00000 00c000cc00c00",
    "00  000000c00 00000  00000 00c000000  00",
    "3   000000c                  c000000   3",
    "00  000000c00 00000  00000 00c000000  00",
    "00ccccc000c00 00000  00000 00c000ccccc00",
    "00c00cc000c00              00c000cc00c00",
    "00c00cc000c0000000 00 0000000c000cc00c00",
    "00c00cc000c0000000 00 0000000c000cc00c00",
    "00c00cccccx        00      00xccccc00c00",
    "00c0000000c00c000000000000c00c0000000c00",
    "00c0000000c00c000000000000c00c0000000c00",
    "00cccccccccccccccc    cccccccccccccccc00",
    "00c000c000000c0000    0000c000000c000c00",
    "00c000c000000c0000    0000c000000c000c00",
    "00xccccccccccccccc    cccccccccccccccx00",
    "0000000000000000000000000000000000000000",
    "0000000000000000000000000000000000000000",
  };
  
  
  int posx=0,posy=0;
  
  int i=0;j=0;
  int dir=0;
  float x=0;y=0;
  float cx=1.5,cy=1.5;
  int f1=60,framex=0,f2=60,framey=0;
  int l=1,level=0;
  double point=0;
  double t=0;
  int sheild=1000;
  int inc=1;
  font myfont;
  text gameover;
  text mypoint;
  text mypoints;
  text mytome;
  text myscores;
  text youwin;
  text bg;
  myfont.loadFromFile("ab.ttf");
  srand(time(NULL));
  
  renderWindow start(VideoMode(1600,900,64), "start");
  
          bg.setFont(myfont);
          bg.setString("PACMAN");
          bg.setCharacterSize(200);
          bg.setColor(Color(222,222,0));
          bg.set.Position(460,50);
      
      Texture eg;
      eg.LoadFromFile("exitgame..png");
      sprit exitgame(eg);
      exitgame.setposition(700,700);
      
      Texture m;
      m.loadFromFile("mm.png");
      sprite mm(m);
      
      Texture l1;
      l1.loadFromFile("level1.png");
      sprite level1(l1);
      level1.setposition(150.300);
      
      Texture l2;
      l2.loadFromFile("level2.png");
      sprite level1(l2);
      level2.setposition(150.500);
      
      Texture l3;
      l3.loadFromFile("level3.png");
      sprite level1(l3);
      level3.setposition(150.700);
      
      Music click;
      click.openFromFile("click.wav");
      
      while(start.isopen())
      {
        Event e;
        while (start.pollEvent(e))
        {
          
          if(e.type == Event::Closed)
          {
            start.close();
            exit(0);
          }
        }
        start.setMouseCursorVisible(false);
        Vector2i mousepos = Mouse::getPosition(start);
        mm.setPosition(mousepos.x,mousepos.y);
        
        if(mm.etGlobalBounds().intersects(level1.getGlobalBounds()))
        {
          click.pause();
          if(e.key.code==Mouse::lefft)
          {
            level=3;
            start.close();
          }
        }
        if(mm.getGlobalBounds().intersects(level2.getGlobalBounds()))
        {
          click.pause();
          if(e.key.code==Mouse::left)
          {
            level=6;
            start.close();
          }
        }
        if(mm.getGlobalBounds().intersects(level3.getGlobalBounds()))
        {
            click.pause();
          if(e.key.code==Mouse::left)
          {
            level=9;
            start.close();
          }
        }
        
          if(mm.getGlobalBounds().intersects(exitgame.getGlobalBounds()))
        {
          click.pause();
          if(e.key.code==Mouse::left)
          {
            exit(0);
          }
        }
        
        if(mm.getGlobalBounds().intersects(mm.getGlobalBounds()))
        {
          click.play();
        }
        start.clear();
        start.draw(level1);
        start.draw(level2);
        start.draw(level3);
        start.draw(exitgame);
        start.draw(bg);
        start.draw(mm);
        start.display();
      }
      RenderWindow window(VideoMode(1600,900,64), "pacman");
      
      gameover.setFont(myfont);
      gameover.setString("Game Over");
      gameover.setCharacterSize(40);
      gameover.setColor(Color(255,255,255));
      gameover.setPosition(490,420);
      
      
      youwin.setFont(myfont);
      youwin.setString("You Win");
      youwin.setCharacterSize(40);
      youwin.setColor(Color(255,255,255));
      youwin.setPosition(500,420);
      
      myscores.setFont(myfont);
      myscores.setString("Time : ");
      myscores.setCharacterSize(30);
      myscores.setColor(Color(222,222,0));
      myscores.setPosition(1250,300);
      
      mypoints.setFont(myfont);
      mypoints.setString("Coins : ");
      mypoints.setCharacterSize(30);
      mypoints.setColor(Color(255,255,255));
      mypoints.setPosition(1250,150);
      
      SoundBuffer buffer;
      buffer.loadFromFile("collect.way");
      sound collect;
      collect.setBuffer(buffer);
      
      Music death;
      death.openFromFile("death.way");
      
      Music win;
      win.openFromFile("win.way");
      
      Music music;
      music.openFromFile("music.ogg");
      music.play();
      music.setloop(true);
      
      Texture ms;
      ms.loadFromFile("mm.png");
      sprite m1(ms);
      
      Texture exitg;
      exitg.loadFromFile("exitgame.png");
      sprite exitgame(exitg);
      exigame1.setPosition(1400,700);
      
      Texture b;
      b.loadFromFile("ball.png");
      sprite ball(b);
      
      Texture gm;
      gm.loadFromFile("gmap.png");
      sprite gmap(gm);
      
      Texture p;
      p.loadFromFile("pacman.png");
      sprite pacman(p);
      
      Texture c;
      c.loadFromFile("coin.png");
      sprite coin(c);
      
      Texture e;
      e.loadFromFile("enemy1.png");
      sprite enemy1(e);
      enemy1.setPosition(600,400);
      int direnemy1=0;
      direnemy1=rand()%4+1;
      
      vector<sprite> enemy;
      enemy.push_back(enemy1);
      
      
      while(window.isOpen())
      {
        t+=0.1;
        
        if(point==202)
        {
          music.pause();
          win.play();
          window.draw(youwin);
          windoe.display();
          sleep(4000);
          goto a;
        }
        
        
      mypoint.setFont(myfont);
      mypoint.setString(s(point));
      mypoint.setCharacterSize(30);
      mypoint.setColor(Color(222,222,0));
      mypoint.setPosition(1400,150);
      
      mytime.setFont(myfont);
      mytime.setString(s(t));
      mytime.setCharacterSize(30);
      mytime.setColor(Color(255,0,0));
      mytime.setPosition(1400,300);
      
      window.setMouseCursorVisible(false);
      Vector2i mousepos = Mouse::getPosition(window);
      m1.setPosition(mousepos.x,mousepos.y);
        
      if(l<level)
      {
        enemy.puh_bak(enemyl);
        l++;
      }
      
      
        
  if (shield == 1000)
  {
  inv = 1;
  pacman.setColor(color::Yellow);
  for (size_t i = 0; i < enemy.size(); i++)
  {
    enemy[i].setColor()Color::Yellow);
    if(pacman.getPosition().x>enemy[i].getPosition().x-85 
      && pacman.getPosition().x < enemy[i].getPosition().x + 85)
      if (pacman.getPosition().y > enemy[i].getPosition().y - 85
        && pacman.getPosition().y < enemy[i].getPosition().y + 85)
      {
        music.pause();
        death.play();
        window.draw.(gameover);
        window.display();
        sleep(3000);
        goto a;
      }
  }
}

if (shield < 1000)
{
  inv = 0;
  shield++;
  pacman.setColor(Color::Red);
  for (size_t i = 0; i < enemy.size(); i++)
  {
    enemy[i].setColor()Color::Blue);
    if (pacman.getPosition().x > enemy[i].getPosition().x - 85
      && pacman.getPosition().x < enemy[i].getPosition().x + 85)
      if (pacman.getPosition().y > enemy[i].getPosition().y - 85
        && pacman.getPosition().y < enemy[i].getPosition().y + 85)
      {
        enemy[i].setPosition(590,420)
      }
  }
}
                  ////////////////////////////
      
    
    srand(time(NULL));
    
    /////////////////////////
    for (size_t i = 0; i < enemy.size(); i++)
    {
      direnemy1 = rand() % 4 + 1;
      if (direnemy1 == 1) enemy[i].move(0, -1);
      if (direnemy1 == 2) enemy[i].move(0, 1);
      if (direnemy1 == 3) enemy[i].move(-1, 0);
      if (direnemy1 == 4) enemy[i].move(1, 0);
      
      if (inv == 1)
      {
        if (enemy[i].getPosition().x < pacman.getPosition().x)enemy[i].move(1, 0);
        if (enemy[i].getPosition().x > pacman.getPosition().x)enemy[i].move(-1, 0);
        if (enemy[i].getPosition().y < pacman.getPosition().y)enemy[i].move(0, 1);
        if (enemy[i].getPosition().y > pacman.getPosition().y)enemy[i].move(0, -1);
      }
      if (inv == 0)
      {
        if (enemy[i].getPosition().x > pacman.getPosition().x)enemy[i].move(1, 0);
        if (enemy[i].getPosition().x < pacman.getPosition().x)enemy[i].move(-1, 0);
        if (enemy[i].getPosition().y > pacman.getPosition().y)enemy[i].move(0, 1);
        if (enemy[i].getPosition().y < pacman.getPosition().y)enemy[i].move(0, -1);
      }
    }
    ////////////////////////////////
    
    for(i=0;i< H; i++)
    for (j = 0; j < W; j++)
      {
        srand(time(NULL));
        gmap.setPosition(j * 32, i * 32);
        if (gamemap[i][j] == '0' && gamemap[i + 1][j] == '0' && gamemap[i][j + 1] == '0'
          && gamemap[i][j + 1] == '0' || && gamemap[i][j] == '3')
        {
          for (size_t i = 0; i < enemy.size(); i++)
          {
            if (enemy[i].getGlobalBounds().intersects(gmap.getGlobalBounds()))
            {
              if (enemy[i].getPosition().x > gmap.getPosition().x)
              {
                enemy[i].move(1.5, 0);
              }
              if (enemy[i].getPosition().x < gmap.getPosition().x)
              {
                enemy[i].move(-1.5, 0);
              }
              if (enemy[i].getPosition().y > gmap.getPosition().y)
              {
                enemy[i].move(0,1.5);
              }
              if (enemy[i].getPosition().y < gmap.getPosition().y)
              {
                enemy[i].move(0,-1.5);
              }
            }
          }
        }
  
        if (gamemap[i][j] == 'x')
        {
          if (pacman.getGlobalBounds().intersects(gmap.getGlobalBounds()))
          {
            gamemap[i][j] = ' ';
            shield = 0;
          }
      }
      }
      
    /////////////////
    for (i = 0; i < H; i++)
      for (j = 0; j < W; j++)
      {
        gmap.setPosition(j * 32, i * 32);
        if (gamemap[i][j] == '0' && gamemap[i + 1][j] == '0' && gamemap[i][j + 1] == '0'
          && gamemap[i + 1][j + 1] == '0')
        {
          direnemy1 = rand() % 4 + 1;
        }
      }
    //////////////////////
    
    
    
    pacman.setOrigin(30, 30);
    pacman.setPosition(625 + x, 830 + y);
    posx = (50 + x) / 32;
    posx = (50 + y) / 32;
    pacman.setTextureRect(InRect(framex, framey, f1, f2))
    vector2f pos = pacman.getPosition();
      
    if (pacman.getPosition().y >= 445 && pacman.getPosition().y <= 451 && pacman.getPosition().x < 0)
    {
      x = 600;
    }
    if (pacman.getPosition().y >= 445 && pacman.getPosition().y <= 451 && pacman.getPosition().x > 1250)
    {
      x = 600;
    }
    
    window.setFramerateLimit(80);
    
    Event e;
    
    if (m1.getGlobalBound().intersects(exitgame1.getGlobalBounds()))
    {
      if (e.key.code == Mouse::Left)
      {
        goto a;
      }
    }
    
    
    while (window.pollEvent(e))
    {
     
      if (e.type == Event::Closed)window.close();
    }
    
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
      dir = 1;
      f2 = -60;
      framey = 60;
      f1 = 60;
      framex = 0;
      pacman.setRotation(270);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
      dir = 2;
      f2 = -60;
      framey = 0;
      f1 = 60;
      framex = 60;
      pacman.setRotation(90);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
      dir = 3;
      f2 = -60;
      framey = 0;
      f1 = 60;
      framex = 60;
      pacman.setRotation(0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
      dir = 4;
      f2 = -60;
      framey = 0;
      f1 = 60;
      framex = 0;
      pacman.setRotation(0);
    }
    
    if(dir == 1)
    {
      y = y - cy;
    }
    if (dir == 2)
    {
      y = y + cy;
    }
    if (dir == 3)
    {
      x = x - cx;
    }
    if (dir == 4)
    {
      x = x + cx;
    }
    
    window.clear(Color(0, 0, 0));
    
    for(i=0; i<H; i++)
      for (j = 0; i < W; j++)
      {
        if (gamemap[i][j] == '0' && gamemap[i + 1][j] == '0' && gamemap[i][j + 1] == '0'
          && gamemap[i + 1][j + 1] == '0')
        {
          gmap.setTextureRect(InRect(0, 0, 32, 32));
          gamp.setPosition(j * 32, i * 32);
          window.draw(gmap);
        }
        if (gamemap[i][j] == 'c')
        {
          coin.setposition(j * 32 - 16, i * 32 - 16);
          window.draw(coin);
        }
        
        if (gamemap[i][j] == 'x')
        {
          coin.setposition(j * 32 - 16, i * 32 - 16);
          window.draw(ball);
        }
        
        if (gamemap[i][j] != '0') continue;
      }

     for (i = 0; i < H; i++)
      for (j = 0; j < W; j++)
      {
       gmap.setPosition(j * 32, i * 32);
        if (gamemap[i][j] == '0' && gamemap[i + 1][j] == '0' && gamemap[i][j + 1] == '0'
          && gamemap[i + 1][j + 1] == '0')
        {

          if (pacman.getGlobalBounds().intersects(gmap.getGlobalBounds()))
          {
            if (pacman.getPosition().x > gmap.getPosition().x + 32)
            {
              x += 1.5;
            }
            if (pacman.getPosition().x < gmap.getPosition().x)
            {
              x -= 1.5;
            }
            if (pacman.getPosition().y > gmap.getPosition().y + 32)
            {
              y += 1.5;
            }
            if (pacman.getPosition().y < gmap.getPosition().y)
            {
              y -= 1.5;
            }

          }
        }
        if (gamemap[i][j] == 'c')
        {
          //if(pacman.getGlobalBounds().intersects(gmap.getGlobalBounds())
          if (pacman.getPosition().x > gamp.getPosition().x - 25
            && pacman.getPosition().x < gmap.getPosition().x + 30
            && pacman.getPosition().y > gmap.getPosition().y - 25
            && pacman.getPosition().y gmap.getPosition().y + 30)
          {
            collect.play();
            gamemap[i][j] = ' ';
            point++;
          }
        }

      }
    for (size_t i = 0; i < enemy.size(); i++)
    {
      window.draw(enemy[i]);
    }
     window.draw(m1);
     window.draw(mytime);
     window.draw(myscores);
     window.draw(mypoint);
     window.draw(mypoints);
     window.draw(exitgame);
     window.draw(pacman);
     window.display();
   }
    return 0;
    }

    string s(double n)
    {
      stringstream ss;
      ss < n;
      return ss.str();
    }
      
      
                
  
  
  
    
    
    
    }
}