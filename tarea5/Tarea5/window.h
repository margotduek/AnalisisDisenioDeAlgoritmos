#ifndef WINDOW_H
#define WINDOW_H

#include "render.h"

#include <QList>
#include <QPainterPath>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QComboBox;
QT_END_NAMESPACE


class Window : public QWidget
{
  Q_OBJECT

public:
    Window();

public slots:
  void operationChanged();
  void shapeSelected(int index);

private:
  void setupShapes();
  enum { NumTransformedAreas = 4 }; //La cantidad de ventanas
  Render *originalRenderArea;
  Render *transformedRenderArea[NumTransformedAreas];
  QComboBox *shapeComboBox;
  QComboBox *operationComboBoxes[NumTransformedAreas];
  QList<QPainterPath> shapes;

};

#endif // WINDOW_H
