#ifndef RENDER_H
#define RENDER_H

#include <QList>
#include <QPainterPath>
#include <QRect>
#include <QWidget>
#include <QInputDialog>

using namespace std;

QT_BEGIN_NAMESPACE
class QPaintEvent;
class RenderFlags;
QT_END_NAMESPACE

enum Operation { NoTransformation, Translate, Rotate, ZoomIn, ZoomOut, ReflectionX, ReflectionY, Reflection };

class Render : public QWidget
{
    Q_OBJECT
public:
    Render(QWidget *parent = 0);

    bool i;
    void setOperations(const QList<Operation> &operations);
    void setShape(const QPainterPath &shape);
    void transformPainter(QPainter &painter);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawCoordinates(QPainter &painter);
    void drawOutline(QPainter &painter);
    void drawShape(QPainter &painter);

    QList<Operation> operations;
    QPainterPath shape;
    QRect xBoundingRect;
    QRect yBoundingRect;
};
#endif // RENDER_H
