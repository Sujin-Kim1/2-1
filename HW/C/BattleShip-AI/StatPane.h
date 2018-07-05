#ifndef STATPANE_H
#define STATPANE_H

#include "CommonDefine.h"
#include "Pane.h"

class StatPane : public Pane
{
  public:
    StatPane(int x, int y, int width, int height);
    ~StatPane();

    virtual void Draw();
    void PrintTurn(int turn) const;
    void PrintDestroy(ShipType type);

  private:
    bool m_firstDestroyer;
};

#endif //STATPANE_H
