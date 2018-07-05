#ifndef INPUTPANE_H
#define INPUTPANE_H

#include "Pane.h"
#include "CommonDefine.h"

class InputPane : public Pane
{
  public:
    InputPane(int x, int y, int width, int height);
    ~InputPane();

    virtual void Draw();

    void GetInput(char *input);

    void GetRandomInput(char *input);

    void SetAttacked(Position pos);

private:
    bool m_attacked[MAP_SIZE][MAP_SIZE];
};

#endif //INPUTPANE_H
