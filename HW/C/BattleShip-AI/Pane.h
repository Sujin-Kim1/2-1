#ifndef PANE_H
#define PANE_H

#include <ncurses.h>

class Pane
{
  public:
    Pane(int x, int y, int width, int height);
    Pane();
    virtual ~Pane();
    
    virtual void Draw();
    virtual WINDOW *GetWindow() const { return m_pWindow; };

  protected:
    int m_width;
    int m_height;
    int m_x, m_y;
    WINDOW *m_pWindow;
};

#endif //PANE_H
